#include "InsertionSort.h"

std::vector<std::vector<double>>* InsertionSort::Sort(std::vector<std::vector<double>>* matrix, int N, int M) {
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

void InsertionSort::Selection_sort(std::vector<double>& array, int size) {
    for (size_t i = 0, j = 0; i < size - 1; ++i) {
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
