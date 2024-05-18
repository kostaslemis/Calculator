#pragma once    // TO DO : Throw Exceptions

#include <iostream>


class Polynomial {
    private:
        const size_t _degree;
        double *_coefficients;
    public:
            Polynomial(const size_t degree);
            Polynomial(const Polynomial &polynomial);
            Polynomial(double *coefficients, const size_t degree);
           ~Polynomial();
        Polynomial &operator=(const Polynomial &polynomial);
        void scan_polynomial(const char *string);

        size_t degree() const;

        double& operator()(const size_t n);
        double coeff(const size_t n) const;

        friend std::ostream &operator<<(std::ostream &os, const Polynomial &polynomial);

        double p_x(const double x);
};
