#pragma once

#include "Polynomial.h"
#include "Vector.h"


double find_random_root(Polynomial polynomial, unsigned int accuracy);

Vector linear_formula(Polynomial polynomial);

Vector quantratic_formula(Polynomial polynomial);

Vector roots(Polynomial polynomial);

Polynomial polynomials_add(Polynomial p, Polynomial q);

Polynomial polynomials_sub(Polynomial p, Polynomial q);

Polynomial polynomial_scalar_mult(Polynomial polynomial, double k);

Polynomial polynomials_mult(Polynomial p, Polynomial q);

bool polynomials_equal(Polynomial p, Polynomial q);

// bool operator == (const Polynomial &p, const std::string& polynomial);

bool polynomials_not_equal(Polynomial p, Polynomial q);

Polynomial derivative(Polynomial polynomial);

Polynomial anti_derivative(Polynomial polynomial);

double integral(Polynomial polynomial, double a, double b);
