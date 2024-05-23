#include <iostream>
#include <vector>


class ISort {

protected:

	int swap_counter = 0;
	int comparison_counter = 0;

public:

	virtual std::vector<std::vector<double>>* Sort(std::vector<std::vector<double>>& matrix, int N, int M) = 0;

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

	//дисплей
	/*for (size_t i = 0; i < M; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			std::cout << trans_matrix[i][j] << " ";
		}
		std::cout << "\n";

	}*/
}


//сортировка выбором
class SelectionSort : public ISort {
public:
	std::vector<std::vector<double>>* Sort(std::vector<std::vector<double>>& matrix,int N,int M) override {
		std::vector<std::vector<double>>* trans_matrix_ptr = Transponding(matrix, N, M);
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
	std::vector<std::vector<double>>* Sort(std::vector<std::vector<double>>& matrix, int N, int M) override {
		std::vector<std::vector<double>>* trans_matrix_ptr = Transponding(matrix, N, M);
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
	std::vector<std::vector<double>>* Sort(std::vector<std::vector<double>>& matrix, int N, int M) override {
		std::vector<std::vector<double>>* trans_matrix_ptr = Transponding(matrix, N, M);
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
	std::vector<std::vector<double>>* Sort(std::vector<std::vector<double>>& matrix, int N, int M) override {
		std::vector<std::vector<double>>* trans_matrix_ptr = Transponding(matrix, N, M);
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
				double temp = array[i];
				size_t j = 0;
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
	std::vector<std::vector<double>>* Sort(std::vector<std::vector<double>>& matrix, int N, int M) override {
		std::vector<std::vector<double>>* trans_matrix_ptr = Transponding(matrix, N, M);
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













int main() {

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
}


/*
transponding matrix
возможно сделать свап в исорте шаблонами

3 2 
3 1 -72 0 2 3 



3 1
-72 0
2 3







*/