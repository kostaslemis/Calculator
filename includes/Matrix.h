#pragma once

#include <iostream>


class Matrix {
    private:
        const int _rows;
        const int _cols;
        double** _elements;
    public:
            Matrix(const int r, const int c);
            Matrix(const Matrix& matrix);
           ~Matrix();
        Matrix& operator = (const Matrix& matrix);
        void scan_matrix(const std::string& string);

        int rows() const;
        int cols() const;
    
        double& operator () (const int row, const int col);
        double elem(const int row, const int col) const;

        friend std::ostream& operator << (std::ostream& os, const Matrix& matrix);
        
        void swap(const int row_a, const int row_b);                
        void scalar(const double k, const int row);
        void pivot(const double k, const int row_a, const int row_b);
        void row_operation(const std::string& string);                      
};
