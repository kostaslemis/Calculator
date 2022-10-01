#pragma once    // TO DO : Throw Exceptions

#include <iostream>
#include <cmath>

// Το αρχικό μέγεθος που δεσμεύουμε
#define VECTOR_MIN_CAPACITY 10


class Vector {
    private:
        unsigned int _size;
        unsigned int _capacity;
        double* _elements;
    public:
            Vector(unsigned int size);
            Vector(const Vector &vector);
           ~Vector();
        Vector &operator= (const Vector &vector);
        void scan_vector(const char *string);

        unsigned int size() const;

        double &operator()(unsigned int i);
        double elem(unsigned int i) const;

        friend std::ostream &operator<<(std::ostream &os, const Vector &vector);

        void insert_last(double new_value);
        void remove_last();
};
