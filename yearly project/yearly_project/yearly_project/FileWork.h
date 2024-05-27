#pragma once


bool FileIsEmpty(std::string filename);
bool OpenFile(std::string filename, std::ifstream& file); // чтение
bool OpenFile(std::string filename, std::ofstream& file); //запись
void FileFilling(std::vector<std::vector<double>>*& matrix, int& N, int& M);
