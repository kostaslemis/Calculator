#include "Fraction_Operations.h"
#include "Matrix_Operations.h"
#include "Polynomial_Operations.h"
#include "Vector_Operations.h"


int main() {
    Matrix A(3, 3);
    A.scan_matrix("{{1, 2, 3}, {4, 2, 4}, {5, 6, 4}}");

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
    u.scan_vector("(1, 0, 0)");
    std::cout << u << std::endl;

    Vector v(3);
    v.scan_vector("(0, 1, 0)");

    std::cout << cross_product(u, v) << std::endl;

    Fraction a = "-12/3";
    Fraction b = "2/3";
    std::cout << a + b << std::endl;

    return EXIT_SUCCESS;
}
