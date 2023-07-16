#pragma once

#include <iostream>


class Matrix {
    private:
        const size_t _rows;
        const size_t _cols;
        double **_elements;
    public:
            Matrix(size_t rows, size_t cols);
            Matrix(const Matrix &matrix);
           ~Matrix();
        Matrix &operator=(const Matrix& matrix);
        void scan_matrix(const char *string);

        size_t rows() const;
        size_t cols() const;

        double &operator()(size_t row, size_t col);
        double elem(size_t row, size_t col) const;

        friend std::ostream &operator<<(std::ostream &os, const Matrix &matrix);

        void operator+=(const Matrix &matrix);
        void operator-=(const Matrix &matrix);
        void operator*=(double z);
        // TO DO
        // void operator*=(const Matrix &matrix);

        void swap(size_t row_a, size_t row_b);
        void scalar(double k, size_t row);
        void pivot(double k, size_t row_a, size_t row_b);
        // void row_operation(const char *string);
};
