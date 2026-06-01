#include <iostream>

using namespace std;

// ---------------------------------------------------
// Функція increment з одним аргументом
// Збільшує змінну на 1
// ---------------------------------------------------
void increment(int& var) {

    var++;

}

// ---------------------------------------------------
// Перевантажена функція increment
// Збільшує змінну на значення value
// ---------------------------------------------------
void increment(int& var, int value) {

    var += value;

}

int main(void) {

    int var = 0;

    for (int i = 0; i < 10; i++)

        // Якщо число непарне
        if (i % 2)

            // Збільшуємо на 1
            increment(var);

        else

            // Збільшуємо на i
            increment(var, i);

    cout << var << endl;

    return 0;
}