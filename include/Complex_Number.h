#pragma once

#include <iostream>


class Complex_Number {
    private:
        double _x, _y;
    public:
        Complex_Number(double x, double y);
        Complex_Number();

        void set_complex_number();

        friend std::ostream &operator<<(std::ostream & os, const Complex_Number &complex_number);
};

Complex_Number::Complex_Number() {
}

Complex_Number::~Complex_Number() {
}
