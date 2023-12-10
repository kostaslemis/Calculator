#include <stdio.h>
#include <stdlib.h>

#include "timer.h"
#include "Vector_Operations.h"
#include "Matrix_Operations.h"


int main(void) {
    // Vector vector = vector_create(4);

    // vector_set_value(vector, 1, 25);
    // vector_set_value(vector, 2, 10);

    // vector_print(vector);

    // fprintf(stdout, "%f\n", vectors_dot_product(vector, vector));

    // vector_destroy(vector);

    // Matrix matrix = matrix_create(3, 4);

    // matrix_print(matrix);
    // matrix_destroy(matrix);

    // vector = vector_create_random(100000000, 100);

    // double start, end;
    // GET_TIME(start)
    // vector_length(vector);
    // GET_TIME(end);

    // double start_omp, end_omp;
    // GET_TIME(start_omp);
    // vector_length_omp(vector, 16);
    // GET_TIME(end_omp);

    // fprintf(stdout, "Vector length took %f seconds to execute\n", end - start);

    // fprintf(stdout, "Vector length omp took %f seconds to execute\n", end_omp - start_omp);

    // vector_destroy(vector);

    // Vector v = vector_create_random(100000000, 1000);
    // Vector u = vector_create_random(100000000, 1000);

    // GET_TIME(start);
    // vectors_dot_product(v, u);
    // GET_TIME(end);

    // fprintf(stdout, "Vector dot product took %f seconds to execute\n", end - start);

    // for (size_t i = 1; i <= vector_size(vector); i++) {
    //     vector_set_value(v, i, 1.0);
    //     vector_set_value(u, i, 0.0);
    // }

    // GET_TIME(start);
    // double euclidean_distance = vectors_euclidean_distance(v, u);
    // GET_TIME(end);

    // fprintf(stdout, "Vector euclidean distance took %f seconds to execute with result %f\n", end - start, euclidean_distance);

    // GET_TIME(start);
    // double manhattan_distance = vectors_manhattan_distance(v, u);
    // GET_TIME(end);

    // fprintf(stdout, "Vector manhattan distance took %f seconds to execute with result %f\n", end - start, manhattan_distance);

    // vector_destroy(v);
    // vector_destroy(u);

    int N = 100;
    Vector v = vector_create_random(N, 10);
    Vector u = vector_create_random(N, 10);
   
    double start, end;
    GET_TIME(start);
    int M = 10000000;
    for (int i = 0; i < M; i++) {
        vectors_dot_product(v, u);
    }
    GET_TIME(end);
    fprintf(stdout, "Vector dot product took %f seconds to execute\n", end - start);

    GET_TIME(start);
    for (int i = 0; i < M; i++) {
        vectors_euclidean_distance(v, u);
    }
    GET_TIME(end);
    fprintf(stdout, "Vector euclidean distance took %f seconds to execute\n", end - start);

    vector_destroy(v);
    vector_destroy(u);

    return EXIT_SUCCESS;
}
