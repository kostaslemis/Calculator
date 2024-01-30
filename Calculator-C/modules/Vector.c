#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../include/Vector.h"

struct vector {
    size_t size;
    size_t capacity;
    double *elements;
};


Vector vector_create(size_t size) {
    Vector vector = malloc(sizeof(*vector));
    vector->size = size;
    vector->capacity = vector->size < VECTOR_MIN_CAPACITY ? VECTOR_MIN_CAPACITY : vector->size;
    vector->elements = malloc(vector->capacity * sizeof(double));

    for (size_t i = 0; i < vector->size; i++)
        vector->elements[i] = 0.0;

    return vector;
}

Vector vector_create_random(size_t size, int MAX_VALUE) {
    Vector vector = malloc(sizeof(*vector));
    vector->size = size;
    vector->capacity = vector->size < VECTOR_MIN_CAPACITY ? VECTOR_MIN_CAPACITY : vector->size;
    vector->elements = malloc(vector->capacity * sizeof(double));

    srand(time(NULL));
    for (size_t i = 0; i < vector->size; i++)
        vector->elements[i] = (double)(rand() % MAX_VALUE);

    return vector;
}

void vector_destroy(Vector vector) {
    free(vector->elements);
    free(vector);
}

Vector vector_copy(Vector vector) {
    Vector new_vector = malloc(sizeof(*new_vector));
    new_vector->size = vector->size;
    new_vector->capacity = vector->capacity;
    new_vector->elements = malloc(new_vector->capacity * sizeof(double));

    for (size_t i = 0; i < new_vector->size; i++)
        new_vector->elements[i] = vector->elements[i];

    return new_vector;
}

size_t vector_size(Vector vector) {
    return vector->size;
}

double vector_elem(Vector vector, size_t i) {
    const double dummy = 0.0;
    if (vector->elements == NULL)
        return dummy;

    return (i >= 1 && i <= vector->size)
        ? vector->elements[i - 1]
        : dummy;
}

void vector_set_value(Vector vector, size_t i, double value) {
    if (vector->elements == NULL)
        return;

    if (i >= 1 && i <= vector->size)
        vector->elements[i - 1] = value;
}

void vector_print(Vector vector) {
    fprintf(stdout, "(");
    for (size_t i = 0; i < vector->size - 1; i++)
        fprintf(stdout, "%f, ", vector->elements[i]);
    fprintf(stdout, "%f)", vector->elements[vector->size - 1]);
    fprintf(stdout, "\n");
}

void vector_insert_last(Vector vector, double new_value) {
    if (vector->capacity == vector->size) {
        vector->capacity *= 2;
        vector->elements = (double*)realloc(vector->elements, vector->capacity * sizeof(double));
    }

    vector->elements[vector->size] = new_value;
    vector->size++;
}

void vector_remove_last(Vector vector) {
    vector->size--;

    if (vector->capacity > vector->size * 4 && vector->capacity > 2 * VECTOR_MIN_CAPACITY) {
        vector->capacity /= 2;
        vector->elements = (double*)realloc(vector->elements, vector->capacity * sizeof(double));
    }
}
