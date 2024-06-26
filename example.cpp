#include "Fraction_Operations.h"
#include "Matrix_Operations.h"
#include "Polynomial_Operations.h"
#include "Vector_Operations.h"
#include "CSR_Format_Matrix_Operations.h"
#include "Complex_Number.h"


int main() {
    // Matrix A(3, 3);
    // A.scan_matrix("{{1, 2, 3}, {4, 2, 4}, {5, 6, 4}}");

    // std::cout << A << std::endl;
    // std::cout << characteristic_polynomial(A) << std::endl;

    // std::cout << get_row(A, 2) << std::endl;

    // A.swap(1, 2);
    // std::cout << A << std::endl;

    // Polynomial p(2);
    // p(2) = 1; p(1) = 0; p(0) = -1;
    // std::cout << p << std::endl;

    // std::cout << quantratic_formula(p) << std::endl;

    // Vector u(3);
    // u.scan_vector("(1, 0, 0)");
    // std::cout << u << std::endl;

    // Vector v(3);
    // v.scan_vector("(0, 1, 0)");

    // std::cout << cross_product(u, v) << std::endl;

    // Fraction a = "-12/3";
    // Fraction b = "2/3";
    // std::cout << a + b << std::endl;

    Matrix matrix(2, 3);
    matrix.scan_matrix("{{1, -1, 2}, {0, -3, 1}}");
    std::cout << matrix << std::endl;

    Vector vector(3);
    vector.scan_vector("(2, 1, 0)");
    std::cout << vector << std::endl;

    std::cout << matrix * vector << std::endl;

    // // Generalization of cross product to n dimensions ?
    // Vector v(4);
    // v.scan_vector("(1, 2, 3, 4)");

    // Vector u(4);
    // u.scan_vector("(1, 3, 5, 6)");

    // std::cout << cross_product(v, u) << std::endl;

    CSR_Format_Matrix csr_fromat_matrix(matrix);
    std::cout << csr_fromat_matrix << std::endl;

    std::cout << csr_fromat_matrix.matrix() << std::endl;

    std::cout << 2 * csr_fromat_matrix << std::endl;

    Matrix I(3, 3);
    I.scan_matrix("{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}");
    std::cout << I << std::endl;

    CSR_Format_Matrix A(I);
    std::cout << A << std::endl;

    // Polynomial p(2);
    // p(2) = 5; p(1) = 2; p(0) = 1;

    // std::cout << p << std::endl;

    // Polynomial q(1);
    // q(1) = 1; q(0) = 5;

    // std::cout << q << std::endl;

    // std::cout << p * q << std::endl;

    // Polynomial test(0);
    // test(0) = 5;

    // std::cout << test;

    // Complex_Number a(2.0, 5.0);
    // std::cout << a << std::endl;

    // Matrix Pow
    double b[] = { 1.0, 1.0,
                   1.0, 2.0 };
    Matrix B(b, 2, 2);
    Matrix base_matrix = B;
    Matrix pow_matrix = B;
    size_t no_primes = 2;
    size_t primes[] =       {2, 5};
    size_t exponents[] =    {1, 1};
    for (size_t i = 0; i < no_primes; i++) {
        size_t prime = primes[i];
        size_t exponent = exponents[i];
        for (size_t j = 1; j < prime; j++) {
            pow_matrix *= base_matrix;
        }
        for (size_t j = 1; j < exponent; j++) {
            base_matrix = pow_matrix;
            for (size_t k = 1; k < prime; k++) {
                pow_matrix *= base_matrix;
            }
        }
        base_matrix = pow_matrix;
    }

    std::cout << pow_matrix;

    return EXIT_SUCCESS;
}
