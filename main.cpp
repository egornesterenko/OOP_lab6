#include "header.cpp"

int main() {
    try {
        Lineral_system one;
        ~one;
    }
    catch (int a) {
        cout << "Error of inputing data";
    }
    catch (errorMatrix& z) {
        z.Message();
        return 0;
    }
}
