#include <regex>

#include "Fraction.h"   // TO DO : Throw Exceptions

static Fraction fraction_regex(const char *string) {
    std::smatch matches;
    int i = 0, j = 0, k = 0;
    
    std::string str_check = string;
    std::regex reg_check ("[^-\\d\\/]");
    while (std::regex_search(str_check, matches, reg_check)) {
        str_check = matches.suffix().str();
        i++;
    }

    std::string str_input = string;
    std::regex reg_input("(^(-)?(\\d)+\\/(-)?(\\d)+$)");
    while (std::regex_search(str_input, matches, reg_input)) {
        str_input = matches.suffix().str();
        j++;
    }

    Fraction fraction;
    int _numerator, _denominator;
    std::string str_values = string;
    std::regex reg_values("((-)?(\\d)+)");
    while (std::regex_search(str_values, matches, reg_values)) {
        std::string value = matches.str();
        str_values = matches.suffix().str();
        if (k == 0)
            _numerator = stoi(value);
        else if (k == 1)
            _denominator = stoi(value);
        k++;
    }

    if (i > 0 || j != 1 || k != 2) {
        std::cout << "Invalid input" << std::endl;
        std::cout << "Follow specific format : \"x/y\"" << std::endl;
        Fraction error_fraction(0, 0);
        return error_fraction;
    }

    fraction.set_fraction(_numerator, _denominator);
    return fraction;
}


Fraction::Fraction(int x, int y) {
    _x = x;
    _y = y;
    if (y < 0) {
        _x *= -1;
        _y *= -1;
    }
    this->simplify();
    _value = (double)_x/(double)_y;
}

Fraction::Fraction(int x) {
    _x = x;
    _y = 1;
    _value = (double)_x/(double)_y;
}

Fraction::Fraction(const char *string) {
    Fraction fraction = fraction_regex(string);
    _x = fraction.numerator();
    _y = fraction.denominator();
    _value = (double)_x/(double)_y;
}

Fraction::Fraction(const Fraction &fraction) {
    _x = fraction._x;
    _y = fraction._y;
    _value = fraction._value;
}

Fraction::Fraction() {
    _x = 0;
    _y = 0;
    _value = 0;
}

Fraction &Fraction::operator=(int x) {
    _x = x;
    _y = 1;
    _value = (double)_x/(double)_y;
    return *this;
}

Fraction &Fraction::operator=(const char *string) {
    Fraction fraction = fraction_regex(string);
    _x = fraction.numerator();
    _y = fraction.denominator();
    _value = (double)_x/(double)_y;
    return *this;
}

Fraction &Fraction::operator=(const Fraction &fraction) {
    _x = fraction._x;
    _y = fraction._y;
    _value = fraction._value;
    return *this;
}

void Fraction::scan_fraction(const char *string) {
    Fraction fraction = fraction_regex(string);
    _x = fraction.numerator();
    _y = fraction.denominator();
    _value = (double)_x/(double)_y;
}

int Fraction::numerator() const {
    return _x;
}

int Fraction::denominator() const {
    return _y;
}

double Fraction::value() const {
    return _value;
}

void Fraction::set_fraction(int x, int y) {
    Fraction fraction(x, y);
    *this = fraction;
}

std::ostream &operator<<(std::ostream &os, const Fraction &fraction) {
    if (fraction._y == 1)
        os << fraction._x << std::endl;
    else
        os << fraction._x << "/" << fraction._y << std::endl;
    return os;
}

Fraction &Fraction::simplify() {
    int gcd = _x > _y ? _x : _y;
    while (gcd > 0) {
        if (_x % gcd == 0 && _y % gcd == 0) {
            break;
        }
        gcd--;
    }

    _x /= gcd;
    _y /= gcd;
    _value = (double)_x/(double)_y;
    return *this;
}
