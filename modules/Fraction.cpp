#include "Fraction.h"


Fraction::Fraction(int x, int y) {
    _x = x; _y = y;
    _value = (double)_x/(double)_y;
}

Fraction::Fraction(int x) {
    _x = x; _y = 1;
    _value = (double)_x/(double)_y;
}

Fraction::Fraction(const char *string) {
    std::cout << string << std::endl;
    _x = 4; _y = 3; // REGEX
    _value = (double)_x/(double)_y;
}

Fraction::Fraction(const Fraction &fraction) {
    _x = fraction._x; _y = fraction._y;
    _value = fraction._value;
}

Fraction::Fraction() {
    _x = 0; _y = 1;
    _value = 0;
}

Fraction &Fraction::operator=(int x) {
    _x = x; _y = 1;
    _value = (double)_x/(double)_y;
    return *this;
}

Fraction &Fraction::operator=(const char *string) {
    std::cout << string << std::endl;
    _x = 4; _y = 3; // REGEX
    _value = (double)_x/(double)_y;
    return *this;
}

Fraction &Fraction::operator=(const Fraction &fraction) {
    _x = fraction._x; _y = fraction._y;
    _value = fraction._value;
    return *this;
}

void scan_fraction(const char *string) {
    // REGEX
}

int Fraction::numerator() const {
    return _x;
}

int Fraction::denominator() const {
    return _y;
}

double Fraction::value() const {
    return _value;
}

std::ostream &operator<<(std::ostream &os, const Fraction &fraction) {
    if (fraction._y == 1)
        os << fraction._x << std::endl;
    else
        os << fraction._x << "/" << fraction._y << std::endl;
    return os;
}

Fraction &Fraction::simplify() {
    int gcd = _x > _y ? _x : _y;
    while (gcd > 0) {
        if (_x % gcd == 0 && _y % gcd == 0) {
            break;
        }
        gcd--;
    }

    _x /= gcd; _y /= gcd;
    _value = (double)_x/(double)_y;
    return *this;
}
