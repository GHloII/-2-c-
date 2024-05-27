#include <iostream>
#include <vector>

#include "Menu.h"
#include "NumInput.h"
#include "FileWork.h"

class ISort {

protected:

	int swap_counter = 0;
	int comparison_counter = 0;

public:

	virtual std::vector<std::vector<double>>* Sort(std::vector<std::vector<double>>* matrix, int N, int M) = 0;

	int Get_swap_counter() { return swap_counter; }
	int Get_comparison_counter() { return comparison_counter; }

	void Show_counters() {
		std::cout << "Swaps: " << swap_counter << "\n";
		std::cout << "Comparison: " << comparison_counter << "\n";
	}

	void Reset_counters() {
		swap_counter = 0;
		comparison_counter = 0;
	}


	virtual ~ISort() = default;

};



std::vector<std::vector<double>>* Transponding(std::vector<std::vector<double>>& matrix, int N, int M) {

	//std::vector<std::vector<double>> trans_matrix(M, std::vector<double>(N));
	auto * trans_matrix = new std::vector<std::vector<double>>(M, std::vector<double>(N));

	for (size_t i = 0; i < M; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			(*trans_matrix)[i][j] = matrix[j][i];
		}
	}
	return trans_matrix;

}

void Display(std::vector<std::vector<double>>* matrix, int& N, int& M) {
	std::vector<std::vector<double>> matrix_display = *matrix;
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			std::cout << matrix_display[i][j] << "\t";
		}
		std::cout << "\n";
	}
}

//сортировка выбором
class SelectionSort : public ISort {
public:
	std::vector<std::vector<double>>* Sort(std::vector<std::vector<double>>* matrix,int N,int M) override {
		std::vector<std::vector<double>>* trans_matrix_ptr = Transponding(*matrix, N, M);
		std::vector<std::vector<double>>& trans_matrix = *trans_matrix_ptr;
		int t = N;
		N = M;
		M = t;
		for (int i = 0; i < N; ++i) {
			Selection_sort(trans_matrix[i], M);
		}
		std::vector<std::vector<double>>* result_matrix_ptr = Transponding(trans_matrix, N, M);

		delete trans_matrix_ptr;
		return result_matrix_ptr;
	}
private:

	void Selection_sort(std::vector<double>& array, int size) {
		for (size_t i = 0; i < size; i++) {
			for (size_t j = i + 1; j < size; j++) {
				comparison_counter++;
				if (abs(array[j]) < abs(array[i])) {
					swap_counter++;
					double t = array[i];
					array[i] = array[j];
					array[j] = t;
				}
			}
		}
	}

};

//сортировка вставками
class InsertionSort : public ISort {

public:
	std::vector<std::vector<double>>* Sort(std::vector<std::vector<double>>* matrix, int N, int M) override {
		std::vector<std::vector<double>>* trans_matrix_ptr = Transponding(*matrix, N, M);
		std::vector<std::vector<double>>& trans_matrix = *trans_matrix_ptr;
		int t = N;
		N = M;
		M = t;
		for (int i = 0; i < N; ++i) {
			Selection_sort(trans_matrix[i], M);
		}
		std::vector<std::vector<double>>* result_matrix_ptr = Transponding(trans_matrix, N, M);

		delete trans_matrix_ptr;
		return result_matrix_ptr;
	}
private:

	void Selection_sort(std::vector<double>& array, int size) {
		for (size_t i = 0,j=0; i < size-1; ++i) {
			 j = i + 1;
			while ((j > 0) && (comparison_counter++, std::abs(array[j - 1]) > std::abs(array[j]))) {
				double t = array[j - 1];
				array[j - 1] = array[j];
				array[j] = t;
				j = j - 1;
				swap_counter++;
			}
		}
	}


};

//сортировка пузырьком
class BubbleSort : public ISort {

public:
	std::vector<std::vector<double>>* Sort(std::vector<std::vector<double>>* matrix, int N, int M) override {
		std::vector<std::vector<double>>* trans_matrix_ptr = Transponding(*matrix, N, M);
		std::vector<std::vector<double>>& trans_matrix = *trans_matrix_ptr;
		int t = N;
		N = M;
		M = t;
		for (int i = 0; i < N; ++i) {
			Bubble_sort(trans_matrix[i], M);
		}
		std::vector<std::vector<double>>* result_matrix_ptr = Transponding(trans_matrix, N, M);

		delete trans_matrix_ptr;
		return result_matrix_ptr;
	}
private:

	void Bubble_sort(std::vector<double>& array, int size) {
		for (size_t i = 1; i < size; i++) {
			for (size_t j = 0; j < size-i; j++) {
				comparison_counter++;
				if ( abs(array[j]) > abs(array[j+1]) ) {
					swap_counter++;
					double t = array[j];
					array[j] = array[j+1];
					array[j+1] = t;
				}
			}
		}
	}


};

//сортировка Шелла
class ShellSort : public ISort {

public:
	std::vector<std::vector<double>>* Sort(std::vector<std::vector<double>>* matrix, int N, int M) override {
		std::vector<std::vector<double>>* trans_matrix_ptr = Transponding(*matrix, N, M);
		std::vector<std::vector<double>>& trans_matrix = *trans_matrix_ptr;
		int t = N;
		N = M;
		M = t;
		for (int i = 0; i < N; ++i) {
			Shell_sort(trans_matrix[i], M);
		}
		std::vector<std::vector<double>>* result_matrix_ptr = Transponding(trans_matrix, N, M);

		delete trans_matrix_ptr;
		return result_matrix_ptr;
	}
private:

	void Shell_sort(std::vector<double>& array, int size) {
		for (size_t gap = size / 2; gap > 0; gap = gap / 2) {
			for (size_t i = gap; i < size; ++i) {
				for (size_t j = i; j >= gap; j -= gap) {

					comparison_counter++;
					if (abs(array[j - gap]) <= abs(array[j])) break;

					std::swap(array[j - gap], array[j]);
					swap_counter++;
				}
			}
		}
	}


};

//быстрая сортировка
class QSort : public ISort {

public:
	std::vector<std::vector<double>>* Sort(std::vector<std::vector<double>>* matrix, int N, int M) override {
		std::vector<std::vector<double>>* trans_matrix_ptr = Transponding(*matrix, N, M);
		std::vector<std::vector<double>>& trans_matrix = *trans_matrix_ptr;
		int t = N;
		N = M;
		M = t;
		for (int i = 0; i < N; ++i) {
			QuickSort(trans_matrix[i],0, M-1);
		}
		std::vector<std::vector<double>>* result_matrix_ptr = Transponding(trans_matrix, N, M);

		delete trans_matrix_ptr;
		return result_matrix_ptr;
	}
private:


	int Partition(std::vector<double>& array, int low, int high) {

		double pivot = array[high];
		int i = low - 1;

		for (int j = low; j <= high - 1; j++) {
			comparison_counter++;

			if (abs(array[j]) < abs(pivot)) {

				i++;
				swap_counter++;
				std::swap(array[i], array[j]);
			}
		}

		swap_counter++;
		std::swap(array[i + 1], array[high]);

		return i + 1;
	}

	void QuickSort(std::vector<double>& array, int low, int high) {

		if (low < high) {

			int pi = Partition(array, low, high);

			QuickSort(array, low, pi - 1);
			QuickSort(array, pi + 1, high);
		}
	}


};



void HandFilling(std::vector<std::vector<double>>& matrix, int& N, int& M) {
	size_t size = N * M;
	std::cout << "enter "<< size <<"numbers" << "\n";
	for(size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			double temp = double_Num_input();
			(matrix[i][j]) = temp;
		}
	}
	std::cout << "\n" << "\n" << "\n";

}

void Filling(bool option, std::vector<std::vector<double>> *&matrix, int& N, int& M) {
	if (option == file_filling) {
		FileFilling(matrix, N, M);
	}
	else {
		HandFilling(*matrix, N, M);
	}
}



void Function() {
	int N = 0; // количество строк i
	int M = 0; // количество столбцов j
	std::vector<std::vector<double>> *matrix = nullptr;

	std::cout << "type a option of filling " << "\n"
		"2 - random 1 - file 0 - hand" << "\n";

	int option_of_filling = hand_filling;
	while (true) {
		option_of_filling = int_Num_input();
		if (option_of_filling == file_filling || option_of_filling == hand_filling || option_of_filling == random_filling) {
			break;
		}
		std::cout << "Invalid input. Please enter a valid number." << "\n";
	}


	if (option_of_filling == hand_filling) {

		std::cout << "enter the number of rows and the number of columns " << "\n";
		N = int_Num_input();
		M = int_Num_input();
		matrix = new std::vector<std::vector<double>> (N, std::vector<double>(M));
	}

	Filling(option_of_filling, matrix, N,M); 

	std::cout << "do you want to save the result?\n 1 - yes\n 0 - no" << "\n";// ������ ����������� ������
	int option_of_save = 0;
	while (true) {
		option_of_save = int_Num_input();
		if (option_of_save == save || option_of_save == dontSave) {
			break;
		}
		std::cout << "Invalid input. Please enter a valid number." << "\n";
	}
	std::cout << "\n";

	//далее выполнение то есть создание резалт матиц для всех сортировок и приравнивание их к сорту далее придумать как их дисплеить

	SelectionSort  selection_sort;
	InsertionSort  insertion_sort;
	BubbleSort	   bubble_sort;
	ShellSort	   shell_sort;
	QSort		   quick_sort;


	std::vector<std::vector<double>> *selection_sort_result_matrix = selection_sort.Sort(matrix, N, M);
	std::vector<std::vector<double>> *insertion_sort_result_matrix = insertion_sort.Sort(matrix, N, M);
	std::vector<std::vector<double>> *bubble_sort_result_matrix    = bubble_sort.Sort(matrix, N, M);
	std::vector<std::vector<double>> *shell_sort_result_matrix     = shell_sort.Sort(matrix, N, M);
	std::vector<std::vector<double>> *quick_sort_result_matrix     = quick_sort.Sort(matrix, N, M);




	std::cout << "The original matrix:\n";
	Display(matrix, N, M);
	std::cout << "\n";

	std::cout << "The selection sort matrix:\n";
	Display(selection_sort_result_matrix, N, M);
	selection_sort.Show_counters();
	std::cout << "\n";

	std::cout << "The insertion sort matrix:\n";
	Display(insertion_sort_result_matrix, N, M);
	insertion_sort.Show_counters();
	std::cout << "\n";

	std::cout << "The bubble sort matrix:\n";
	Display(bubble_sort_result_matrix   , N, M);
	bubble_sort.Show_counters();
	std::cout << "\n";

	std::cout << "The shell sort matrix:\n";
	Display(shell_sort_result_matrix    , N, M);
	shell_sort.Show_counters();
	std::cout << "\n";

	std::cout << "The quick sort matrix:\n";
	Display(quick_sort_result_matrix    , N, M);
	quick_sort.Show_counters();
	std::cout << "\n";




	
	delete selection_sort_result_matrix;
	delete insertion_sort_result_matrix;
	delete bubble_sort_result_matrix; 
	delete shell_sort_result_matrix;    
	delete quick_sort_result_matrix;
	delete matrix;
}








int main()
{
	setlocale(LC_CTYPE, "Russian");
	int command = 0;

	std::cout << "Hello, Alexey Konstantinovich, Roman Valerievich and Ivan Grigorievich\n"
		<< "Author: Ivanov Gleb Igorevich\n"
		<< "group: 4303, 2024\n"
		<< "Project name: 2_c++_prog.cpp\n"
		<< "Task name: task 2 variant 13\n"

		<< "Task text:  Базовый класс – документ предприятия. Производный класс – письмо.\n";
	while (true) {

		std::cout << "begin - 1\ntest - 2 \nexit - 0\n";
		command =int_Num_input();
		//std::cout << "\n\n";

		if (command == start) {
			Function(/*start*/);
		}
		else if (command == test) {
			Function(/*test*/);
			std::cout << "\n\n";
		}
		else if (command == Exit) {


			std::cout << "prog has been finished";
			std::cout << "\n\n";
			break;

		}
		else {
			std::cout << "command not found" << "\n" << "\n";
		}
	}
}


/*
transponding matrix
возможно сделать свап в исорте шаблонами

3 2 
3 1 -72 0 2 3 



3 1
-72 0
2 3













	int N = 0; // количество строк i
	int M = 0; // количество столбцов j

	std::cout << "введите количество строк и количество столбцов\n";
	std::cin >> N >> M;
	std::vector<std::vector<double>> matrix(N, std::vector<double>(M));

	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			std::cin >> matrix[i][j];
		}
	}

	QSort sort;
	std::vector<std::vector<double>> result_matrix = *(sort.Sort(matrix, N, M));
	sort.Show_counters();

	std::cout << "\n";
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			std::cout << result_matrix[i][j]<<" ";
		}
		std::cout << "\n";

	}




	1 
	0 
	4 5 

	167 898 23 892 3 
	32 323 928 23 1 
	74897 34 23 432 4 
	0 32 43 5 9 




	1 
	1 
	test.txt 
	0 




*/