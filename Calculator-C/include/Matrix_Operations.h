#pragma once

#include <stdbool.h>

#include "Matrix.h"
#include "Vector.h"


bool matrices_equal_dimensions(const Matrix *A, const Matrix *B);

bool matrix_is_square(const Matrix *matrix);

bool matrix_is_diagonal(const Matrix *matrix);

Matrix *matrices_add(const Matrix *A, const Matrix *B);

Matrix *matrices_sub(const Matrix *A, const Matrix *B);

Matrix *matrix_scalar_mult(const Matrix *matrix, double k);

Vector *matrix_vector_mult(const Matrix *mattrix, const Vector *vector);

Matrix *matrices_mult(const Matrix *A, const Matrix *B);

bool matrices_equal(const Matrix *A, const Matrix *B);

bool matrices_not_equal(const Matrix *A, const Matrix *B);

double matrix_trace(const Matrix *matrix);

Matrix *matrix_sub_matrix(const Matrix *matrix, size_t col);

double matrix_det(const Matrix *matrix);

Matrix *matrix_identity(size_t n);

Matrix *matrix_pow(const Matrix *matrix, size_t exponent);

Matrix *matrix_transpose(const Matrix *matrix);

Matrix *matrix_minor(const Matrix *matrix, size_t row, size_t col);

Matrix *matrix_cofactor(const Matrix *matrix);

Matrix *matrix_adjacent(const Matrix *matrix);

Matrix *matrix_inverse(const Matrix *matrix);

Vector *matrix_get_row(const Matrix *matrix, size_t row);

Vector *matrix_get_col(const Matrix *matrix, size_t col);

Matrix *matrix_gauss_elimination(const Matrix *matrix);
