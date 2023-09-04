#include <stdio.h>
#include <TXLib.h>

#include "matrix.h"
#include "error.h"

int main ()
{
    double matrix_1[5][5] = {{ 0,  1,  2,  3,  4},
                             {10, 11, 12, 13, 14},
                             {20, 21, 22, 23, 24},
                             {30, 31, 32, 32, 34},
                             {40, 41, 42, 43, 44}};

    double matrix_2[5][5] = {{ 5,  6,  7,  8,  9},
                             {15, 16, 17, 18, 19},
                             {25, 26, 27, 28, 29},
                             {35, 36, 37, 38, 39},
                             {45, 46, 47, 48, 49}};

    double matrix_3[5][5] = {{},
                             {},
                             {},
                             {},
                             {}};

    int matrix_triangle[15] = {1,
                               2,   3,
                               4,   5,  6,
                               7,   8,  9,  10,
                               11, 12, 13, 14, 15};

    FILE *fp_1 = fopen ("matrix_1.txt", "r+");

    FILE *fp_2 = fopen ("matrix_2.txt", "r+");

    FILE *fp_multiplicate = fopen ("matrix_multiplicate.txt", "r+");

    FILE *fp_triangle = fopen ("matrix_triangle.txt", "r+");

    if (fp_1 == NULL || fp_2 == NULL || fp_multiplicate == NULL || fp_triangle == NULL)
    {
        fprintf (stderr, "%s", my_strerr (ERR_FOPEN));
    }

    #if 1
    print_matrix_1 (matrix_1, 5, 5, fp_1);

    print_matrix_2 ((double *) matrix_1, 5, 5, fp_2);

    matrix_multiplicate ((double *) matrix_1, (double *) matrix_2, (double *) matrix_3, 5, 5);

    print_matrix_2 ((double *) matrix_3, 5, 5, fp_multiplicate);

    print_triangle_matrix ((int *) matrix_triangle, 5, fp_triangle);

    #endif

    if (fclose (fp_1) != 0 || fclose (fp_2) != 0 || fclose (fp_multiplicate) != 0 || fclose (fp_triangle) != 0)
    {
        fprintf (stderr, "%s", my_strerr (ERR_FOPEN));
    }

    return 0;
}

