#include <cmath>        // TO DO : Throw Exceptions

#include "Matrix_Operations.h"


bool equal_dimensions(const Matrix &A, const Matrix &B) {
    return A.rows() == B.rows() && A.cols() == B.cols();
}

bool square_matrix(const Matrix &matrix) {
    return matrix.rows() == matrix.cols();
}

bool diagonal_matrix(const Matrix &matrix) {
    for (int r = 1; r <= matrix.rows(); r++)
        for (int c = 1; c <= matrix.cols(); c++)
            if (r != c && matrix.elem(r, c) != 0)
                return false;
                
    return true;
}

Matrix operator+(const Matrix &A, const Matrix &B) {
    Matrix new_matrix(A.rows(), B.cols());
    if (!equal_dimensions(A, B))
        return new_matrix;
        
    for (int r = 1; r <= A.rows(); r++)
        for (int c = 1; c <= B.cols(); c++)
            new_matrix(r, c) = A.elem(r, c) + B.elem(r, c);

    return new_matrix;
}

Matrix operator-(const Matrix &A, const Matrix &B) {
    Matrix new_matrix(A.rows(), B.cols());

    if (!equal_dimensions(A, B))
        return new_matrix;

    for (int r = 1; r <= A.rows(); r++)
        for (int c = 1; c <= B.cols(); c++)
            new_matrix(r, c) = A.elem(r, c) - B.elem(r, c);

    return new_matrix;
}

Matrix operator*(const Matrix &A, const Matrix &B) {
    Matrix new_matrix(A.rows(), B.cols());

    if (A.cols() != B.rows()) 
        return new_matrix;

    for (int r = 1; r <= A.rows(); r++)
        for (int c = 1; c <= B.cols(); c++)
            for (int k = 1; k <= A.cols(); k++)
                new_matrix(r, c) += A.elem(r, k) * B.elem(k, c);

    return new_matrix;
}

Matrix operator*(double k, const Matrix &matrix) {
    Matrix new_matrix(matrix.rows(), matrix.cols());

    for (int r = 1; r <= matrix.rows(); r++)
        for (int c = 1; c <= matrix.cols(); c++)
            new_matrix(r, c) = k * matrix.elem(r, c);
  
    return new_matrix;
}

bool operator==(const Matrix &A, const Matrix &B) {
    if (!equal_dimensions(A, B))
        return false;

    for (int r = 1; r <= A.rows(); r++)
        for (int c = 1; c <= B.cols(); c++)
            if (A.elem(r, c) != B.elem(r, c))
                return false;

    return true;
}

bool operator!=(const Matrix &A, const Matrix &B) {
    if (!equal_dimensions(A, B))
        return true;

    for (int r = 1; r <= A.rows(); r++)
        for (int c = 1; c <= B.cols(); c++)
            if (A.elem(r, c) == B.elem(r, c))
                return false;

    return true;
}

double trace(const Matrix &matrix) {
    double trace = 0.0;
    for (int i = 1; i <= matrix.rows(); i++)
        trace += matrix.elem(i, i);

    return trace;
}

Matrix sub_matrix(const Matrix &matrix, unsigned int col) {
    Matrix new_matrix(matrix.rows() - 1, matrix.cols() - 1);

    for (int r = 2; r <= matrix.rows(); r++) {
        for (int c = 1; c <= matrix.cols(); c++) {
            if (c < col) 
                new_matrix(r - 1, c) = matrix.elem(r, c);
            else if (c > col)
                new_matrix(r - 1, c - 1) = matrix.elem(r, c);
        }
    }

    return new_matrix;
}

double det(const Matrix &matrix) {
    if (!square_matrix(matrix))
        return 0.0;

    if (matrix.rows() == 1)
        return matrix.elem(1, 1);

    if (matrix.rows() == 2)
        return matrix.elem(1, 1)*matrix.elem(2, 2) - matrix.elem(1, 2)*matrix.elem(2, 1);

    double sum = 0.0;
    for (int c = 1, sign = 1; c <= matrix.cols(); c++, sign *= -1)
        sum += matrix.elem(1, c)*det(sub_matrix(matrix, c))*sign;
        
    return sum;
}

Matrix identity_matrix(unsigned int n) {
    Matrix new_matrix(n, n);

    for (int r = 1; r <= n; r++)
        for (int c = 1; c <= n; c++)
            new_matrix(r,c) = r == c ? 1 : 0;

    return new_matrix;
}

Matrix pow(const Matrix &matrix, unsigned int exponent) {
    Matrix new_matrix = identity_matrix(matrix.rows());
    if (!square_matrix(matrix))
        return new_matrix;

    if (exponent == 0)
        return new_matrix;

    for (int i = 0; i < exponent; i++) {
        Matrix result = new_matrix * matrix;
        new_matrix = result;
    }

    return new_matrix;
}

Matrix transpose(const Matrix &matrix) {
    Matrix new_matrix(matrix.cols(), matrix.rows());

    for (int r = 1; r <= matrix.rows(); r++)
        for (int c = 1; c <= matrix.cols(); c++)
            new_matrix(c, r) = matrix.elem(r, c);

    return new_matrix;
}

Matrix minor(const Matrix &matrix, const int row, const int col) {
    Matrix new_matrix(matrix.rows() - 1, matrix.cols() - 1);

    for (int r = 1; r <= matrix.rows(); r++) {
        for (int c = 1; c <= matrix.cols(); c++) {
            if (r < row && c < col)
                new_matrix(r, c) = matrix.elem(r, c);
            else if (r < row && c > col)
                new_matrix(r, c - 1) = matrix.elem(r, c);
            else if (r > row && c < col)
                new_matrix(r - 1, c) = matrix.elem(r, c);
            else if (r > row && c > col)
                new_matrix(r - 1, c - 1) = matrix.elem(r, c);
        }
    }

    return new_matrix; 
}

Matrix cofactor(const Matrix &matrix) {
    Matrix new_matrix(matrix.rows(), matrix.cols());

    for (int r = 1; r <= matrix.rows(); r++)
        for (int c = 1; c <= matrix.cols(); c++)
            new_matrix(r, c) = pow(-1, r + c)*det(minor(matrix, r, c));

    return new_matrix;
}

Matrix adj(const Matrix &matrix) {
    return transpose(cofactor(matrix));
}

Matrix inverse(const Matrix &matrix) {
    return 1.0/det(matrix)*adj(matrix);
}

Polynomial characteristic_polynomial(const Matrix &matrix) {
    int n = matrix.rows();
    Polynomial char_poly(n);

    if (!square_matrix(matrix))
        return char_poly;

    // 2 x 2 Matrix        
    if (matrix.rows() == 2) {        
        char_poly(2) = 1;
        char_poly(1) = -trace(matrix);
        char_poly(0) = det(matrix);
        return char_poly;
    }

    // n x n Matrix
    char_poly(n) = 1;
    char_poly(0) = pow(-1, n)*det(matrix);
    Vector coeffs(0);
    coeffs.insert_last(1);
    for (int m = 1; m < n; m++) {
        double Sum = 0;
        for (int k = 1; k <= m; k++)
            Sum += coeffs(k)*(trace(pow(matrix, m - k + 1)));

        double c_k = -Sum/m;
        coeffs.insert_last(c_k);
        char_poly(n-m) = c_k;
    }

    return char_poly;
}

Vector get_row(const Matrix &matrix, unsigned int row) {
    Vector vector_row(0);

    for (int c = 1; c <= matrix.cols(); c++)
        vector_row.insert_last(matrix.elem(row, c));

    return vector_row;
}

Vector get_col(const Matrix &matrix, unsigned int col) {
    Vector vector_col(0);

    for (int r = 1; r <= matrix.rows(); r++)
        vector_col.insert_last(matrix.elem(r, col));

    return vector_col;
}

unsigned int factorial(unsigned int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

// e^(At) = Sum_of (t^n/n!)A^n , n from -inf to inf
Matrix exp(const Matrix &matrix, double t) {
    Matrix exp_matrix(matrix.rows(), matrix.cols());
    
    for (int n = 0; n < 10; n++)
        exp_matrix = exp_matrix + pow(t, n)/factorial(n)*pow(matrix, n);

    return exp_matrix;
}

// Matrix echelon_form(const Matrix& matrix) {

// }

// Matrix reduced_echelon_form(const Matrix& matrix) {

// }

// int matrix_rank(const Matrix matrix) {

// }
