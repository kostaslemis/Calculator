#include <regex>

#include "Fraction.h"
#include "Vector.h"

static Vector fraction_regex(const char *string) {
    std::smatch matches;
    int i = 0, j = 0, k = 0;
    
    std::string str_check = string;
    std::regex reg_check ("[^-\\d\\/]");
    while (std::regex_search(str_check, matches, reg_check)) {
        std::cout << matches.str(1) << std::endl;
        str_check = matches.suffix().str();
        i++;
    }

    std::string str_input = string;
    std::regex reg_input("((-)?\\d\\/(-)?\\d)");
    while (std::regex_search(str_input, matches, reg_input)) {
        str_input = matches.suffix().str();
        j++;
    }

    Vector vector(0);
    std::string str_values = string;
    std::regex reg_values("((-)?\\d)");
    while (std::regex_search(str_values, matches, reg_values)) {
        std::string value = matches.str();
        vector.insert_last(stoi(value));
        str_values = matches.suffix().str();
        k++;
    }

    if (i > 0 || j != 1 || k != 2) {
        std::cout << "Invalid input" << std::endl;
        std::cout << "Follow specific format : \"x/y\"" << std::endl;
        Vector error_vector(0);
        return error_vector;
    }

    return vector;
}


Fraction::Fraction(int x, int y) {
    _x = x;
    _y = y;
    _value = (double)_x/(double)_y;
}

Fraction::Fraction(int x) {
    _x = x;
    _y = 1;
    _value = (double)_x/(double)_y;
}

Fraction::Fraction(const char *string) {
    Vector vector = fraction_regex(string);
    _x = vector(1);
    _y = vector(2);
    _value = (double)_x/(double)_y;
}

Fraction::Fraction(const Fraction &fraction) {
    _x = fraction._x;
    _y = fraction._y;
    _value = fraction._value;
}

Fraction::Fraction() {
    _x = 0;
    _y = 1;
    _value = 0;
}

Fraction &Fraction::operator=(int x) {
    _x = x;
    _y = 1;
    _value = (double)_x/(double)_y;
    return *this;
}

Fraction &Fraction::operator=(const char *string) {
    Vector vector = fraction_regex(string);
    _x = vector(1);
    _y = vector(2);
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
    Vector vector = fraction_regex(string);
    _x = vector(1);
    _y = vector(2);
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

    _x /= gcd; _y /= gcd;
    _value = (double)_x/(double)_y;
    return *this;
}
