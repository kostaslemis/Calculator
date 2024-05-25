#pragma once

typedef struct matrix Matrix;


Matrix *matrix_create(size_t rows, size_t cols);

Matrix *matrix_create_random(size_t rows, size_t cols, int MAX_VALUE);

Matrix *matrix_create_view(double *elements, size_t rows, size_t cols);

void matrix_destroy(Matrix *matrix);

Matrix *matrix_copy(const Matrix *matrix);

size_t matrix_rows(const Matrix *matrix);

size_t matrix_cols(const Matrix *matrix);

double matrix_elem(const Matrix *matrix, size_t row, size_t col);

void matrix_set_value(Matrix *matrix, size_t row, size_t col, double value);

void matrix_print(const Matrix *matrix);

void matrix_swap(Matrix *matrix, size_t row_a, size_t row_b);

void matrix_scalar(Matrix *matrix, double k, size_t row);

void matrix_pivot(Matrix *matrix, double k, size_t row_a, size_t row_b);
