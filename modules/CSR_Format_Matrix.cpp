#include "../include/CSR_Format_Matrix.h"


CSR_Format_Matrix::CSR_Format_Matrix(const Matrix &matrix)
    : _rows(matrix.rows()), _cols(matrix.cols()),
    _non_zero_values(0), _col_indices(0), _row_indices(matrix.rows() + 1) {
    size_t nnz = 0;
    _row_indices(1) = 0.0;
    for (size_t r = 1; r <= matrix.rows(); r++) {
        for (size_t c = 1; c <= matrix.cols(); c++)
            if (matrix.elem(r, c) != 0) {
                nnz++;
                _non_zero_values.insert_last(matrix.elem(r, c));
                _col_indices.insert_last(c);
            }
        _row_indices(r + 1) = nnz;
    }
}

CSR_Format_Matrix::CSR_Format_Matrix(const Vector &non_zero_values, const Vector &col_indices, const Vector &row_indices, const size_t cols)
    : _rows(row_indices.size() - 1), _cols(cols),
    _non_zero_values(non_zero_values), _col_indices(col_indices), _row_indices(row_indices) {
}

CSR_Format_Matrix::CSR_Format_Matrix(const CSR_Format_Matrix &csr_format_matrix)
    :   _rows(csr_format_matrix.rows()), _cols(csr_format_matrix.cols()),
    _non_zero_values(csr_format_matrix.non_zero_values()),
    _col_indices(csr_format_matrix.col_indices()),
    _row_indices(csr_format_matrix.row_indices()) {
}

// CSR_Format_Matrix &CSR_Format_Matrix::operator=(const CSR_Format_Matrix &csr_format_matrix) {

// }

size_t CSR_Format_Matrix::rows() const {
    return _rows;
}

size_t CSR_Format_Matrix::cols() const {
    return _cols;
}

Vector CSR_Format_Matrix::non_zero_values() const {
    return _non_zero_values;
}

Vector CSR_Format_Matrix::col_indices() const {
    return _col_indices;
}

Vector CSR_Format_Matrix::row_indices() const {
    return _row_indices;
}

void CSR_Format_Matrix::set_value(const size_t row, const size_t col, const double value) {
    size_t row_start = _row_indices.elem(row);
    size_t row_end = _row_indices.elem(row + 1);
    for (size_t c = row_start + 1; c <= row_end; c++)
        if (_col_indices.elem(c) == col)
            _non_zero_values(c) = value;
    // If it doesn't exist
}

double CSR_Format_Matrix::elem(const size_t row, const size_t col) const {
    size_t row_start = _row_indices.elem(row);
    size_t row_end = _row_indices.elem(row + 1);
    for (size_t c = row_start + 1; c <= row_end; c++)
        if (_col_indices.elem(c) == col)
            return _non_zero_values.elem(c);
    return 0.0;
}

Matrix CSR_Format_Matrix::matrix() const {
    Matrix matrix(_rows, _cols);

    for (size_t r = 1; r <= _rows; r++) {
        size_t row_start = _row_indices.elem(r);
        size_t row_end = _row_indices.elem(r + 1);
        for (size_t c = row_start + 1; c <= row_end; c++) {
            size_t col = _col_indices.elem(c);
            matrix(r, col) = _non_zero_values.elem(c);
        }
    }

    return matrix;
}

std::ostream &operator<<(std::ostream &os, const CSR_Format_Matrix &csr_format_matrix) {
    os << csr_format_matrix._non_zero_values
       << csr_format_matrix._col_indices
       << csr_format_matrix._row_indices;

    return os;
}
