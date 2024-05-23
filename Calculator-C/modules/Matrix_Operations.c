#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "../include/Matrix_Operations.h"
#include "../include/Vector.h"


bool matrices_equal_dimensions(const Matrix *A, const Matrix *B) {
    return matrix_rows(A) == matrix_rows(B) && matrix_cols(A) == matrix_cols(B);
}

bool matrix_is_square(const Matrix *matrix) {
    return matrix_rows(matrix) == matrix_cols(matrix);
}

bool matrix_is_diagonal(const Matrix *matrix) {
    for (size_t r = 1; r <= matrix_rows(matrix); r++)
        for (size_t c = 1; c <= matrix_cols(matrix); c++)
            if (r != c && matrix_elem(matrix, r, c) != 0)
                return false;

    return true;
}

Matrix *matrices_add(const Matrix *A, const Matrix *B) {
    Matrix *new_matrix = matrix_create(matrix_rows(A), matrix_cols(B));
    if (!matrices_equal_dimensions(A, B))
        return new_matrix;

    for (size_t r = 1; r <= matrix_rows(A); r++)
        for (size_t c = 1; c <= matrix_cols(B); c++)
            matrix_set_value(new_matrix, r, c, matrix_elem(A, r, c) + matrix_elem(B, r, c));

    return new_matrix;
}

Matrix *matrices_sub(const Matrix *A, const Matrix *B) {
    Matrix *new_matrix = matrix_create(matrix_rows(A), matrix_cols(B));
    if (!matrices_equal_dimensions(A, B))
        return new_matrix;

    for (size_t r = 1; r <= matrix_rows(A); r++)
        for (size_t c = 1; c <= matrix_cols(B); c++)
            matrix_set_value(new_matrix, r, c, matrix_elem(A, r, c) - matrix_elem(B, r, c));

    return new_matrix;
}

Matrix *matrix_scalar_mult(const Matrix *matrix, double k) {
    Matrix *new_matrix = matrix_create(matrix_rows(matrix), matrix_cols(matrix));

    for (size_t r = 1; r <= matrix_rows(matrix); r++)
        for (size_t c = 1; c <= matrix_cols(matrix); c++)
            matrix_set_value(new_matrix, r, c, k * matrix_elem(matrix, r, c));

    return new_matrix;
}

// Matrix matrix_vector_mult(Matrix mattrix, Vector vector);

Matrix *matrices_mult(const Matrix *A, const Matrix *B) {
    Matrix *new_matrix = matrix_create(matrix_rows(A), matrix_cols(B));

    if (matrix_cols(A) != matrix_rows(B))
        return new_matrix;

    for (size_t r = 1; r <= matrix_rows(A); r++)
        for (size_t c = 1; c <= matrix_cols(B); c++)
            for (size_t k = 1; k < matrix_cols(A); k++)
                matrix_set_value(new_matrix, r, c,
                    matrix_elem(new_matrix, r, c) + matrix_elem(A, r, k) * matrix_elem(B, k, c));

    return new_matrix;
}

bool matrices_equal(const Matrix *A, const Matrix *B) {
    if (!matrices_equal_dimensions(A, B))
        return false;

    for (size_t r = 1; r <= matrix_rows(A); r++)
        for (size_t c = 1; c <= matrix_cols(B); c++)
            if (matrix_elem(A, r, c) != matrix_elem(B, r, c))
                return false;

    return true;
}

bool matrices_not_equal(const Matrix *A, const Matrix *B) {
    if (!matrices_equal_dimensions(A, B))
        return false;

    for (size_t r = 1; r <= matrix_rows(A); r++)
        for (size_t c = 1; c <= matrix_cols(B); c++)
            if (matrix_elem(A, r, c) != matrix_elem(B, r, c))
                return true;

    return false;
}

double matrix_trace(const Matrix *matrix) {
    double trace = 0.0;

    for (size_t i; i <= matrix_rows(matrix); i++)
        trace += matrix_elem(matrix, i, i);

    return trace;
}

Matrix *matrix_sub_matrix(const Matrix *matrix, size_t col) {
    Matrix *new_matrix = matrix_create(matrix_rows(matrix) - 1, matrix_cols(matrix) - 1);

    for (size_t r = 2; r <= matrix_rows(matrix); r++)
        for (size_t c = 1; c <= matrix_cols(matrix); c++)
            if (c < col)
                matrix_set_value(new_matrix, r - 1, c, matrix_elem(matrix, r, c));
            else if (c > col)
                matrix_set_value(new_matrix, r - 1, c - 1, matrix_elem(matrix, r, c));

    return new_matrix;
}

double matrix_det(const Matrix *matrix) {
    if (!matrix_is_square(matrix))
        return 0.0;

    if (matrix_rows(matrix) == 1)
        return matrix_elem(matrix, 1, 1);

    if (matrix_rows(matrix) == 2)
        return matrix_elem(matrix, 1, 1) * matrix_elem(matrix, 2, 2)
            - matrix_elem(matrix, 1, 2) * matrix_elem(matrix, 2, 1);

    double sum = 0.0;
    for (size_t c = 1, sign = 1; c <= matrix_cols(matrix); c++, sign *= -1)
        sum += matrix_elem(matrix, 1, c) * matrix_det(matrix_sub_matrix(matrix, c)) * sign;

    return sum;
}

Matrix *matrix_identity(size_t n) {
    Matrix *new_matrix = matrix_create(n, n);

    for (size_t r = 1; r <= n; r++)
        for (size_t c = 1; c <= n; c++)
            matrix_set_value(new_matrix, r, c, r == c ? 1 : 0);

    return new_matrix;
}

// Matrix matrix_pow(Matrix matrix, size_t exponent) {

// }

Matrix *matrix_transpose(const Matrix *matrix) {
    Matrix *new_matrix = matrix_create(matrix_cols(matrix), matrix_rows(matrix));

    for (size_t r = 1; r <= matrix_rows(matrix); r++)
        for (size_t c = 1; c <= matrix_cols(matrix); c++)
            matrix_set_value(new_matrix, c, r, matrix_elem(matrix, r, c));

    return new_matrix;
}

Matrix *matrix_minor(const Matrix *matrix, size_t row, size_t col) {
    Matrix *new_matrix = matrix_create(matrix_rows(matrix) - 1, matrix_cols(matrix) - 1);

    for (size_t r = 1; r <= matrix_rows(matrix); r++)
        for (size_t c = 1; c <= matrix_cols(matrix); c++)
            if (r < row && c < col)
                matrix_set_value(new_matrix, r, c, matrix_elem(matrix, r, c));
            else if (r < row && c > col)
                matrix_set_value(new_matrix, r, c - 1, matrix_elem(matrix, r, c));
            else if (r > row && c < col)
                matrix_set_value(new_matrix, r - 1, c, matrix_elem(matrix, r, c));
            else if (r > row && c > col)
                matrix_set_value(new_matrix, r - 1, c - 1, matrix_elem(matrix, r, c));

    return new_matrix;
}

Matrix *matrix_cofactor(const Matrix *matrix) {
    Matrix *new_matrix = matrix_create(matrix_rows(matrix), matrix_cols(matrix));

    for (size_t r = 1; r <= matrix_rows(matrix); r++)
        for (size_t c = 1; c <= matrix_cols(matrix); c++)
            matrix_set_value(new_matrix, r, c, pow(-1, r + c) * matrix_det(matrix_minor(matrix, r, c)));

    return new_matrix;
}

Matrix *matrix_adjacent(const Matrix *matrix) {
    return matrix_transpose(matrix_cofactor(matrix));
}

Matrix *matrix_inverse(const Matrix *matrix) {
    return matrix_scalar_mult(matrix_adjacent(matrix), 1.0 / matrix_det(matrix));
}

Vector *matrix_get_row(const Matrix *matrix, size_t row) {
    Vector *vector_row = vector_create(matrix_cols(matrix));

    for (size_t c = 1; c <= matrix_cols(matrix); c++)
        vector_set_value(vector_row, c, matrix_elem(matrix, row, c));

    return vector_row;
}

Vector *matrix_get_col(const Matrix *matrix, size_t col) {
    Vector *vector_col = vector_create(matrix_rows(matrix));

    for (size_t r = 1; r <= matrix_rows(matrix); r++)
        vector_set_value(vector_col, r, matrix_elem(matrix, r, col));

    return vector_col;
}

Matrix *matrix_gauss_elimination(const Matrix *matrix) {
    Matrix *new_matrix = matrix_copy(matrix);

    for (size_t c = 1; c <= matrix_cols(new_matrix); c++) {
        size_t p = c;
        for (size_t r = c; r <= matrix_rows(new_matrix); r++) {
            if ((matrix_elem(new_matrix, p, c) == 0 && matrix_elem(new_matrix, r, c) != 0) ||
                (abs(matrix_elem(new_matrix, r, c)) < abs(matrix_elem(new_matrix, p, c)) &&
                matrix_elem(new_matrix, r, c) != 0))
                p = r;
        }

        if (matrix_elem(new_matrix, p, c) == 0) {
            fprintf(stdout, "No single solution exists\n");
            return new_matrix;
        }

        if (p != c)
            matrix_swap(new_matrix, c, p);

        for (size_t r = c + 1; r <= matrix_rows(new_matrix); r++) {
            const double m = - matrix_elem(new_matrix, r, c) / matrix_elem(new_matrix, c, c);
            matrix_pivot(new_matrix, m, c, r);
        }

        if (matrix_elem(new_matrix, matrix_rows(new_matrix), matrix_cols(new_matrix)) == 0) {
            fprintf(stdout, "No single solution exists\n");
            return new_matrix;
        }
    }
    
    return new_matrix;
}
