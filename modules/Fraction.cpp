#include "Fraction.h"


Fraction::Fraction(int x, int y) {
    _x = x; _y = y;
    _num = (double)_x/(double)_y;
} 

Fraction::Fraction(const Fraction &fraction) {
    _x = fraction._x;
    _y = fraction._y;
    _num = fraction._num;
}

Fraction &Fraction::operator=(const Fraction &fraction) {
    _x = fraction._x;
    _y = fraction._y;
    _num = fraction._num;

    return *this;
}

void scan_fraction(const std::string &string) {

}

int Fraction::numerator() const {
    return _x;
}

int Fraction::denominator() const {
    return _y;
}

double Fraction::value() const {
    return _num;
}

std::ostream &operator<<(std::ostream &os, const Fraction &fraction) {
    os << fraction._x << "/" << fraction._y << std::endl;
    return os;
}

void Fraction::simplify() {
    int gcd = _x > _y ? _x : _y;
    while (gcd > 0) {
        if (_x % gcd == 0 && _y % gcd == 0) {
            break;
        }
        gcd--;
    }

    _x /= gcd;
    _y /= gcd;
    _num = (double)_x/(double)_y;
}
