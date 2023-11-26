#pragma once

#include <stdbool.h>

#include "Matrix.h"


bool equal_dimensions(Matrix A, Matrix B);

bool square_matrix(Matrix matrix);

bool diagonal_matrix(Matrix matrix);

Matrix matrices_add(Matrix A, Matrix B);

Matrix matrices_sub(Matrix A, Matrix B);

Matrix matrix_scalar_mult(Matrix matrix, double k);

// Matrix matrix_vector_mult(Matrix mattrix, Vector vector);

Matrix matrices_mult(Matrix A, Matrix B);

bool matrices_equal(Matrix A, Matrix B);

bool matrices_not_equal(Matrix A, Matrix B);

double trace(Matrix matrix);

Matrix sub_matrix(Matrix matrix, size_t col);

double det(Matrix matrix);

Matrix identity_matrix(size_t n);

Matrix matrix_pow(Matrix matrix, size_t exponent);

Matrix transpose(Matrix matrix);

Matrix minor(Matrix matrix, size_t row, size_t col);

Matrix cofactor(Matrix matrix);

Matrix adj(Matrix matrix);

Matrix inverse(Matrix matrix);
