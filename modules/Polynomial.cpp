#include <cmath>    // TO DO : Throw Exceptions

#include "Polynomial.h"

// static Polynomial polynomial_regex(const char *string, size_t size) {
//     Polynomial polynomial(0);
//     return polynomial;
// }


Polynomial::Polynomial(size_t degree) : _degree(degree) {
    _coefficients = new double[_degree + 1];

    for (size_t i = 0; i <= _degree; i++)
        _coefficients[i] = 0;
}

Polynomial::Polynomial(const Polynomial &polynomial) : _degree(polynomial._degree) {
    _coefficients = new double[_degree + 1];

    for (size_t i = 0; i <= _degree; i++)
        _coefficients[i] = polynomial._coefficients[i];
}

Polynomial::~Polynomial() {
    delete[] _coefficients;
}

Polynomial &Polynomial::operator=(const Polynomial& polynomial) {
    if (_coefficients == NULL)
        _coefficients = new double[polynomial._degree + 1];

    for (size_t i = 0; i <= polynomial._degree; i++)
        _coefficients[i] = polynomial._coefficients[i];

    return *this;
}

void Polynomial::scan_polynomial(const char *string) {

}

size_t Polynomial::degree() const {
    return _degree;
};

double &Polynomial::operator()(size_t n) {
    static double dummy = 0.0;
    if (_coefficients == NULL)
        return dummy;

    return (n >= 0 && n <= _degree)
        ? _coefficients[n]
        : dummy;
}

double Polynomial::coeff(size_t n) const {
    const double dummy = 0.0;
    if (_coefficients == NULL)
        return dummy;

    return (n >= 0 && n <= _degree)
        ? _coefficients[n]
        : dummy;
}

void sign(std::ostream &os, double coeff) {
    if (coeff > 0)
        os << " + ";
    else
        os << " - ";
}

void print_coeff(std::ostream &os, double coeff, const char *string, size_t degree) {
    sign(os, coeff);
    os << abs(coeff) << string;
    if (degree > 1)
        os << degree;
}

std::ostream &operator<<(std::ostream &os, const Polynomial &polynomial) {
    size_t degree = polynomial.degree();
    double coeff;

    if (degree == 0) {
        os << polynomial.coeff(0) << std::endl;
        return os;
    }

    if (degree == 1) {
        os << polynomial.coeff(1) << "x";
        coeff = polynomial.coeff(0);
        sign(os, coeff);
        os << abs(coeff) << std::endl;
        return os;
    }

    os << polynomial.coeff(degree) << "x^" << degree;

    for (size_t n = degree - 1; n > 1; n--) {
        coeff = polynomial.coeff(n);
        print_coeff(os, coeff, "x^", n);
    }

    coeff = polynomial.coeff(1);
    print_coeff(os, coeff, "x", 1);

    coeff = polynomial.coeff(0);
    print_coeff(os, coeff, "", 0);

    os << std::endl;
    return os;
}

double Polynomial::p_x(double x) {
    _x = x;
    double _P_x = 0.0;

    for (size_t i = 0; i <= _degree; i++)
        _P_x += _coefficients[i]*pow(_x, i);

    return _P_x;
}

// double find_root(const Polynomial& polynomial, const int accuracy) {

// }
