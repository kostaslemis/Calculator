#include "acutest.h"

#include "Matrix.h"


void test_create(void) {
    size_t rows = 5;
    size_t cols = 5;

    Matrix matrix = matrix_create(rows, cols);

    TEST_ASSERT(matrix != NULL);

    TEST_ASSERT(matrix_rows(matrix) == rows);
    TEST_ASSERT(matrix_cols(matrix) == cols);

    matrix_destroy(matrix);
}

TEST_LIST = {
    {"matrix_create", test_create},
    {NULL, NULL}
};
