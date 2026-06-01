#include <iostream>
#include <cmath>

using namespace std;

// Функція перевіряє чи є число простим
bool isPrime(int num) {

    // Числа менші за 2 не прості
    if (num < 2) {
        return false;
    }

    // Перевірка дільників
    for (int i = 2; i <= sqrt(num); i++) {

        // Якщо ділиться без остачі
        if (num % i == 0) {
            return false;
        }
    }

    // Число просте
    return true;
}

int main() {

    int number;

    cout << "Введіть число: ";
    cin >> number;

    // Перевірка числа
    if (isPrime(number)) {
        cout << "Число просте";
    }
    else {
        cout << "Число не просте";
    }

    return 0;
}