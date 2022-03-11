#include "Matrix.h"


int main (void) {

    Matrix a(2, 2);
    a(1, 1) = 3; a(1, 2) = 1;
    a(2, 1) = 3; a(2, 2) = 3;

    std::cout << char_poly(a) << std::endl;

    return EXIT_SUCCESS;
}
