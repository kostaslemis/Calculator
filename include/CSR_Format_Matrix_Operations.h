#pragma once

#include "CSR_Format_Matrix.h"


bool equal_dimensions(const CSR_Format_Matrix &A, const CSR_Format_Matrix &B);

CSR_Format_Matrix operator+(const CSR_Format_Matrix &A, const CSR_Format_Matrix &B);

CSR_Format_Matrix operator-(const CSR_Format_Matrix &A, const CSR_Format_Matrix &B);

CSR_Format_Matrix operator*(const double k, const CSR_Format_Matrix &csr_format_matrix);

Vector operator*(const CSR_Format_Matrix &csr_format_matrix, const Vector &vector);

CSR_Format_Matrix operator*(const CSR_Format_Matrix &A, const CSR_Format_Matrix &B);

bool operator==(const CSR_Format_Matrix &A, const CSR_Format_Matrix &B);

bool operator!=(const CSR_Format_Matrix &A, const CSR_Format_Matrix &B);

CSR_Format_Matrix transpose(const CSR_Format_Matrix &csr_format_matrix);
