#include "ISort.h"

int ISort::Get_swap_counter() {
    return swap_counter;
}

int ISort::Get_comparison_counter() {
    return comparison_counter;
}

void ISort::Show_counters() {
    std::cout << "Swaps: " << swap_counter << "\n";
    std::cout << "Comparison: " << comparison_counter << "\n";
}

void ISort::Reset_counters() {
    swap_counter = 0;
    comparison_counter = 0;
}

 ISort::~ISort() {
     Reset_counters();
}