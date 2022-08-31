#pragma once

#include <iostream>


class Fraction {
    private:
        int _x, _y;
        double _num;
    public:
        Fraction(int x, int y);

    const int numerator() const { return _x; }
    const int denominator() const { return _y; }
    double value() const { return _num; }
};

Fraction::Fraction(int x, int y) {
    _x = x; _y = y;
    _num = (double)_x/_y;
} 

std::ostream& operator << (std::ostream& os, const Fraction& fraction) {
    os << fraction.numerator() << "/" << fraction.denominator() << std::endl; 

    return os;
}
