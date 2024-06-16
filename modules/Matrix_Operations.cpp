#include <cmath>        // TO DO : Throw Exceptions

#include "Matrix_Operations.h"


bool equal_dimensions(const Matrix &A, const Matrix &B) {
    return A.rows() == B.rows() && A.cols() == B.cols();
}

bool square_matrix(const Matrix &matrix) {
    return matrix.rows() == matrix.cols();
}

bool diagonal_matrix(const Matrix &matrix) {
    for (size_t r = 1; r <= matrix.rows(); r++)
        for (size_t c = 1; c <= matrix.cols(); c++)
            if (r != c && matrix.elem(r, c) != 0)
                return false;

    return true;
}

Matrix operator+(const Matrix &A, const Matrix &B) {
    Matrix new_matrix(A.rows(), B.cols());
    if (!equal_dimensions(A, B))
        return new_matrix;

    for (size_t r = 1; r <= A.rows(); r++)
        for (size_t c = 1; c <= B.cols(); c++)
            new_matrix(r, c) = A.elem(r, c) + B.elem(r, c);

    return new_matrix;
}

Matrix operator-(const Matrix &A, const Matrix &B) {
    Matrix new_matrix(A.rows(), B.cols());

    if (!equal_dimensions(A, B))
        return new_matrix;

    for (size_t r = 1; r <= A.rows(); r++)
        for (size_t c = 1; c <= B.cols(); c++)
            new_matrix(r, c) = A.elem(r, c) - B.elem(r, c);

    return new_matrix;
}

Matrix operator*(const double k, const Matrix &matrix) {
    Matrix new_matrix(matrix.rows(), matrix.cols());

    for (size_t r = 1; r <= matrix.rows(); r++)
        for (size_t c = 1; c <= matrix.cols(); c++)
            new_matrix(r, c) = k * matrix.elem(r, c);

    return new_matrix;
}

Vector operator*(const Matrix &matrix, const Vector &vector) {
    Vector new_vector(matrix.rows());

    if (matrix.cols() != vector.size())
        return new_vector;

    for (size_t r = 1; r <= matrix.rows(); r++)
        for (size_t c = 1; c <= matrix.cols(); c++)
            new_vector(r) += matrix.elem(r, c) * vector.elem(c);

    return new_vector;
}

Matrix operator*(const Matrix &A, const Matrix &B) {
    Matrix new_matrix(A.rows(), B.cols());

    if (A.cols() != B.rows())
        return new_matrix;

    for (size_t r = 1; r <= A.rows(); r++)
        for (size_t c = 1; c <= B.cols(); c++)
            for (size_t k = 1; k <= A.cols(); k++)
                new_matrix(r, c) += A.elem(r, k) * B.elem(k, c);

    return new_matrix;
}

bool operator==(const Matrix &A, const Matrix &B) {
    if (!equal_dimensions(A, B))
        return false;

    for (size_t r = 1; r <= A.rows(); r++)
        for (size_t c = 1; c <= B.cols(); c++)
            if (A.elem(r, c) != B.elem(r, c))
                return false;

    return true;
}

bool operator!=(const Matrix &A, const Matrix &B) {
    if (!equal_dimensions(A, B))
        return true;

    for (size_t r = 1; r <= A.rows(); r++)
        for (size_t c = 1; c <= B.cols(); c++)
            if (A.elem(r, c) != B.elem(r, c))
                return true;

    return false;
}

double trace(const Matrix &matrix) {
    double trace = 0.0;
    for (size_t i = 1; i <= matrix.rows(); i++)
        trace += matrix.elem(i, i);

    return trace;
}

Matrix sub_matrix(const Matrix &matrix, const size_t col) {
    Matrix new_matrix(matrix.rows() - 1, matrix.cols() - 1);

    for (size_t r = 2; r <= matrix.rows(); r++) {
        for (size_t c = 1; c <= matrix.cols(); c++) {
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
    for (size_t c = 1, sign = 1; c <= matrix.cols(); c++, sign *= -1)
        sum += matrix.elem(1, c)*det(sub_matrix(matrix, c))*sign;

    return sum;
}

Matrix identity_matrix(const size_t n) {
    Matrix new_matrix(n, n);

    for (size_t r = 1; r <= n; r++)
        for (size_t c = 1; c <= n; c++)
            new_matrix(r,c) = r == c ? 1 : 0;

    return new_matrix;
}

Matrix pow(const Matrix &matrix, const size_t exponent) {
    Matrix new_matrix = identity_matrix(matrix.rows());
    if (!square_matrix(matrix))
        return new_matrix;

    if (exponent == 0)
        return new_matrix;

    for (size_t i = 0; i < exponent; i++) {
        // new_matrix *= matrix
        Matrix result = new_matrix * matrix;
        new_matrix = result;
    }

    return new_matrix;
}

Matrix transpose(const Matrix &matrix) {
    Matrix new_matrix(matrix.cols(), matrix.rows());

    for (size_t r = 1; r <= matrix.rows(); r++)
        for (size_t c = 1; c <= matrix.cols(); c++)
            new_matrix(c, r) = matrix.elem(r, c);

    return new_matrix;
}

Matrix minor(const Matrix &matrix, const size_t row, const size_t col) {
    Matrix new_matrix(matrix.rows() - 1, matrix.cols() - 1);

    for (size_t r = 1; r <= matrix.rows(); r++) {
        for (size_t c = 1; c <= matrix.cols(); c++) {
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

    for (size_t r = 1; r <= matrix.rows(); r++)
        for (size_t c = 1; c <= matrix.cols(); c++)
            // pow func too slow
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
    size_t n = matrix.rows();
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
    for (size_t m = 1; m < n; m++) {
        double Sum = 0;
        for (size_t k = 1; k <= m; k++)
            Sum += coeffs(k)*(trace(pow(matrix, m - k + 1)));

        double c_k = -Sum/m;
        coeffs.insert_last(c_k);
        char_poly(n-m) = c_k;
    }

    return char_poly;
}

Vector get_row(const Matrix &matrix, const size_t row) {
    Vector vector_row(matrix.cols());

    for (size_t c = 1; c <= matrix.cols(); c++)
        vector_row(c) = matrix.elem(row, c);

    return vector_row;
}

Vector get_col(const Matrix &matrix, const size_t col) {
    Vector vector_col(matrix.rows());

    for (size_t r = 1; r <= matrix.rows(); r++)
        vector_col(r) = matrix.elem(r, col);

    return vector_col;
}

static size_t factorial(size_t n) {
    // Not efficient - Use of for loop
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

// e^(At) = Sum_of (t^n/n!)A^n , n from 0 to inf
Matrix exp(const Matrix &matrix, const double t) {
    Matrix exp_matrix(matrix.rows(), matrix.cols());

    for (size_t n = 0; n < 10; n++)
        // factorial not efficient 
        // pow use not efficient
        // matrix_pow use not efficient - Need to rename most of the functions
        // exp_matrix += pow(t, n)/factorial(n)*pow(matrix, n);
        exp_matrix = exp_matrix + pow(t, n)/factorial(n)*pow(matrix, n);

    return exp_matrix;
}

Matrix format_matrix(const Matrix &matrix) {
    Matrix format_matrix = matrix;

    size_t format_rows = 1; 
    for (size_t c = 1; c <= format_matrix.cols(); c++) {
        size_t pivots = 0;
        for (size_t r = format_rows; r <= format_matrix.rows(); r++) {
            if (format_matrix.elem(r, c) != 0)
                pivots++;
        }

        size_t format_pivots = 0;
        for (size_t r = format_rows; r <= format_matrix.rows(); r++) {
            if (format_matrix.elem(r, c) == 0)
                break;
            format_pivots++;
        }

        if (pivots == format_pivots)
            continue;

        size_t swaps = 0;
        for (size_t r = format_rows + format_pivots; r <= format_matrix.rows(); r++) {
            if (format_matrix.elem(r, c) != 0) {
                format_matrix.swap(r, format_rows + format_pivots + swaps);
                swaps++;
            }
        }

        format_rows += pivots;
    }

    return format_matrix;
}

Matrix echelon_form(const Matrix &matrix) {
    Matrix echelon_matrix = format_matrix(matrix);

    for (size_t c = 1; c <= echelon_matrix.cols(); c++) {
        size_t pivots = 0;
        for (size_t r = c; r <= echelon_matrix.rows(); r++) {
            if (echelon_matrix.elem(r, c) == 0)
                break;
            pivots++;
        }

        if (pivots > 1)
            continue;

        for (size_t r = c + 1; r <= c + pivots; r++) {
            double k = -1*echelon_matrix(r, c)/echelon_matrix(c + 1, c);
            echelon_matrix.pivot(k, c + 1, r);
        }

        // format next col
        size_t format_pivots = 0;
        for (size_t r = c + 1; r <= echelon_matrix.rows(); r++) {
            if (echelon_matrix.elem(r, c) == 0)
                break;
            format_pivots++;
        }

        if (pivots == format_pivots)
            continue;

        size_t swaps = 0;
        for (size_t r = c + format_pivots + 1; r <= echelon_matrix.rows(); r++) {
            if (echelon_matrix.elem(r, c) != 0) {
                echelon_matrix.swap(r, c + format_pivots + swaps + 1);
                swaps++;
            }
        }
    }

    return echelon_matrix;
}

Matrix reduced_echelon_form(const Matrix &matrix) {
    Matrix reduced_echelon_matrix = echelon_form(matrix);

    return reduced_echelon_matrix;
}

Matrix gaussian_elimination(const Matrix &matrix) {
    Matrix new_matrix = matrix;

    for (size_t c = 1; c <= new_matrix.cols(); c++) {
        size_t p = c;
        for (size_t r = c; r <= new_matrix.rows(); r++) {
            if ((new_matrix.elem(p, c) == 0 && new_matrix.elem(r, c) != 0) ||
                (abs(new_matrix.elem(r, c)) < abs(new_matrix.elem(p, c)) && new_matrix.elem(r, c) != 0))
                p = r;
        }

        if (new_matrix.elem(p, c) == 0) {
            std::cout << "No signle solution exists" << std::endl;
            return new_matrix;
        }

        if (p != c)
            new_matrix.swap(c, p);

        for (size_t r = c + 1; r <= matrix.rows(); r++) {
            const double m = - new_matrix.elem(c, r) / new_matrix.elem(c, c);
            new_matrix.pivot(m, c, r);
        }

        if (new_matrix.elem(new_matrix.rows(), new_matrix.cols()) == 0) {
            std::cout << "No signle solution exists" << std::endl;
            return new_matrix;
        }
    }

    return new_matrix;
}

int matrix_rank(const Matrix &matrix) {
    Matrix echelon_matrix = echelon_form(matrix);

    int rank = 0;
    for (size_t r = 1; r <= echelon_matrix.rows(); r++) {
        for (size_t c = 1; c <= echelon_matrix.cols(); c++) {
            if (echelon_matrix.elem(r, c) != 0)
                continue;
        }
        rank++;
    }

    return rank;
}
