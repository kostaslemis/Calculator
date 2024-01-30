#pragma once

#include <stdbool.h>

#include "Vector.h"


bool vectors_equal_size(Vector u, Vector v);

Vector vectors_add(Vector u, Vector v);

Vector vectors_sub(Vector u, Vector v);

Vector vector_scalar_mult(Vector u,  double k);

bool vectors_equal(Vector u, Vector v);

bool vectors_not_equal(Vector u, Vector v);

double vectors_dot_product(Vector u, Vector v);

double vectors_dot_product_omp(Vector v, Vector u, int threads);

Vector vectors_cross_product(Vector u, Vector v);

Vector vectors_tensor_product(Vector u, Vector v);

double vector_norm(Vector vector);

double vector_norm_omp(Vector vector, int threads);

double vectors_euclidean_distance(Vector v, Vector u);

double vectors_euclidean_disatnce_omp(Vector v, Vector u, int threads);

double vectors_manhattan_distance(Vector v, Vector u);

double vectors_manhattan_distance_omp(Vector v, Vector u, int threads);
