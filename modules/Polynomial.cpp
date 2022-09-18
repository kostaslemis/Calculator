#include <cmath>    // TO DO : Throw Exceptions

#include "Polynomial.h"


Polynomial::Polynomial(unsigned int degree) : _degree(degree) {
    _coefficients = new double[_degree + 1];

    for (int i = 0; i <= _degree; i++)
        _coefficients[i] = 0;
}

Polynomial::Polynomial(const Polynomial &polynomial) : _degree(polynomial._degree) {
    _coefficients = new double[_degree + 1];

    for (int i = 0; i <= _degree; i++)
        _coefficients[i] = polynomial._coefficients[i];
}

Polynomial::~Polynomial() {
    delete[] _coefficients;
}

Polynomial &Polynomial::operator=(const Polynomial& polynomial) {
    if (_coefficients == NULL)
        _coefficients = new double[polynomial._degree + 1];

    for (int i = 0; i <= polynomial._degree; i++)
        _coefficients[i] = polynomial._coefficients[i];
    
    return *this;
}


void Polynomial::scan_polynomial(const std::string &string) {

}

int Polynomial::degree() const {
    return _degree;
};


double &Polynomial::operator()(unsigned int n) {
    static double dummy = 0.0;
    if (_coefficients == NULL)
        return dummy;

    return (n >= 0 && n <= _degree)
        ? _coefficients[n]
        : dummy;
}

double Polynomial::coeff(unsigned int n) const {
    static double dummy = 0.0;
    if (_coefficients == NULL)
        return dummy;

    return (n >= 0 && n <= _degree)
        ? _coefficients[n]
        : dummy;
}

void sign(double number) {
    if (number > 0)
        std::cout << " + "; 
    else
        std::cout << " - ";
}

std::ostream &operator<<(std::ostream &os, const Polynomial &polynomial) {
    int degree = polynomial.degree();

    if (abs(polynomial.coeff(degree)) > 1)
        os << polynomial.coeff(degree)<<"x^"<<degree;
    else if (polynomial.coeff(degree) == -1)
        os << "-x^"<<degree;
    else if (polynomial.coeff(degree) == 1)
        os << "x^"<<degree;

    for (int n = degree-1; n > 1; n--) {
        if (abs(polynomial.coeff(n)) > 1) {
            sign(polynomial.coeff(n));
            os << abs(polynomial.coeff(n))<<"x^"<<n;
        } else if (abs(polynomial.coeff(n)) == 1) {
            sign(polynomial.coeff(n));
            os << "x^"<<n;
        }    
    }
    
    if (abs(polynomial.coeff(1)) > 1) {
        sign(polynomial.coeff(1));
        os << abs(polynomial.coeff(1))<<"x"; 
    } else if (polynomial.coeff(1) == 1) {
        sign(polynomial.coeff(1));
        os << "x";
    }

    if (polynomial.coeff(0) != 0) {
        sign(polynomial.coeff(0));
        os << abs(polynomial.coeff(0));
    }

    os << std::endl;

    return os;
}

double Polynomial::P_x(double x) {
    _x = x;
    double _P_x = 0.0;

    for (int i = 0; i <= _degree; i++)
        _P_x += _coefficients[i]*pow(_x, i);

    return _P_x;
}

// double find_root(const Polynomial& polynomial, const int accuracy) {

// }
