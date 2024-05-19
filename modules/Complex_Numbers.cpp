#include <regex>

#include "Complex_Number.h"     // TO DO : Throw Exceptions

// static Complex_Number complex_number_regex(const char *sting) {

// }


Complex_Number::Complex_Number(const double re, const double im)
    : _re(re), _im(im) {
}

Complex_Number::Complex_Number(const double re)
    : _re(re), _im(0.0) {
}

Complex_Number::Complex_Number(const Complex_Number &complex_number)
    : _re(complex_number._re), _im(complex_number._im) {
}

// Complex_Number::Complex_Number(const char *string) {
//     Complex_Number complex_number = complex_number_regex(string);
//     _re = complex_number._re;
//     _im = complex_number._im;
// }

Complex_Number::Complex_Number()
    : _re(0.0), _im(0.0) {
}

Complex_Number &Complex_Number::operator=(const double re) {
    _re = re;
    _im = 0.0;
    return *this;
}

Complex_Number &Complex_Number::operator=(const Complex_Number &complex_number) {
    _re = complex_number._re;
    _im = complex_number._im;
    return *this;
}

// void Complex_Number::scan_complex_number(const char *string) {
//     Complex_Number complex_number = complex_number_regex(string);
//     _re = complex_number._re;
//     _im = complex_number._im;
// }

double Complex_Number::re() const {
    return _re;
}

double Complex_Number::im() const {
    return _im;
}

void Complex_Number::set_complex_number(const double re, const double im) {
    _re = re;
    _im = im;
}

std::ostream &operator<<(std::ostream & os, const Complex_Number &complex_number) {
    os << complex_number._re;
    if (complex_number._im >= 0.0)
        os << " + ";
    else
        os << " - "; 
    os << complex_number._im << "i" << std::endl;   
    return os; 
}
