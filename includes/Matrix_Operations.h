#pragma once

#include "Matrix.h"
#include "Polynomial.h"
#include "Vector.h"


bool equal_dimensions(const Matrix& p, const Matrix& q);

bool square_matrix(const Matrix& matrix);

bool diagonal_matrix(const Matrix& matrix);

Matrix operator + (const Matrix& p, const Matrix& q);

Matrix operator - (const Matrix& p, const Matrix& q);

Matrix operator * (const Matrix& p, const Matrix& q);

Matrix operator * (const double k, const Matrix& p);

bool operator == (const Matrix& p, const Matrix& q);

bool operator != (const Matrix& p, const Matrix& q);

double trace(const Matrix& matrix);

Matrix sub_matrix(const Matrix& matrix, const int col);

double det(const Matrix matrix);

Matrix identity_matrix(const int n);

Matrix pow(const Matrix& p, const int exponent);

Matrix transpose(const Matrix& matrix);

Matrix minor(const Matrix& matrix, const int row, const int col);

Matrix cofactor(const Matrix& matrix);

Matrix adj(const Matrix& matrix);

Matrix inverse(const Matrix& matrix);

// Faddeev–LeVerrier Algorithm - https://en.wikipedia.org/wiki/Faddeev%E2%80%93LeVerrier_algorithm
Polynomial characteristic_polynomial(const Matrix& matrix);

Vector get_row(const Matrix& matrix, const int row);

Vector get_col(const Matrix& matrix, const int col);

// Matrix echelon_form(const Matrix& matrix) {

// Matrix reduced_echelon_form(const Matrix& matrix);

// int matrix_rank(const Matrix matrix);
