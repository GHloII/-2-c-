#pragma once
#include <iostream>
#include <cstdint>
#include "Document.h"
#include "Letter.h"
#include "FileWork.h"
#include <unordered_map>
#include <fstream>
#include "NumInput.h"

Document* FindDocumentByName(std::unordered_map <std::string, Document*>& document_list, std::string name);

void DeleteDocument(std::unordered_map <std::string, Document*>& document_list, std::string name);

void AddDocument(std::unordered_map <std::string, Document*>& document_list);

void DisplayAll(std::unordered_map <std::string, Document*>& document_list);

void Test1();

void Test2();

void Test3();

void Test4();

void Test5();

void Function(uint16_t option);


