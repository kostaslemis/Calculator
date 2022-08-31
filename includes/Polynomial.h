#pragma once    // TO DO : Throw Exceptions

#include <iostream>


class Polynomial {
    private:
        double _x;
        const int _degree;
        double* _coefficients;
    public:
            Polynomial(const int degree);
            Polynomial(const Polynomial& polynomial);
           ~Polynomial();
        Polynomial& operator = (const Polynomial& polynomial);
        void scan_polynomial(const std::string& string);

        int degree() const;

        double& operator () (const int n);
        double coeff(const int n) const;

        friend std::ostream& operator << (std::ostream& os, const Polynomial& polynomial);

        double P_x(const double x);
};
