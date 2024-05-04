#pragma once
#include <iostream>
#include <unordered_map>
#include <string>
#include "Document.h"


void FileFilling(std::unordered_map <std::string, Document*>& document_list, size_t& size_of_book);

uint16_t OpenFile(std::string filename, std::ifstream& file);
bool OpenFile(std::string filename, std::ofstream& file);


bool FileIsEmpty(std::string filename);

void FileInput(std::unordered_map <std::string, Document*>& document_list);
void FileFilling(std::unordered_map <std::string, Document*>& document_list, size_t& size_of_book, std::string document_filename);            // для тестов
