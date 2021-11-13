#include <iostream>
#include <math.h>


class Matrix
{
private:
    const short rows;
    const short cols;
    double **elems;
public:
        Matrix(const short, const short);
        ~Matrix();
    short getRows() { return rows; }
    short getCols() { return cols; }
    double& operator () (const short, const short);
};

Matrix::Matrix (const short r = 0, const short c = 0) : rows(r), cols(c) {
    elems = new double*[rows];
    for (int r = 0; r < rows; r++)
        elems[r] = new double[cols];
    // Initialize the elements of the Matrix with the value 0
    for (int r = 0; r < rows; r++)
        for (int c = 0; c < cols; c++)
            elems[r][c] = 0;       
}

Matrix::~Matrix() {
    for (int r = 0; r < rows; r++)
        delete[] elems[r];
    delete[] elems;
}

double& Matrix::operator () (const short row, const short col) {
    static double dummy = 0.0;
    return (row >= 1 && row <= rows && col >= 1 && col <= cols)
        ? elems[row - 1][col - 1]
        : dummy;
}

std::ostream& operator << (std::ostream& os, Matrix &matrix) {
    for (int r = 1; r <= matrix.getRows(); r++) {
        for (int c = 1; c <= matrix.getCols(); c++)
            os << matrix(r, c) << "  ";
        os << std::endl;
    }

    return os;
}

Matrix operator + (Matrix &p, Matrix &q) {
    Matrix matrix(p.getRows(), q.getCols());
    if (p.getRows() != q.getRows() || p.getCols() != q.getCols())
        return matrix;
        
    for (int r = 1; r <= p.getRows(); r++)
        for (int c = 1; c <= q.getCols(); c++)
            matrix(r, c) = p(r, c) + q(r, c);

    return matrix;
}

Matrix operator - (Matrix &p, Matrix &q) {
    Matrix matrix(p.getRows(), q.getCols());

    if (p.getRows() != q.getRows() || p.getCols() != q.getCols())
        return matrix;

    for (int r = 1; r <= p.getRows(); r++)
        for (int c = 1; c <= q.getCols(); c++)
            matrix(r, c) = p(r, c) - q(r, c);

    return matrix;
}

Matrix operator * (Matrix &p, Matrix &q) {
    Matrix m(p.getRows(), q.getCols());
    
    if (p.getCols() != q.getRows()) 
        return m;

    for (int r = 1; r <= p.getRows(); r++)
        for (int c = 1; c <= q.getCols(); c++)
            for (int k = 1; k <= p.getCols(); k++)
                m(r, c) += p(r, k) * q(k, c);

    return m;
}

Matrix operator * (double k, Matrix &p) {
    Matrix m(p.getRows(), p.getCols());

    for (int r = 1; r <= p.getRows(); r++)
        for (int c = 1; c <= p.getCols(); c++)
            m(r, c) = k * p(r, c);
  
    return m;
}

bool equalRowsCols(Matrix &p, Matrix &q) {
    return p.getRows() == q.getRows() && p.getCols() == q.getCols();
}

bool operator == (Matrix &p, Matrix &q) {
    for (int r = 1; r <= p.getRows(); r++)
        for (int c = 1; c <= p.getCols(); c++)
            if (p(r, c) != q(r, c))
                return false;

    return true;
}

bool operator != (Matrix &p, Matrix &q) {
    return !(p == q);
}

bool isSquareMatrix(Matrix &p) {
    return p.getRows() == p.getCols();
}

double trace(Matrix &p) {
    double trace = 0;
    for (int i = 1; i <= p.getCols(); i++)
        trace += p(i, i);
    return trace;
}

Matrix subMatrix(Matrix &p, int col) {
    Matrix m(p.getRows() - 1, p.getCols() - 1);

    for (int r = 2; r <= p.getRows(); r++)
        for (int c = 1; c <= p.getCols(); c++) {
            if (c < col) 
                m(r - 1, c) = p(r, c);
            else if (c > col)
                m(r - 1, c - 1) = p(r, c);
        }

    return m;
}

double det(Matrix &p) {
    if (p.getRows() == 1 && p.getRows() == 1)
        return p(1, 1);

    if (p.getRows() == 2 && p.getCols() == 2)
        return p(1, 1)*p(2, 2) - p(1, 2)*p(2, 1);

    int sign = 1;
    double Sum = 0;
    for (int c = 1; c <= p.getCols(); c++, sign *= -1) {
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

Matrix transpose(Matrix &p) {
    Matrix matrix(p.getCols(), p.getRows());

    for (int r = 1; r <= p.getRows(); r++)
        for (int c = 1; c <= p.getCols(); c++)
            matrix(c, r) = p(r, c);

    return matrix;
}

Matrix minor(Matrix &p, int row, int col) {
    Matrix matrix(p.getRows() - 1, p.getCols() - 1);
    // Really bad code
    for (int r = 1; r <= p.getRows(); r++) {
        if (r < row)
            for (int c = 1; c <= p.getCols(); c++) {
                if (c < col)
                    matrix(r, c) = p(r, c);
                else if (c > col)
                    matrix(r, c - 1) = p(r, c);
            }
        else if (r > row)
            for (int c = 1; c <= p.getCols(); c++) {
                if (c < col)
                    matrix(r - 1, c) = p(r, c);
                else if (c > col)
                    matrix(r - 1, c - 1) = p(r, c);
            }  
    }

    return matrix; 
}

Matrix cofactor(Matrix &p) {
    Matrix matrix(p.getRows(), p.getCols());

    for (int r = 1; r <= p.getRows(); r++)
        for (int c = 1; c <= p.getCols(); c++) {
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
