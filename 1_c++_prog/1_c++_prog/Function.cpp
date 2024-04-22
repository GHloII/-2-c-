#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>
#include "PhoneUser.h"
#include "FileWork.h"
#include "menu.h"
#include "test.h"



unsigned long long Num_input() {
    unsigned long long input = 0;
    bool isError = false;

    do {
        if (isError) {
            std::cout << "Invalid input. Please enter a valid number." << std::endl;
        }

        if (!(std::cin >> input)) {
            isError = true;
            std::cin.clear(); // ������� ���� ������ �����
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ������� ����� ����� �� ������� ����� ������
        }
        else {
            isError = false;
        }

    } while (isError);

    return input;
}







void LongDistanceCallsUser(PhoneUser* book, int size_of_book, int option_of_save) { // ������ �������
    std::vector<PhoneUser> save_book;

    for (int i = 0; i < size_of_book; i++) { //����� �������
        if (book[i].GetTimeLongDistanceCalls()) {
            if (option_of_save == dontSave || option_of_save == save) {
                std::cout << book[i].GetSecondName() << " " << book[i].GetName() << " " << book[i].GetAddress()
                    << " " << book[i].GetPhoneNumber() << " " << book[i].GetTimeInnerCityCalls()
                    << " " << book[i].GetTimeLongDistanceCalls() << "\n";
            }

            if (option_of_save) {
                save_book.push_back(book[i]);
            }
        }
    }
    if (option_of_save == save) {
        FileInput(&save_book);
    }
    else if (option_of_save == test_2) {
        Test2(&save_book);
    }
    else if (option_of_save == test_4) {
        Test4(&save_book);
    }
}

void InnerCityCallsUserLimit(PhoneUser* book, int size_of_book, int limit, int option_of_save) {
    std::vector<PhoneUser> save_book;

    for (int i = 0; i < size_of_book; i++) { //����� �������
        if (book[i].GetTimeInnerCityCalls() > limit) {
            if (option_of_save == dontSave || option_of_save == save) {
                std::cout << book[i].GetSecondName() << " " << book[i].GetName() << " " << book[i].GetAddress()
                    << " " << book[i].GetPhoneNumber() << " " << book[i].GetTimeInnerCityCalls()
                    << " " << book[i].GetTimeLongDistanceCalls() << "\n";
            }

            if (option_of_save) {
                save_book.push_back(book[i]);
            }
        }
    }
    if (option_of_save == save) {
        FileInput(&save_book);
    }
    else if (option_of_save == test_3) {
        Test3(&save_book);
    }
    else if (option_of_save == test_5) {
        Test5(&save_book);
    }
}

bool ValueCmp(PhoneUser& a, PhoneUser& b)
{
    if (a.GetSecondName() == b.GetSecondName()) {
        return  a.GetName() < b.GetName();
    }
    return a.GetSecondName() < b.GetSecondName();
}
void AlphabetOrderSort(PhoneUser* book, int size_of_book) {
    std::sort(book, book + size_of_book, ValueCmp);
}

void AlphabetOrder(PhoneUser* book, int size_of_book, int option_of_save) {
    AlphabetOrderSort(book, size_of_book);
    std::vector<PhoneUser> save_book;

    for (int i = 0; i < size_of_book; i++) { //����� �������

        if (option_of_save == dontSave || option_of_save == save) {
            std::cout << book[i].GetSecondName() << " " << book[i].GetName() << " " << book[i].GetAddress()
                << " " << book[i].GetPhoneNumber() << " " << book[i].GetTimeInnerCityCalls()
                << " " << book[i].GetTimeLongDistanceCalls() << "\n";
        }

        if (option_of_save) {
            save_book.push_back(book[i]);
            //std::reverse(save_book.begin(), save_book.end());
        }
    }
    if (option_of_save == save) {
        FileInput(&save_book);
    }
    else if (option_of_save == test_1) {
        Test1(&save_book);
    }
    else if (option_of_save == test_4) {
        LongDistanceCallsUser(book, size_of_book, test_4);
    }
    else if (option_of_save == test_5) {
        int limit = 100;
        InnerCityCallsUserLimit(book, size_of_book, limit, test_5);
    }

}




//

void HandFilling(PhoneUser*& book, int& size_of_book) {
    std::cout << "example: name secondName \"address\" phone innerTime longDistansetime" << "\n";
    for (int i = 0; i < size_of_book; i++) { // ����������
        string name;
        string second_name;
        int phone = 0;
        int inner_time = 0;
        int long_distance_time = 0;


        std::cin >> second_name;

        std::cin >> name;

        book[i].SetAddress();
        std::cin.ignore(); // clear input buffer
        phone = static_cast<int>(Num_input());

        inner_time = static_cast<int>(Num_input());

        long_distance_time = static_cast<int>(Num_input());

        book[i].SetSecondName(second_name);
        book[i].SetName(name);
        book[i].SetPhoneNumber(phone);
        book[i].SetTimeInnerCityCalls(inner_time);
        book[i].SetTimeLongDistanceCalls(long_distance_time);
    }
    std::cout << "\n" << "\n" << "\n";

}

void Filling(bool option, PhoneUser*& book, int& size_of_book) {
    if (option == file_filling) {
        FileFilling(book, size_of_book);
    }
    else {
        HandFilling(book, size_of_book);
    }
}
//


void Function() {
    int size_of_book = 0;
    PhoneUser* book = nullptr;


    std::cout << "type a option of filling " << "\n"
        "1 - file 0 - hand" << "\n";// ������ ����������
    int option_of_filling = hand_filling;
    while (true) {
        option_of_filling = static_cast<int>(Num_input());
        if (option_of_filling == file_filling || option_of_filling == hand_filling) {
            break;
        }
        std::cout << "Invalid input. Please enter a valid number." << "\n";
    }


    if (option_of_filling == hand_filling) {

        std::cout << "type a size of book of users " << "\n";
        size_of_book = static_cast<int>(Num_input());
        book = new PhoneUser[size_of_book];
    }

    Filling(option_of_filling, book, size_of_book); //����� ������� ����������


    bool exit = false;
    while (!exit) {
        // ���������� ��� �� �������
        //  ����� ������ ����� 
        // ����� ��������� �� ����������

        int option_of_function = 0;
        std::cout << "\n\n";
        std::cout << "type a option of function\n alphabet - 1\n used long distanse - 2\n inner sity - 3\n exit - 0" << "\n";// ������ �������
        while (true) { //�������� �� ������������ ��������� �������
            option_of_function = static_cast<int>(Num_input());
            if (option_of_function == alphabetOrder) {//a������ ������� ������
                break;
            }
            else if (option_of_function == longDistanceCallsUser) {// long distanse users ������� ������
                break;
            }
            else if (option_of_function == inner�ity�allsUserLimit) {// inner city sf ������� ������
                break;
            }
            else if (option_of_function == exit) {// �����
                exit = true;
                break;
            }
            else {
                std::cout << "Invalid input. Please enter a valid number." << "\n";
            }
        }

        if (exit == true) {
            break;
        }

        std::cout << "do you want to save the result?\n 1 - yes\n 0 - no" << "\n";// ������ ����������� ������
        int option_of_save = 0;
        while (true) {
            option_of_save = static_cast<int>(Num_input());
            if (option_of_save == save || option_of_save == dontSave) {
                break;
            }
            std::cout << "Invalid input. Please enter a valid number." << "\n";
        }
        std::cout << "\n\n";

        switch (option_of_function) { // ����� ������� 
        case alphabetOrder:
            AlphabetOrder(book, size_of_book, option_of_save);
            break;
        case longDistanceCallsUser:
            LongDistanceCallsUser(book, size_of_book, option_of_save);
            break;
        case inner�ity�allsUserLimit:
            std::cout << "type a limit for innercity calls" << "\n";
            int limit = static_cast<int>(Num_input());
            InnerCityCallsUserLimit(book, size_of_book, limit, option_of_save);
            break;
        }
        std::cout << "\n" << "\n" << "\n";

    }
    delete[] book;
}

