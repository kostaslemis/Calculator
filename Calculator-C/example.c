#include <stdio.h>
#include <stdlib.h>

#include "Vector_Operations.h"
#include "Matrix_Operations.h"

int main(void) {

    Vector vector = vector_create(4);

    vector_set_value(vector, 2, 10);

    vector_print(vector);

    vector_destroy(vector);

    return EXIT_SUCCESS;
}