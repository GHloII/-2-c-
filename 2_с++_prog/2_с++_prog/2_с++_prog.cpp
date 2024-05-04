﻿#include <iostream>
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <set>
#include <fstream>


#include "NumInput.h"
#include "Document.h"
#include "Letter.h"
#include "FileWork.h"




Document* FindDocumentByName(std::unordered_map <std::string, Document*>& document_list,std::string name) {
	if (document_list.empty()) return nullptr;
	else if (!document_list.contains(name)) return nullptr;
	else if (document_list.contains(name)) return document_list[name];
}

void DeleteDocument(std::unordered_map <std::string, Document*>& document_list, std::string name) {
	document_list.erase(name);
}

void AddDocument(std::unordered_map <std::string, Document*>& document_list) {
	std::cout << "example: type (letter) \"name\" filename ....." << "\n";

		std::string type;
		std::string name;
		std::string filename;

		while (true) {
		std::cin >> type;
			if (type == "letter" /* || type == dontSave*/) {
				break;
			}
			std::cout << "Invalid input. Please enter a valid type." << "\n";
			std::cin.ignore();
		}
		std::cout << "\n";

		std::cin >> name;
		std::cin >> filename;

		//сделать выбор для разных типов 
		if (type == "letter") {
			auto* document = new Letter;
			std::cout << "example continue:  addressee, sender\n ";
			std::string addressee; //получатель
			std::string sender;
			std::cin >> addressee;
			std::cin >> sender;
			document->SetSender(sender);
			document->SetAddressee(addressee);
			document->SetDocumentFilename(filename);
			document->SetName(name);
			document->SetType(type);
			document_list.insert({ name, document });
		}
		
		
		

	std::cout << "\n" << "\n";
}

void DisplayAll(std::unordered_map <std::string, Document*>& document_list) {
	for (const auto& [name, document] : document_list) {
		document->Display();
	}
}


void Test1() {
	std::string filename_for_test = "./test1";
	std::ifstream file;
	if (OpenFile(filename_for_test, file) == 0) { // н открываеится
		std::cout << "test1 successfull\n";
		file.close();
	}
}

void Test2() {
	std::string filename_for_test = "./test2.txt"; //пустой
	std::ifstream file;
	if (OpenFile(filename_for_test, file) == 2) {
		std::cout << "test2 successfull\n";
		file.close();
	}
}  

void Test3() {
	std::string filename_for_test = "./test3.txt";
	std::ifstream file;
	if (OpenFile(filename_for_test, file) == 1) {
		std::cout << "test3 successfull\n";
		file.close();
	}
}

void Test4() {
	std::unordered_map <std::string, Document*> document_list;
	size_t size;
	std::string filename_for_test = "./test4.txt";

	// написать filefilllingh с filename
	FileFilling(document_list, size, filename_for_test);
	Document* document = FindDocumentByName(document_list, "Nos");//добавить имя
	if (document == nullptr) {
		std::cout << "test4 successfull\n";
	}
}

void Test5() {
	std::unordered_map <std::string, Document*> document_list;
	size_t size;
	std::string filename_for_test = "./test5.txt";

	// написать filefilllingh с filename
	FileFilling(document_list, size, filename_for_test);
	Document* document = FindDocumentByName(document_list, "KIngdomCome");
	if (document != nullptr) {
		std::cout << "test5 successfull\n";
	}
}


void Function(uint16_t option) {
	// запускается программа
	// открывается база данных
	// можно вывести базу или добавить элемент или удалить
	// или поиск по имени
	std::unordered_map <std::string, Document*> document_list;
	size_t size;
	
	FileFilling(document_list, size); // база данных записалась

	if (option == 1) { //обычное 
		while (true) {


			int option_of_function = 0;
			std::cout << "\n";
			std::cout << "type a option of function\n Display all - 1\n Add document - 2\n Delete document - 3\n Find and display document - 4\n exit - 0" << "\n";
			while (true) { 
				option_of_function = static_cast<int>(Num_input());
				if (option_of_function == 1) {//Display all
					break;
				}
				else if (option_of_function == 2) {// Add document
					break;
				}
				else if (option_of_function == 3) {// Delete document
					break;
				}
				else if (option_of_function == 4) {// Find and display document
					break;
				}
				else if (option_of_function == 0) {// exit
					break;
				}
				else {
					std::cout << "Invalid input. Please enter a valid command." << "\n";
				}
			}


			switch (option_of_function) {
			case 1:
				DisplayAll(document_list);
				break;

			case 2:
				AddDocument(document_list);
				break;

			case 3:
				{
				std::cout << "type a name to delete" << "\n";
				std::string name;
				std::cin >> name;
				if (FindDocumentByName(document_list, name) == nullptr) {
					std::cout << "there is not document with this name\n";
					break;
				}
				DeleteDocument(document_list, name);
				}
				break;

			case 4:
				{
				std::cout << "type a name to find" << "\n";
				std::string name;
				std::cin >> name;
				if (FindDocumentByName(document_list, name) == nullptr) {
					std::cout << "there is not document with this name\n";
					break;
				}
				Document* document = FindDocumentByName(document_list, name);
				document->Display();
				}
				break;
			}
			std::cout << "\n";

		}


	}
	
	else if (option == 2) {
		Test1();
		Test2();
		Test3();
		Test4();
		Test5();
	}



}


int main()
{
	setlocale(LC_CTYPE, "Russian");
	int command = 0;

	//std::cout << "Hello, Alexey Konstantinovich, Roman Valerievich and Ivan Grigorievich\n"
	//	<< "Author: Ivanov Gleb Igorevich\n"
	//	<< "group: 4303, 2023\n"
	//	<< "Project name: 1_c++_prog.cpp\n"
	//	<< "Task name: task 1 variant 13\n"
	//	<< "Task text: Абонент: фамилия, имя, отчество, адрес, номер телефона, время внутригородских разговоров, время междугородних разговоров.\nСоздать массив объектов. Реализовать возможность получения:\nсписка абонентов, время внутригородских разговоров которых\nпревышает заданное,\nсписка абонентов, воспользовавшихся междугородней связью,\nсписка абонентов, выведенных в алфавитном порядке.\n\n";
	while (true) {

		std::cout << "begin - 1\ntest - 2 \nexit - 0\n";
		command = static_cast<int>(Num_input());
		//std::cout << "\n\n";

		if (command == 1) {
			Function(1);
		}
		else if (command == 2) {
			Function(2);
			std::cout << "\n\n";
		}
		else if (command == 0) {


			std::cout << "prog has been finished";
			std::cout << "\n\n";
			break;

		}
		else {
			std::cout << "command not found" << "\n" << "\n";
		}
	}
}
