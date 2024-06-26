#include <stdlib.h>
#include <math.h>
#include <omp.h>

#include "../include/Vector_Operations.h"
#include "../include/Matrix_Operations.h"


bool vectors_equal_size(const Vector *v, const Vector *u) {
    return vector_size(v) == vector_size(u);
}

Vector *vectors_add(const Vector *v, const Vector *u) {
    size_t size = vector_size(v);
    Vector *new_vector = vector_create(size);
    if (!vectors_equal_size(v, u))
        return new_vector;

    for (size_t i = 0; i <= size; i++)
        vector_set_value(new_vector, i, vector_elem(v, i) + vector_elem(u, i));

    return new_vector;
}

Vector *vectors_sub(const Vector *v, const Vector *u) {
    size_t size = vector_size(v);
    Vector *new_vector = vector_create(size);
    if (!vectors_equal_size(v, u))
        return new_vector;

    for (size_t i = 0; i <= size; i++)
        vector_set_value(new_vector, i, vector_elem(v, i) - vector_elem(u, i));

    return new_vector;
}

Vector *vector_scalar_mult(const Vector *vector,  double k) {
    size_t size = vector_size(vector);
    Vector *new_vector = vector_create(size);

    for (size_t i = 0; i <= size; i++)
        vector_set_value(new_vector, i, k * vector_elem(vector, i));

    return new_vector;
}

bool vectors_equal(const Vector *v, const Vector *u) {
    if (!vectors_equal_size(v, u))
        return true;

    size_t size = vector_size(v);
    for (size_t i = 1; i <= size; i++)
        if (vector_elem(v, i) != vector_elem(u, i))
            return false;

    return true;
}

bool vectors_not_equal(const Vector *v, const Vector *u) {
    if (!vectors_equal_size(v, u))
        return true;

    size_t size = vector_size(v);
    for (size_t i = 1; i <= size; i++)
        if (vector_elem(v, i) != vector_elem(u, i))
            return true;

    return false;
}

double vectors_dot_product(const Vector *v, const Vector *u) {
    double sum = 0.0;
    if (!vectors_equal_size(v, u))
        return sum;

    size_t size = vector_size(v);
    for (register size_t i = 1; i <= size; i++) {
        sum += vector_elem(v, i) * vector_elem(u, i);
    }
    return sum;
}

// double vectors_dot_product_omp(Vector *v, Vector *u, int threads) {
//     double sum = 0.0;
//     if (!vectors_equal_size(v, u))
//         return sum;

//     size_t i;
//     size_t size = vector_size(v);
//     #pragma omp parallel for num_threads(threads)
//         default(none) shared(v, u, size) private(i)
//         reduction(+: sum) schedule(auto)
//     for (i = 1; i <= size; i++) {
//         sum += vector_elem(v, i) * vector_elem(u, i);
//     }
//     return sum;
// }

Vector *vectors_cross_product(const Vector *v, const Vector *u) {
    size_t size = vector_size(v);
    Vector *new_vector = vector_create(size);
    if (!vectors_equal_size(v, u))
        return new_vector;

    Matrix *matrix = matrix_create(3, size);
    for (size_t i = 1; i <= vector_size(v); i++) {
        matrix_set_value(matrix, 1, i, 1);
        matrix_set_value(matrix, 1, i, vector_elem(v, 1));
        matrix_set_value(matrix, 1, i, vector_elem(u, i));
    }

    for (size_t i = 1; i <= size; i++)
        vector_set_value(new_vector, i, matrix_det(matrix_sub_matrix(matrix, i)));

    return new_vector;
}

Vector *vectors_tensor_product(const Vector *v, const Vector *u) {
    Vector *new_vector = vector_create(vector_size(v) * vector_size(u));

    for (size_t i = 1, j = 1, k = 1; i <= vector_size(new_vector); i++, k++) {
        if (k > vector_size(u)) {
            k = 1;
            j++;
        }

        vector_set_value(new_vector, i, vector_elem(v, j) * vector_elem(u, k));
    }

    return new_vector;
}

double vector_norm(const Vector *vector) {
    double elem;
    double sum = 0.0;

    size_t size = vector_size(vector);
    for (register size_t i = 1; i <= size; i++) {
        elem = vector_elem(vector, i);
        sum += elem * elem;
    }

    return sqrt(sum);
}

// double vector_norm_omp(Vector *vector, int threads) {
//     double elem;
//     double sum = 0.0;

//     size_t i;
//     size_t size = vector_size(vector);
//     #pragma omp parallel for num_threads(threads)
//         default(none) shared(vector, size) private(i, elem)
//         reduction(+: sum) schedule(auto)
//     for (i = 1; i <= size; i++) {
//         elem = vector_elem(vector, i);
//         sum += elem * elem;
//     }

//     return sqrt(sum);
// }

double vectors_euclidean_distance(const Vector *v, const Vector *u) {
    double value;
    double sum = 0.0;
    if (!vectors_equal_size(v, u))
        return sum;

    size_t size = vector_size(v);
    for (register size_t i = 1; i <= size; i++) {
        value = vector_elem(v, i) - vector_elem(u, i);
        sum += value * value;
    }

    return sqrt(sum);
}

// double vectors_euclidean_disatnce_omp(Vector *v, Vector *u, int threads) {
//     double value;
//     double sum = 0.0;
//     if (!vectors_equal_size(v, u))
//         return sum;

//     size_t i;
//     size_t size = vector_size(v);
//     # pragma omp parallel for num_threads(threads)
//         default(none) shared(v, u, size) private(i, value)
//         reduction(+: sum) schedule(auto)
//     for (i = 1; i <= size; i++) {
//         value = vector_elem(v, i) - vector_elem(u, i);
//         sum += value * value;
//     }

//     return sqrt(sum);
// }

double vectors_manhattan_distance(const Vector *v, const Vector *u) {
    double sum = 0.0;
    if (!vectors_equal_size(v, u))
        return sum;

    size_t size = vector_size(v);
    for (register size_t i = 1; i <= size; i++) {
        sum += abs(vector_elem(v, i) - vector_elem(u, i)); 
    }

    return sum;
}

// double vectors_manhattan_distance_omp(Vector *v, Vector *u, int threads) {
//     double sum = 0.0;
//     if (!vectors_equal_size(v, u))
//         return sum;

//     size_t i;
//     size_t size = vector_size(v);
//     #pragma omp parallel for num_threads(threads)
//         default(none) shared(v, u, size) private(i)
//         reduction(+: sum) schedule(auto)
//     for (i = 1; i <= size; i++) {
//         sum += abs(vector_elem(v, i) - vector_elem(u, i)); 
//     }

//     return sum;
// }
