#include "ShellSort.h"

std::vector<std::vector<double>>* ShellSort::Sort(std::vector<std::vector<double>>* matrix, int N, int M) {
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

void ShellSort::Shell_sort(std::vector<double>& array, int size) {
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