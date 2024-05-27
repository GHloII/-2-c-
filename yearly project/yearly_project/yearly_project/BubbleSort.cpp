#include "BubbleSort.h"

std::vector<std::vector<double>>* BubbleSort::Sort(std::vector<std::vector<double>>* matrix, int N, int M) {
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

void BubbleSort::Bubble_sort(std::vector<double>& array, int size) {
    for (size_t i = 1; i < size; i++) {
        for (size_t j = 0; j < size - i; j++) {
            comparison_counter++;
            if (abs(array[j]) > abs(array[j + 1])) {
                swap_counter++;
                double t = array[j];
                array[j] = array[j + 1];
                array[j + 1] = t;
            }
        }
    }
}