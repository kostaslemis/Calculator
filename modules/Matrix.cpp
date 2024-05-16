#include <regex>

#include "Matrix.h"     // TO DO : Throw Exceptions

static Matrix matrix_regex(const char *string, size_t rows, size_t cols) {
    size_t i = 0, j = 0, r = 0;

    std::smatch matches;
    std::string str_check = string;
    std::regex reg_check ("[^-,\\s\\d{}]");
    while (std::regex_search(str_check, matches, reg_check)) {
        str_check = matches.suffix().str();
        i++;
    }

    std::string str_input = string;
    std::regex reg_input("(^\\{(\\s)*?((\\{((-)?(\\d)+(\\s)*?,(\\s)*?)*(-)?(\\d)+(\\s)*?\\})(\\s)*?,(\\s)*?)*(\\{((-)?(\\d)+(\\s)*?,(\\s)*?)*(-)?(\\d)+(\\s)*?\\})(\\s)*?\\}$)");
    while (std::regex_search(str_input, matches, reg_input)) {
        str_input = matches.suffix().str();
        j++;
    }

    Matrix matrix(rows, cols);
    std::string str_rows = string;
    std::regex reg_rows("(\\{((-)?(\\d)+(\\s)*?,(\\s)*?)*(-)?(\\d)+(\\s)*?\\})");
    while (std::regex_search(str_rows, matches, reg_rows)) {
        size_t c = 0;
        std::string str_values = matches.str();
        std::regex reg_values("((-)?(\\d)+)");
        std::sregex_iterator current_match(str_values.begin(), str_values.end(), reg_values);
        std::sregex_iterator last_match;
        while (current_match != last_match) {
            std::smatch match = *current_match;
            std::string value = match.str();
            matrix(r + 1, c + 1) = stoi(value);
            current_match++;
            c++;
        }

        if (c > cols) {
            r = -1;
            break;
        }

        str_rows= matches.suffix().str();
        r++;
    }

    if (i > 0 || j != 1 || r != rows) {
        std::cout << "Invalid input" << std::endl;
        std::cout << "Follow specific format :" << std::endl;
        std::cout << "\"{{x_11, x_12, ..., x_1n}, {x_21, x_22, ..., x_2n}, ..., {x_n1, x_n2, ..., x_nn}}\"" << std::endl;
        Matrix error_matrix(0, 0);
        return error_matrix;
    }

    return matrix;
}

// static void row_operation_regex(const char *string) {

// }


Matrix::Matrix(size_t rows, size_t cols) : _rows(rows), _cols(cols) {
    _elements = new double*[_rows];
    for (size_t r = 0; r < _rows; r++)
        _elements[r] = new double[_cols];

    for (size_t r = 0; r < _rows; r++)
        for (size_t c = 0; c < _cols; c++)
            _elements[r][c] = 0.0;
}

Matrix::Matrix(const Matrix &matrix) : _rows(matrix._rows), _cols(matrix._cols) {
    _elements = new double*[_rows];
    for (size_t r = 0; r < _rows; r++)
        _elements[r] = new double[_cols];

    for (size_t r = 0; r < _rows; r++)
        for (size_t c = 0; c < _cols; c++)
            _elements[r][c] = matrix._elements[r][c];
}

Matrix::Matrix(double *elements, size_t rows, size_t cols) : _rows(rows), _cols(cols) {
    _elements = new double*[_rows];
    for (size_t r = 0; r < _rows; r++)
        _elements[r] = new double[_cols];

    for (size_t r = 0; r < _rows; r++)
        for (size_t c = 0; c < _cols; c++)
            _elements[r][c] = elements[c + _rows*r];
}

Matrix::~Matrix() {
    for (size_t r = 0; r < _rows; r++)
        delete[] _elements[r];
    delete[] _elements;
}

Matrix &Matrix::operator=(const Matrix &matrix) {
    if (_elements == NULL) {
        _elements = new double*[matrix._rows];
        for (size_t r = 0; r < _rows; r++)
            _elements[r] = new double[matrix._cols];
    }

    for (size_t r = 0; r < matrix._rows; r++)
        for (size_t c = 0; c < matrix._cols; c++)
            _elements[r][c] = matrix._elements[r][c];

    return *this;
}

void Matrix::scan_matrix(const char *string) {
    Matrix matrix = matrix_regex(string, _rows, _cols);
    for (size_t r = 0; r < _rows; r++)
        for (size_t c = 0; c < _cols; c++)
            _elements[r][c] = matrix._elements[r][c];
}

size_t Matrix::rows() const {
    return _rows;
}

size_t Matrix::cols() const {
    return _cols;
}

double &Matrix::operator()(size_t row, size_t col) {
    static double dummy = 0.0;
    if (_elements == NULL)
        return dummy;

    return (row >= 1 && row <= _rows && col >= 1 && col <= _cols)
        ? _elements[row - 1][col - 1]
        : dummy;
}

double Matrix::elem(size_t row, size_t col) const {
    const double dummy = 0.0;
    if (_elements == NULL)
        return dummy;

    return (row >= 1 && row <= _rows && col >= 1 && col <= _cols)
        ? _elements[row - 1][col - 1]
        : dummy;
}

std::ostream &operator<<(std::ostream &os, const Matrix &matrix) {
    for (size_t r = 0; r < matrix._rows; r++) {
        for (size_t c = 0; c < matrix._cols; c++)
            os << matrix._elements[r][c] << "  ";
        os << std::endl;
    }

    return os;
}

void Matrix::operator+=(const Matrix &matrix) {
    if (_rows != matrix._rows || _cols != matrix._cols)
        return;

    for (size_t r = 0; r < _rows; r++)
        for (size_t c = 0; c < _cols; c++)
            _elements[r][c] = _elements[r][c] + matrix._elements[r][c];
}

void Matrix::operator-=(const Matrix &matrix) {
    if (_rows != matrix._rows || _cols != matrix._cols)
        return;

    for (size_t r = 0; r < _rows; r++)
        for (size_t c = 0; c < _cols; c++)
            _elements[r][c] = _elements[r][c] - matrix._elements[r][c];
}

void Matrix::operator*=(double z) {
    if (z == 0)
        return;

    for (size_t r = 0; r < _rows; r++)
        for (size_t c = 0; c < _cols; c++)
            _elements[r][c] = z * _elements[r][c];
}

// row_a <-> row_b : swap row_a with row_b
void Matrix::swap(size_t row_a, size_t row_b) {
    // Check row_a and row_b

    // temp_row <= row_a
    double* temp_row = new double[_cols];
    for (size_t i = 0; i < _cols; i++)
        temp_row[i] = _elements[row_a - 1][i]; 

    // row_a <= row_b
    for (size_t c = 0; c < _cols; c++)
        _elements[row_a - 1][c] = _elements[row_b - 1][c];

    // row_b <= temp_row
    for (size_t c = 0; c < _cols; c++)
        _elements[row_b - 1][c] = temp_row[c];

    delete[] temp_row;
}

// k * row : multiply row with k
void Matrix::scalar(double k, size_t row) {
    // Check row and k != 0

    for (size_t c = 0; c < _cols; c++)
        _elements[row - 1][c] = k * _elements[row - 1][c];
}

// row_b <= k*row_a + row_b : replace row_b by the sum of itself and a multiple of row_a
void Matrix::pivot(double k, size_t row_a, size_t row_b) {
    // Check row_a, row_b and k != 0

    for (size_t c = 0; c < _cols; c++)
        _elements[row_b - 1][c] = k * _elements[row_a - 1][c] + _elements[row_b - 1][c];
}

// void Matrix::row_operation(const char *string) {

// }
