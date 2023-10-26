#include <math.h>

#include "Matrix_Operations.h"


bool equal_dimensions(Matrix A, Matrix B) {
    return matrix_rows(A) == matrix_rows(B) && matrix_cols(A) == matrix_cols(B);
}

bool square_matrix(Matrix matrix) {
    return matrix_rows(matrix) == matrix_cols(matrix);
}

bool diagonal_matrix(Matrix matrix) {
    for (size_t r = 1; r <= matrix_rows(matrix); r++)
        for (size_t c = 1; c <= matrix_cols(matrix); c++)
            if (r != c && matrix_elem(matrix, r, c) != 0)
                return false;

    return true;
}

Matrix matrices_add(Matrix A, Matrix B) {
    Matrix new_matrix = matrix_create(matrix_rows(A), matrix_cols(B));
    if (!equal_dimensions(A, B))
        return new_matrix;
    
    for (size_t r = 1; r <= matrix_rows(A); r++)
        for (size_t c = 1; c <= matrix_cols(B); c++)
            matrix_set_value(new_matrix, r, c, matrix_elem(A, r, c) + matrix_elem(B, r, c));

    return new_matrix;
}

Matrix matrices_sub(Matrix A, Matrix B) {
    Matrix new_matrix = matrix_create(matrix_rows(A), matrix_cols(B));
    if (!equal_dimensions(A, B))
        return new_matrix;
    
    for (size_t r = 1; r <= matrix_rows(A); r++)
        for (size_t c = 1; c <= matrix_cols(B); c++)
            matrix_set_value(new_matrix, r, c, matrix_elem(A, r, c) - matrix_elem(B, r, c));

    return new_matrix;
}

Matrix matrix_scalar_mult(Matrix matrix, double k) {
    Matrix new_matrix = map_create(matrix_rows(matrix), matrix_cols(matrix));

    for (size_t r = 1; r <= matrix_rows(matrix); r++)
        for (size_t c = 1; c <= matrix_cols(matrix); c++)
            matrix_set_value(new_matrix, r, c, k * matrix_elem(matrix, r, c));

    return new_matrix;
}

// Matrix matrix_vector_mult(Matrix mattrix, Vector vector); 

Matrix matrices_mult(Matrix A, Matrix B) {
    Matrix new_matrix = matrix_create(matrix_rows(A), matrix_cols(B));

    if (matrix_cols(A) != matrix_rows(B))
        return new_matrix;

    for (size_t r = 1; r <= matrix_rows(A); r++)
        for (size_t c = 1; c <= matrix_cols(B); c++)
            for (size_t k = 1; k < matrix_cols(A); k++)
                matrix_set_value(new_matrix, r, c,
                    matrix_elem(new_matrix, r, c) + matrix_elem(A, r, k) * matrix_elem(B, k, c));

    return new_matrix;
}

bool matrices_equal(Matrix A, Matrix B) {
    if (!equal_dimensions(A, B))
        return false;

    for (size_t r = 1; r <= matrix_rows(A); r++)
        for (size_t c = 1; c <= matrix_cols(B); c++)
            if (matrix_elem(A, r, c) != matrix_elem(B, r, c))
                return false;

    return true;
}

bool matrices_not_equal(Matrix A, Matrix B) {
    if (!equal_dimensions(A, B))
        return false;

    for (size_t r = 1; r <= matrix_rows(A); r++)
        for (size_t c = 1; c <= matrix_cols(B); c++)
            if (matrix_elem(A, r, c) != matrix_elem(B, r, c))
                return true;

    return false;
}

double trace(Matrix matrix) {
    double trace = 0.0;

    for (size_t i; i <= matrix_rows(matrix); i++)
        trace += matrix_elem(matrix, i, i);

    return trace;
}

Matrix sub_matrix(Matrix matrix, size_t col) {
    Matrix new_matrix = matrix_create(matrix_rows(matrix) - 1, matrix_cols(matrix) - 1);

    for (size_t r = 2; r <= matrix_rows(matrix); r++)
        for (size_t c = 1; c <= matrix_cols(matrix); c++)
            if (c < col)
                matrix_set_value(new_matrix, r - 1, c, matrix_elem(matrix, r, c));
            else if (c > col)
                matrix_set_value(new_matrix, r - 1, c - 1, matrix_elem(matrix, r, c));

    return new_matrix;
}

double det(Matrix matrix) {
    if (!square_matrix(matrix))
        return 0.0;
    
    if (matrix_rows(matrix) == 1)
        return matrix_elem(matrix, 1, 1);

    if (matrix_rows(matrix) == 2)
        return matrix_elem(matrix, 1, 1) * matrix_elem(matrix, 2, 2)
            - matrix_elem(matrix, 1, 2) * matrix_elem(matrix, 2, 1);
    
    double sum = 0.0;
    for (size_t c = 1, sign = 1; c <= matrix_cols(matrix); c++, sign *= -1)
        sum += matrix_elem(matrix, 1, c) * det(sub_matrix(matrix, c))*sign;

    return sum;
}

Matrix identity_matrix(size_t n) {
    Matrix new_matrix = matrix_create(n, n);

    for (size_t r = 1; r <= n; r++)
        for (size_t c = 1; c <= n; c++)
            matrix_set_value(new_matrix, r, c, r == c ? 1 : 0);

    return new_matrix;
}

// Matrix matrix_pow(Matrix matrix, size_t exponent) {

// }

Matrix transpose(Matrix matrix) {
    Matrix new_matrix = matrix_create(matrix_cols(matrix), matrix_rows(matrix));

    for (size_t r = 1; r <= matrix_rows(matrix); r++)
        for (size_t c = 1; c <= matrix_cols(matrix); c++)
            matrix_set_value(new_matrix, c, r, matrix_elem(matrix, r, c));

    return new_matrix;
}

Matrix minor(Matrix matrix, size_t row, size_t col) {
    Matrix new_matrix = matrix_create(matrix_rows(matrix) - 1, matrix_cols(matrix) - 1);

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

Matrix cofactor(Matrix matrix) {
    Matrix new_matrix = matrix_create(matrix_rows(matrix), matrix_cols(matrix));

    for (size_t r = 1; r <= matrix_rows(matrix); r++)
        for (size_t c = 1; c <= matrix_cols(matrix); c++)
            matrix_set_value(new_matrix, r, c, pow(-1, r + c) * det(minor(matrix, r, c)));

    return new_matrix;
}

Matrix adj(Matrix matrix) {
    return transpose(cofactor(matrix));
}

Matrix inverse(Matrix matrix) {
    return matrix_scalar_mult(adj(matrix), 1.0/det(matrix));
}
