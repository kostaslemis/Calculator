#include <stdio.h>

#include "Vector.h"

struct vector {
    size_t _size;
    size_t _capacity;
    double **_elements;
};


Vector vector_create(size_t size) {
    Vector vector = malloc(sizeof(vector));
    vector->_size = size;
    vector->_capacity = vector->_size < VECTOR_MIN_CAPACITY ? VECTOR_MIN_CAPACITY : vector->_size;
    vector->_elements = malloc(vector->_capacity * sizeof(double));

    for (size_t i = 0; i < vector->_size; i++)
        vector->_elements[i] = 0;
}

void vector_destroy(Vector vector) {
    free(vector->_elements);
    free(vector);
}

Vector vector_copy(Vector vector) {
    Vector new_vector = malloc(sizeof(new_vector));
    new_vector->_size = vector->_size;
    new_vector->_capacity = vector->_size < VECTOR_MIN_CAPACITY ? VECTOR_MIN_CAPACITY : vector->_size;
    new_vector->_elements = malloc(vector->_size * sizeof(double));

    Matrix new_matrix = malloc(sizeof(new_matrix));
    new_matrix->_rows = matrix->_rows;
    new_matrix->_cols = matrix->_cols;
    new_matrix->_elements = malloc(new_matrix->_rows * sizeof(double*));
    for (size_t r = 0; r < new_matrix->_rows; r++) 
        new_matrix->_elements[r] = malloc(new_matrix->_cols * sizeof(double));

    for (size_t r = 0; r < new_matrix->_rows; r++)
        for (size_t c = 0; c < new_matrix->_cols; c++)
            new_matrix->_elements[r][c] = matrix->_elements[r][c];

    return new_matrix;
}

size_t vector_size(Vector vector) {
    return vector->_size;
}

double vector_elem(Vector vector, size_t i) {

}

void vector_set_value(Vector vector, size_t i, double value) {

}

void vector_print(Vector vector) {
    printf("(");
    for (size_t i = 0; i < vector->_size - 1; i++)
        printf("%f, ", vector->_elements[i]);
    printf("%f)", vector->_elements[vector->_size - 1]);
    printf("\n");
}

void vector_insert_last(Vector vector, double value) {

}

void vector_remove_last(Vector vector) {

}