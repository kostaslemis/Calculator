#pragma once

#include <iostream>


class Fraction {
    private:
        int _x, _y;
        double _value;
    public:
            Fraction(int x, int y);
            Fraction(int x);
            Fraction(double z);
            Fraction(const Fraction &fraction);
            Fraction(const char *string);
            Fraction();
        Fraction &operator=(int x);
        Fraction &operator=(double z);
        Fraction &operator=(const Fraction &fraction);
        Fraction &operator=(const char *string);
        void scan_fraction(const char *string);

        int numerator() const;
        int denominator() const;
        double value() const;

        void set_fraction(int x, int y);

        friend std::ostream &operator<<(std::ostream &os, const Fraction &fraction);

        Fraction &simplify();
};
