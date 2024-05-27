#include <iostream>
#include <vector>
#include <ctime>

#include "Menu.h"
#include "NumInput.h"
#include "FileWork.h"
#include "ISort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "BubbleSort.h"
#include "ShellSort.h"
#include "QSort.h"


int main()
{
	setlocale(LC_CTYPE, "Russian");
	srand(time(NULL));
	int command = 0;

	std::cout << "Hello, Alexey Konstantinovich, Roman Valerievich and Ivan Grigorievich\n"
		<< "Author: Ivanov Gleb Igorevich\n"
		<< "group: 4303, 2024\n"
		<< "Project name: 2_c++_prog.cpp\n"
		<< "Task name: task 2 variant 13\n"

		<< "Task text:  Базовый класс – документ предприятия. Производный класс – письмо.\n";
	while (true) {

		std::cout << "begin - 1\ntest - 2 \nexit - 0\n";
		command =int_Num_input();
		//std::cout << "\n\n";

		if (command == start) {
			Function(/*start*/);
		}
		else if (command == test) {
			Function(/*test*/);
			std::cout << "\n\n";
		}
		else if (command == Exit) {


			std::cout << "prog has been finished";
			std::cout << "\n\n";
			break;

		}
		else {
			std::cout << "command not found" << "\n" << "\n";
		}
	}
}


/*
transponding matrix


3 2 
3 1 -72 0 2 3 



3 1
-72 0
2 3





	int N = 0; // количество строк i
	int M = 0; // количество столбцов j



	1 
	0 
	4 5 

	167 898 23 892 3 
	32 323 928 23 1 
	74897 34 23 432 4 
	0 32 43 5 9 




	1 
	1 
	test1.txt 
	




*/