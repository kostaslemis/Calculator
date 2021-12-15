#include <iostream>
#include <math.h>


class Matrix
{
private:
    const short _rows;
    const short _cols;
    double **elems = NULL;
public:
        Matrix(const short, const short);
        Matrix(const Matrix&);
       ~Matrix();
    short rows() const { return _rows; };
    short cols() const { return _cols; };
    double& operator() (const short row, const short col);
    double elem(short row, short col) const;
    Matrix& operator = (const Matrix&);
};

Matrix::Matrix (const short r = 0, const short c = 0) : _rows(r), _cols(c) {
    elems = new double*[_rows];
    for (int r = 0; r < _rows; r++)
        elems[r] = new double[_cols]; 
}

Matrix::Matrix(const Matrix &p) : _rows(p._rows), _cols(p._cols) {
    elems = new double*[_rows];
    for (int r = 0; r < _rows; r++)
        elems[r] = new double[_cols];

    for (int r = 0; r < _rows; r++)
        for (int c = 0; c < _cols; c++)
            this->elems[r][c] = p.elems[r][c];
}

Matrix::~Matrix() {
    for (int r = 0; r < _rows; r++)
        delete[] elems[r];
    delete[] elems;
}

double& Matrix::operator() (const short row, const short col) {
    static double dummy = 0.0;
    return (row >= 1 && row <= _rows && col >= 1 && col <= _cols)
        ? elems[row - 1][col - 1]
        : dummy;
}

double Matrix::elem(short row, short col) const {
    static double dummy = 0.0;
    return (row >= 1 && row <= _rows && col >= 1 && col <= _cols)
        ? elems[row - 1][col - 1]
        : dummy;
}

Matrix& Matrix::operator = (const Matrix &p) {
    if (this->elems == NULL) {
        elems = new double*[p.rows()];
        for (int r = 0; r < _rows; r++)
            elems[r] = new double[p.cols()];
    }

    for (int r = 0; r < p.rows(); r++)
        for (int c = 0; c < p.cols(); c++)
            this->elems[r][c] = p.elems[r][c];
    
    return *this;
}

std::ostream& operator << (std::ostream& os, const Matrix &matrix) {
    for (int r = 1; r <= matrix.rows(); r++) {
        for (int c = 1; c <= matrix.cols(); c++)
            os << matrix.elem(r, c) << "  ";
        os << std::endl;
    }

    return os;
}

bool equalRowsCols(const Matrix &p, const Matrix &q) {
    return p.rows() == q.rows() && p.cols() == q.cols();
}

Matrix operator + (const Matrix &p, const Matrix &q) {
    Matrix matrix(p.rows(), q.cols());
    if (!equalRowsCols(p, q))
        return matrix;
        
    for (int r = 1; r <= p.rows(); r++)
        for (int c = 1; c <= q.cols(); c++)
            matrix(r, c) = p.elem(r, c) + q.elem(r, c);

    return matrix;
}

Matrix operator - (const Matrix &p, const Matrix &q) {
    Matrix matrix(p.rows(), q.cols());

    if (equalRowsCols(p, q))
        return matrix;

    for (int r = 1; r <= p.rows(); r++)
        for (int c = 1; c <= q.cols(); c++)
            matrix(r, c) = p.elem(r, c) - q.elem(r, c);

    return matrix;
}

Matrix operator * (const Matrix &p, const Matrix &q) {
    Matrix m(p.rows(), q.cols());
    
    if (p.cols() != q.rows()) 
        return m;

    for (int r = 1; r <= p.rows(); r++)
        for (int c = 1; c <= q.cols(); c++)
            for (int k = 1; k <= p.cols(); k++)
                m(r, c) += p.elem(r, k) * q.elem(k, c);

    return m;
}

Matrix operator * (double k, const Matrix &p) {
    Matrix m(p.rows(), p.cols());

    for (int r = 1; r <= p.rows(); r++)
        for (int c = 1; c <= p.cols(); c++)
            m(r, c) = k * p.elem(r, c);
  
    return m;
}


bool operator == (const Matrix &p, const Matrix &q) {
    if (!equalRowsCols(p, q))
        return false;

    for (int r = 1; r <= p.rows(); r++)
        for (int c = 1; c <= p.cols(); c++)
            if (p.elem(r, c) != q.elem(r, c))
                return false;

    return true;
}

bool operator != (const Matrix &p, const Matrix &q) {
    if (!equalRowsCols(p, q))
        return false;

    return !(p == q);
}

inline bool isSquareMatrix(const Matrix &p) {
    return p.rows() == p.cols();
}

double trace(const Matrix &p) {
    double trace = 0;
    for (int i = 1; i <= p.cols(); i++)
        trace += p.elem(i, i);
    return trace;
}

Matrix subMatrix(const Matrix &p, int col) {
    Matrix m(p.rows() - 1, p.cols() - 1);

    for (int r = 2; r <= p.rows(); r++)
        for (int c = 1; c <= p.cols(); c++) {
            if (c < col) 
                m(r - 1, c) = p.elem(r, c);
            else if (c > col)
                m(r - 1, c - 1) = p.elem(r, c);
        }

    return m;
}

double det(const Matrix &p) {
    if (!isSquareMatrix(p))
        return 0.0;

    if (p.rows() == 1 && p.rows() == 1)
        return p.elem(1, 1);

    if (p.rows() == 2 && p.cols() == 2)
        return p.elem(1, 1)*p.elem(2, 2) - p.elem(1, 2)*p.elem(2, 1);

    double Sum = 0;
    for (int c = 1, sign = 1; c <= p.cols(); c++, sign *= -1)
        Sum += p.elem(1, c) * det(subMatrix(p, c)) * sign;

    return Sum;
}

Matrix identity_matrix(int n) {
    Matrix I(n, n);
    for (int i = 1; i <= n; i++)
        I(i, i) = 1;
    
    return I;
}

Matrix pow(const Matrix &p, int exponent) {
    Matrix dummy(0, 0);
    if (!isSquareMatrix(p)) return dummy;

    Matrix pow_matrix = identity_matrix(p.rows());
    if (exponent = 0) return p;

    for (int i = 0; i < exponent; i++) {
        Matrix result = pow_matrix * p;
        pow_matrix = result;
    }

    return pow_matrix;
}

Matrix transpose(const Matrix &p) {
    Matrix matrix(p.cols(), p.rows());

    for (int r = 1; r <= p.rows(); r++)
        for (int c = 1; c <= p.cols(); c++)
            matrix(c, r) = p.elem(r, c);

    return matrix;
}

Matrix minor(const Matrix &p, int row, int col) {
    Matrix matrix(p.rows() - 1, p.cols() - 1);
    // Really bad code
    for (int r = 1; r <= p.rows(); r++) {
        if (r < row)
            for (int c = 1; c <= p.cols(); c++) {
                if (c < col)
                    matrix(r, c) = p.elem(r, c);
                else if (c > col)
                    matrix(r, c - 1) = p.elem(r, c);
            }
        else if (r > row)
            for (int c = 1; c <= p.cols(); c++) {
                if (c < col)
                    matrix(r - 1, c) = p.elem(r, c);
                else if (c > col)
                    matrix(r - 1, c - 1) = p.elem(r, c);
            }  
    }

    return matrix; 
}

Matrix cofactor(const Matrix &p) {
    Matrix matrix(p.rows(), p.cols());

    for (int r = 1; r <= p.rows(); r++)
        for (int c = 1; c <= p.cols(); c++)
            matrix(r, c) = pow(-1, r + c)*det(minor(p, r, c));

    return matrix;
}

Matrix adj(const Matrix &p) {
    return transpose(cofactor(p));
}

Matrix inverse(const Matrix &p) {
    return 1/det(p)*adj(p);
}
