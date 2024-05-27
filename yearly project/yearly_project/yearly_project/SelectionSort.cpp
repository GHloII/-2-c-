#include "SelectionSort.h"


std::vector<std::vector<double>>* SelectionSort::Sort(std::vector<std::vector<double>>* matrix, int N, int M) {
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

void SelectionSort::Selection_sort(std::vector<double>& array, int size) {
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
