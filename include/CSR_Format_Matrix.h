#pragma once    // TO DO: Throw Exceptions

#include <iostream>

#include "Matrix.h"
#include "Vector.h"


class CSR_Format_Matrix {
private:
    const size_t _rows;
    const size_t _cols;
    Vector _non_zero_values;
    Vector _col_indices;
    Vector _row_indices;
public:
        CSR_Format_Matrix(const Matrix &matrix);
        CSR_Format_Matrix(const Vector &non_zero_values, const Vector &col_indices, const Vector &row_indices, size_t cols);
        CSR_Format_Matrix(const CSR_Format_Matrix &csr_format_matrix);
    CSR_Format_Matrix &operator=(const Matrix & matrix);
    CSR_Format_Matrix &operator=(const CSR_Format_Matrix &csr_format_matrix);

    size_t rows() const;
    size_t cols() const;

    Vector non_zero_values() const;
    Vector col_indices() const;
    Vector row_indices() const;

    void set_value(size_t row, size_t col, double value);
    double elem(size_t row, size_t col) const;

    friend std::ostream &operator<<(std::ostream &os, const CSR_Format_Matrix &csr_format_matrix);
};
