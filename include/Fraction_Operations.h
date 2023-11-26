#pragma once

#include "Fraction.h"


Fraction operator+(const Fraction &a, const Fraction &b);

Fraction operator+(const Fraction &fraction, int k);

Fraction operator-(const Fraction &a, const Fraction &b);

Fraction operator-(const Fraction &fraction, int k);

Fraction operator*(const Fraction &a, const Fraction &b);

Fraction operator*(int k, const Fraction &fraction);

Fraction operator/(const Fraction &a, const Fraction &b);

Fraction operator/(const Fraction &fraction, int k);

bool operator==(const Fraction &a, const Fraction &b);

bool operator!=(const Fraction &a, const Fraction &b);

Fraction irreducible_fraction(Fraction fraction);
