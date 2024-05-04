#include <iostream>
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <set>
#include <fstream>


#include "NumInput.h"
#include "Document.h"
#include "Letter.h"
#include "FileWork.h"
#include "Functions.h"
#include "Menu.h"



int main()
{
	setlocale(LC_CTYPE, "Russian");
	int command = 0;

	std::cout << "Hello, Alexey Konstantinovich, Roman Valerievich and Ivan Grigorievich\n"
		<< "Author: Ivanov Gleb Igorevich\n"
		<< "group: 4303, 2023\n"
		<< "Project name: 2_c++_prog.cpp\n"
		<< "Task name: task 2 variant 13\n"

		<< "Task text:  Базовый класс – документ предприятия. Производный класс – письмо.\n";
	while (true) {

		std::cout << "begin - 1\ntest - 2 \nexit - 0\n";
		command = static_cast<int>(Num_input());
		//std::cout << "\n\n";

		if (command == start) {
			Function(start);
		}
		else if (command == test) {
			Function(test);
			std::cout << "\n\n";
		}
		else if (command == exit) {


			std::cout << "prog has been finished";
			std::cout << "\n\n";
			break;

		}
		else {
			std::cout << "command not found" << "\n" << "\n";
		}
	}
}
