#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "FileWork.h"
#include "NumInput.h"
#include "Menu.h"


class Text {
public:

    ~Text() {
        //вызывается функция которая сохравняет все из вектора диалогов   в отдельном тхт файле
    }

    

    void DisplayDialog() {
        for (auto& s : dialogs) {
            for (size_t i = 0; i < s.size(); i++)
            {
                std::cout << *s[i]<<"\n";
            }
            std::cout << "\n";
        }
    }

    void AddText() {
        std::string temp;
        int i = 0;
        char h;
        std::cout << "please tape your text" << "\n";
        std::cin >> h;
        text += h;
        while (true) {
            getline(std::cin, temp);

            if (temp == "") {
                break;
            }

            text += temp;
            text += '\n';
            paragraphs.push_back(temp);

            temp = "";
            ++i;
        }
        DialogDivision();
    }

    void AddTextFromFile() {
        std::ifstream file;

        while (true) {

            std::cout << "please tape any filename" << "\n";
            std::string filename = "./test.txt";
            std::cin >> filename;
            
            if (OpenFile(filename, file)) {
                break;
            }
        }

        std::string temp;
        int i = 0;
        while (true) {
            getline(file, temp);

            if (temp == "") {
                break;
            }
            text += temp;
            text += '\n';
            paragraphs.push_back(temp);

            temp = "";
            ++i;
        }
        DialogDivision();
    }
    

    void DisplayText() {
        std::cout << text << "\n";
    }

private:
    std::string text; //строка со всем текстом
    std::vector<std::string> paragraphs; // вестор с абзацами
    std::vector<std::vector<std::string*>> dialogs; //вектор с диалогами

    void DialogDivision() {
        bool is_dialog_continue = false; //проверка был ли предыдущий абзац диалогом
        bool is_dialog = false;
        for (int i = 0, j = 0; i < paragraphs.size(); ++i) {
            if (paragraphs[i][0] == '-') {
                is_dialog = true;
                if (i != 0 && is_dialog_continue == false && j != 0) j++;
                if (j >= dialogs.size()) { // Проверяем, существует ли dialogs[j]
                    dialogs.push_back(std::vector<std::string*>()); // Если не существует, создаем новый вектор
                }

                dialogs[j].push_back(&paragraphs[i]);
                is_dialog_continue = true;

            }
            else {
                is_dialog_continue = false;
            }
        }
    }
};




void Filling(bool option, Text* text) {
    if (option == file_filling) {
        text->AddTextFromFile();
    }
    else {
        text->AddText();
    }
}


void Function() {
    auto text = new Text;

    std::cout << "type a option of filling " << "\n"
        "1 - file 0 - hand" << "\n";
    int option_of_filling = hand_filling;
    while (true) {
        option_of_filling = static_cast<int>(Num_input());
        if (option_of_filling == file_filling || option_of_filling == hand_filling) {
            break;
        }
        std::cout << "Invalid input. Please enter a valid number." << "\n";
    }

    Filling(option_of_filling, text);

    bool exit = false;
    while (!exit) {

        int option_of_function = 0;
        std::cout << "\n\n";
        std::cout << "type a option of function\n display_text - 1\n display_dialogs - 2\n exit - 0" << "\n";
        while (true) {
            option_of_function = static_cast<int>(Num_input());
            if (option_of_function == display_text) {
                break;
            }
            else if (option_of_function == display_dialogs) {
                break;
            }
            else if (option_of_function == Exit) {
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

        switch (option_of_function) {
        case display_text:
            text->DisplayText();
            break;
        case display_dialogs:
            text->DisplayDialog();
            break;
        }
    }
    delete text;
}


int main()
{
    setlocale(LC_CTYPE, "Russian");
    int command = 0;

    std::cout << "Hello, Alexey Konstantinovich, Roman Valerievich and Ivan Grigorievich\n"
        << "Author: Ivanov Gleb Igorevich\n"
        << "group: 4303, 2023\n"
        << "Project name: 2_c++_prog.cpp\n"
        << "Task name: task 2 variant 13\n"

        << "Task text:  Базовый класс – документ предприятия. Производный класс – письмо.\n";
    while (true) {

        std::cout << "begin - 1\ntest - 2 \nexit - 0\n";
        command = static_cast<int>(Num_input());
        //std::cout << "\n\n";

        if (command == start) {
            Function();
        }
        else if (command == test) {
            //Function(test);
            std::cout << "\n\n";
        }
        else if (command == Exit) {


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

setlocale(LC_CTYPE, "Ru");
    Text text;
    text.AddText();
    //text.DisplayText();
    text.DialogDivision();
    text.DisplayDialog();
*/