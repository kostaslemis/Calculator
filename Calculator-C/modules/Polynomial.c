#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "../include/Polynomial.h"

struct polynomial {
    size_t degree;
    double *coefficients;
};

Polynomial *polynomial_create(size_t degree) {
    Polynomial *polynomial = malloc(sizeof(*polynomial));
    polynomial->degree = degree;
    polynomial->coefficients = malloc((polynomial->degree + 1) * sizeof(double));

    for (size_t n = 0; n <= degree; n++)
        polynomial->coefficients[n] = 0.0;

    return polynomial;
}

Polynomial *polynomial_create_random(size_t degree, int MAX_VALUE) {
    Polynomial *polynomial = malloc(sizeof(*polynomial));
    polynomial->degree = degree;
    polynomial->coefficients = malloc((polynomial->degree + 1) * sizeof(double));

    srand(time(NULL));
    for (size_t n = 0; n <= degree; n++)
        polynomial->coefficients[n] = (double)(rand() % MAX_VALUE);

    return polynomial;
}

Polynomial *polynomial_create_view(double *coefficients, size_t degree) {
    Polynomial *polynomial = malloc(sizeof(*polynomial));
    polynomial->degree = degree;
    polynomial->coefficients = malloc((polynomial->degree + 1) * sizeof(double));

    for (size_t n = 0; n <= degree; n++)
        polynomial->coefficients[n] = coefficients[n];

    return polynomial;
}

void polynomial_destroy(Polynomial *polynomial) {
    free(polynomial->coefficients);
    free(polynomial);
}

Polynomial *polynomial_copy(const Polynomial *polynomial) {
    Polynomial *new_polynomial = malloc(sizeof(*new_polynomial));
    new_polynomial->degree = polynomial->degree;
    new_polynomial->coefficients = polynomial->coefficients;

    for (size_t n = 0; n <= polynomial->degree; n++)
        new_polynomial->coefficients[n] = polynomial->coefficients[n];

    return new_polynomial;
}

size_t polynomial_degree(const Polynomial *polynomial) {
    return polynomial->degree;
}

double polynomial_coeff(const Polynomial *polynomial, size_t n) {
    const double dummy = 0.0;
    if (polynomial->coefficients == NULL)
        return dummy;

    return (n >= 0 && n <= polynomial->degree)
        ? polynomial->coefficients[n]
        : dummy;
}

void polynomial_set_value(Polynomial *polynomial, size_t n, double value) {
    if (polynomial->coefficients == NULL)
        return;

    if (n >= 0 && n <= polynomial->degree)
        polynomial->coefficients[n] = value;
}

void sign(double coeff) {
    if (coeff > 0)
        fprintf(stdout, " + ");
    else
        fprintf(stdout, " - ");
}

void print_coeff(double coeff, const char *string, size_t degree) {
    sign(coeff);
    fprintf(stdout, "%.2lf%s", fabs(coeff), string);
    if (degree > 1)
        fprintf(stdout, "%ld", degree);
}

void polynomial_print(const Polynomial *polynomial) {
    size_t degree = polynomial->degree;
    double coeff;

    if (degree == 0) {
        fprintf(stdout, "%.2lf\n", polynomial->coefficients[0]);
        return;
    }

    if (degree == 1) {
        fprintf(stdout, "%.2lfx", polynomial->coefficients[1]);
        coeff = polynomial->coefficients[0];
        sign(coeff);
        fprintf(stdout, "%.2lf\n", fabs(coeff));
        return;
    }

    fprintf(stdout, "%.2lfx^%ld", polynomial->coefficients[degree], degree);

    for (size_t n = degree - 1; n > 1; n--) {
        coeff = polynomial->coefficients[n];
        print_coeff(coeff, "x^", n);
    }

    coeff = polynomial->coefficients[1];
    print_coeff(coeff, "x", 1);

    coeff = polynomial->coefficients[0];
    print_coeff(coeff, "", 0);

    fprintf(stdout, "\n");
}

double polynomial_p_x(const Polynomial *polynomial, double x) {
    double _p_x = 0.0;

    for (size_t n = 0; n <= polynomial->degree; n++)
        _p_x += polynomial->coefficients[n]*pow(x, n);

    return _p_x;
}
