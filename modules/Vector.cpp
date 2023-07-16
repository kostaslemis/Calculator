#include <regex>

#include "Vector.h"     // TO DO : Throw Exceptions

static Vector vector_regex(const char *string, size_t size) {
    std::smatch matches;
    size_t i = 0, j = 0, k = 0;
    
    std::string str_check = string;
    std::regex reg_check ("[^-,\\s\\d())]");
    while (std::regex_search(str_check, matches, reg_check)) {
        str_check = matches.suffix().str();
        i++;
    }

    std::string str_input = string;
    std::regex reg_input("(^(\\(((-)?(\\d)+(\\s)*?,(\\s)*?)*(-)?(\\d)+(\\s)*?\\))$)");
    while (std::regex_search(str_input, matches, reg_input)) {
        str_input = matches.suffix().str();
        j++;
    }

    Vector vector(0);
    std::string str_values = string;
    std::regex reg_values("((-)?(\\d)+)");
    while (std::regex_search(str_values, matches, reg_values)) {
        std::string value = matches.str();
        vector.insert_last(stoi(value));
        str_values = matches.suffix().str();
        k++;
    }

    if (i > 0 || j != 1 || k != size) {
        std::cout << "Invalid input" << std::endl;
        std::cout << "Follow specific format : \"(x_1, x_2, x_3, ... ,x_n)\"" << std::endl;
        Vector error_vector(0);
        return error_vector;
    }

    return vector;
}


Vector::Vector(size_t size) : _size(size) {
    _capacity = _size < VECTOR_MIN_CAPACITY ? VECTOR_MIN_CAPACITY : _size;
    _elements = new double[_capacity];

    for (size_t i = 0; i < _size; i++)
        _elements[i] = 0;
}

Vector::Vector(const Vector &vector) : _size(vector._size) {
    _elements = new double[vector._capacity];

    for (size_t i = 0; i < _size; i++)
        _elements[i] = vector._elements[i];
}

Vector::~Vector() {
    delete[] _elements;
}

Vector &Vector::operator=(const Vector &vector) {
    if (_elements == NULL)
        _elements = new double[vector._capacity];

    for (size_t i = 0; i < vector._size; i++)
        _elements[i] = vector._elements[i];

    return *this;
}

void Vector::scan_vector(const char *string) {
    Vector vector = vector_regex(string, _size);
    for (size_t i = 0; i < _size; i++)
        this->_elements[i] = vector._elements[i];
}

size_t Vector::size() const {
    return _size;
}

double &Vector::operator()(size_t i) {
    static double dummy = 0.0;
    if (_elements == NULL)
        return dummy;

    return (i >= 1 && i <= _size)
        ? _elements[i - 1]
        : dummy;
}

double Vector::elem(size_t i) const {
    static double dummy = 0.0;
    if (_elements == NULL)
        return dummy;

    return (i >= 1 && i <= _size)
        ? _elements[i - 1]
        : dummy;
}

std::ostream &operator<<(std::ostream &os, const Vector &vector) {
    os << "(";
    for (size_t i = 0; i < vector._size - 1; i++)
        os << vector._elements[i] << ", ";
    os << vector._elements[vector._size - 1] << ")";
    os << std::endl;

    return os;
}

void Vector::insert_last(double new_value) {
	if (_capacity == _size) {
		_capacity *= 2;
		_elements = (double*)realloc(_elements, _capacity * sizeof(double));
	}

	_elements[_size] = new_value;
	_size++;
}

void Vector::remove_last() {
	_size--;

	if (_capacity > _size * 4 && _capacity > 2 * VECTOR_MIN_CAPACITY) {
		_capacity /= 2;
		_elements = (double*)realloc(_elements, _capacity * sizeof(double));
	}
}