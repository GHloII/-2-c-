#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "PhoneUser.h"

bool FileIsEmpty(std::string filename);

bool OpenFile(std::string filename, std::ifstream& file);

bool OpenFile(std::string filename, std::ofstream& file);

void FileInput(std::vector<PhoneUser>* save_book);

void FileFilling(PhoneUser*& book, int& size_of_book);

void FileFilling(std::vector<PhoneUser>& book, std::string filename);