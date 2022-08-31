#include <cmath>    // TO DO : Throw Exceptions

#include "Polynomial_Operations.h"


static int max(int a, int b) {
    return  a > b ? a : b;
}

double find_random_root(const Polynomial& p, const int accuracy) {
    return 0.0;
}

Vector linear_formula(const Polynomial& polynomial) {
    Vector dummy(0);
    if (polynomial.coeff(1) == 0)
        return dummy;

    Vector roots(1);
    double root = -polynomial.coeff(0)/polynomial.coeff(1);
    roots(1) = root;

    return root;
}

Vector quantratic_formula(const Polynomial& polynomial) {
    if (polynomial.coeff(2) == 0)
        return linear_formula(polynomial);

    double b = polynomial.coeff(1);
    double sqrt_b2_4ac = sqrt(pow(polynomial.coeff(1), 2) - 4*polynomial.coeff(2)*polynomial.coeff(0));
    double _2a = 2*polynomial.coeff(2);

    Vector roots(2);
    roots(1) = (-b + sqrt_b2_4ac)/_2a;
    roots(2) = (-b - sqrt_b2_4ac)/_2a;

    return roots;
}

Vector roots(const Polynomial& polynomial) {
    if (polynomial.degree() == 2)
        return quantratic_formula(polynomial);

    Vector dummy(0);
    return dummy;
}

Polynomial operator + (const Polynomial& p, const Polynomial& q) {
    int degree = max(p.degree(), q.degree());
    Polynomial new_polynomial(degree);

    for (int n = 0; n <= degree; n++)
        new_polynomial(n) = p.coeff(n) + q.coeff(n);

    return new_polynomial;
}

Polynomial operator - (const Polynomial& p, const Polynomial& q) {
    int degree = max(p.degree(), q.degree());
    Polynomial new_polynomial(degree);

    for (int n = 0; n <= degree; n++)
        new_polynomial(n) = p.coeff(n) - q.coeff(n);

    return new_polynomial;
}

Polynomial operator * (const Polynomial &p, const Polynomial &q) {
    int degree = p.degree() + q.degree();
    Polynomial new_polynomial(degree);

    int n = max(p.degree(), q.degree());
    for (int k = 0; k <= 2*n; k++) {
        double diagonal_sum_k = 0;
        if (k <= n)
            for (int i = 0, j = k; i <= k && j >= 0; i++, j--)
                diagonal_sum_k += p.coeff(i)*q.coeff(j);
        else
            for (int i = n, j = k-n; i >= k-n && j <= n; i--, j++)
                diagonal_sum_k += p.coeff(i)*q.coeff(j);
        
        new_polynomial(k) = diagonal_sum_k;
    }

    return new_polynomial;
}

Polynomial operator * (const double k, const Polynomial& polynomial) {
    Polynomial new_polynomial(polynomial.degree());

    for (int n = 0; n <= polynomial.degree(); n++)
        new_polynomial(n) = k * polynomial.coeff(n); 

    return new_polynomial;
}


bool operator == (const Polynomial &p, const Polynomial &q) {
    int degree = max(p.degree(), q.degree());

    for (int n = 0; n <= degree; n++)
        if (p.coeff(n) != q.coeff(n))
            return false;

    return true;
}

// bool operator == (const Polynomial &p, const std::string& polynomial) {

// }

bool operator != (const Polynomial &p, const Polynomial &q) {
    int degree = max(p.degree(), q.degree());
    
    for (int n = 0; n <= degree; n++)
        if (p.coeff(n) == q.coeff(n))
            return false;

    return true;
}

Polynomial derivative(const Polynomial& polynomial) {
    Polynomial new_polynomial(polynomial.degree()-1);

    for (int n = polynomial.degree(); n >= 1; n--)
        new_polynomial(n - 1) = n * polynomial.coeff(n);

    return new_polynomial;
}

Polynomial anti_derivative(const Polynomial& polynomial) {
    Polynomial new_polynomial(polynomial.degree() + 1);

    for (int n = polynomial.degree(); n >= 0; n--)
        new_polynomial(n + 1) = polynomial.coeff(n)/(n + 1);

    return new_polynomial;
}

double integral(const Polynomial& polynomial, const int a, const int b) {
    Polynomial new_polynomial = anti_derivative(polynomial);

    return new_polynomial.P_x(b) - new_polynomial.P_x(a);
}
