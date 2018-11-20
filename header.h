#ifndef UNTITLED_HEADER_H
#define UNTITLED_HEADER_H

using namespace std;

class Lineral_system {
    int size;
    double **matrix;
    double *vector;
public:
    Lineral_system();
    Lineral_system(const Lineral_system &obj);
    void Show();
    double* operator~();
    ~Lineral_system();
};

#endif
