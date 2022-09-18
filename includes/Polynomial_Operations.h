#pragma once

#include "Polynomial.h"
#include "Vector.h"


double find_random_root(const Polynomial &polynomial, unsigned int accuracy);

Vector linear_formula(const Polynomial &polynomial);

Vector quantratic_formula(const Polynomial &polynomial);

Vector roots(const Polynomial &polynomial);

Polynomial operator+(const Polynomial &p, const Polynomial &q);

Polynomial operator-(const Polynomial &p, const Polynomial &q);

Polynomial operator*(const Polynomial &p, const Polynomial &q);

Polynomial operator*(double k, const Polynomial &polynomial);

bool operator==(const Polynomial &p, const Polynomial &q);

// bool operator == (const Polynomial &p, const std::string& polynomial);

bool operator!=(const Polynomial &p, const Polynomial &q);

Polynomial derivative(const Polynomial &polynomial);

Polynomial anti_derivative(const Polynomial &polynomial);

double integral(const Polynomial &polynomial, double a, double b);
