#pragma once

#include "ISort.h"
#include <vector>
#include <cmath>
#include <algorithm> // Äëÿ std::swap
#include "Function.h"


class ShellSort : public ISort {
public:
    std::vector<std::vector<double>>* Sort(std::vector<std::vector<double>>* matrix, int N, int M) override;

private:
    void Shell_sort(std::vector<double>& array, int size);
};