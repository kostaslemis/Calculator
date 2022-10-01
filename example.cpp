#include "Fraction_Operations.h"
#include "Matrix_Operations.h"
#include "Polynomial_Operations.h"
#include "Vector_Operations.h"


int main() {
    Matrix A(3, 3);
    A(1, 1) = 1; A(1, 2) = 2; A(1, 3) = 3;
    A(2, 1) = 4; A(2, 2) = 2; A(2, 3) = 4;
    A(3, 1) = 5; A(3, 2) = 6; A(3, 3) = 4;

    std::cout << A << std::endl;
    std::cout << characteristic_polynomial(A) << std::endl;

    std::cout << get_row(A, 2) << std::endl;

    A.swap(1, 2);
    std::cout << A << std::endl;

    Polynomial p(2);
    p(2) = 1; p(1) = 0; p(0) = -1;
    std::cout << p << std::endl;

    std::cout << quantratic_formula(p) << std::endl;

    Vector u(3);
    u(1) = 1; u(2) = 0; u(3) = 0;

    Vector v(3);
    v(1) = 0; v(2) = 1; v(3) = 0;

    std::cout << cross_product(u, v) << std::endl;

    Fraction a(1, 4);
    Fraction b(1, 3);
    Fraction fraction = a + b;
    std::cout << fraction << std::endl;
    
    Fraction c(1, 12);
    std::cout << fraction + c << std::endl;


    return EXIT_SUCCESS;
}
