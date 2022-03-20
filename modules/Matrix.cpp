#include "Matrix.h"


int main(void) {
    Matrix a(3, 3);
    a(1, 1) = 1; a(1, 2) = 3; a(1, 3) = 3;
    a(2, 1) = 2; a(2, 2) = 2; a(2, 3) = 4;
    a(3, 1) = 5; a(3, 2) = 6; a(3, 3) = 4;

    std::cout << a << std::endl;

    std::cout << char_poly(a) << std::endl;

    return EXIT_SUCCESS;
}