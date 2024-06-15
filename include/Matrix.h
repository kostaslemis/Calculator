#pragma once    // TO DO : Throw Exceptions

#include <iostream>


class Matrix {
    private:
        const size_t _rows;
        const size_t _cols;
        double **_elements;
    public:
            Matrix(const size_t rows, const size_t cols);
            Matrix(const Matrix &matrix);
            Matrix(double *elements, const size_t rows, const size_t cols);
           ~Matrix();
        Matrix &operator=(const Matrix &matrix);
        void scan_matrix(const char *string);

        size_t rows() const;
        size_t cols() const;

        double &operator()(const size_t row, const size_t col);
        double elem(const size_t row, const size_t col) const;

        friend std::ostream &operator<<(std::ostream &os, const Matrix &matrix);

        void operator+=(const Matrix &matrix);
        void operator-=(const Matrix &matrix);
        void operator*=(const double k);
        void operator*=(const Matrix &matrix);

        void swap(const size_t row_a, const size_t row_b);
        void scalar(const double k, const size_t row);
        void pivot(const double k, const size_t row_a, const size_t row_b);
        // void row_operation(const char *string);
};
