#pragma once
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>
#include "PhoneUser.h"
#include "FileWork.h"
#include "menu.h"
#include "test.h"

unsigned long long Num_input();
void LongDistanceCallsUser(PhoneUser* book, int size_of_book, int option_of_save);
void InnerCityCallsUserLimit(PhoneUser* book, int size_of_book, int limit, int option_of_save);
bool ValueCmp(PhoneUser& a, PhoneUser& b);
void AlphabetOrderSort(PhoneUser* book, int size_of_book);
void AlphabetOrder(PhoneUser* book, int size_of_book, int option_of_save);
void HandFilling(PhoneUser*& book, int& size_of_book);
void Filling(bool option, PhoneUser*& book, int& size_of_book);
void Function();
