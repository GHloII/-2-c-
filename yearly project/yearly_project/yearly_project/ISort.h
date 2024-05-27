#pragma once
#include <vector>
#include <iostream>

class ISort {
protected:
    int swap_counter = 0;
    int comparison_counter = 0;

public:
    virtual std::vector<std::vector<double>>* Sort(std::vector<std::vector<double>>* matrix, int N, int M) = 0;

    int Get_swap_counter();
    int Get_comparison_counter();

    void Show_counters();
    void Reset_counters();

    virtual ~ISort();
};