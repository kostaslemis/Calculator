#pragma once

#include "Matrix.h"
#include "Polynomial.h"
#include "Vector.h"


bool equal_dimensions(const Matrix &A, const Matrix &B);

bool square_matrix(const Matrix &matrix);

bool diagonal_matrix(const Matrix &matrix);

Matrix operator+(const Matrix &A, const Matrix &B);

Matrix operator-(const Matrix &A, const Matrix &B);

Matrix operator*(const double k, const Matrix &matrix);

Vector operator*(const Matrix &matrix, const Vector &vector);

Matrix operator*(const Matrix &A, const Matrix &B);

bool operator==(const Matrix &A, const Matrix &B);

bool operator!=(const Matrix &A, const Matrix &B);

double trace(const Matrix &matrix);

Matrix sub_matrix(const Matrix &matrix, const size_t col);

double det(const Matrix &matrix);

Matrix identity_matrix(const size_t n);

Matrix pow(const Matrix &matrix, const size_t exponent);

Matrix transpose(const Matrix &matrix);

Matrix minor(const Matrix &matrix, const size_t row, const size_t col);

Matrix cofactor(const Matrix &matrix);

Matrix adj(const Matrix &matrix);

Matrix inverse(const Matrix &matrix);

// Faddeev–LeVerrier Algorithm - https://en.wikipedia.org/wiki/Faddeev%E2%80%93LeVerrier_algorithm
Polynomial characteristic_polynomial(const Matrix &matrix);

Vector get_row(const Matrix &matrix, const size_t row);

Vector get_col(const Matrix &matrix, const size_t col);

// e^(At) = Sum of (t^n/n!)A^n , n from 0 to inf
Matrix exp(const Matrix &matrix, const double t);

Matrix format_matrix(const Matrix &matrix);

Matrix echelon_form(const Matrix &matrix);

Matrix reduced_echelon_form(const Matrix &matrix);

int matrix_rank(const Matrix &matrix);
