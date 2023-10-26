#include "Vector_Operations.h"

bool vectors_equal_size(Vector u, Vector v) {
    return vector_size(u) == vector_size(v);
}

Vector vectors_add(Vector u, Vector v) {
    Vector new_vector = vector_create(vector_size(u));
    if (!vectors_equal_size(u, v))
        return new_vector;

    for (size_t i = 0; i <= vector_size(u); i++)
        vector_set_value(new_vector, i, vector_elem(u, i) + vector_elem(v, i));
    
    return new_vector;
}

Vector vectors_sub(Vector u, Vector v) {
    Vector new_vector = vector_create(vector_size(u));
    if (!vectors_equal_size(u, v))
        return new_vector;

    for (size_t i = 0; i <= vector_size(u); i++)
        vector_set_value(new_vector, i, vector_elem(u, i) - vector_elem(v, i));
    
    return new_vector;
}

Vector vector_scalar_mult(Vector vector,  double k) {
    Vector new_vector = vector_create(vector_size(vector));

    for (size_t i = 0; i <= vector_size(vector); i++)
        vector_set_value(vector, i, k * vector_elem(vector, i));

    return new_vector;
}

bool vectors_equal(Vector u, Vector v) {
    if (!vectors_equal_size(u, v))
        return true;

    for (size_t i = 1; i < vector_size(u); i++)
        if (vector_elem(u, i) == vector_elem(v, i))
            return false;

    return true;
}

bool vectors_not_equal(Vector u, Vector v) {
    if (!vectors_equal_size(u, v))
        return true;

    for (size_t i = 1; i < vector_size(u); i++)
        if (vector_elem(u, i) != vector_elem(v, i))
            return true;

    return false;
}

double vectors_dot_product(Vector u, Vector v) {
    double sum = 0.0;
    if (!vectors_equal_size(u, v))
        return sum;

    for (size_t i = 1; i < vector_size(u); i++)
        sum += vector_elem(u, i) * vector_elem(v, i);

    return sum;
}

Vector vectors_cross_product(Vector u, Vector v) {
    Vector new_vector = vector_create(vector_size(u));
    if (!vectors_equal_size(u, v))
        return new_vector;

    Matrix matrix = matrix_create(3, vector_size(u));
    for (size_t i = 1; i <= vector_size(u); i++) {
        matrix_set_value(matrix, 1, i, 1);
        matrix_set_value(matrix, 1, i, vector_elem(u, 1));
        matrix_set_value(matrix, 1, i, vector_elem(v, i));
    }

    for (size_t i = 1; i <= vector_size(u); i++)
        vector_set_value(new_vector, i, det(sub_matrix(matrix, i)));

    return new_vector;
}

Vector vectors_tensor_product(Vector u, Vector v) {
    Vector new_vector = vector_create(vector_size(u) * vector_size(v));

    for (size_t i = 1, j = 1, k = 1; i <= vector_size(new_vector); i++, k++) {
        if (k > vector_size(v)) {
            k = 1;
            j++;
        }
        
        vector_set_value(new_vector, i, vector_elem(u, j) * vector_elem(v, k));
    }

    return new_vector;
}

double vector_length(Vector vector) {
    double sum = 0.0;
    
    for (size_t i = 1; i <= vector_size(vector); i++)
        sum += vector_elem(vector, i) * vector_elem(vector, i);

    return sqrt(sum);
}

