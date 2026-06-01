// Lab 4.5.8
// Text manipulation: templates

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {

    // Рядок з name=value парами
    string values;
    getline(cin, values);

    // Шаблонний текст
    string text;
    getline(cin, text);

    // Контейнер для збереження пар
    map<string, string> data;

    // Початкова позиція
    size_t start = 0;

    // Розбір усіх пар name=value
    while (start < values.length()) {

        // Пошук коми
        size_t comma = values.find(',', start);

        string pair;

        // Якщо коми більше немає
        if (comma == string::npos)
            pair = values.substr(start);

        // Взяти підрядок до коми
        else
            pair = values.substr(start, comma - start);

        // Пошук знака =
        size_t eq = pair.find('=');

        // Якщо = знайдено
        if (eq != string::npos) {

            // Отримати ім'я
            string name = pair.substr(0, eq);

            // Отримати значення
            string value = pair.substr(eq + 1);

            // Додати у map
            data[name] = value;
        }

        // Завершення циклу
        if (comma == string::npos)
            break;

        // Перехід після коми
        start = comma + 1;
    }

    // Позиція пошуку шаблону
    size_t pos = 0;

    // Пошук конструкцій [name]
    while ((pos = text.find('[', pos)) != string::npos) {

        // Пошук ]
        size_t end = text.find(']', pos);

        // Якщо ] не знайдено
        if (end == string::npos)
            break;

        // Отримати ключ без дужок
        string key = text.substr(pos + 1, end - pos - 1);

        // Якщо ключ існує у map
        if (data.count(key)) {

            // Замінити [key] на значення
            text.replace(pos, end - pos + 1, data[key]);

            // Перехід після вставленого тексту
            pos += data[key].length();
        }
        else {

            // Якщо ключ не знайдений
            pos = end + 1;
        }
    }

    // Виведення результату
    cout << text << endl;

    return 0;
}