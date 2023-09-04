#ifndef MATRIX_H
#define MATRIX_H

void print_matrix_1 (const double matrix[][5], size_t sizeX, size_t sizeY, FILE *fp);

void print_matrix_2 (const double *matrix, size_t sizeX, size_t sizeY, FILE *fp);

void print_triangle_matrix (const int *matrix, size_t Size, FILE *fp);

void matrix_multiplicate (const double *matrix_1, const double *matrix_2, double *matrix_3, const size_t sizeX, const size_t sizeY);

void input_score (const int *matrix_score);

#endif // MATRIX_H
