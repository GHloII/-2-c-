#pragma once


bool FileIsEmpty(std::string filename);
bool OpenFile(std::string filename, std::ifstream& file); // ������
bool OpenFile(std::string filename, std::ofstream& file); //������
void FileFilling(std::vector<std::vector<double>>*& matrix, int& N, int& M);
