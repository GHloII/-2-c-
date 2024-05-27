#pragma once

#include "ISort.h"
#include <vector>
#include <cmath>
#include <algorithm> // Äëÿ std::swap
#include "Function.h"


class QSort : public ISort {
public:
    std::vector<std::vector<double>>* Sort(std::vector<std::vector<double>>* matrix, int N, int M) override;

private:
    int Partition(std::vector<double>& array, int low, int high);
    void QuickSort(std::vector<double>& array, int low, int high);
};