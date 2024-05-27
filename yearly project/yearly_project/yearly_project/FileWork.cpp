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
        //std::cout << "File successfully opened" << "\n";
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
                std::cout << "File successfully opened" << "\n";
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



bool TestFileFilling(std::vector<std::vector<double>>*& matrix, int& N, int& M,std::string filename) {
    std::ifstream file;

        bool error = false;

        while (true) {

            //std::cout << "please tape any filenameway" << "\n";
            //std::string filename;
            //std::cin >> filename;

            //открытие файла:
            if (OpenFile(filename, file)) {
                break;
            }

        }

        std::vector<std::string> array_of_amount_of_rows_columns(2);

        for (size_t i = 0; i < 2 && std::getline(file, array_of_amount_of_rows_columns[i], ','); ++i) {}
        if (error) return !error;

        size_t* idx1 = nullptr;
        size_t* idx2 = nullptr;
        N = std::stoi(array_of_amount_of_rows_columns[0], idx1);
        M = std::stoi(array_of_amount_of_rows_columns[1], idx2);
        if (idx1 != nullptr || idx2 != nullptr || array_of_amount_of_rows_columns[0] == "0" ||
            array_of_amount_of_rows_columns[0] == "" || array_of_amount_of_rows_columns[1] == "0" ||
            array_of_amount_of_rows_columns[1] == "") {

            //std::cout << "invalid value, failed to record the file data\n";
            file.close();
            error = true;
            
        }
        if (error) return !error;

        std::vector<std::string> string_matrix(M * N);
        for (int i = 0; i < N * M && std::getline(file, string_matrix[i], ','); ++i) {

            if (string_matrix[i] == "") {
                //std::cout << "invalid value, failed to record the file data\n";
                file.close();
                error = true;
                break;
            }
        }
        if (error) return !error;

        matrix = new std::vector<std::vector<double>>(N, std::vector<double>(M));
        size_t counter = 0;
        for (size_t i = 0; i < N; i++)
        {
            for (size_t j = 0; j < M; j++)
            {
                if (string_matrix[counter] == "" || string_matrix[counter] == "\n") {
                    //std::cout << "invalid value, failed to record the file data\n";
                    file.close();
                    error = true;
                    break;
                }
                if (!isdigit(string_matrix[counter][0]) && string_matrix[counter][0] != '\n') {
                    //std::cout << "invalid value, failed to record the file data\n";
                    matrix->clear();
                    file.close();
                    error = true;
                    break;
                }
                size_t* idx = nullptr;
                (*matrix)[i][j] = std::stod(string_matrix[counter], idx);

                if (idx != nullptr) {
                    //std::cout << "invalid value, failed to record the file data\n";
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
            return !error;
        }
        // Закрытие файла
        file.close();
        
        return !error;
}


/*
0,0 один массив 

1,

1, 2

*/