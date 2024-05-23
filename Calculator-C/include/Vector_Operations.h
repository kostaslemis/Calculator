#pragma once

#include <stdbool.h>

#include "Vector.h"


bool vectors_equal_size(const Vector *u, const Vector *v);

Vector *vectors_add(const Vector *u, const Vector *v);

Vector *vectors_sub(const Vector *u, const Vector *v);

Vector *vector_scalar_mult(const Vector *u,  double k);

bool vectors_equal(const Vector *u, const Vector *v);

bool vectors_not_equal(const Vector *u, const Vector *v);

double vectors_dot_product(const Vector *u, const Vector *v);

// double vectors_dot_product_omp(Vector *v, Vector *u, int threads);

Vector *vectors_cross_product(const Vector *u, const Vector *v);

Vector *vectors_tensor_product(const Vector *u, const Vector *v);

double vector_norm(const Vector *vector);

// double vector_norm_omp(Vector *vector, int threads);

double vectors_euclidean_distance(const Vector *v, const Vector *u);

// double vectors_euclidean_disatnce_omp(Vector *v, Vector *u, int threads);

double vectors_manhattan_distance(const Vector *v, const Vector *u);

// double vectors_manhattan_distance_omp(Vector *v, Vector *u, int threads);
