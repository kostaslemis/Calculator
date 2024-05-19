#pragma once

#include <iostream>


class Complex_Number {
    private:
        double _re, _im;
    public:
            Complex_Number(const double re, const double im);
            Complex_Number(const double re);
            Complex_Number(const Complex_Number &complex_number);
            Complex_Number(const char *string);
            Complex_Number();
        Complex_Number &operator=(const double re);
        Complex_Number &operator=(const Complex_Number &complex_number);
        Complex_Number &operator=(const char *string);
        void scan_complex_number(const char *string);

        double re() const;
        double im() const;

        void set_complex_number(const double re, const double im);

        friend std::ostream &operator<<(std::ostream & os, const Complex_Number &complex_number);
};
