#pragma once

#include <iostream>


class Fraction {
    private:
        int _x, _y;
        double _num;
    public:
            Fraction(int x, int y);
            Fraction(const Fraction &fraction);
        Fraction &operator=(const Fraction &fraction);
        void scan_fraction(const std::string &string);

        int numerator() const;
        int denominator() const;
        double value() const;

        friend std::ostream &operator<<(std::ostream &os, const Fraction &fraction);

        void simplify();
};
