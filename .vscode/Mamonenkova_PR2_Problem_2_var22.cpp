 #include <iostream>

 using namespace std;

void IsPalindrome() {
    int number;
    cout << "Введите трёхзначное число:\n";
    cin >> number;
    if ((number / 100) == (number % 10)) {
        cout << "Число является палиндромом.\n";
    } else {
        cout << "Число не является палиндромом.\n";
    }
}

void IsArithmeticProgression() {
    int a, b, c;
    cout << "Введите три целых числа по возрастанию:\n";
    cin >> a >> b >> c;
    if ((a != b) && (b != c) && (a != c)) {
        if ((b - a) == (c - b)) {
            cout << "Числа образуют арифметическую прогрессию.\n";
        } else {
            cout << "Числа не образуют арифметическую прогрессию.\n";
        }
    }
}

void IsThereADate() {
    int m, d;
    cout << "Введите номер месяца:\n";
    cin >> m;
    if (1 > m || m > 12) {
        cout << "Номер месяца должен находиться в дипазоне от 1 до 12. Введите корректные данные.\n";
        return;
    }
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

//вспомогательная функция, определяющая високосный год или нет.
bool IsLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int DaysInMonth(int month, int year) {
    switch (month) {
        case 2: return IsLeapYear(year) ? 29 : 28;
        case 4: case 6: case 9: case 11: return 30;
        default: return 31;
    }
}

void DetermineTheDate() {
    int d, m, g, n;
    cout << "Введите дату в таком формате: день месяц год:\n";
    cin >> d >> m >> g;
    cout << "Введите количество дней:\n";
    cin >> n;
    if (m < 1 || m > 12 || d < 1 || d > DaysInMonth(m, g)) {
        cout << "Ошибка! Введите корректные данные.\n";
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
        cout << "\n Пожалуйста, введите номер нужного задания или 0, если вы хотите закрыть приложение: \n";
        cin >> funcSelect;
        switch (funcSelect) {
            case 0: cout << "Выход из программы.\n"; return 0;
            case 1: IsPalindrome(); break;
            case 2: IsArithmeticProgression(); break;
            case 3: IsThereADate(); break;
            case 4: DetermineTheDate(); break;
            default: cout << "Неверный ввод. Попробуйте снова.\n";
        }
    }
    return 0;
 }