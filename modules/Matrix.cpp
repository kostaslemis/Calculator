#include <Matrix.h>     // TO DO : Throw Exceptions


Matrix::Matrix(unsigned int r, unsigned int c) : _rows(r), _cols(c) {
    _elements = new double*[_rows];
    for (int r = 0; r < _rows; r++)
        _elements[r] = new double[_cols];

    for (int r = 0; r < _rows; r++)
        for (int c = 0; c < _cols; c++)
            _elements[r][c] = 0;
}

Matrix::Matrix(const Matrix &matrix) : _rows(matrix._rows), _cols(matrix._cols) {
    _elements = new double*[_rows];
    for (int r = 0; r < _rows; r++)
        _elements[r] = new double[_cols];

    for (int r = 0; r < _rows; r++)
        for (int c = 0; c < _cols; c++)
            _elements[r][c] = matrix._elements[r][c];
}

Matrix::~Matrix() {
    for (int r = 0; r < _rows; r++)
        delete[] _elements[r];
    delete[] _elements;
}

Matrix &Matrix::operator=(const Matrix &matrix) {
    if (_elements == NULL) {
        _elements = new double*[matrix._rows];
        for (int r = 0; r < _rows; r++)
            _elements[r] = new double[matrix._cols];
    }

    for (int r = 0; r < matrix._rows; r++)
        for (int c = 0; c < matrix._cols; c++)
            _elements[r][c] = matrix._elements[r][c];
    
    return *this;
}

void Matrix::scan_matrix(const std::string &string) {

}

unsigned int Matrix::rows() const {
    return _rows;
}

unsigned int Matrix::cols() const {
    return _cols;
}

double &Matrix::operator()(unsigned int row, unsigned int col) {
    static double dummy = 0.0;
    if (_elements == NULL)
        return dummy;

    return (row >= 1 && row <= _rows && col >= 1 && col <= _cols)
        ? _elements[row - 1][col - 1]
        : dummy;
}

double Matrix::elem(unsigned int row, unsigned int col) const {
    static double dummy = 0.0;
    if (_elements == NULL)
        return dummy;

    return (row >= 1 && row <= _rows && col >= 1 && col <= _cols)
        ? _elements[row - 1][col - 1]
        : dummy;
}

std::ostream &operator<<(std::ostream &os, const Matrix &matrix) {
    for (int r = 0; r < matrix._rows; r++) {
        for (int c = 0; c < matrix._cols; c++)
            os << matrix._elements[r][c] << "  ";
        os << std::endl;
    }

    return os;
}

// row_a <-> row_b : swap row_a with row_b
void Matrix::swap(unsigned int row_a, unsigned int row_b) {
    // Check row_a and row_b

    // temp_row <= row_a
    double* temp_row = new double[_cols];
    for (int i = 0; i < _cols; i++)
        temp_row[i] = _elements[row_a - 1][i]; 

    // row_a <= row_b
    for (int c = 0; c < _cols; c++)
        _elements[row_a - 1][c] = _elements[row_b - 1][c];

    // row_b <= temp_row
    for (int c = 0; c < _cols; c++)
        _elements[row_b - 1][c] = temp_row[c];

    free(temp_row);
}              

// k * row : multiply row with k
void Matrix::scalar(double k, unsigned int row) {
    // Check row and k != 0

    for (int c = 0; c < _cols; c++)
        _elements[row - 1][c] = k * _elements[row - 1][c];
}

// row_b <= k*row_a + row_b : replace row_b by the sum of itself and a multiple of row_a
void Matrix::pivot(double k, unsigned int row_a, unsigned int row_b) {
    // Check row_a and row_b - k != 0

    for (int c = 0; c < _cols; c++)
        _elements[row_b - 1][c] = k * _elements[row_a - 1][c] + _elements[row_b - 1][c];
}

void Matrix::row_operation(const std::string& string) {

}
