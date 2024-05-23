#pragma once

typedef struct polynomial Polynomial;


Polynomial *polynomial_create(size_t degree);

Polynomial *polynomial_random_create(size_t degree, int MAX_VALUE);

void polynomial_destroy(Polynomial *polynomial);

Polynomial *polynomial_copy(const Polynomial *polynomial);

size_t polynomial_degree(const Polynomial *polynomial);

double polynomial_coeff(const Polynomial *polynomial, size_t n);

void polynomial_set_value(Polynomial *polynomial, size_t n, double value);

void polynomial_print(const Polynomial *polynomial);

double polynomial_p_x(const Polynomial *polynomial, double x);
