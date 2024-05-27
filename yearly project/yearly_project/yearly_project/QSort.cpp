#include "QSort.h"

std::vector<std::vector<double>>* QSort::Sort(std::vector<std::vector<double>>* matrix, int N, int M) {
    std::vector<std::vector<double>>* trans_matrix_ptr = Transponding(*matrix, N, M);
    std::vector<std::vector<double>>& trans_matrix = *trans_matrix_ptr;
    int t = N;
    N = M;
    M = t;
    for (int i = 0; i < N; ++i) {
        QuickSort(trans_matrix[i], 0, M - 1);
    }
    std::vector<std::vector<double>>* result_matrix_ptr = Transponding(trans_matrix, N, M);

    delete trans_matrix_ptr;
    return result_matrix_ptr;
}

int QSort::Partition(std::vector<double>& array, int low, int high) {
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

void QSort::QuickSort(std::vector<double>& array, int low, int high) {
    if (low < high) {
        int pi = Partition(array, low, high);
        QuickSort(array, low, pi - 1);
        QuickSort(array, pi + 1, high);
    }
}
