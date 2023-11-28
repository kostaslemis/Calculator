#pragma once

#include <stdbool.h>

#include "Matrix.h"
#include "Vector.h"


bool matrices_equal_dimensions(Matrix A, Matrix B);

bool matrix_is_square(Matrix matrix);

bool matrix_is_diagonal(Matrix matrix);

Matrix matrices_add(Matrix A, Matrix B);

Matrix matrices_sub(Matrix A, Matrix B);

Matrix matrix_scalar_mult(Matrix matrix, double k);

// Matrix matrix_vector_mult(Matrix mattrix, Vector vector);

Matrix matrices_mult(Matrix A, Matrix B);

bool matrices_equal(Matrix A, Matrix B);

bool matrices_not_equal(Matrix A, Matrix B);

double matrix_trace(Matrix matrix);

Matrix matrix_sub_matrix(Matrix matrix, size_t col);

double matrix_det(Matrix matrix);

Matrix matrix_identity(size_t n);

Matrix matrix_pow(Matrix matrix, size_t exponent);

Matrix matrix_transpose(Matrix matrix);

Matrix matrix_minor(Matrix matrix, size_t row, size_t col);

Matrix matrix_cofactor(Matrix matrix);

Matrix matrix_adjacent(Matrix matrix);

Matrix matrix_inverse(Matrix matrix);

Vector matrix_get_row(Matrix matrix, size_t row);

Vector matrix_get_col(Matrix matrix, size_t col);

Matrix matrix_gauss_elimination(Matrix matrix);
