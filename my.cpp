#include <iostream>
#include <string>


class Room;
class Student;

// Класс Стоимость проживания
class Cost {
private:
    double cost;
    bool isPaid;

public:
    Cost(double c) : cost(c), isPaid(false) {}

    void pay() {
        isPaid = true;
        std::cout << "Оплата произведена. Стоимость: " << cost << std::endl;
    }

    bool isPaidStatus() const {
        return isPaid;
    }

    double getCost() const {
        return cost;
    }
};

class Person {
protected:
    std::string name;
public:
    Person(std::string n) : name(n) {}
    virtual void displayInfo() const {
        std::cout << "Имя: " << name << std::endl;
    }
};
// Класс Администратор
class Administrator : public Person {
private:
    std::string building;
public:
    Administrator(std::string n, std::string b) : Person(n), building(b) {}
    void displayInfo() const override {
        std::cout << "Администратор: " << name << ", Корпус: " << building << std::endl;
    }

    bool checkBron(bool hasBron) {
        return hasBron;
    }

    bool checkDocuments(std::string personalDoc, std::string medicalDoc) {
        return !personalDoc.empty() && !medicalDoc.empty();
    }

    void createContract(Student& student, Room& room, Cost& cost);

    friend class Building; 
};

// Класс Студент
class Student : public Person {
private:
    std::string personalDocument;
    std::string medicalDocument;
public:
    bool hasBron;
    Student(std::string n, bool brony, std::string personalDoc, std::string medicalDoc)
        : Person(n), hasBron(brony), personalDocument(personalDoc), medicalDocument(medicalDoc) {
    }
    void displayInfo() const override {
        std::cout << "Студент: " << name << ", Документы: " << personalDocument << ", " << medicalDocument << std::endl;
    }

    void provideDocuments() {
        std::cout << "Студент " << name << " предоставил документы: " << personalDocument << " и " << medicalDocument << std::endl;
    }

    void payForProzhivanie(Cost& cost) {
        cost.pay();
    }

    std::string getName() const {
        return name;
    }

    friend class Administrator; // Дружественный класс
};

// Класс Комната
class Room {
private:
    int number;
    std::string building;

public:
    Room(int num, std::string bld) : number(num), building(bld) {}

    int getNumber() const {
        return number;
    }

    std::string getBuilding() const {
        return building;
    }
};

// Класс Договор
class Contract {
private:
    std::string studentName;
    Room room;
    double cost;

public:
    Contract(std::string student, Room r, double c) : studentName(student), room(r), cost(c) {}

    void displayContract() {
        std::cout << "Договор заключен со студентом " << studentName << " на комнату №" << room.getNumber() << " в корпусе " << room.getBuilding() << ". Стоимость: " << cost << std::endl;
    }
};

// Класс Корпус
class Building {
private:
    std::string name;
    Administrator* admin;

public:
    Building(std::string n, Administrator* a) : name(n), admin(a) {}

    void displayInfo() {
        std::cout << "Корпус " << name << " управляется администратором " << admin->name << std::endl;
    }
};

// Реализация метода createContract
void Administrator::createContract(Student& student, Room& room, Cost& cost) {
    if (cost.isPaidStatus()) {
        Contract contract(student.getName(), room, cost.getCost());
        contract.displayContract();
        std::cout << "Заселение студента " << student.getName() << " успешно завершено!" << std::endl;
    }
    else {
        std::cout << "Ошибка: оплата не произведена. Договор не может быть заключен." << std::endl;
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    // Создание объектов
    Administrator admin("Иван Иванов", "ГК 4");
    Student student("Петр Петров", true, "Паспорт", "Справка Ф20");
    Room room(101, "ГК 4");
    Building building("ГК 4", &admin);
    Cost cost(13000);
    
    building.displayInfo();
    student.provideDocuments();

    if (admin.checkBron(student.hasBron) && admin.checkDocuments("Паспорт", "Справка Ф20")) {
        std::cout << "Проверка документов и брони прошла успешно." << std::endl;
        student.payForProzhivanie(cost); // Студент оплачивает проживание
        admin.createContract(student, room, cost); // Администратор составляет договор
    }
    else {
        std::cout << "Заселение невозможно: проверка не пройдена." << std::endl;
    }

    

    return 0;
}