#include <iostream>
#include <ctime>

using namespace std;

// структура для збереження дати
struct Date {
    int year;
    int month;
    int day;
};

// перевірка на високосний рік
bool isLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// кількість днів у місяці
int monthLength(int year, int month) {
    int days[] = { 31, 28, 31, 30, 31, 30,
                  31, 31, 30, 31, 30, 31 };

    if (month == 2 && isLeap(year))
        return 29;

    return days[month - 1];
}

// функція отримання поточної дати
Date today(void) {
    time_t t = time(NULL);
    tm tl = *localtime(&t);

    Date current;

    current.year = tl.tm_year + 1900;
    current.month = tl.tm_mon + 1;
    current.day = tl.tm_mday;

    return current;
}

// функція підрахунку кількості днів від 01.01.0001 до заданої дати
long countDays(Date d) {
    long days = 0;

    // додаємо дні за роки
    for (int y = 1; y < d.year; y++) {
        if (isLeap(y))
            days += 366;
        else
            days += 365;
    }

    // додаємо дні за місяці
    for (int m = 1; m < d.month; m++) {
        days += monthLength(d.year, m);
    }

    // додаємо дні поточного місяця
    days += d.day;

    return days;
}

int main() {
    // введення дати народження
    Date birth;

    cout << "Введіть дату народження:\n";
    cout << "Рік: ";
    cin >> birth.year;

    cout << "Місяць: ";