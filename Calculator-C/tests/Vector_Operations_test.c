#include "acutest.h"

#include <stdio.h>

#include "Vector_Operations.h"


void test_dot_product(void) {
    Vector v = vector_create(2);

    vector_set_value(v, 1, 2.0);
    vector_set_value(v, 2, 3.0);

    Vector u = vector_create(2);

    vector_set_value(u, 1, 1.0);
    vector_set_value(u, 2, 5.0);

    TEST_ASSERT(vectors_dot_product(v, u) == 17.0);

    TEST_ASSERT(vectors_dot_product_omp(v, u) == 17.0);

    vector_destroy(v);
    vector_destroy(u);
}

void test_length(void) {
    Vector vector = vector_create_random(1000, 10);

    TEST_ASSERT(vector_length(vector) == vector_length_omp(vector, 8));

    vector_destroy(vector);
}


TEST_LIST = {
    {"vectors_dot_product", test_dot_product},
    {"vector_length", test_length},
    {NULL, NULL}
};
