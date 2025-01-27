#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int data;    
    Node* next;  
    Node* prev;  

 
    Node() {
        prev = nullptr;
        next = nullptr;
    }
    Node(int value) {
        this->data = value;
    }
};


class LinkedList {
public:
    Node* head;
    LinkedList() {
        head = nullptr;
    }

    ~LinkedList() {
        destroy();
    }
    

    void initialize() {
        if (head != nullptr) {
            cout << "Список уже инициализирован." << endl;
            return;
        }
        head = nullptr;
        cout << "Список инициализирован." << endl;
    }

    void add_elem(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            newNode->next = newNode;
            newNode->prev = newNode;
            head = newNode;
        }
        else {
            newNode->next = head;
            newNode->prev = head->prev;
            head->prev->next = newNode;
            head->prev = newNode;
            head = newNode;
        }
    }

    void del_elem (int value) {
        if (head == nullptr) {
            cout << "Список пуст." << endl;
            return;
        }

        Node* current = head;
        bool found = false;

        do {
            if (current->data == value) {
                found = true;
                Node* todelete = current;
                if (current == head) {
                    head = head->next;
                    if (head == todelete) { 
                        head = nullptr;
                    }
                }
                current->prev->next = current->next;
                current->next->prev = current->prev;
                current = current->next;
                delete todelete;
            }
            else {
                current = current->next;
            }
        } while (current != head && head != nullptr);

        if (!found) {
            cout << "Элемент не найден." << endl;
        }
        else {
            cout << "Все вхождения элемента " << value << " удалены." << endl;
        }
    }

    void del_after(int value) {
        if (head == nullptr) {
            cout << "Список пуст." << endl;
            return;
        }

        Node* current = head;
        bool found = false;

        do {
            if (current->data == value) {
                found = true;
                Node* todelete = current->next;
                if (todelete == head) {
                    head = head->next;
                }
                current->next = todelete->next;
                todelete->next->prev = current;
                delete todelete;
            }
            current = current->next;
        } while (current != head);

        if (!found) {
            cout << "Элемент не найден." << endl;
        }
        else {
            cout << "Элементы после каждого вхождения " << value << " удалены." << endl;
        }
    }

    void search(int value) {
        if (head == nullptr) {
            cout << "Список пуст." << endl;
            return;
        }

        Node* current = head;
        int position = 0;
        bool found = false;

        do {
            if (current->data == value) {
                cout << "Элемент найден на позиции " << position + 1 << endl;
                found = true;
            }
            current = current->next;
            position++;
        } while (current != head);

        if (!found) {
            cout << "Элемент не найден." << endl;
        }
    }

    void destroy() {
        if (head == nullptr) {
            return;
        }
        Node* current = head;
        Node* nodeNext;
        while (current->next != head) {
            nodeNext = current->next;
            delete current;
            current = nodeNext;
        }
        delete current;
        head = nullptr;
    }

    void print() {
        if (head == nullptr) {
            cout << "Список пуст." << endl;
            return;
        }

        Node* current = head;
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);
        cout << endl;
    }

    vector<int> toVector() {
        vector<int> vec;
        if (head == nullptr) {
            return vec;
        }

        Node* current = head;
        do {
            vec.push_back(current->data);
            current = current->next;
        } while (current != head);

        return vec;
    }

    vector<int> sym_dif(const vector<int>& vec1, const vector<int>& vec2) {
        vector<int> result;
        for (int val : vec1) {
            bool found = false;
            for (int v : vec2) {
                if (val == v) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                result.push_back(val);
            }
        }
        for (int val : vec2) {
            bool found = false;
            for (int v : vec1) {
                if (val == v) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                result.push_back(val);
            }
        }
        return result;
    }

    void sym_dif(LinkedList& otherList) {
        vector<int> vec1 = this->toVector();
        vector<int> vec2 = otherList.toVector();

        vector<int> result = sym_dif(vec1, vec2);

        cout << "Первый список: ";
        this->print();
        cout << "Второй список: ";
        otherList.print();
        cout << "Симметрическая разность: ";
        for (int val : result) {
            cout << val << " ";
        }
        cout << endl;
    }
};

void displayMenu() {
    cout << "Меню:" << endl;
    cout << "1. Инициализация списка" << endl;
    cout << "2. Освобождение памяти" << endl;
    cout << "3. Добавление элемента в начало" << endl;
    cout << "4. Удаление всех вхождений элемента" << endl;
    cout << "5. Удаление после каждого вхождения элемента" << endl;
    cout << "6. Поиск элемента" << endl;
    cout << "7. Печать списка" << endl;
    cout << "8. Симметрическая разность двух списков" << endl;
    cout << "9. Выход" << endl;
}
int CheckInput() {
    int value;
    while (true) {
        std::cin >> value;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Некорректный ввод, попробуйте еще раз: ";
        }
        else {
            return value;
        }
    }
}
int main() {
    setlocale(LC_ALL, "Rus");
    LinkedList list;
    LinkedList otherList;
    int choice, count; 
    bool initialized = false;


    while (true) {
        displayMenu();
        cout << "Выберите операцию: ";
        choice = CheckInput();

        switch (choice) {
        case 1: {
            list.initialize();
            initialized = true;
            break;
        }
        case 2: {
            list.~LinkedList();
            initialized = false;
            cout << "Память освобождена." << endl;
            break;
        }
        case 3: {
            if (!initialized) {
                cout << "Список не инициализирован." << endl;
                break;
            }
            int value;
            cout << "Введите значение элемента: ";
            value = CheckInput();
            list.add_elem(value);
            break;
        }
        case 4: {
            if (!initialized) {
                cout << "Список не инициализирован." << endl;
                break;
            }
            int value;
            cout << "Введите значение элемента для удаления: ";
            value = CheckInput();
            list.del_elem(value);
            break;
        }
        case 5: {
            if (!initialized) {
                cout << "Список не инициализирован." << endl;
                break;
            }
            int value;
            cout << "Введите значение элемента: ";
            value = CheckInput();
            list.del_after(value);
            break;
        }
        case 6: {
            if (!initialized) {
                cout << "Список не инициализирован." << endl;
                break;
            }
            int value;
            cout << "Введите значение элемента для поиска: ";
            value = CheckInput();
            list.search(value);
            break;
        }
        case 7: {
            if (!initialized) {
                cout << "Список не инициализирован." << endl;
                break;
            }
            list.print();
            break;
        }
        case 8: {
            if (!initialized) {
                cout << "Первый список не инициализирован." << endl;
                break;
            }
            std::cout << "Введите количество элементов для второго списка: ";
            count = CheckInput();;
            otherList.initialize();
            cout << "Введите элементы второго списка:" << endl;

             for (int i = 0; i < count; ++i) {
                 int value;
                 std::cout << "Элемент " << (i + 1) << ": ";
                 value = CheckInput();
                 otherList.add_elem(value);
             }
             list.sym_dif(otherList);
             break;
        }
        case 9: {
            return 0;
        }
        default: {
            cout << "Неверный выбор. Пожалуйста, выберите операцию от 1 до 9." << endl;
            break;
        }
        }
    }

    return 0;
}


