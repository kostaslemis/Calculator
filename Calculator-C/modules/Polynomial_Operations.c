#include <stdio.h>
#include <stdbool.h>
#include <math.h>


#include "../include/Polynomial_Operations.h"


int max(int a, int b) {
    return a > b ? a : b;
}

double find_random_root(Polynomial polynomial, unsigned int accuracy) {
    return 0.0;
}

// Vector linear_formula(Polynomial polynomial) {

// }

// Vector quantratic_formula(Polynomial polynomial) {

// }

// Vector roots(Polynomial polynomial) {

// }

Polynomial polynomials_add(Polynomial p, Polynomial q) {
    size_t degree = max(polynomial_degree(p) , polynomial_degree(q));
    Polynomial new_polynomial = polynomial_create(degree);

    for (size_t n = 0; n <= degree; n++)
        polynomial_set_value(new_polynomial, n, polynomial_coeff(p, n) + polynomial_coeff(q, n));

    return new_polynomial;
}

Polynomial polynomials_sub(Polynomial p, Polynomial q) {
    size_t degree = max(polynomial_degree(p) , polynomial_degree(q));
    Polynomial new_polynomial = polynomial_create(degree);

    for (size_t n = 0; n <= degree; n++)
        polynomial_set_value(new_polynomial, n, polynomial_coeff(p, n) - polynomial_coeff(q, n));

    return new_polynomial;
}

Polynomial polynomial_scalar_mult(Polynomial polynomial, double k) {
    size_t degree = polynomial_degree(polynomial);
    Polynomial new_polynomial = polynomial_create(degree);

    for (size_t n = 0; n <= degree; n++)
        polynomial_set_value(new_polynomial, n, k * polynomial_coeff(polynomial, n));

    return new_polynomial;
}

Polynomial polynomials_mult(Polynomial p, Polynomial q) {
    size_t degree = polynomial_degree(p) + polynomial_degree(q);
    Polynomial new_polynomial = polynomial_create(degree);

    double diagonal_sum_k;    
    size_t k, i, j;
    size_t n = max(polynomial_degree(p), polynomial_degree(q));
    #pragma omp parallel for num_threads(3) \
        default(none) shared(p, q, new_polynomial, n) private(k, i, j, diagonal_sum_k) \
        schedule(auto)
    for (k = 0; k <= 2*n; k++) {
        diagonal_sum_k = 0.0;
        if (k <= n)
            for (i = 0, j = k; i <= k && j >= 0; i++, j--)
                diagonal_sum_k += polynomial_coeff(p, i) * polynomial_coeff(q, j);
        else
            for (i = n, j = k - n; i >= k - n && j <= n; i--, j++)
                diagonal_sum_k += polynomial_coeff(p, i) * polynomial_coeff(q, j);
       polynomial_set_value(new_polynomial, k, diagonal_sum_k); 
    }

    return new_polynomial;
}

bool polynomials_equal(Polynomial p, Polynomial q) {
    size_t degree = max(polynomial_degree(p), polynomial_degree(q));

    for (size_t n = 0; n <= degree; n++)
        if (polynomial_coeff(p, n) != polynomial_coeff(q, n))
            return false;

    return true;
}

// bool operator == (const Polynomial &p, const std::string& polynomial);

bool polynomials_not_equal(Polynomial p, Polynomial q) {
    size_t degree = max(polynomial_degree(p), polynomial_degree(q));

    for (size_t n = 0; n <= degree; n++)
        if (polynomial_coeff(p, n) != polynomial_coeff(q, n))
            return false;

    return false;
}

// Polynomial derivative(Polynomial polynomial) {

// }

// Polynomial anti_derivative(Polynomial polynomial) {

// }

// double integral(Polynomial polynomial, double a, double b) {

// }
