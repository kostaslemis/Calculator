#pragma once

#include "Complex_Number.h"

Complex_Number operator+(const Complex_Number &a, const Complex_Number &b);

Complex_Number operator+(const Complex_Number &complex_number, const double k);

Complex_Number operator-(const Complex_Number &a, const Complex_Number &b);

Complex_Number operator-(const Complex_Number &complex_number, const double k);

Complex_Number operator*(const Complex_Number &a, const Complex_Number &b);

Complex_Number operator*(const double k, const Complex_Number &complex_number);

Complex_Number operator/(const Complex_Number &a, const Complex_Number &b);

Complex_Number operator/(const Complex_Number &complex_number, const double k);

bool operator==(const Complex_Number &a, const Complex_Number &b);

bool operator!=(const Complex_Number &a, const Complex_Number &b);
