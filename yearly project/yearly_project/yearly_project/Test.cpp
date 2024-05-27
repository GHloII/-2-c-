#include "Function.h"

#include <iostream>


void Test() {

	int N = 0; // количество строк i
	int M = 0; // количество столбцов j
	std::vector<std::vector<double>>* matrix = nullptr;
	std::vector<std::vector<double>>* result_matrix_from_file = nullptr;
	std::vector<std::vector<double>>* result_matrix_after_sort = nullptr;
	std::string working_file_path = "test.txt";
	std::string result_file_path = "sort_result.txt";

	//test 1
	if (TestFileFilling(matrix, N, M, working_file_path)) {
		std::cout<<"test 1 completed successfully\n";
	}
	else {
		std::cout<<"test 1 completed with failure \n";
	}

	//test 2
	if (TestFileFilling(result_matrix_from_file, N, M, result_file_path)) {
		SelectionSort  selection_sort;
		result_matrix_after_sort = selection_sort.Sort(matrix, N, M);

		if (*result_matrix_after_sort == *result_matrix_from_file) {
		std::cout << "test 2 completed successfully\n";
		}
		result_matrix_from_file->clear();
		result_matrix_from_file = nullptr;
		result_matrix_after_sort->clear();
		result_matrix_after_sort = nullptr;

	}
	else {
		std::cout << "test 2 completed with failure \n";
	}

	//test 3
	if (TestFileFilling(result_matrix_from_file, N, M, result_file_path)) {
		SelectionSort  quick_sort;
		result_matrix_after_sort = quick_sort.Sort(matrix, N, M);

		if (*result_matrix_after_sort == *result_matrix_from_file) {
		std::cout << "test 3 completed successfully\n";
		}
		result_matrix_from_file->clear();
		result_matrix_from_file = nullptr;
		result_matrix_after_sort->clear();
		result_matrix_after_sort = nullptr;
	}
	else {
		std::cout << "test 3 completed with failure \n";
	}


	std::string test4_file_path = "CON.txt";
	std::string test5_file_path = "test5.txt";



	//test 4
	if (TestFileFilling(matrix, N, M, working_file_path)) {
		std::cout << "test 4 completed successfully\n";
	}
	else {
		std::cout << "test 4 completed with failure \n";
	}

	//test 5
	if (TestFileFilling(matrix, N, M, working_file_path)) {
		std::cout << "test 5 completed successfully\n";
	}
	else {
		std::cout << "test 5 completed with failure \n";
	}

	delete matrix;

}