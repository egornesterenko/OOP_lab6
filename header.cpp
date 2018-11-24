#include <iostream>
#include <iomanip>
#include <cmath>
#include "header.h"
using namespace std;

class errorMatrix { //класс ошибок
public:
    errorMatrix () {
        cout << "ууупс..." << endl;
    }
    virtual void Message() {
        cout << "Найдена ошибка!" << endl;
    }
};
class Degeneracy : public errorMatrix { //матрица вырожденная
public:
    void Message() {
        cout << "Матрица вырожденая - ноль на главной диагонале " << endl;
    }
};
class Invalid : public errorMatrix {
public:
    void Message() {
        cout << "Ошибка введеных данных " << endl;
    }
};


Lineral_system::Lineral_system() {

    cout << "Кількість рівнянь: ";
    int n;
    if (!(cin >> n)) {
        throw Invalid();
    }
    else if (n<0) {
        throw Invalid();
    }

    size = n;

    matrix = new double *[size];
    vector = new double[size];
    for (int i = 0; i < size; i++) {
        matrix[i] = new double[size];
        for (int j = 0; j < size; j++) {
            cout << "matrix[" << i << "][" << j << "]= ";
            if (!(cin >> matrix[i][j])) {
                throw Invalid();
            }
        }
    }
    for (int i = 0; i < size; i++) {
        cout << "vector[" << i << "]= ";
            if (!(cin >> vector[i])) {
                throw Invalid();
            }
        }
    }

Lineral_system::Lineral_system(const Lineral_system &obj) {
    size = obj.size;
    matrix = new double*[obj.size];
    vector = new double[obj.size];
    for (int i = 0; i < obj.size; i++)
    {
        matrix[i] = new double[obj.size];
        for (int j = 0; j < obj.size; j++)
        {
            matrix[i][j] = obj.matrix[i][j];
        }
    }
    for (int i = 0; i < obj.size; i++) {
        vector[i] = obj.vector[i];
    };
}

void Lineral_system::Show() {
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << matrix[i][j] << "*x" << j;
            if (j < size - 1)
                cout << " + ";
        }
        cout << " = " << vector[i] << endl;
    }
    return;
}

double* Lineral_system::operator~()
{
    double *x, max;
    int k, index;
    x = new double[size];
    k = 0;
    while (k < size) {
        max = abs(matrix[k][k]);
        index = k;
        for (int i = k + 1; i < size; i++) {
            if (abs(matrix[i][k]) > max) {
                max = abs(matrix[i][k]);
                index = i;
            }
        }
        if (max <= 0.001) {
            throw Degeneracy();
        }
        for (int j = 0; j < size; j++) {
            double temp = matrix[k][j];
            matrix[k][j] = matrix[index][j];
            matrix[index][j] = temp;
        }
        double temp = vector[k];
        vector[k] = vector[index];
        vector[index] = temp;
        for (int i = k; i < size; i++) {
            double temp = matrix[i][k];
            for (int j = 0; j < size; j++)
                matrix[i][j] /= temp;
            vector[i] /= temp;
            if (i == k) continue;
            for (int j = 0; j < size; j++)
                matrix[i][j] -= matrix[k][j];
            vector[i] -=  vector[k];
        }
        k++;
    }

    for (k = size - 1; k >= 0; k--)
    {
        x[k] = vector[k];
        for (int i = 0; i < k; i++)
            vector[i] -= matrix[i][k] * x[k];
    }
    for (int i = 0; i < size; i++)
        cout << "x[" << i << "]=" << x[i] << endl;
    return x;
}


Lineral_system::~Lineral_system() {
    delete []vector;
    for (int i = 0; i < size; i++)
    {
        delete []matrix[i];
    }
    delete []matrix;
}
