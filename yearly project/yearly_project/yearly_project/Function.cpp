#include "Function.h"

std::vector<std::vector<double>>* Transponding(std::vector<std::vector<double>>& matrix, int N, int M) {

	//std::vector<std::vector<double>> trans_matrix(M, std::vector<double>(N));
	auto* trans_matrix = new std::vector<std::vector<double>>(M, std::vector<double>(N));

	for (size_t i = 0; i < M; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			(*trans_matrix)[i][j] = matrix[j][i];
		}
	}
	return trans_matrix;

}

void show_greeting() {

	std::cout << "Ivanov Gleb Igorevich; group 4303; number 13" << "\n";
	std::cout << "Course work." << "\n" << "\n";


	std::cout << "Create a console program to sort an array. Additionally, sort the columns of a matrix in ascending order." << "\n"; //
	std::cout << "bubble sort, selection sort, insertion sort, shell sort, and quicksort." << "\n";
	std::cout << "Display the unordered array once, and then display the ordered arrays for each sorting method." << "\n";
	std::cout << "Also, create a comparative table showing the efficiency of each sorting method," << "\n";
	std::cout << "including the number of comparisons and variable swaps." << "\n" << "\n";

	std::cout << "The unordered matrix of N rows and M columns is inputted once" << "\n";
	std::cout << "(from the keyboard, file, or generated randomly) and is then used for each sorting method." << "\n" << "\n";

}

void Display(std::vector<std::vector<double>>* matrix, int& N, int& M) {
	std::vector<std::vector<double>> matrix_display = *matrix;
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			std::cout << matrix_display[i][j] << "\t";
		}
		std::cout << '\n';
	}
}



void HandFilling(std::vector<std::vector<double>>& matrix, int& N, int& M) {
	size_t size = N * M;
	std::cout << "enter " << size << " numbers" << "\n";
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			double temp = double_Num_input();

			(matrix[i][j]) = temp;
		}
	}
	std::cout << "\n" << "\n" << "\n";
}


void RandomFilling(std::vector<std::vector<double>>& matrix, int& N, int& M) {
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			const int MAX_RANDOM = 1000;
			(matrix[i][j]) = static_cast<double>(rand()) / RAND_MAX * MAX_RANDOM - static_cast<double>(rand()) / RAND_MAX * MAX_RANDOM;
		}
	}
}

void Filling(int option, std::vector<std::vector<double>>*& matrix, int& N, int& M) {
	if (option == file_filling) {
		FileFilling(matrix, N, M);
	}
	else if (option == hand_filling) {
		HandFilling(*matrix, N, M);
	}
	else if (option == random_filling) {
		RandomFilling(*matrix, N, M);
	}
}



void Function() {
	int N = 0; // количество строк i
	int M = 0; // количество столбцов j
	std::vector<std::vector<double>>* matrix = nullptr;

	std::cout << "Enter a option of filling " << "\n"
		"2 - random 1 - file 0 - hand" << "\n";

	int option_of_filling = hand_filling;
	while (true) {
		option_of_filling = int_Num_input();
		if (option_of_filling == file_filling || option_of_filling == hand_filling || option_of_filling == random_filling) {
			break;
		}
		std::cout << "Invalid input. Please enter a valid number." << "\n";
	}


	if (option_of_filling == hand_filling || option_of_filling == random_filling) {

		std::cout << "Enter the number of rows and the number of columns " << "\n";
		N = int_Num_input();
		M = int_Num_input();
		matrix = new std::vector<std::vector<double>>(N, std::vector<double>(M));
	}

	Filling(option_of_filling, matrix, N, M);



	//далее выполнение то есть создание резалт матrиц для всех сортировок и приравнивание их к сорту далее придумать как их дисплеить

	SelectionSort  selection_sort;
	InsertionSort  insertion_sort;
	BubbleSort	   bubble_sort;
	ShellSort	   shell_sort;
	QSort		   quick_sort;


	std::vector<std::vector<double>>* selection_sort_result_matrix = selection_sort.Sort(matrix, N, M);
	std::vector<std::vector<double>>* insertion_sort_result_matrix = insertion_sort.Sort(matrix, N, M);
	std::vector<std::vector<double>>* bubble_sort_result_matrix = bubble_sort.Sort(matrix, N, M);
	std::vector<std::vector<double>>* shell_sort_result_matrix = shell_sort.Sort(matrix, N, M);
	std::vector<std::vector<double>>* quick_sort_result_matrix = quick_sort.Sort(matrix, N, M);




	std::cout << "The original matrix:\n";
	Display(matrix, N, M);
	std::cout << "\n";
	std::cout << "\n";

	std::cout << "The selection sort matrix:\n";
	Display(selection_sort_result_matrix, N, M);
	std::cout << "\n";
	std::cout << "\n";

	std::cout << "The insertion sort matrix:\n";
	Display(insertion_sort_result_matrix, N, M);
	std::cout << "\n";
	std::cout << "\n";

	std::cout << "The bubble sort matrix:\n";
	Display(bubble_sort_result_matrix, N, M);
	std::cout << "\n";
	std::cout << "\n";

	std::cout << "The shell sort matrix:\n";
	Display(shell_sort_result_matrix, N, M);
	std::cout << "\n";
	std::cout << "\n";

	std::cout << "The quick sort matrix:\n";
	Display(quick_sort_result_matrix, N, M);
	std::cout << "\n";
	std::cout << "\n";



	std::cout << "Table\n";
	std::cout << "Sort type: \t   Amount of comparisons: \t         Amount of swaps:\n\n";
	std::cout << "Selection sort \t\t\t\t" << selection_sort.Get_comparison_counter() << "\t\t\t\t" << selection_sort.Get_swap_counter()<<"\n";
	std::cout << "insertion sort \t\t\t\t" << insertion_sort.Get_comparison_counter() << "\t\t\t\t" << insertion_sort.Get_swap_counter()<<"\n";
	std::cout << "Bubble sort \t\t\t\t"    << bubble_sort.Get_comparison_counter()    << "\t\t\t\t" << bubble_sort.Get_swap_counter()   <<"\n";
	std::cout << "Shell sort \t\t\t\t"     << shell_sort.Get_comparison_counter()     << "\t\t\t\t" << shell_sort.Get_swap_counter()    <<"\n";
	std::cout << "Quick sort \t\t\t\t"     << quick_sort.Get_comparison_counter()     << "\t\t\t\t" << quick_sort.Get_swap_counter()    <<"\n\n\n";



	std::cout << "Want to save the original matrix?\n 1 - yes\n 0 - no" << "\n";// ������ ����������� ������
	int option_of_save = 0;
	while (true) {
		option_of_save = int_Num_input();
		if (option_of_save == save || option_of_save == dontSave) {
			break;
		}
		std::cout << "Invalid input. Please enter a valid number." << "\n";
	}
	if (option_of_save == save) FileInput(*matrix, N, M);
	std::cout << "\n";



	std::cout << "Want to save the result?\n 1 - yes\n 0 - no" << "\n";
	int option_of_save_result = 0;
	while (true) {
		option_of_save_result = int_Num_input();
		if (option_of_save_result == save || option_of_save_result == dontSave) {
			break;
		}
		std::cout << "Invalid input. Please enter a valid number." << "\n";
	}
	if (option_of_save_result == save) {
		std::ofstream file;

		while (true) {

			std::cout << "please tape any filenameway" << "\n";
			std::string filename;
			std::cin >> filename;

			//открытие файла:
			if (OpenFile(filename, file)) {
				break;
			}
		}

		file << "original matrix:\n";
		for (size_t i = 0; i < N; i++) {
			for (size_t j = 0; j < M; j++) {
				file << (*matrix)[i][j] << "\t";
			}
			file << '\n';
		}

		file << "sorted matrix:\n";
		for (size_t i = 0; i < N; i++) {
			for (size_t j = 0; j < M; j++) {
				file << (*quick_sort_result_matrix)[i][j] << "\t";
			}
			file << '\n';
		}

		file << "Table\n";
		file << "Sort type: \t   Amount of comparisons: \t         Amount of swaps:\n\n";
		file << "Selection sort \t\t\t\t" << selection_sort.Get_comparison_counter() << "\t\t\t\t" << selection_sort.Get_swap_counter() << "\n";
		file << "insertion sort \t\t\t\t" << insertion_sort.Get_comparison_counter() << "\t\t\t\t" << insertion_sort.Get_swap_counter() << "\n";
		file << "Bubble sort \t\t\t\t" << bubble_sort.Get_comparison_counter() << "\t\t\t\t" << bubble_sort.Get_swap_counter() << "\n";
		file << "Shell sort \t\t\t\t" << shell_sort.Get_comparison_counter() << "\t\t\t\t" << shell_sort.Get_swap_counter() << "\n";
		file << "Quick sort \t\t\t\t" << quick_sort.Get_comparison_counter() << "\t\t\t\t" << quick_sort.Get_swap_counter() << "\n\n\n";
	}
	std::cout << "\n";



	delete selection_sort_result_matrix;
	delete insertion_sort_result_matrix;
	delete bubble_sort_result_matrix;
	delete shell_sort_result_matrix;
	delete quick_sort_result_matrix;
	delete matrix;
}

