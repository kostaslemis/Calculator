#include <iostream>
#include <math.h>


class Polynomial
{
private:
    const short _degree;
    double *coefficients;
    double _x;
public:
    Polynomial(int n);
    Polynomial(const Polynomial& p);
    ~Polynomial();

    void scanPolynomial(const std::string &polynomial);
    double& operator() (int n);
    double coeff(int n) const;

    short degree() const { return _degree; };
    double P_x(double x);

    double find_root(const Polynomial p, int accuracy);
};

Polynomial::Polynomial(int degree) : _degree(degree) {
    coefficients = new double[_degree+1];
}

Polynomial::Polynomial(const Polynomial& p) : _degree(p._degree) {
    coefficients = new double[_degree+1];
    for (int i = 0; i <= _degree; i++)
        coefficients[i] = p.coefficients[i];
}

Polynomial::~Polynomial() {
    delete[] coefficients;
}

void Polynomial::scanPolynomial(const std::string &polynomial) {

}

double& Polynomial::operator() (int n) {
    static double dummy = 0.0;
    return (n >= 0 && n <= _degree)
        ? coefficients[n]
        : dummy;
}

double Polynomial::coeff(int n) const {
    static double dummy = 0.0;
    return (n >= 0 && n <= _degree)
        ? coefficients[n]
        : dummy;
}

double Polynomial::P_x(double x) {
    _x = x;
    double _P_x = 0.0;

    for (int i = 0; i <= _degree; i++)
        _P_x += coefficients[i]*pow(_x, i);

    return _P_x;
}

void sign(double number) {
    if (number > 0)  std::cout << " + "; 
    else  std::cout << " - ";
}

std::ostream& operator << (std::ostream& os, const Polynomial &p) {
    int degree = p.degree();

    if (p.coeff(degree) != 0) {
        if (abs(p.coeff(degree)) > 1) os << p.coeff(degree)<<"x^"<<degree;
        else if (p.coeff(degree) == -1) os << "-x^"<<degree;
        else  os << "x^"<<degree;
    }

    for (int n = degree-1; n > 1; n--)
        if (abs(p.coeff(n)) > 1) {
            sign(p.coeff(n)); std::cout << abs(p.coeff(n))<<"x^"<<n;
        } else if (abs(p.coeff(n)) == 1) {
            sign(p.coeff(n)); os << "x^"<<n;
        }    

    if (abs(p.coeff(1)) > 1) {
        sign(p.coeff(1)); os << abs(p.coeff(1))<<"x"; 
    } else if (p.coeff(1) == 1) {
        sign(p.coeff(1)); os << "x";
    }

    if (p.coeff(0) != 0) {
        sign(p.coeff(0)); os << abs(p.coeff(0));
    }

    return os;
}

// double Polynomial::find_root(Polynomial P, int accuracy) {

// }

int max(int a, int b) {
    return  a > b ? a : b;
}

Polynomial operator + (const Polynomial &p, const Polynomial &q) {
    int degree = max(p.degree(), q.degree());
    Polynomial polynomial(degree);

    for (int n = degree; n >= 0; n++)
        polynomial(n) = p.coeff(n) + q.coeff(n);

    return polynomial;
}

Polynomial operator - (const Polynomial &p, const Polynomial &q) {
    int degree = max(p.degree(), q.degree());
    Polynomial polynomial(degree);

    for (int n = degree; n >= 0; n++)
        polynomial(n) = p.coeff(n) - q.coeff(n);

    return polynomial;
}

Polynomial operator * (const Polynomial &p, const Polynomial &q) {
    int degree = p.degree() + q.degree();
    Polynomial polynomial(degree);

    int n = max(p.degree(), q.degree());
    for (int k = 0; k <= 2*n; k++) {
        double diagonal_sum_k = 0;
        if (k <= n)
            for (int i = 0, j = k; i <= k && j >= 0; i++, j--)
                diagonal_sum_k += p.coeff(i)*q.coeff(j);
        else
            for (int i = n, j = k-n; i >= k-n && j <= n; i--, j++)
                diagonal_sum_k += p.coeff(i)*q.coeff(j);
        
        polynomial(k) = diagonal_sum_k;
    }

    return polynomial;
}

Polynomial operator * (double k, const Polynomial &p) {
    Polynomial polynomial(p.degree());

    for (int n = p.degree(); n >= 0; n++)
        polynomial(n) = k * p.coeff(n); 

    return polynomial;
}


bool operator == (const Polynomial &p, const Polynomial &q) {
    int degree = max(p.degree(), q.degree());

    for (int n = degree; n >= 0; n++)
        if (p.coeff(n) != q.coeff(n)) return false;

    return true;
}

// bool operator == (const Polynomial &p, const std::string& polynomial) {

// }

bool operator != (const Polynomial &p, const Polynomial &q) {
    return !(p == q);
}

Polynomial Derivative(const Polynomial &p) {
    Polynomial polynomial(p.degree()-1);

    for (int n = p.degree(); n >= 1; n--)
        polynomial(n-1) = n*p.coeff(n);

    return polynomial;
}

Polynomial Antiderivative(const Polynomial &p) {
    Polynomial polynomial(p.degree()+1);

    for (int n = p.degree(); n >= 0; n--)
        polynomial(n+1) = p.coeff(n)/(n+1);

    return polynomial;
}

double Integral(const Polynomial &p, int a, int b) {
    Polynomial polynomial = Antiderivative(p);

    return polynomial.P_x(b) - polynomial.P_x(a);
}
