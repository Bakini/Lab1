#include <iostream>
#include <string>
#ifdef _WIN32
#endif
#define N 7

struct Student {
    std::string surname;
    std::string name;
    std::string group;
    int course;
    double avg;
};

struct Node {
    Student data;
    Node* next;
};

void add(Node*& head, Node*& tail, Student s) {
    Node* node = new Node{ s,nullptr };
    if (head == nullptr) {
        head = node;
    }
    else {
        tail->next = node;
    }
    tail = node;
}

std::string toLower(std::string s) {
    std::string r;
    r.reserve(s.size());
    for (size_t i = 0; i < s.size(); ++i) {
        unsigned char c = (unsigned char)s[i];
        if (c < 0x80) {                                  
            if (c >= 'A' && c <= 'Z') c += 32;
            r += (char)c;
        }
        else if (c == 0xD0 && i + 1 < s.size()) {        
            unsigned char d = (unsigned char)s[i + 1];
            if (d >= 0x90 && d <= 0x9F) { r += (char)0xD0; r += (char)(d + 0x20); } 
            else if (d >= 0xA0 && d <= 0xAF) { r += (char)0xD1; r += (char)(d - 0x20); } 
            else if (d == 0x81) { r += (char)0xD1; r += (char)0x91; }       
            else { r += (char)c; r += (char)d; }
            ++i;
        }
        else if (c == 0xD1 && i + 1 < s.size()) {        
            r += (char)c; r += (char)s[i + 1];
            ++i;
        }
        else r += (char)c;
    }
    return r;
}

int main() {
#ifdef _WIN32
    SetConsoleCP(CP_UTF8); 
    SetConsoleOutputCP(CP_UTF8); 
#endif

    Node* head = nullptr;
    Node* tail = nullptr;

    Student st[N] = {
        {"Меллстрой","Александр","25ВВВ1",2,3.3},
        {"Джураев","Данил","26ВВВ4",1,3.4},
        {"Боссес","Боссин","24ВВВ2",3,5.0},
        {"Пузова","Маргарита","24ВВВ2",3,3.8},
        {"Йегуда","Дмитрий","23ВВВ1",4,4.3},
        {"Зовный","Александр","23ВВВ2",4,4.6},
        {"Джура","Богдан","26ВВВ4",1,3.4}
    };

    for (int i = 0; i < N; i++) {
        add(head, tail, st[i]);
    }

    std::cout << "Что ищем: ";
    std::string a;
    std::getline(std::cin, a);

    std::string key = toLower(a);

    int finded = 0;
    for (Node* p = head; p != nullptr; p = p->next) {
        Student s = p->data;
        std::string grade = std::to_string(s.avg).substr(0, 3);

        std::string all = s.surname + " " + s.name + " " + s.group + " "
            + std::to_string(s.course) + " " + grade;

        if (toLower(all).find(key) != std::string::npos) {
            std::cout << s.surname << " " << s.name
                << ", группа " << s.group
                << ", курс " << s.course
                << ", балл " << grade << "\n";
            finded++;
        }
    }

    if (finded == 0) std::cout << "Ничего не найдено\n";

    while (head != nullptr) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
}