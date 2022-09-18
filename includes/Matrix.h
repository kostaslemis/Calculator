#pragma once

#include <iostream>


class Matrix {
    private:
        const unsigned int _rows;
        const unsigned int _cols;
        double** _elements;
    public:
            Matrix(unsigned int r, unsigned int c);
            Matrix(const Matrix &matrix);
           ~Matrix();
        Matrix &operator=(const Matrix& matrix);
        void scan_matrix(const std::string& string);

        unsigned int rows() const;
        unsigned int cols() const;
    
        double &operator()(unsigned int row, unsigned int col);
        double elem(unsigned int row, unsigned int col) const;

        friend std::ostream &operator<<(std::ostream &os, const Matrix &matrix);
        
        void swap(unsigned int row_a, unsigned int row_b);                
        void scalar(double k, unsigned int row);
        void pivot(double k, unsigned int row_a, unsigned int row_b);
        void row_operation(const std::string &string);                      
};
