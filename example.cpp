#include "Matrix_Operations.h"
#include "Vector_Operations.h"
#include "Polynomial_Operations.h"


int main() {
    Matrix a(3, 3);
    a(1, 1) = 1; a(1, 2) = 2; a(1, 3) = 3;
    a(2, 1) = 4; a(2, 2) = 2; a(2, 3) = 4;
    a(3, 1) = 5; a(3, 2) = 6; a(3, 3) = 4;

    std::cout << a << std::endl;
    std::cout << characteristic_polynomial(a) << std::endl;

    std::cout << get_row(a, 2) << std::endl;

    a.swap(1, 2);
    std::cout << a << std::endl;

    Polynomial p(2);
    p(2) = 1; p(1) = 0; p(0) = -1;
    std::cout << p << std::endl;

    std::cout << quantratic_formula(p) << std::endl;

    Vector u(3);
    u(1) = 1; u(2) = 0; u(3) = 0;

    Vector v(3);
    v(1) = 0; v(2) = 1; v(3) = 0;

    std::cout << cross_product(u, v) << std::endl;

    return EXIT_SUCCESS;
}
