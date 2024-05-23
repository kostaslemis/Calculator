#pragma once

typedef struct vector Vector;

#define VECTOR_MIN_CAPACITY 10


Vector *vector_create(size_t size);

Vector *vector_create_random(size_t size, int MAX_VALUE);

void vector_destroy(Vector *vector);

Vector *vector_copy(const Vector *vector);

size_t vector_size(const Vector *vector);

double vector_elem(const Vector *vector, size_t i);

void vector_set_value(Vector *vector, size_t i, double value);

void vector_print(const Vector *vector);

void vector_insert_last(Vector *vector, double new_value);

void vector_remove_last(Vector *vector);
