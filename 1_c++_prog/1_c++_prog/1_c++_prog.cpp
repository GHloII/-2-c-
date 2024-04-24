
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>
#include "PhoneUser.h"
#include "FileWork.h"
#include "Function.h"
#include "test.h"
#include "menu.h"


int main()
{
    setlocale(LC_CTYPE, "Russian");
    int command = 0;
    
    std::cout<< "Hello, Alexey Konstantinovich, Roman Valerievich and Ivan Grigorievich\n"
             << "Author: Ivanov Gleb Igorevich\n"
             << "group: 4303, 2023\n"
             << "Project name: 1_c++_prog.cpp\n"
             << "Task name: task 1 variant 13\n"
             << "Task text: Абонент: фамилия, имя, отчество, адрес, номер телефона, время внутригородских разговоров, время междугородних разговоров.\nСоздать массив объектов. Реализовать возможность получения:\nсписка абонентов, время внутригородских разговоров которых\nпревышает заданное,\nсписка абонентов, воспользовавшихся междугородней связью,\nсписка абонентов, выведенных в алфавитном порядке.\n\n";
    while (true) {

        std::cout << "begin - 1\ntest - 2 \nexit - 0\n\n";
        command = static_cast<int>(Num_input());
        std::cout << "\n\n";

        if (command == start) {

            Function();

        }
        else if (command == test) {

            Test();
            std::cout << "\n\n";
        }
        else if (command == 0) {


            std::cout << "prog has been finished";
            std::cout << "\n\n";
            break;

        }
        else {
            std::cout << "command not found" << "\n" << "\n";
        }
    }
}



/*

to do list:
1. use enum
2. make russuian done 
3. make tests done 
4. unint done 
5. checking is file empty DONE




C:\Users\Gleb\Desktop\for_test\test.txt




1
C:\Users\Gleb\Desktop\folder_fortests\file.txt
1
1
C:\Users\Gleb\Desktop\folder_fortests\result.txt


test: name secondName "address" phone innerTime longDistansetime

4
1
0
Ivanov Gleb 8937340 2345345 0
Petrov Roman 8932342 345345 3245
Mazo Ivan 89123389 345345 0
Khamidullin Bogdan 3432445 5757656 5



C:\Users\Gleb\Desktop\folder_fortests\file.txt

25
1
0
Ivanov Gleb "ufa 114" 8937340 2345345 0                    
Petrov Roman "ufa 114" 8932342 345345 3245   
Mazo Ivan "ufa 114" 89123389 345345 0
Khamidullin Bogdan "ufa 114" 3432445 5757656 5
Smirnov Dmitry "ufa 114" 89112233 123456 4356
Sidorov Pavel "ufa 114" 8966778 9876543 0
Kuznetsov Andrey "ufa 114" 891234567 5436789 235
Volkov Sergey "ufa 114" 89991234 7891234 0
Fedorov Mikhail "ufa 114" 8900011 4567890 0
Mikhailov Alexey "ufa 114" 8987654 5678901 0
Egorov Alexander "ufa 114" 8956789 2345678 789
Vasiliev Anton "ufa 114" 89098765 1234567 4321
Alexandrov Artem "ufa 114" 89112345 5437890 0
Antonov Ivan "ufa 114" 8976543 9876543 0
Dmitriev Dmitry "ufa 114" 8912398 8765432 6578
Sergeev Sergey "ufa 114" 89567890 1234567 0
Nikolaev Nikolay "ufa 114" 8909876 1234567 233
Pavlov Pavel "ufa 114" 8911234 8765432 0
Maksimov Maxim "ufa 114" 8965432 3456789 0
Yakovlev Yakov "ufa 114" 89012345 2345678 0
Timofeev Timofey "ufa 114" 891234567 5678901 0
Grigoriev Grigory "ufa 114" 8987654 9876543 0
Zaitsev Roman "ufa 114" 8998765 1234567 0
Ivanov Igor "ufa 114" 89876543 9876543 0
Kozlov Konstantin "ufa 114" 8934821 2342342 0


5
0
Ivanov Gleb "ufa 114" 8937340 2345345 0
Petrov Roman "ufa 114" 8932342 345345 3245
Mazo Ivan "ufa 114" 89123389 345345 0
Khamidullin Bogdan "ufa 114" 3432445 5757656 5
Smirnov Dmitry "ufa 114" 89112233 123456 4356
1
1
C:\Users\Gleb\Desktop\folder_fortests\file.txt


3
1
0
Ivanov Gleb "ufa 114" 8937340 2345345 0
Petrov Roman "ufa 114" 8932342 345345 3245
Mazo Ivan "ufa 114" 89123389 345345 0



for (int i = 0; i < size_of_book; i++) { //вывод массива
                std::cout << book[i].GetSecondName() << "\t" << book[i].GetName() << "\n";
            }



//AlphabetOrder(book, size_of_book);// вызов функции сортировки по алфавиту

LongDistanceCallsUser(book, size_of_book); 

InnerСityСallsUserLimit(book, size_of_book, 345345);







  

*/











