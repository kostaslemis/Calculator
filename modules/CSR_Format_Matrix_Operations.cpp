#include "../include/CSR_Format_Matrix_Operations.h"
#include "../include/Vector_Operations.h"


bool equal_dimensions(const CSR_Format_Matrix &A, const CSR_Format_Matrix &B) {
    return A.rows() == B.rows() && A.cols() == B.cols();
}

// CSR_Format_Matrix operator+(const CSR_Format_Matrix &A, const CSR_Format_Matrix &B) {

// }

// CSR_Format_Matrix operator-(const CSR_Format_Matrix &A, const CSR_Format_Matrix &B) {

// }

CSR_Format_Matrix operator*(const double k, const CSR_Format_Matrix &csr_format_matrix) {
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

    for (size_t r = 1; r <= csr_format_matrix.rows(); r++) {
        size_t row_start = csr_format_matrix.row_indices().elem(r);
        size_t row_end = csr_format_matrix.row_indices().elem(r + 1);
        for (size_t c = row_start + 1; c <= row_end; c++) {
            size_t v_r = csr_format_matrix.col_indices().elem(c);
            new_vector(r) += csr_format_matrix.non_zero_values().elem(c) * vector.elem(v_r);
        }
    }

    return new_vector;
}

// B transpose
// CSR_Format_Matrix operator*(const CSR_Format_Matrix &A, const CSR_Format_Matrix &B) {
//     if (A.cols() != B.cols()) {
//         Matrix error_matrix(0, 0);
//         CSR_Format_Matrix error_csr_format_matrix(error_matrix);
//         return error_csr_format_matrix;
//     }

//     Vector A_non_zero_values = A.non_zero_values();
//     Vector A_col_indices = A.col_indices();
//     Vector A_row_indices = A.row_indices();

//     Vector B_non_zero_values = B.non_zero_values();
//     Vector B_col_indices = B.col_indices();
//     Vector B_row_indices = B.row_indices();

//     for (size_t A_r = 1; A_r <= A.rows(); A_r++) {
//         size_t A_row_start = A_row_indices(A_r);
//         size_t A_row_end = A_row_indices(A_r + 1);
//         for (size_t B_r = 1; B_r <= B.rows(); B_r++) {
//             double sum = 0.0;
//             for (size_t c = A_row_start + 1; c <= A_row_end; c++) {
//                 if (A_col_indices(c) == B_col_indices(c))
//                     sum += A_non_zero_values(c) * B_non_zero_values(c);
//             }
//         }
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

// CSR_Format_Matrix transpose(const CSR_Format_Matrix &csr_format_matrix) {

// }
