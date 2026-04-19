#include <iostream>
#include <cmath>
#include <numeric>

using namespace std;

void RingArea() {
    double r, R, S;
    const double PI = 3.14159;
    cout << "Введите значение внешнего радиуса:\n";
    cin >> R;
    cout << "Введите значение внутреннего радиуса:\n";
    cin >> r;
    S = PI * (pow(R, 2) - pow(r, 2));
    cout << "Результат задания 1: " << S << endl;
}

void IsPalindrome() {
    int number;
    cout << "Введите четырёхзначное число:\n";
    cin >> number;
    if ((number%10 == number/1000) and ((number%100)/10 == (number/100)%10)) {
        cout << "Результат задания 2: ДА, это число является палиндромом." << endl;
    } else {
        cout << "Результат задания 2: Нет, это число не является палиндромом." << endl;
    }
}

void GCDNumbers() {
    int first_num, second_num;
    cout << "Введите первое число:\n";
    cin >> first_num;
    cout << "Введите второе число:\n";
    cin >> second_num;
    int result = gcd(first_num, second_num);
    cout << "Результат задания 3: " << result << endl;
}

void SameQuarter() {
    double x_1, y_1, x_2, y_2;
    cout << "Введите значения x и y для первой точки:\n";
    cin >> x_1 >> y_1;
    cout << "Введите значения x и y для второй точки:\n";
    cin >> x_2 >> y_2;
    if (x_1*x_2 > 0 and y_1*y_2 > 0) {
        cout << "Результат задания 4: Да, точки лежат в одной координатной четверти.\n";
    } else {
        cout << "Результат задания 4: Нет, точки не лежат в одной координатной четверти.\n";
    }
}

void Direction() {
    char direction;
    cout << "Введите направление (N, S, E, W):\n";
    cin >> direction;
    switch (direction) {
        case 'N':
            cout << "Результат задания 5: Север\n";
            break;
        case 'S':
            cout << "Результат задания 5: Юг\n";
            break;
        case 'E':
            cout << "Результат задания 5: Восток\n";
            break;
        case 'W':
            cout << "Результат задания 5: Запад\n";
            break;
        default:
            cout << "Результат задания 5: Ошибка вводв данных.\n";
    }
}


int main() 
{
    setlocale(LC_ALL, "Russian");
    int funcSelect = 0;
    for (;;)
    {
        cout << "\nTask 1. Вычисление площади кольца.\n";
        cout << "Task 2. Определить, является ли число палиндромом.\n";
        cout << "Task 3. Вычисление наибольшего общего делителя.\n";
        cout << "Task 4. Определение расположения двух точек.\n";
        cout << "Task 5. Описание строны света.\n";
        cout << "\n Пожалуйста, введите номер нужного задания или 0, если вы хотите закрыть приложение: \n";
        cin >> funcSelect;
        switch (funcSelect) 
        {
            case 0: cout << "Выход из программы.\n"; return 0;
            case 1: RingArea(); break;
            case 2: IsPalindrome(); break;
            case 3: GCDNumbers(); break;
            case 4: SameQuarter(); break;
            case 5: Direction(); break;
            default: cout << "Неверный ввод. Пробуйте снова.\n";
        }
    }
    return 0;
}