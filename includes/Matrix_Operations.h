#pragma once

#include "Matrix.h"
#include "Polynomial.h"
#include "Vector.h"


bool equal_dimensions(const Matrix &A, const Matrix &B);

bool square_matrix(const Matrix &matrix);

bool diagonal_matrix(const Matrix &matrix);

Matrix operator+(const Matrix &A, const Matrix &B);

Matrix operator-(const Matrix &A, const Matrix &B);

Matrix operator*(const Matrix &A, const Matrix &B);

Matrix operator*(double k, const Matrix &matrix);

bool operator==(const Matrix &A, const Matrix &B);

bool operator!=(const Matrix &A, const Matrix &B);

double trace(const Matrix &matrix);

Matrix sub_matrix(const Matrix &matrix, unsigned int col);

double det(const Matrix &matrix);

Matrix identity_matrix(unsigned int n);

Matrix pow(const Matrix &matrix, unsigned int exponent);

Matrix transpose(const Matrix &matrix);

Matrix minor(const Matrix &matrix, unsigned int row, unsigned int col);

Matrix cofactor(const Matrix &matrix);

Matrix adj(const Matrix &matrix);

Matrix inverse(const Matrix &matrix);

// Faddeev–LeVerrier Algorithm - https://en.wikipedia.org/wiki/Faddeev%E2%80%93LeVerrier_algorithm
Polynomial characteristic_polynomial(const Matrix &matrix);

Vector get_row(const Matrix &matrix, unsigned int row);

Vector get_col(const Matrix &matrix, unsigned int col);

// e^(At) = Sum of (t^n/n!)A^n , n from -inf to inf
Matrix exp(const Matrix &matrix, double t);

// Matrix echelon_form(const Matrix& matrix) {

// Matrix reduced_echelon_form(const Matrix& matrix);

// int matrix_rank(const Matrix matrix);
