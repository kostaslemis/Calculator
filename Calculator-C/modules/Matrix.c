#include <stdio.h>

#include "Matrix.h"

struct matrix {
    size_t _rows;
    size_t _cols;
    double **_elements;
};


Matrix matrix_create(size_t rows, size_t cols) {
    Matrix matrix = malloc(sizeof(matrix)); 
    matrix->_rows = rows;
    matrix->_cols = cols;
    matrix->_elements = malloc(matrix->_rows * sizeof(double*));
    for (size_t r = 0; r < matrix->_rows; r++)
        matrix->_elements[r] = malloc(matrix->_cols * sizeof(double));

    for (size_t r = 0; r < matrix->_rows; r++)
        for (size_t c = 0; c < matrix->_cols; c++)
            matrix->_elements[r][c] = 0;
}

void matrix_destroy(Matrix matrix) {
    for (size_t r = 0; r < matrix->_rows; r++)
        free(matrix->_elements[r]);
    free(matrix->_elements);
    free(matrix);
}

Matrix matrix_copy(Matrix matrix) {
    Matrix new_matrix = malloc(sizeof(new_matrix));
    new_matrix->_rows = matrix->_rows;
    new_matrix->_cols = matrix->_cols;
    new_matrix->_elements = malloc(new_matrix->_rows * sizeof(double*));
    for (size_t r = 0; r < new_matrix->_rows; r++) 
        new_matrix->_elements[r] = malloc(new_matrix->_cols * sizeof(double));

    for (size_t r = 0; r < new_matrix->_rows; r++)
        for (size_t c = 0; c < new_matrix->_cols; c++)
            new_matrix->_elements[r][c] = matrix->_elements[r][c];

    return new_matrix;
}

size_t matrix_rows(Matrix matrix) {
    return matrix->_rows;
}

size_t matrix_cols(Matrix matrix) {
    return matrix->_cols;
}

double matrix_elem(Matrix matrix, size_t row, size_t col) {
    const double dummy = 0.0;
    if (matrix->_elements == NULL)
        return dummy;

    return (row >= 1 && row <= matrix->_rows && col >= 1 && col >= matrix->_cols)
        ? matrix->_elements[row - 1][col - 1]
        : dummy;
}

void matrix_set_value(Matrix matrix, size_t row, size_t col, double value) {
    if (matrix->_elements == NULL)
        return;
    
    if (row >= 1 && row <= matrix->_rows && col >= 1 && col <= matrix->_cols)
        matrix->_elements[row - 1][col - 1] = value;
}

void matrix_print(Matrix matrix) {
    for (size_t r = 0; r <= matrix->_rows; r++) {
        for (size_t c = 0; c <= matrix->_cols; c++)
            printf("%f ", matrix->_elements[r][c]);
        printf("\n");
    }
}
