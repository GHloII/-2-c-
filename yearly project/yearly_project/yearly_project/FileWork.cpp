#include <iostream>
#include <fstream>
#include <vector>
#include <filesystem>
#include <cctype> 

namespace fs = std::filesystem;

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

bool OpenFile(std::string filename, std::ifstream& file) { // чтение
    std::error_code ec{};
    bool is_empty = FileIsEmpty(filename);

    // Попытаться открыть файл
    file.open(filename);
    if (!fs::is_regular_file(filename, ec)) {
        std::cout << "file path contains invalid values. Failed to open the file. " << "\n";
        return 0;
    }
    if (is_empty == 1) {
        std::cout << "File is empty, failed to open the file. " << "\n";
        return 0;
    }
    if (file.is_open() && is_empty == 0) {
        std::cout << "File successfully opened" << "\n";
        return 1;
    }

    else {
        std::cout << "Failed to open the file." << "\n";
        return 0;
    }
}
bool OpenFile(std::string filename, std::ofstream& file) { //запись
    std::error_code ec{};

    bool is_empty = FileIsEmpty(filename);
    // Попытаться открыть файл
    file.open(filename, std::ios::app);// для дозаписи
    if (file.is_open() && is_empty) {
        std::cout << "File successfully opened" << "\n";
        return 1;
    }
    if (!fs::is_regular_file(filename, ec)) {
        std::cout << "file path contains invalid values. Failed to open the file. " << "\n";
        return 0;
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

//void FileInput(std::vector<PhoneUser>* save_book) {
//    std::ofstream file;
//
//    while (true) {
//
//        std::cout << "please tape any filenameway" << "\n";
//        std::string filename;
//        std::cin >> filename;
//
//        //открытие файла:
//        if (OpenFile(filename, file)) {
//            break;
//        }
//
//    }
//    // Запись данных в файл
//    file << save_book->size() << "\n";
//    for (PhoneUser& user : *save_book) {
//        file << user.GetSecondName() << " " << user.GetName() << " " << user.GetAddress() << " " << user.GetPhoneNumber() << " " << user.GetTimeInnerCityCalls()
//            << " " << user.GetTimeLongDistanceCalls() << "\n";
//    }
//
//
//
//    std::cout << "Data successfully written to the file." << std::endl;
//
//
//    // Закрытие файла
//    file.close();
//}


void FileFilling(std::vector<std::vector<double>>*& matrix, int& N, int& M) {
    std::ifstream file;


    while (true) {

        bool error = false;

        while (true) {

            std::cout << "please tape any filenameway" << "\n";
            std::string filename;
            std::cin >> filename;

            //открытие файла:
            if (OpenFile(filename, file)) {
                break;
            }

        }

        std::vector<std::string> array_of_amount_of_rows_columns(2);

        for (size_t i = 0; i < 2 && std::getline(file, array_of_amount_of_rows_columns[i], ','); ++i) {}
        if (error) continue;

        size_t* idx1 = nullptr;
        size_t* idx2 = nullptr;
        N = std::stoi(array_of_amount_of_rows_columns[0], idx1);
        M = std::stoi(array_of_amount_of_rows_columns[1], idx2);
        if (idx1 != nullptr || idx2 != nullptr || array_of_amount_of_rows_columns[0] == "0" ||
            array_of_amount_of_rows_columns[0] == "" || array_of_amount_of_rows_columns[1] == "0" ||
            array_of_amount_of_rows_columns[1] == "") {

            std::cout << "invalid value, failed to record the file data\n";
            file.close();
            error = true;
            break;
        }
        if (error) continue;

        std::vector<std::string> string_matrix(M * N);
        for (int i = 0; i < N * M && std::getline(file, string_matrix[i], ','); ++i) {

            if (string_matrix[i] == "") {
                std::cout << "invalid value, failed to record the file data\n";
                file.close();
                error = true;
                break;
            }
        }
        if (error) continue;

        matrix = new std::vector<std::vector<double>>(N, std::vector<double>(M));
        size_t counter = 0;
        for (size_t i = 0; i < N; i++)
        {
            for (size_t j = 0; j < M; j++)
            {
                if (string_matrix[counter] == ""|| string_matrix[counter] == "\n") {
                    std::cout << "invalid value, failed to record the file data\n";
                    file.close();
                    error = true;
                    break;
                }
                if ( !isdigit(string_matrix[counter][0]) && string_matrix[counter][0] != '\n' ) {
                    std::cout << "invalid value, failed to record the file data\n";
                    matrix->clear();
                    file.close();
                    error = true;
                    break;
                }
                size_t* idx = nullptr;
                (*matrix)[i][j] = std::stod(string_matrix[counter], idx);

                if (idx != nullptr) {
                    std::cout << "invalid value, failed to record the file data\n";
                    file.close();
                    error = true;
                    break;
                }
                counter++;
            }
            if (error) break;
        }

        if (error) {
            (*matrix).clear();
            continue;
        }
        // Закрытие файла
        file.close();
        break;
    }
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



/*
0,0 один массив 

1,

1, 2

*/