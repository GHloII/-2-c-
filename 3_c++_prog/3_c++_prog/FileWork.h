#pragma once
#include <iostream>
#include <unordered_map>
#include <string>




bool OpenFile(std::string filename, std::ifstream& file);
bool OpenFile(std::string filename, std::ofstream& file);


bool FileIsEmpty(std::string filename);

//void FileInput(std::unordered_map <std::string, Document*>& document_list);
