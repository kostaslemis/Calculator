#include "acutest.h"

#include "Vector.h"


void test_create(void) {
    size_t size = 10;

    Vector vector = vector_create(size);

    TEST_ASSERT(vector != NULL);

    TEST_ASSERT(vector_size(vector) == size);

    vector_destroy(vector);
}


TEST_LIST = {
    {"vector_create", test_create},
    {NULL, NULL}
};
