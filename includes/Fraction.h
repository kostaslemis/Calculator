#pragma once

#include <iostream>


class Fraction {
    private:
        int _x, _y;
        double _value;
    public:
            Fraction(int x, int y);
            Fraction(int x);
            Fraction(const char *string);
            Fraction(const Fraction &fraction);
            Fraction();
        Fraction &operator=(int x);
        Fraction &operator=(const char *string);
        Fraction &operator=(const Fraction &fraction);
        void scan_fraction(const char *string);

        int numerator() const;
        int denominator() const;
        double value() const;

        void set(int x, int y);

        friend std::ostream &operator<<(std::ostream &os, const Fraction &fraction);

        Fraction &simplify();
};
