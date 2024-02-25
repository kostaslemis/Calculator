#include "Complex_Numbers_Operations.h"


Complex_Number operator+(const Complex_Number &a, const Complex_Number &b) {
    double re = a.re() + b.re();
    double im = a.im() + b.im();
    Complex_Number new_complex_number(re, im);
    return new_complex_number;
}

Complex_Number operator+(const Complex_Number &complex_number, double k) {
    Complex_Number new_complex_number(complex_number.re() + k, complex_number.im());
    return new_complex_number;
}

Complex_Number operator-(const Complex_Number &a, const Complex_Number &b) {
    double re = a.re() - b.re();
    double im = a.im() - b.im();
    Complex_Number new_complex_number(re, im);
    return new_complex_number;
}

Complex_Number operator-(const Complex_Number &complex_number, double k) {
    Complex_Number new_complex_number(complex_number.re() - k, complex_number.im());
    return new_complex_number;
}

Complex_Number operator*(const Complex_Number &a, const Complex_Number &b) {
    double a_re = a.re();
    double a_im = a.im();
    double b_re = b.re();
    double b_im = b.im();
    Complex_Number new_complex_number(a_re*b_re - a_im*b_im, a_re*b_im + a_im*b_re);
    return new_complex_number;
}

Complex_Number operator*(double k, const Complex_Number &complex_number) {
    Complex_Number new_complex_number(k * complex_number.re(), k * complex_number.im());
    return new_complex_number;
}

Complex_Number operator/(const Complex_Number &a, const Complex_Number &b) {
    double a_re = a.re();
    double a_im = a.im();
    double b_re = b.re();
    double b_im = b.im();
    double denominator = b_re*b_re + b_im*b_im;
    Complex_Number new_complex_number((a_re*b_re + a_im*b_im) / denominator, (a_im*b_re - a_re*b_im) / denominator);
    return new_complex_number;
}

Complex_Number operator/(const Complex_Number &complex_number, double k) {
    Complex_Number new_complex_number(complex_number.re() / k, complex_number.im() / k);
    return new_complex_number;
}
