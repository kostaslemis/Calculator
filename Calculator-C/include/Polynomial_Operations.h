#pragma once

#include "Polynomial.h"
#include "Vector.h"


double find_random_root(const Polynomial *polynomial, unsigned int accuracy);

Vector *linear_formula(Polynomial *polynomial);

Vector *quantratic_formula(Polynomial *polynomial);

Vector *roots(Polynomial polynomial);

Polynomial *polynomials_add(const Polynomial *p, const Polynomial *q);

Polynomial *polynomials_sub(const Polynomial *p, const Polynomial *q);

Polynomial *polynomial_scalar_mult(const Polynomial *polynomial, double k);

Polynomial *polynomials_mult(const Polynomial *p, const Polynomial *q);

// Polynomial *polynomials_mult_omp(const Polynomial *p, const Polynomial *q);

bool polynomials_equal(const Polynomial *p, const Polynomial *q);

bool polynomials_not_equal(const Polynomial *p, const Polynomial *q);

Polynomial *derivative(const Polynomial *polynomial);

Polynomial *anti_derivative(const Polynomial *polynomial);

double integral(const Polynomial *polynomial, double a, double b);
