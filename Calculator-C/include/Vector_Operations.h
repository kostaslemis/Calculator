#pragma once

#include <math.h>

#include "Vector.h"
#include "Matrix_Operations.h"


bool vectors_equal_size(Vector u, Vector v);

Vector vectors_add(Vector u, Vector v);

Vector vectors_sub(Vector u, Vector v);

Vector vector_scalar_mult(Vector u,  double k);

bool vectors_equal(Vector u, Vector v);

bool vectors_not_equal(Vector u, Vector v);

double vectors_dot_product(Vector u, Vector v);

double vectors_dot_product_omp(Vector v, Vector u);

Vector vectors_cross_product(Vector u, Vector v);

Vector vectors_tensor_product(Vector u, Vector v);

double vector_length(Vector vector);

double vector_length_omp(Vector vector, int threads);
