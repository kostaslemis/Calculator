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
    double& operator() (const short, const short);
    Matrix& operator = (Matrix&);
};

Matrix::Matrix (const short r = 0, const short c = 0) : _rows(r), _cols(c) {
    elems = new double*[_rows];
    for (int r = 0; r < _rows; r++)
        elems[r] = new double[_cols]; 
}

Matrix::Matrix(const Matrix& p) : _rows(p._rows), _cols(p._cols) {
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

Matrix& Matrix::operator = (Matrix &p) {
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

std::ostream& operator << (std::ostream& os, Matrix &matrix) {
    for (int r = 1; r <= matrix.rows(); r++) {
        for (int c = 1; c <= matrix.cols(); c++)
            os << matrix(r, c) << "  ";
        os << std::endl;
    }

    return os;
}

bool equalRowsCols(Matrix &p, Matrix &q) {
    return p.rows() == q.rows() && p.cols() == q.cols();
}

Matrix operator + (Matrix &p, Matrix &q) {
    Matrix matrix(p.rows(), q.cols());
    if (!equalRowsCols(p, q))
        return matrix;
        
    for (int r = 1; r <= p.rows(); r++)
        for (int c = 1; c <= q.cols(); c++)
            matrix(r, c) = p(r, c) + q(r, c);

    return matrix;
}

Matrix operator - (Matrix &p, Matrix &q) {
    Matrix matrix(p.rows(), q.cols());

    if (equalRowsCols(p, q))
        return matrix;

    for (int r = 1; r <= p.rows(); r++)
        for (int c = 1; c <= q.cols(); c++)
            matrix(r, c) = p(r, c) - q(r, c);

    return matrix;
}

Matrix operator * (Matrix &p, Matrix &q) {
    Matrix m(p.rows(), q.cols());
    
    if (p.cols() != q.rows()) 
        return m;

    for (int r = 1; r <= p.rows(); r++)
        for (int c = 1; c <= q.cols(); c++)
            for (int k = 1; k <= p.cols(); k++)
                m(r, c) += p(r, k) * q(k, c);

    return m;
}

Matrix operator * (double k, Matrix &p) {
    Matrix m(p.rows(), p.cols());

    for (int r = 1; r <= p.rows(); r++)
        for (int c = 1; c <= p.cols(); c++)
            m(r, c) = k * p(r, c);
  
    return m;
}


bool operator == (Matrix &p, Matrix &q) {
    if (!equalRowsCols(p, q))
        return false;

    for (int r = 1; r <= p.rows(); r++)
        for (int c = 1; c <= p.cols(); c++)
            if (p(r, c) != q(r, c))
                return false;

    return true;
}

bool operator != (Matrix &p, Matrix &q) {
    if (!equalRowsCols(p, q))
        return false;

    return !(p == q);
}

inline bool isSquareMatrix(Matrix &p) {
    return p.rows() == p.cols();
}

double trace(Matrix &p) {
    double trace = 0;
    for (int i = 1; i <= p.cols(); i++)
        trace += p(i, i);
    return trace;
}

Matrix subMatrix(Matrix &p, int col) {
    Matrix m(p.rows() - 1, p.cols() - 1);

    for (int r = 2; r <= p.rows(); r++)
        for (int c = 1; c <= p.cols(); c++) {
            if (c < col) 
                m(r - 1, c) = p(r, c);
            else if (c > col)
                m(r - 1, c - 1) = p(r, c);
        }

    return m;
}

double det(Matrix &p) {
    if (!isSquareMatrix(p))
        return 0.0;

    if (p.rows() == 1 && p.rows() == 1)
        return p(1, 1);

    if (p.rows() == 2 && p.cols() == 2)
        return p(1, 1)*p(2, 2) - p(1, 2)*p(2, 1);

    int sign = 1;
    double Sum = 0;
    for (int c = 1; c <= p.cols(); c++, sign *= -1) {
        Matrix sub_matrix = subMatrix(p, c);
        Sum += p(1, c) * det(sub_matrix) * sign;
    }
    return Sum;
}

Matrix identity_matrix(int n) {
    Matrix I(n, n);
    for (int i = 1; i <= n; i++)
        I(i, i) = 1;
    
    return I;
}

Matrix pow(Matrix &p, int exponent) {
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

Matrix transpose(Matrix &p) {
    Matrix matrix(p.cols(), p.rows());

    for (int r = 1; r <= p.rows(); r++)
        for (int c = 1; c <= p.cols(); c++)
            matrix(c, r) = p(r, c);

    return matrix;
}

Matrix minor(Matrix &p, int row, int col) {
    Matrix matrix(p.rows() - 1, p.cols() - 1);
    // Really bad code
    for (int r = 1; r <= p.rows(); r++) {
        if (r < row)
            for (int c = 1; c <= p.cols(); c++) {
                if (c < col)
                    matrix(r, c) = p(r, c);
                else if (c > col)
                    matrix(r, c - 1) = p(r, c);
            }
        else if (r > row)
            for (int c = 1; c <= p.cols(); c++) {
                if (c < col)
                    matrix(r - 1, c) = p(r, c);
                else if (c > col)
                    matrix(r - 1, c - 1) = p(r, c);
            }  
    }

    return matrix; 
}

Matrix cofactor(Matrix &p) {
    Matrix matrix(p.rows(), p.cols());

    for (int r = 1; r <= p.rows(); r++)
        for (int c = 1; c <= p.cols(); c++) {
            Matrix minor_matrix = minor(p, r, c);
            matrix(r, c) = pow(-1, r + c)*det(minor_matrix);
        }

    return matrix;
}

Matrix adj(Matrix &p) {
    Matrix cofactor_matrix = cofactor(p);
    return transpose(cofactor_matrix);
}

Matrix inverse(Matrix &p) {
    Matrix adjoint = adj(p);
    return 1/det(p)*adjoint;
}
