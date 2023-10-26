#include "../include/CSR_Format_Matrix_Operations.h"
#include "../include/Vector_Operations.h"


bool equal_dimensions(const CSR_Format_Matrix &A, const CSR_Format_Matrix &B) {
    return A.rows() == B.rows() && A.cols() == B.cols();
}

// CSR_Format_Matrix operator+(const CSR_Format_Matrix &A, const CSR_Format_Matrix &B) {

// }

// CSR_Format_Matrix operator-(const CSR_Format_Matrix &A, const CSR_Format_Matrix &B) {

// }

CSR_Format_Matrix operator*(double k, const CSR_Format_Matrix &csr_format_matrix) {
    Vector new_non_zero_values(csr_format_matrix.non_zero_values());
    for (size_t i = 1; i <= new_non_zero_values.size(); i++)
        new_non_zero_values(i) *= k;

    CSR_Format_Matrix new_csr_format_matrix(new_non_zero_values,
    csr_format_matrix.col_indices(), csr_format_matrix.row_indices(), csr_format_matrix.cols());
    return new_csr_format_matrix;
}

Vector operator*(const CSR_Format_Matrix &csr_format_matrix, const Vector &vector) {
    Vector new_vector(csr_format_matrix.rows());

    if (csr_format_matrix.cols() != vector.size())
        return new_vector;

    Vector row_indices = csr_format_matrix.row_indices();
    Vector non_zero_values = csr_format_matrix.non_zero_values();
    for (size_t r = 1; r <= csr_format_matrix.rows(); r++) {
        size_t row_start = row_indices.elem(r);
        size_t row_end = row_indices.elem(r + 1);
        for (size_t c = row_start + 1; c <= row_end; c++)
            new_vector(r) += non_zero_values.elem(c) * vector.elem(r);
    }

    return new_vector;
}

// CSR_Format_Matrix operator*(const CSR_Format_Matrix &A, const CSR_Format_Matrix &B) {
//     if (A.cols() != B.rows()) {
//         Matrix error_matrix(0, 0);
//         CSR_Format_Matrix error_csr_format_matrix(error_matrix);
//         return error_csr_format_matrix;
//     }

    

// }

bool operator==(const CSR_Format_Matrix &A, const CSR_Format_Matrix &B) {
    if (!equal_dimensions(A, B))
        return false;
    
    return A.non_zero_values() == B.non_zero_values() &&
    A.col_indices() == B.col_indices() &&
    A.row_indices() == B.row_indices();
}

bool operator!=(const CSR_Format_Matrix &A, const CSR_Format_Matrix &B) {
    if (!equal_dimensions(A, B))
        return true;
    
    return A.non_zero_values() != B.non_zero_values() ||
    A.col_indices() != B.col_indices() ||
    A.row_indices() != B.row_indices();
}

// CSR_Format_Matrix transpose(CSR_Format_Matrix &csr_format_matrix) {

// }
