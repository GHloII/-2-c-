#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>

#include "Menu.h"
#include "NumInput.h"
#include "FileWork.h"
#include "ISort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "BubbleSort.h"
#include "ShellSort.h"
#include "QSort.h"


std::vector<std::vector<double>>* Transponding(std::vector<std::vector<double>>& matrix, int N, int M);

void Display(std::vector<std::vector<double>>* matrix, int& N, int& M);

void HandFilling(std::vector<std::vector<double>>& matrix, int& N, int& M);

void RandomFilling(std::vector<std::vector<double>>& matrix, int& N, int& M);

void Filling(int option, std::vector<std::vector<double>>*& matrix, int& N, int& M);

void Function();
void show_greeting();


