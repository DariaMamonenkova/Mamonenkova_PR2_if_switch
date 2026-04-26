//Мамоненкова
#include <iostream>

using namespace std;

int inputInt(const char* prompt) {
    int value;
    cout << prompt;
    while (!(cin >> value) || (value < 100) || (value > 999)) {
        cout << "Ошибка! Введите целое трёхзначное число: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    return value;
}


int main() {
    setlocale(LC_ALL, "Russian");
    int number = inputInt("Введите целое трёхзначное число:\n");
    const char* result = ((number / 100) == (number % 10)) ? "является палиндромом" : "не является палиндромом";
    cout << "Число " << result << ".\n";
 }
 