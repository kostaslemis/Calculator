#include "Vector.h"     // TO DO : Throw Exceptions


Vector::Vector(unsigned int size) : _size(size) {
    _capacity = _size < VECTOR_MIN_CAPACITY ? VECTOR_MIN_CAPACITY : _size;
    _elements = new double[_capacity];

    for (int i = 0; i < _size; i++)
        _elements[i] = 0;
}

Vector::Vector(const Vector &vector) : _size(vector._size) {
    _elements = new double[vector._capacity];

    for (int i = 0; i < _size; i++)
        _elements[i] = vector._elements[i];
}

Vector::~Vector() {
    delete[] _elements;
}

Vector &Vector::operator=(const Vector &vector) {
    if (_elements == NULL)
        _elements = new double[vector._capacity];

    for (int i = 0; i < vector._size; i++)
        _elements[i] = vector._elements[i];

    return *this;
}

void Vector::scan_vector(const char *string) {

}

unsigned Vector::size() const {
    return _size;
}

double &Vector::operator()(unsigned int i) {
    static double dummy = 0.0;
    if (_elements == NULL)
        return dummy;

    return (i >= 1 && i <= _size)
        ? _elements[i - 1]
        : dummy;
}

double Vector::elem(unsigned int i) const {
    static double dummy = 0.0;
    if (_elements == NULL)
        return dummy;

    return (i >= 1 && i <= _size)
        ? _elements[i - 1]
        : dummy;
}

std::ostream &operator<<(std::ostream &os, const Vector &vector) {
    os << "(";
    for (int i = 0; i < vector._size - 1; i++)
        os << vector._elements[i] << ", ";
    os << vector._elements[vector._size - 1] << ")";
    os << std::endl;

    return os;
}

void Vector::insert_last(double new_value) {
	// Μεγαλώνουμε τον πίνακα, ώστε να χωράει τουλάχιστον size στοιχεία
	if (_capacity == _size) {
		_capacity *= 2;
		_elements = (double*)realloc(_elements, _capacity * sizeof(double));
	}

	_elements[_size] = new_value;
	_size++;
}

void Vector::remove_last() {
	_size--;

	// Μικραίνουμε τον πίνακα αν χρειαστεί, ώστε να μην υπάρχει υπερβολική σπατάλη χώρου.
	if (_capacity > _size * 4 && _capacity > 2 * VECTOR_MIN_CAPACITY) {
		_capacity /= 2;
		_elements = (double*)realloc(_elements, _capacity * sizeof(double));
	}
}