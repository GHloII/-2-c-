#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <filesystem>
#include <cctype> 

bool FileIsEmpty(std::string filename);
bool OpenFile(std::string filename, std::ifstream& file); // чтение
bool OpenFile(std::string filename, std::ofstream& file); //запись
void FromFileFilling(std::vector<std::vector<double>>*& matrix, int& N, int& M);
bool TestFileFilling(std::vector<std::vector<double>>*& matrix, int& N, int& M, std::string filename);
void FileInput(std::vector<std::vector<double>>& matrix, int& N, int& M);
std::string Removing_Quotes(std::string& path_to_the_file);
bool Does_Have_Blocked_Symbols(const std::string& path_to_the_file);
bool Is_not_Txt_Format(const std::string& path_to_the_file);
bool IsValideFilePath(std::string& path_to_the_file);

