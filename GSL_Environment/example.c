#include <stdio.h>
#include <gsl/gsl_blas.h>


int
main (void)
{
	double a[] = { 0.11, 0.12, 0.13,
				   0.21, 0.22, 0.23 };

	double b[] = { 1011, 1012,
				   1021, 1022,
				   1031, 1032 };

	double c[] = { 0.00, 0.00,
				   0.00, 0.00 };

	gsl_matrix_view A = gsl_matrix_view_array(a, 2, 3);
	gsl_matrix_view B = gsl_matrix_view_array(b, 3, 2);
	gsl_matrix_view C = gsl_matrix_view_array(c, 2, 2);

	/* Compute C = A B */

	gsl_blas_dgemm (CblasNoTrans, CblasNoTrans,
					1.0, &A.matrix, &B.matrix,
					0.0, &C.matrix);

	printf ("[ %g, %g\n", c[0], c[1]);
	printf ("  %g, %g ]\n", c[2], c[3]);


	double v[] = {1.0, 2.0, 3.0};
	double u[] = {1.0, 1.0, 1.0};

	gsl_vector_view v_view = gsl_vector_view_array(v, 3);
	gsl_vector_view u_view = gsl_vector_view_array(u, 3);

	double *result = malloc(sizeof(double));
	gsl_blas_ddot(&v_view.vector, &u_view.vector, result);

	printf("%lf\n", *result);

	free(result);

	return 0;
}
