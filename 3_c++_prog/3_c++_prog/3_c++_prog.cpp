#include <iostream>
#include <string>
#include <vector>



class Text {
public:

   

    void DialogDivision() {
        bool is_dialog_continue = false; //проверка был ли предыдущий абзац диалогом
        bool is_dialog = false;
        for (int i = 0, j = 0; i < paragraphs.size(); ++i) {
            if (paragraphs[i][0] == '-') {
                is_dialog = true;
                if (i != 0 && is_dialog_continue == false&&j!=0) j++;
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

    void DisplayDialog() {
        for (auto& s : dialogs) {
            for (size_t i = 0; i < s.size(); i++)
            {
                std::cout << *s[i]<<"\n";
            }
        }
    }

    void AddText() {
        std::string temp;
        int i = 0;
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
    }

    void DisplayText() {
        std::cout << text << "\n";
    }

private:
    std::string text; //строка со всем текстом
    std::vector<std::string> paragraphs; // вестор с абзацами
    std::vector<std::vector<std::string*>> dialogs; //вектор с диалогами


};


int main() {
    setlocale(LC_CTYPE, "Ru");
    Text text;
    text.AddText();
    //text.DisplayText();
 //   text.ParagraphDivision();
    text.DialogDivision();
    text.DisplayDialog();
}

/*


*/