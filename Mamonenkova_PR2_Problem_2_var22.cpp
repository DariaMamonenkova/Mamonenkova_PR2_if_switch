 //Мамоненкова
 #include <iostream>

 using namespace std;

int inputInt(const char* prompt) {
    int value;
    cout << prompt;
    while (!(cin >> value)) {
        cout << "Ошибка! Введите целое число: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    return value;
}

void IsPalindrome() {
    int number;
    number = inputInt("Введите трёхзначное число:\n");
    if (number < 100 || number > 999) {
        cout << "Ошибка: Введите трёхзначное число: ";
        cin.clear();
        cin.ignore(10000, '\n');;
    }
    if ((number / 100) == (number % 10)) {
        cout << "Число является палиндромом.\n";
    } else {
        cout << "Число не является палиндромом.\n";
    }
}

void IsArithmeticProgression() {
    int a, b, c;
    cout << "Введите три целых числа по возрастанию:\n";
    a = inputInt("Введите первое число: ");
    b = inputInt("Введите второе число: ");
    c = inputInt("Введите третье число: ");
    if (((a != b) && (b != c) && (a != c)) && (a < b < c)) {
        if ((b - a) == (c - b)) {
            cout << "Числа образуют арифметическую прогрессию.\n";
        } else {
            cout << "Числа не образуют арифметическую прогрессию.\n";
        }
    } else {
        cout << "Числа должны быть различными и строго возрастающими!\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

void IsThereADate() {
    int m = inputInt("Введите номер месяца: ");
    cout << "Введите номер месяца:\n";
    if (1 > m || m > 12) {
        cout << "Номер месяца должен находиться в дипазоне от 1 до 12. Введите корректные данные.\n";
        return;
    }
    int d = inputInt("Введите число месяца: ");
    int DaysInMonth;
    switch (m) {
        case 2: DaysInMonth = 29; break;
        case 4: case 6: case 9: case 11: DaysInMonth = 30; break;
        default: DaysInMonth = 31;
    }
    cout << "Введите число месяца:\n" ;
    cin >> d;
    if (d >= 1 && d <= DaysInMonth) {
        cout << "Дата " << d << "." << m << " существует в высокосном году.\n";
    } else {
        cout << "Дата " << d << "." << m << " не существует в высокосном году.\n";
    }
}

//вспомогательная функция к заданию 4. Определяет, является год високосным или нет.
bool IsLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

//вспомогательная функция к заданию 4. Определяет количество дней в месяце.
int DaysInMonth(int month, int year) {
    switch (month) {
        case 2: return IsLeapYear(year) ? 29 : 28;
        case 4: case 6: case 9: case 11: return 30;
        default: return 31;
    }
}

void DetermineTheDate() {
    int g = inputInt("Введите год: ");
    int m = inputInt("Введите номер месяца(1-12): ");
    int d = inputInt("Введите число месяца(1-31): ");
    int n = inputInt("Введите количество дней n: ");
    if (m < 1 || m > 12 || d < 1 || d > DaysInMonth(m, g)) {
        cout << "Ошибка! Введите корректные данные.\n";
        cin.clear();
        cin.ignore(10000, '\n');
        return;
    }
    d += n;
    while (d > DaysInMonth(m, g)) {
        d -= DaysInMonth(m, g);
        m++;
        if (m > 12) {
            m = 1;
            g++;
        }
    }
    cout << "Дата через " << n << " дней: " << d << "." << m << "." << g << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int funcSelect = 0;
    for (;;) {
        cout << "\nTask 1. Определить, является ли трёхзначное число палиндромом.\n";
        cout << "Task 2. Определить, образуют ли три числа арифметическую прогрессию.\n";
        cout << "Task 3. Определить, есть ли введёная дата в высокосном году.\n";
        cout << "Task 4. Определить дату, через n дней после заданной.\n";
        funcSelect = inputInt("\n Пожалуйста, введите номер нужного задания или 0, если вы хотите закрыть приложение: \n");
        switch (funcSelect) {
            case 0: cout << "Выход из программы.\n"; return 0;
            case 1: IsPalindrome(); break;
            case 2: IsArithmeticProgression(); break;
            case 3: IsThereADate(); break;
            case 4: DetermineTheDate(); break;
            default: cout << "Неккоректный ввод номера задания.\n"; break;
        }
    }
    return 0;
 }