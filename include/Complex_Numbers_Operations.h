#pragma once

#include "Complex_Number.h"

Complex_Number operator+(const Complex_Number &a, const Complex_Number &b);

Complex_Number operator+(const Complex_Number &complex_number, double k);

Complex_Number operator-(const Complex_Number &a, const Complex_Number &b);

Complex_Number operator-(const Complex_Number &complex_number, double k);

Complex_Number operator*(const Complex_Number &a, const Complex_Number &b);

Complex_Number operator*(double k, const Complex_Number &complex_number);

Complex_Number operator/(const Complex_Number &a, const Complex_Number &b);

Complex_Number operator/(const Complex_Number &complex_number, double k);
