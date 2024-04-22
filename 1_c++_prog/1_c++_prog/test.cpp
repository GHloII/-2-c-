#include <iostream>
#include <vector>
#include "FileWork.h"
#include "PhoneUser.h"
#include "Function.h"

void Test1(std::vector<PhoneUser>* save_book) {
    std::vector <PhoneUser> result_book1;
    std::string filename = "./result1.txt";
    FileFilling(result_book1, filename);


    bool checker = (*save_book == result_book1);
    if (checker) std::cout << "test 1  -  successful \n";
    else std::cout << "test 1  -  faild \n";
}
void Test2(std::vector<PhoneUser>* save_book) {
    std::vector <PhoneUser> result_book2;
    std::string filename = "./result2.txt";
    FileFilling(result_book2, filename);


    bool checker = (*save_book == result_book2);
    if (checker) std::cout << "test 2  -  successful \n";
    else std::cout << "test 2  -  faild \n";
}
void Test3(std::vector<PhoneUser>* save_book) {
    std::vector <PhoneUser> result_book3;
    std::string filename = "./result3.txt";
    FileFilling(result_book3, filename);


    bool checker = (*save_book == result_book3);
    if (checker) std::cout << "test 3  -  successful \n";
    else std::cout << "test 3  -  faild \n";
}
void Test4(std::vector<PhoneUser>* save_book) {
    std::vector <PhoneUser> result_book4;
    std::string filename = "./result4.txt";
    FileFilling(result_book4, filename);


    bool checker = (*save_book == result_book4);
    if (checker) std::cout << "test 4  -  successful \n";
    else std::cout << "test 4  -  faild \n";
}
void Test5(std::vector<PhoneUser>* save_book) {
    std::vector <PhoneUser> result_book5;
    std::string filename = "./result5.txt";
    FileFilling(result_book5, filename);


    bool checker = (*save_book == result_book5);
    if (checker) std::cout << "test 5  -  successful \n";
    else std::cout << "test 5  -  faild \n";
}



//testing
//./tmp
void Test() {
    std::vector <PhoneUser> book;
    std::string filename = "./test1.txt";
    FileFilling(book, filename);
    int size_of_book = static_cast<int>(book.size());
    PhoneUser* test_book = new PhoneUser[size_of_book];

    for (size_t i = 0; i < size_of_book; i++)
    {
        test_book[i] = book[i];
    }
    //test1 ������ �������
    AlphabetOrder(test_book, size_of_book, test_1); //������� ������
    delete[] test_book;
    test_book = new PhoneUser[size_of_book];
    for (size_t i = 0; i < size_of_book; i++)
    {
        test_book[i] = book[i];
    }
    //test2 ��������
    LongDistanceCallsUser(test_book, size_of_book, test_2);
    delete[] test_book;
    test_book = new PhoneUser[size_of_book];
    for (size_t i = 0; i < size_of_book; i++)
    {
        test_book[i] = book[i];
    }
    //test 3 ���������� � �������
    const int limit = 100;
    InnerCityCallsUserLimit(test_book, size_of_book, limit, test_3);
    delete[] test_book;
    test_book = new PhoneUser[size_of_book];
    for (size_t i = 0; i < size_of_book; i++)
    {
        test_book[i] = book[i];
    }
    //test 4 �������� � ���������
    delete[] test_book;
    test_book = new PhoneUser[size_of_book];
    for (size_t i = 0; i < size_of_book; i++)
    {
        test_book[i] = book[i];
    }
    AlphabetOrder(test_book, size_of_book, test_4);
    //test 5 ���������� � ���������
    delete[] test_book;
    test_book = new PhoneUser[size_of_book];
    for (size_t i = 0; i < size_of_book; i++)
    {
        test_book[i] = book[i];
    }
    AlphabetOrder(test_book, size_of_book, test_5);
}
//
