#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include "Document.h"


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



bool OpenFile(std::string filename, std::ifstream& file) { // ������

    // ���������� ������� ����
    file.open(filename);
    if (file.is_open()) {
        //std::cout << "File successfully opened" << "\n";
        return 1;
    }
    else {
        std::cout << "Failed to open the file." << "\n";
        return 0;
    }
}
bool OpenFile(std::string filename, std::ofstream& file) { //������
    bool is_empty = FileIsEmpty(filename);
    // ���������� ������� ����
    file.open(filename, std::ios::out);// ��� ������ ������ ���������
    if (file.is_open() && is_empty) {
        //std::cout << "File successfully opened" << "\n";
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

        //�������� �����:
        if (OpenFile(filename, file)) {
            break;
        }

    }
    // ������ ������ � ����
    file << save_book->size() << "\n";
    for (PhoneUser& user : *save_book) {
        file << user.GetSecondName() << " " << user.GetName() << " " << user.GetAddress() << " " << user.GetPhoneNumber() << " " << user.GetTimeInnerCityCalls()
            << " " << user.GetTimeLongDistanceCalls() << "\n";
    }



    std::cout << "Data successfully written to the file." << std::endl;


    // �������� �����
    file.close();
}


void FileFilling(std::unordered_map <std::string,Document*> &document_list, size_t& size_of_book) {
    std::ifstream file;

    while (true) {

        std::string filename = "./test.txt";
        //std::cout << "please tape any filenameway" << "\n";
        //std::cin >> filename;

        //�������� �����:
        if (OpenFile(filename, file)) {
            break;
        }

    }

    file >> size_of_book;

    // ������ ������ �� �����
    for (int i = 0; i < size_of_book; i++) { // ����������

        std::string type;
        std::string name;
        std::string document_filename;


        file >> type;
        file >> name;
        file >> document_filename;
        file.ignore(); // clear input buffer
        //������� ����� ��� ������ ����� 

        if (type == "letter") {
            auto* document = new Letter;
            std::string addressee; //����������
            std::string sender;
            std::cin >> addressee;
            std::cin >> sender;
            document->SetSender(sender);
            document->SetAddressee(addressee);
            document->SetDocumentFilename(document_filename);
            document->SetName(name);
            document->SetType(type);
            document_list.insert({ name, document });
        }


    }



    // �������� �����
    file.close();
}

void FileFilling(std::vector<PhoneUser>& book, std::string filename) {                    // ��� ������
    std::ifstream file;

    file.open(filename);
    int size_of_book = 0;
    file >> size_of_book;
    book.resize(size_of_book);
    // ������ ������ �� �����
    for (int i = 0; i < size_of_book; i++) { // ����������
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



    // �������� �����
    file.close();
}



