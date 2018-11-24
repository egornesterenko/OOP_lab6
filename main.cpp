#include "header.cpp"

int main() {
    try {
        Lineral_system one;
        ~one;
    }
    catch (Invalid& o) {
        o.Message();
        return 0;
    }
    catch (Degeneracy& z) {
        z.Message();
        return 0;
    }
}
