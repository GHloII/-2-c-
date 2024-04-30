#include <iostream>
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <set>

#include "NumInput.h"
#include "Document.h"
#include "FileWork.h"


class Letter:public Document {
public:
	void SetAddressee(std::string addressee) {
		addressee_ = addressee;
	}
	void SetSender(std::string sender){
		sender_ = sender;
		}
	auto GetAddressee(){
		return addressee_;
		}
	auto GetSender(){
		return sender_;
		}
	void Display() override {
		std::cout << type_ << " "  << name_<< " " << document_filename_ << " " << addressee_ << " " << sender_ << " ";
	}
private:

	std::string addressee_; //получатель
	std::string sender_; //отправитель

};




Document* FindDocumentByName(std::unordered_map <std::string, Document*>& document_list,std::string name) {
	if (document_list.empty()) return nullptr;
	else if (!document_list.contains(name)) return nullptr;
	else if (document_list.contains(name)) return document_list[name];
}

void DeleteDocument(std::unordered_map <std::string, Document*>& document_list, std::string name) {
	document_list.erase(name);
}

void AddDocument(std::unordered_map <std::string, Document*>& document_list) {
	std::cout << "example: type \"name\" filename" << "\n";

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








		}


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

		std::cout << "begin - 1\ntest - 2 \nexit - 0\n\n";
		command = static_cast<int>(Num_input());
		std::cout << "\n\n";

		if (command == 1) {

			Function();




		}
		else if (command == 2) {

			//Test();
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
