#include <cmath>    // TO DO : Throw Exceptions

#include "Vector_Operations.h"
#include "Matrix_Operations.h"


bool equal_size(const Vector &v, const Vector &u) {
    return v.size() == u.size();
}

Vector operator+(const Vector &v, const Vector &u) {
    Vector new_vector(v.size());
    if (!equal_size(v, u))
        return new_vector;

    for (size_t i = 1; i <= v.size(); i++)
        new_vector(i) = v.elem(i) + u.elem(i);

    return new_vector;
}

Vector operator-(const Vector &v, const Vector &u) {
    Vector new_vector(v.size());
    if (!equal_size(v, u))
        return new_vector;

    for (size_t i = 1; i <= v.size(); i++)
        new_vector(i) = v.elem(i) - u.elem(i);

    return new_vector;
}

Vector operator*(double k, const Vector &v) {
    Vector new_vector(v.size());

    for (size_t i = 1; i <= v.size(); i++)
        new_vector(i) = k * v.elem(i);

    return new_vector;
}

bool operator==(const Vector &v, const Vector &u) {
    if (!equal_size(v, u))
        return false;

    for (size_t i = 1; i <= v.size(); i++)
        if (v.elem(i) != u.elem(i))
            return false;

    return true;
}

bool operator==(const Vector &vector, const char *string) {
    Vector new_vector(vector.size());
    new_vector.scan_vector(string);
    return vector == new_vector;
}

bool operator!=(const Vector &v, const Vector &u) {
    if (!equal_size(v, u))
        return true;

    for (size_t i = 1; i <= v.size(); i++)
        if (v.elem(i) != u.elem(i))
            return true;

    return false;
}

bool operator!=(const Vector &vector, const char *string) {
    Vector new_vector(vector.size());
    new_vector.scan_vector(string);
    return vector != new_vector;
}

double dot_product(const Vector &v, const Vector &u) {
    double sum = 0.0;
    if (!equal_size(v, u))
        return sum;

    for (size_t i = 1; i <= v.size(); i++)
        sum += v.elem(i) * u.elem(i);

    return sum;
}

Vector cross_product(const Vector &u, const Vector &v) {
    Vector new_vector(u.size());
    if (!equal_size(u, v))
        return new_vector;

    Matrix matrix(3, u.size());
    for (size_t i = 1; i <= u.size(); i++) {
        matrix(1, i) = 1;
        matrix(2, i) = u.elem(i);
        matrix(3, i) = v.elem(i);
    }

    for (size_t i = 1; i <= u.size(); i ++)
        new_vector(i) = det(sub_matrix(matrix, i));

    return new_vector;
}

Vector tensor_product(const Vector &v, const Vector &u) {
    Vector new_vector(v.size() * u.size());

    for (size_t i = 1, j = 1, k = 1; i <= new_vector.size(); i++, k++) {
        if (k > u.size()) {
            k = 1;
            j++;
        }

        new_vector(i) = v.elem(j) * u.elem(k);
    }

    return new_vector;
}

double vector_length(const Vector &vector) {
    double sum = 0.0;

    for (size_t i = 1; i <= vector.size(); i++)
        sum += vector.elem(i) * vector.elem(i);

    return sqrt(sum);
}
