// Lab 4.5.7
// Text manipulation: password validation

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {

    // Змінна для збереження пароля
    string password;

    // Зчитування пароля
    getline(cin, password);

    // Прапорці для перевірки умов
    bool hasUpper = false;
    bool hasLower = false;
    bool hasDigit = false;
    bool hasSpecial = false;

    // Перевірка кожного символу пароля
    for (char ch : password) {

        // Якщо велика літера
        if (isupper(ch))
            hasUpper = true;

        // Якщо маленька літера
        else if (islower(ch))
            hasLower = true;

        // Якщо цифра
        else if (isdigit(ch))
            hasDigit = true;

        // Якщо спеціальний символ
        else
            hasSpecial = true;
    }

    // Прапорець правильності пароля
    bool valid = true;

    // Перевірка довжини
    if (password.length() < 8) {
        cout << "The password must be 8 characters long" << endl;
        valid = false;
    }

    // Перевірка великої літери
    if (!hasUpper) {
        cout << "The password must have at least one upper case letter" << endl;
        valid = false;
    }

    // Перевірка маленької літери
    if (!hasLower) {
        cout << "The password must have at least one lower case letter" << endl;
        valid = false;
    }

    // Перевірка цифри
    if (!hasDigit) {
        cout << "The password must have at least one digit" << endl;
        valid = false;
    }

    // Перевірка спеціального символу
    if (!hasSpecial) {
        cout << "The password must have at least one special character" << endl;
        valid = false;
    }

    // Якщо всі умови виконані
    if (valid)
        cout << "The password is valid" << endl;

    return 0;
}