#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include "Document.h"
#include "Letter.h"



bool FileIsEmpty(std::string filename) {
    std::ifstream file;
    file.open(filename);
    char end_of_file;
    if (file.is_open()) {
        file >> end_of_file;
        file.close();
        if (end_of_file <0) return 1;
        else return 0;
    }
    return 0;

}



bool OpenFile(std::string filename, std::ofstream& file) { // запись 

    // Попытаться открыть файл
    file.open(filename, std::ios::out);// для старые данные удаляются
    if (file.is_open()) {
        //std::cout << "File successfully opened" << "\n";
        return 1;
    }
    else {
        std::cout << "Failed to open the file." << "\n";
        return 0;
    }
}
uint16_t OpenFile(std::string filename, std::ifstream& file) { //чтение
    bool is_empty = FileIsEmpty(filename);
    // Попытаться открыть файл
    file.open(filename);
    if (file.is_open() && is_empty) {
       // std::cout << "File is not empty, failed to open the file. " << "\n";
        return 2;
    }
    if (file.is_open()) {
        //std::cout << "File successfully opened" << "\n";
        return 1;
    }
    else {
        std::cout << "Failed to open the file." << "\n";
        return 0;
    }
}




void FileInput(std::unordered_map <std::string, Document*>& document_list) {
    std::ofstream file;

    while (true) {

        std::cout << "please tape any filenameway" << "\n";
        std::string filename;
        std::cin >> filename;

        //открытие файла:
        if (OpenFile(filename, file)) {
            break;
        }

    }
    // Запись данных в файл
    file << document_list.size() << "\n";
    for (auto& [name,document] : document_list) {
        file << document->GetType() << " " << document->GetName() << " " << document->GetDocumentFilename() << " " << document->GetDocumentFilename() << " " << dynamic_cast<Letter*>(document)->GetAddressee() << " " << dynamic_cast<Letter*>(document)->GetSender();
            
    }


    std::cout << "Data successfully written to the file." << std::endl;


    // Закрытие файла
    file.close();
}


void FileFilling(std::unordered_map <std::string,Document*> &document_list, size_t& size_of_book) {
    std::ifstream file;
    uint16_t file_is_open =0;

    while (true) {

        std::string filename = "./test.txt";
        //std::cout << "please tape any filenameway" << "\n";
        //std::cin >> filename;

        //открытие файла:
        file_is_open = OpenFile(filename, file);
        if (file_is_open) {
            break;
        }

    }
    if (file_is_open == 2) {
        size_of_book = 0;
    }
    else file >> size_of_book;
    

    // Чтение данных из файла
    for (int i = 0; i < size_of_book; i++) { // заполнение

        std::string type;
        std::string name;
        std::string document_filename;


        file >> type;
        file >> name;
        file >> document_filename;
        file.ignore(); // clear input buffer
        //сделать выбор для разных типов 

        if (type == "letter") {
            auto* document = new Letter;
            std::string addressee; //получатель
            std::string sender;
            file >> addressee;
            file >> sender;
            document->SetSender(sender);
            document->SetAddressee(addressee);
            document->SetDocumentFilename(document_filename);
            document->SetName(name);
            document->SetType(type);
            document_list.insert({ name, document });
        }


    }



    // Закрытие файла
    file.close();
}

//void FileFilling(std::vector<PhoneUser>& book, std::string filename) {                    // для тестов
//    std::ifstream file;
//
//    file.open(filename);
//    int size_of_book = 0;
//    file >> size_of_book;
//    book.resize(size_of_book);
//    // Чтение данных из файла
//    for (int i = 0; i < size_of_book; i++) { // заполнение
//        string name;
//        string second_name;
//        int phone = 0;
//        int inner_time = 0;
//        int long_distance_time = 0;
//
//        file >> second_name;
//        file >> name;
//        book[i].SetAddress(file);
//        file.ignore(); // clear input buffer
//        file >> phone;
//        file >> inner_time;
//        file >> long_distance_time;
//
//        book[i].SetSecondName(second_name);
//        book[i].SetName(name);
//        book[i].SetPhoneNumber(phone);
//        book[i].SetTimeInnerCityCalls(inner_time);
//        book[i].SetTimeLongDistanceCalls(long_distance_time);
//    }
//
//
//
//    // Закрытие файла
//    file.close();
//}



