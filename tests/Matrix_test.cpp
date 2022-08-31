#include <iostream>

#include "acutest.h"
#include "Matrix_Operations.h"


void test_det(void) {
    Matrix a(1, 1);
    a(1, 1)= 9;

    Matrix b(2, 2);
    b(1, 1) = 1; b(1, 2) = 0;
    b(2, 1) = 0; b(2, 2) = 1;

    Matrix c(3, 3);
    c(1, 1) = 3; c(1, 2) = 2; c(1, 3) = 4;
    c(2, 1) = 1; c(2, 2) = 1; c(2, 3) = 0;
    c(3, 1) = 3; c(3, 2) = 5; c(3, 3) = 2;


    TEST_ASSERT(det(a) == 9);
    TEST_ASSERT(det(b) == 1);
    TEST_ASSERT(det(c) == 10);
}


TEST_LIST = {
    { "test_det", test_det},
    { NULL, NULL }
};
