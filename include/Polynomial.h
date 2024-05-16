#pragma once    // TO DO : Throw Exceptions

#include <iostream>


class Polynomial {
    private:
        const size_t _degree;
        double *_coefficients;
    public:
            Polynomial(size_t degree);
            Polynomial(const Polynomial &polynomial);
            Polynomial(double *coefficients, size_t degree);
           ~Polynomial();
        Polynomial &operator=(const Polynomial &polynomial);
        void scan_polynomial(const char *string);

        size_t degree() const;

        double& operator()(size_t n);
        double coeff(size_t n) const;

        friend std::ostream &operator<<(std::ostream &os, const Polynomial &polynomial);

        double p_x(double x);
};
