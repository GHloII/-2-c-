#include <iostream>
#include <fstream>
#include <vector>
#include "PhoneUser.h"


bool FileIsEmpty(std::string filename) {
    std::ifstream file;
    file.open(filename);
    char end_of_file;
    if (file.is_open()) {
        file >> end_of_file;
        if (end_of_file == EOF) return 1;
        else return 0;
    }
    return 0;

}



bool OpenFile(std::string filename, std::ifstream& file) { // чтение

    // Попытаться открыть файл
    file.open(filename);
    if (file.is_open()) {
        std::cout << "File successfully opened" << "\n";
        return 1;
    }
    else {
        std::cout << "Failed to open the file." << "\n";
        return 0;
    }
}
bool OpenFile(std::string filename, std::ofstream& file) { //запись
    bool is_empty = FileIsEmpty(filename);
    // Попытаться открыть файл
    file.open(filename, std::ios::app);// для дозаписи
    if (file.is_open() && is_empty) {
        std::cout << "File successfully opened" << "\n";
        return 1;
    }
    if (file.is_open() && is_empty == 0) {
        std::cout << "File is not empty, failed to open the file. " << "\n";
        return 0;
    }
    else {
        std::cout << "Failed to open the file." << "\n";
        return 0;
    }
}

void FileInput(std::vector<PhoneUser>* save_book) {
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
    file << save_book->size() << "\n";
    for (PhoneUser& user : *save_book) {
        file << user.GetSecondName() << " " << user.GetName() << " " << user.GetAddress() << " " << user.GetPhoneNumber() << " " << user.GetTimeInnerCityCalls()
            << " " << user.GetTimeLongDistanceCalls() << "\n";
    }



    std::cout << "Data successfully written to the file." << std::endl;


    // Закрытие файла
    file.close();
}


void FileFilling(PhoneUser*& book, int& size_of_book) {
    std::ifstream file;

    while (true) {

        std::cout << "please tape any filenameway" << "\n";
        std::string filename;
        std::cin >> filename;

        //открытие файла:
        if (OpenFile(filename, file)) {
            break;
        }

    }

    file >> size_of_book;
    book = new PhoneUser[size_of_book];

    // Чтение данных из файла
    for (int i = 0; i < size_of_book; i++) { // заполнение
        string name;
        string second_name;
        int phone = 0;
        int inner_time = 0;
        int long_distance_time = 0;

        file >> second_name;
        file >> name;
        book[i].SetAddress(file);
        file.ignore(); // clear input buffer
        file >> phone;
        file >> inner_time;
        file >> long_distance_time;

        book[i].SetSecondName(second_name);
        book[i].SetName(name);
        book[i].SetPhoneNumber(phone);
        book[i].SetTimeInnerCityCalls(inner_time);
        book[i].SetTimeLongDistanceCalls(long_distance_time);
    }



    // Закрытие файла
    file.close();
}

void FileFilling(std::vector<PhoneUser>& book, std::string filename) {                    // для тестов
    std::ifstream file;

    file.open(filename);
    int size_of_book = 0;
    file >> size_of_book;
    book.resize(size_of_book);
    // Чтение данных из файла
    for (int i = 0; i < size_of_book; i++) { // заполнение
        string name;
        string second_name;
        int phone = 0;
        int inner_time = 0;
        int long_distance_time = 0;

        file >> second_name;
        file >> name;
        book[i].SetAddress(file);
        file.ignore(); // clear input buffer
        file >> phone;
        file >> inner_time;
        file >> long_distance_time;

        book[i].SetSecondName(second_name);
        book[i].SetName(name);
        book[i].SetPhoneNumber(phone);
        book[i].SetTimeInnerCityCalls(inner_time);
        book[i].SetTimeLongDistanceCalls(long_distance_time);
    }



    // Закрытие файла
    file.close();
}



