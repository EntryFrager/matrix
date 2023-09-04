#include <stdio.h>
#include <TXLib.h>

#include "matrix.h"
#include "error.h"

void print_matrix_1 (const double matrix[][5], size_t sizeX, size_t sizeY, FILE *fp)
{
    for (size_t y = 0; y < sizeY; y++)
    {
        for (size_t x = 0; x < sizeX; x++)
        {
            fprintf(fp, "%lg ", matrix[y][x]);
        }
        fprintf(fp, "\n");
    }
}

void print_matrix_2 (const double *matrix, size_t sizeX, size_t sizeY, FILE *fp)
{
    my_assert (matrix != NULL);

    size_t y = 0;
    size_t x = 0;

    while (x < sizeX && y < sizeY)
    {
        fprintf(fp, "%lg ", matrix[y * sizeX + x]);

        x++;

        if (x == sizeX)
        {
            x = 0;

            y++;

            fprintf(fp, "\n");
        }
    }
}

void print_triangle_matrix (const int *matrix, size_t Size, FILE *fp)
{
    my_assert (matrix != NULL);

    for (size_t y = 0; y < Size; y++)
    {
        for (size_t x = 0; x <= y; x++)
        {
            fprintf (fp, "%d ", matrix[x + (y + 1) * y / 2]);
        }
        fprintf(fp, "\n");
    }
}

void matrix_multiplicate (const double *matrix_1, const double *matrix_2, double *matrix_3, const size_t sizeX, const size_t sizeY)
{
    my_assert (matrix_1 != NULL);
    my_assert (matrix_2 != NULL);
    my_assert (matrix_3 != NULL);

    for (size_t y = 0; y < sizeY; y++)
    {
        for (size_t x = 0; x < sizeX; x++)
        {
            int sum = 0;
            for (size_t a = 0; a < sizeX; a++)
            {
                sum += matrix_1[a + y * sizeX] * matrix_2[a * sizeX + x];
            }
            matrix_3[x + y * sizeX] = sum;
        }
    }
}
