#pragma once    // TO DO : Throw Exceptions

#include <iostream>
#include <cmath>

// Το αρχικό μέγεθος που δεσμεύουμε
#define VECTOR_MIN_CAPACITY 10


class Vector {
    private:
        int _size;
        int _capacity;
        double* _elements;
    public:
            Vector(const int size);
            Vector(const Vector& vector);
           ~Vector();
        Vector& operator = (const Vector& vector);
        void scan_vector(const std::string& string);

        int size() const;

        double& operator () (const int i);
        double elem(const int i) const;

        friend std::ostream& operator << (std::ostream& os, const Vector& vector);

        void insert_last(const double new_value);
        void remove_last();
};
