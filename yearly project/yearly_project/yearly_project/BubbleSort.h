#pragma once

#include "ISort.h"
#include <vector>
#include <cmath>
#include "Function.h"


class BubbleSort : public ISort {
public:
    std::vector<std::vector<double>>* Sort(std::vector<std::vector<double>>* matrix, int N, int M) override;

private:
    void Bubble_sort(std::vector<double>& array, int size);
};