#include <iostream>
#include <string>
#include <windows.h>
#define N 6

struct Student {
    std::string surname;
    std::string name;
    std::string group;
    int course;
    double avgGrade;
};

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    Student st[N] = {
        {"Меллстрой","Александр","25ВВВ1",2,3.3},
        {"Боссес","Боссин","24ВВВ2",3,5.0},
        {"Пузова","Маргарита","24ВВВ2",3,3.8},
        {"Йегуда","Дмитрий","23ВВВ1",4,4.3},
        {"Зовный","Александр","23ВВВ2",4,4.6},
        {"Джураев","Богдан","26ВВВ4",1,3.4}
    };

    int choice;
    std::cout << "Поиск по:\n";
    std::cout << "1 - фамилия\n";
    std::cout << "2 - имя\n";
    std::cout << "3 - группа\n";
    std::cout << "4 - курс\n";
    std::cout << "5 - средний балл\n";
    std::cout << "Выбор: ";
    std::cin >> choice;

    std::string key;
    int keyCourse = 0;
    double keyGrade = 0;

    if (choice >= 1 && choice <= 3) {
        std::cout << "Что ищем: ";
        std::cin >> key;
    }
    else if (choice == 4) {
        std::cout << "Курс: ";
        std::cin >> keyCourse;
    }
    else if (choice == 5) {
        std::cout << "Балл: ";
        std::cin >> keyGrade;
    }
    else {
        std::cout << "Неверный пункт меню\n";
        return 0;
    }

    int found = 0;
    for (int i = 0;i < N;i++) {
        bool match = false;
        if (choice == 1 && st[i].surname == key)match = true;
        if (choice == 2 && st[i].name == key)match = true;
        if (choice == 3 && st[i].group == key)match = true;
        if (choice == 4 && st[i].course == keyCourse)match = true;
        if (choice == 5 && st[i].avgGrade == keyGrade)match = true;

        if (match) {
            std::cout << st[i].surname << " " << st[i].name << ", группа " << st[i].group << ", курс " << st[i].course << ", балл " << st[i].avgGrade << "\n";
            found++;
        }
    }

    if (found == 0)
        std::cout << "Ничего не найдено\n";
    else
        std::cout << "Найдено записей: " << found << "\n";
}
