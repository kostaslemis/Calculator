#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../include/Matrix.h"

struct matrix {
    size_t rows;
    size_t cols;
    double **elements;
};


Matrix matrix_create(size_t rows, size_t cols) {
    Matrix matrix = malloc(sizeof(*matrix));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->elements = malloc(matrix->rows * sizeof(double*));
    for (size_t r = 0; r < matrix->rows; r++)
        matrix->elements[r] = malloc(matrix->cols * sizeof(double));

    for (size_t r = 0; r < matrix->rows; r++)
        for (size_t c = 0; c < matrix->cols; c++)
            matrix->elements[r][c] = 0.0;
    
    return matrix;
}

Matrix matrix_create_random(size_t rows, size_t cols, int MAX_VALUE) {
    Matrix matrix = malloc(sizeof(*matrix));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->elements = malloc(matrix->rows * sizeof(double*));
    for (size_t r = 0; r < matrix->rows; r++)
        matrix->elements[r] = malloc(matrix->cols * sizeof(double));

    srand(time(NULL));
    for (size_t r = 0; r < matrix->rows; r++)
        for (size_t c = 0; c < matrix->cols; c++)
            matrix->elements[r][c] = (double)(rand() % MAX_VALUE);

    return matrix;
}

void matrix_destroy(Matrix matrix) {
    for (size_t r = 0; r < matrix->rows; r++)
        free(matrix->elements[r]);
    free(matrix->elements);
    free(matrix);
}

Matrix matrix_copy(Matrix matrix) {
    Matrix new_matrix = malloc(sizeof(*new_matrix));
    new_matrix->rows = matrix->rows;
    new_matrix->cols = matrix->cols;
    new_matrix->elements = malloc(new_matrix->rows * sizeof(double*));
    for (size_t r = 0; r < new_matrix->rows; r++)
        new_matrix->elements[r] = malloc(new_matrix->cols * sizeof(double));

    for (size_t r = 0; r < new_matrix->rows; r++)
        for (size_t c = 0; c < new_matrix->cols; c++)
            new_matrix->elements[r][c] = matrix->elements[r][c];

    return new_matrix;
}

size_t matrix_rows(Matrix matrix) {
    return matrix->rows;
}

size_t matrix_cols(Matrix matrix) {
    return matrix->cols;
}

double matrix_elem(Matrix matrix, size_t row, size_t col) {
    const double dummy = 0.0;
    if (matrix->elements == NULL)
        return dummy;

    return (row >= 1 && row <= matrix->rows && col >= 1 && col <= matrix->cols)
        ? matrix->elements[row - 1][col - 1]
        : dummy;
}

void matrix_set_value(Matrix matrix, size_t row, size_t col, double value) {
    if (matrix->elements == NULL)
        return;

    if (row >= 1 && row <= matrix->rows && col >= 1 && col <= matrix->cols)
        matrix->elements[row - 1][col - 1] = value;
}

void matrix_print(Matrix matrix) {
    for (size_t r = 0; r < matrix->rows; r++) {
        for (size_t c = 0; c < matrix->cols; c++)
            fprintf(stdout, "%f ", matrix->elements[r][c]);
        fprintf(stdout, "\n");
    }
}

// row_a <-> row_b : swap row_a with row_b
void matrix_swap(Matrix matrix, size_t row_a, size_t row_b) {
    // Check row_a and row_b

    // temp_row <= row_a
    double *temp_row = malloc(matrix_cols(matrix) * sizeof(double));
    for (size_t c = 0; c < matrix_cols(matrix); c++)
        temp_row[c] = matrix->elements[row_a - 1][c];

    // row_a <= row_b
    for (size_t c = 0; c < matrix_cols(matrix); c++)
        matrix->elements[row_a - 1][c] = matrix->elements[row_b - 1][c];

    // row_b <= temp_row
    for (size_t c = 0; c < matrix_cols(matrix); c++)
        matrix->elements[row_b - 1][c] = temp_row[c];

    free(temp_row);
}

// k * row : multiiply with k
void matrix_scalar(Matrix matrix, double k, size_t row) {
    // Check row and k != 0

    for (size_t c = 0; c < matrix_cols(matrix); c++)
        matrix->elements[row - 1][c] = k * matrix->elements[row - 1][c];
}

// row_b <= k * row_a + row_b : replace row_b by the sum of itself and a multiple of row_a
void matrix_pivot(Matrix matrix, double k, size_t row_a, size_t row_b) {
    // Check row_a, row_b and k != 0

    for (size_t c = 0; c < matrix_cols(matrix); c++)
        matrix->elements[row_b - 1][c] =
            k * matrix->elements[row_a - 1][c] + matrix->elements[row_b - 1][c];
}
