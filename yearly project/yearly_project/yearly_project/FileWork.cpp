#include "FileWork.h"

namespace fs = std::filesystem;

std::string Removing_Quotes(std::string& path_to_the_file)
{
    char ch = 34;
    size_t pos = path_to_the_file.find(ch);
    while (pos != std::string::npos) {
        path_to_the_file.erase(pos, 1);
        pos = path_to_the_file.find(ch);
    }
    return path_to_the_file;
}

bool FileIsEmpty(std::string filename) {
    std::ifstream File_In(filename);
    if (File_In.peek() == std::ifstream::traits_type::eof())
    {
        File_In.close();
        return true;
    }
    else
        return false;

}

bool Does_Have_Blocked_Symbols(const std::string& path_to_the_file)
{
    std::vector <std::string> Blocked_Symbols{ "?", ",", ";", "+", "=", "*",
         "|", "<", ">", "[", "]" };

    for (const std::string& blocked_symbol : Blocked_Symbols)
    {
        if (path_to_the_file.find(blocked_symbol) != std::string::npos)
        {
            std::cout << "Symbol " << blocked_symbol << " forbidden to use \n Try again\n";
            return true;
        }
    }
    return false;
}

bool Is_not_Txt_Format(const std::string& path_to_the_file)
{
    if (path_to_the_file.size() < 5 || path_to_the_file.substr(path_to_the_file.size() - 4) != ".txt")
    {
        std::cout << "error! The file must have the txt extension.\n";
        std::cout << "try again:\n";
        return true;
    }
    else
        return false;
}

bool IsValideFilePath(std::string& path_to_the_file) {
    bool checker = !Is_not_Txt_Format(path_to_the_file) && !Does_Have_Blocked_Symbols(path_to_the_file);
    return checker;
}

bool OpenFile(std::string filename, std::ifstream& file) { // чтение
    std::error_code ec{};

    // Попытаться открыть файл
    if (!IsValideFilePath(filename)) {
        std::cout << "file path contains invalid values.. Failed to open the file. " << "\n";
        file.close();
        filename.clear();
        return false;
    }
    bool is_empty = FileIsEmpty(filename);
    file.open(filename);
    if (!fs::is_regular_file(filename, ec)) {
        std::cout << "file path contains invalid values. Failed to open the file. " << "\n";
        filename.clear();
        file.close();
        return false;
    }
    if (is_empty == 1) {
        std::cout << "File is empty, failed to load the data. " << "\n";
        filename.clear();
        file.close();
        return false;
    }
    if (file.is_open() && is_empty == 0) {
        //std::cout << "File successfully opened" << "\n";
        return true;
    }

    else {
        std::cout << "Failed to open the file." << "\n";
        filename.clear();
        file.close();
        return false;
    }
}

bool OpenFile(std::string filename, std::ofstream& file) { //запись
    std::error_code ec{};

    // Попытаться открыть файл
    if (!IsValideFilePath(filename)) {
        std::cout << "file path contains invalid values.. Failed to open the file. " << "\n";
        filename.clear();
        file.close();
        return false;
    }
    bool is_empty = FileIsEmpty(filename);
    file.open(filename, std::ios::app);// для дозаписи
    if (!fs::is_regular_file(filename, ec)) {
        std::cout << "file path contains invalid values... Failed to open the file. " << "\n";
        filename.clear();
        file.close();
        return false;
    }
    if (file.is_open() && is_empty) {
        std::cout << "File successfully opened" << "\n";
        return true;
    }
    if (file.is_open() && is_empty == 0) {
        std::cout << "File is not empty, failed to open the file. " << "\n";
        filename.clear();
        file.close();
        return false;
    }
    else {
        std::cout << "Failed to open the file." << "\n";
        filename.clear();
        file.close();
        return false;
    }
}

void FileInput(std::vector<std::vector<double>>& matrix, int& N, int& M) {
    std::ofstream file;

    while (true) {

        std::cout << "please tape any filenameway" << "\n";
        std::string filename;
        std::cin >> filename;
        Removing_Quotes(filename);

        //открытие файла:
        if (OpenFile(filename, file)) {
            break;
        }
    }

    // Запись данных в файл
    file << N << ',' << M << ',';
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < M; j++)
        {
            file << matrix[i][j] << ',';
        }
    }



    std::cout << "Data successfully written to the file." << std::endl;


    // Закрытие файла
    file.close();
}


void FromFileFilling(std::vector<std::vector<double>>*& matrix, int& N, int& M) {
    std::ifstream file;


    while (true) {

        bool error = false;
        while (true) {

            std::cout << "please tape any filenameway" << "\n";
            std::string filename;
            std::cin >> filename;
            Removing_Quotes(filename);

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
            array_of_amount_of_rows_columns[1] == ""|| M<0||N<0) {

            std::cout << "invalid value, failed to record the file data\n";
            file.close();
            error = true;
            break;
        }
        if (error) continue;

        std::vector<std::string> string_matrix(M * N);
        //for (int i = 0; i < N * M && std::getline(file, string_matrix[i], ','); ++i) {
        {
            int i = 0;
            while (std::getline(file, string_matrix[i], ',')) {
                if (string_matrix[i] == "") {
                    std::cout << "invalid value, failed to record the file data\n";
                    file.close();
                    error = true;
                    break;
                }
                ++i;
                if (i == M * N) break;
            }
            if (string_matrix.size() != (M * N)) {
                std::cout << "invalid value,, failed to record the file data\n";
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
                if ( !isdigit(string_matrix[counter][0]) && string_matrix[counter][0] != '\n'&& string_matrix[counter][0] != '-') {
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



bool TestFileFilling(std::vector<std::vector<double>>*& matrix, int& N, int& M, std::string filename) {
	std::ifstream file;

	bool error = false;

	while (true) {

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