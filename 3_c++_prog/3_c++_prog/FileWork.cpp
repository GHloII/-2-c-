#include <iostream>
#include <fstream>
#include <vector>

#include "Menu.h"



bool FileIsEmpty(std::string filename) {
    std::ifstream file;
    file.open(filename);
    char end_of_file;
    if (file.is_open()) {
        file >> end_of_file;
        file.close();
        if (end_of_file < 0) return true;
        else return false;
    }
    return false;

}




bool OpenFile(std::string filename, std::ifstream& file) { //чтение

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
bool OpenFile(std::string filename, std::ofstream& file) { // запись
    bool is_empty = FileIsEmpty(filename);
    file.open(filename, std::ios::app);// 
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



//void FileInput(std::unordered_map <std::string, Document*>& document_list) {
    std::ofstream file;

    while (true) {

        //std::cout << "please tape any filenameway" << "\n";
        std::string filename  = "./test.txt";
        //std::cin >> filename;

        //открытие файла:
        if (OpenFile(filename, file)) {
            break;
        }

    }
    // Запись данных в файл
    file << document_list.size() << "\n";
    for (auto& [name,document] : document_list) {
        file << document->GetType() << " " << document->GetName() <<  " " << document->GetDocumentFilename() << " " << dynamic_cast<Letter*>(document)->GetAddressee() << " " << dynamic_cast<Letter*>(document)->GetSender() << " \n";
            
    }


    //std::cout << "Data successfully written to the file." << std::endl;


    // Закрытие файла
    file.close();
}





