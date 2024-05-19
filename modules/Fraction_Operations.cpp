#include "Fraction_Operations.h"

static int gcd(const int x, const int y) {
    // Base Case
    if (x == y)
        return x;
 
    if (x > y)
        return gcd(x - y, y);
    else
        return gcd(x, x - y);
}

static int lcm(const int x, const int y) {
    int result = (x > y) ? x : y;
    while (true) {
        if (result % x == 0 && result % y == 0)
            break;
        result++;
    }

    return result;
}


Fraction operator+(const Fraction &a, const Fraction &b) {
    int _numerator, _denominator;

    if (a.denominator() == b.denominator()) {
        _numerator = a.numerator() + b.numerator();
        _denominator = a.denominator();
    }

    if (a.denominator() != b.denominator()) {
        _denominator = lcm(a.denominator(), b.denominator());
        _numerator = a.numerator()*_denominator/a.denominator() + b.numerator()*_denominator/b.denominator();
    }

    Fraction new_fraction(_numerator, _denominator);
    return new_fraction.simplify();
}

Fraction operator+(const Fraction &fraction, const int k) {
    int _numerator = fraction.numerator() + k*fraction.denominator();

    Fraction new_fraction(_numerator, fraction.denominator());
    return new_fraction.simplify();
}

Fraction operator-(const Fraction &a, const Fraction &b) {
    int _numerator, _denominator;

    if (a.denominator() == b.denominator()) {
        _numerator = a.numerator() - b.numerator();
        _denominator = a.denominator();
    }

    if (a.denominator() != b.denominator()) {
        _denominator = lcm(a.denominator(), b.denominator());
        _numerator = a.numerator()*_denominator/a.denominator() - b.numerator()*_denominator/b.denominator();
    }

    Fraction new_fraction(_numerator, _denominator);
    return new_fraction.simplify();
}

Fraction operator-(const Fraction &fraction, const int k) {
    int _numerator = fraction.numerator() - k*fraction.denominator();

    Fraction new_fraction(_numerator, fraction.denominator());
    return new_fraction.simplify();
}

Fraction operator*(const Fraction &a, const Fraction &b) {
    int _numerator = a.numerator() * b.numerator();
    int _denominator = a.denominator() * b.denominator();

    Fraction new_fraction(_numerator, _denominator);
    return new_fraction.simplify();
}

Fraction operator*(const int k, const Fraction &fraction) {
    int _numerator = k * fraction.numerator();

    Fraction new_fraction(_numerator, fraction.denominator());
    return new_fraction.simplify();
}

Fraction operator/(const Fraction &a, const Fraction &b) {
    int _numerator = a.numerator() * b.denominator();
    int _denominator = a.denominator() * b.numerator();

    Fraction new_fraction(_numerator, _denominator);
    return new_fraction.simplify();
}

Fraction operator/(const Fraction &fraction, const int k) {
    int _denominator = k * fraction.denominator();

    Fraction new_fraction(fraction.numerator(), _denominator);
    return new_fraction.simplify();
}

bool operator==(const Fraction &a, const Fraction &b) {
    return a.numerator() == b.numerator() && a.denominator() == b.denominator();
}

bool operator==(const Fraction &a, const char *string) {
    Fraction fraction = string;
    return a == fraction;
}

bool operator!=(const Fraction &a, const Fraction &b) {
    return a.numerator() != b.numerator() || a.denominator() != b.denominator();
}

bool operator!=(const Fraction &a, const char *string) {
    Fraction fraction = string;
    return a != fraction;
}

Fraction irreducible_fraction(const Fraction &fraction) {
    Fraction new_fraction = fraction;
    return new_fraction.simplify();
}
