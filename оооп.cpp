#include <iostream>
#include <limits>

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    bool flag = true;

    while (flag) {
        int a, b, operation;
        cout << "Введите первое число: ";
        cin >> a;
        while (cin.fail() || a < INT_MIN || a > INT_MAX) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Введите первое число: ";
            cin >> a;
        }
        cout << "Введите второе число: ";
        cin >> b;
        while (cin.fail() || a < INT_MIN || a > INT_MAX) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Введите второе числа: ";
            cin >> b;
        }
        cout << "1.Сумма" << endl << "2.Вычитание" << endl << "3.Умножение" << endl << "4.Деление" << endl << "5.Выход" << endl << "Выберете операцию: ";
        cin >> operation;
        while (cin.fail() || operation > 5 || operation < 1) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "1.Сумма" << endl << "2.Вычитание" << endl << "3.Умножение" << endl << "4.Деление" << endl << "5.Выход" << endl << "Выберете операцию: ";
            cin >> operation;
        }


        switch (operation) {
        case 1:
            cout << "Результат: " << a + b << endl;
            break;
        case 2:
            cout << "Результат: " << a - b << endl;
            break;
        case 3:
            cout << "Результат: " << a * b << endl;
            break;
        case 4:
            if (b == 0) {
                cout << "Ошибка" << endl;
                break;
            }
            cout << "Результат: " << a / b << endl;
            break;
        case 5:
            cout << "Программа завершена";
            flag = false;
            break;

        }
    }


}