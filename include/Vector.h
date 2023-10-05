#pragma once    // TO DO : Throw Exceptions

#include <iostream>
#include <cmath>

#define VECTOR_MIN_CAPACITY 10


class Vector {
    private:
        size_t _size;
        size_t _capacity;
        double *_elements;
    public:
            Vector(size_t size);
            Vector(const Vector &vector);
           ~Vector();
        Vector &operator=(const Vector &vector);
        void scan_vector(const char *string);

        size_t size() const;

        double &operator()(size_t i);
        double elem(size_t i) const;

        friend std::ostream &operator<<(std::ostream &os, const Vector &vector);

        void insert_last(double new_value);
        void remove_last();
};
