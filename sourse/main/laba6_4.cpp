#include <cstdio>
#include "matrix_operations.hpp"
#include "checking_operations.hpp"

int main() {
	int matrix_size = 0;
	printf("Введите размер квадратной матрицы А и В\nОни должны быть одного размера,"
		   " иначе не возможно выполнение программы: ");
	correct_input_matrix_dimension(matrix_size);
	double** matrixA = input_matrix(matrix_size, matrix_size);
	double** matrixB = input_matrix(matrix_size, matrix_size);
	double** matrix_temp = matrix_multiply(matrixA, matrixB, matrix_size);
	matrix_plus_free_number(matrixA, 3, matrix_size);
	printf("Вычисление матрицы A': \n");
	double** matrixA2 = difference_of_functions_f_and_g(matrix_size, matrixA);
	printf("\nВычисление матрицы B': \n");
	double** matrixB2 = difference_of_functions_f_and_g(matrix_size, matrix_temp);

	int ordinal_num_in_line_1, ordinal_num_in_line_2, rank = 1;
	double** matrix_minor = create_matrix(matrix_size, matrix_size);
	first_minor_counter(matrix_size, matrix_size, matrixA2, matrix_minor, ordinal_num_in_line_1, \
		                ordinal_num_in_line_2, rank);
	if (rank != 1)
	    rank = minor_counter_for_rank(matrix_size, matrix_size, ordinal_num_in_line_1, \
	    	                          ordinal_num_in_line_2, matrix_minor, matrixA2);
	printf("\nРанг матрицы A' равен: %d\n\n", rank);

	// 4 - свободный член
	printf("Решние матричного уравнения 4*X - A'*X = B'\n");
    matrix_minus_free_number(matrixA2, 4, matrix_size);
    matrix_multiply_namber(matrixA2, matrix_size, -1);
	double** minors_determinant = minor_determinant_counter(matrixA2, matrix_size);
	double det_matrix = determinant_counter(matrix_size, matrixA2);
	if (det_matrix == 0) {
		printf("Нет решний\n");
		return 0;
	}
	double** matrix_reverse = create_reverse_matrix(matrixA2, matrix_size, minors_determinant);
	double** matrix_answer = matrix_multiply(matrix_reverse, matrixB2, matrix_size);
	printf("Ответ:\n");
	cout_matrix(matrix_answer, matrix_size);

	cleaning_matrix(matrix_size, minors_determinant);
	cleaning_matrix(matrix_size, matrix_reverse);
	cleaning_matrix(matrix_size, matrix_answer);
	cleaning_matrix(matrix_size, matrix_temp);
	cleaning_matrix(matrix_size, matrix_minor);
	cleaning_matrix(matrix_size, matrixA);
	cleaning_matrix(matrix_size, matrixB);
	cleaning_matrix(matrix_size, matrixA2);
	cleaning_matrix(matrix_size, matrixB2);
	return 0;
}