#pragma once

#include <stdlib.h>

typedef struct matrix *Matrix;


Matrix matrix_create(size_t rows, size_t cols);

void matrix_destroy(Matrix matrix);

Matrix matrix_copy(Matrix matrix);

size_t matrix_rows(Matrix matrix);

size_t matrix_cols(Matrix matrix);

double matrix_elem(Matrix matrix, size_t row, size_t col);

void matrix_set_value(Matrix matrix, size_t row, size_t col, double value);

void matrix_print(Matrix matrix);

void matrix_swap(Matrix matrix, size_t row_a, size_t row_b);

void matrix_scalar(Matrix matrix, double k, size_t row);

void matrix_pivot(Matrix matrix, double k, size_t row_a, size_t row_b);
