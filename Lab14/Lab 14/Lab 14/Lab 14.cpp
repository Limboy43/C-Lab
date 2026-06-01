#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));

    int n = 10; // кількість елементів масиву

    // створення динамічного масиву
    float* arr = new float[n];

    int positive = 0;
    int negative = 0;

    // заповнення та виведення масиву
    cout << "Елементи масиву:\n";

    for (int i = 0; i < n; i++) {
        // випадкові числа в діапазоні (-2; 2)
        arr[i] = -2 + static_cast<float>(rand()) / RAND_MAX * 4;

        cout << arr[i] << " ";

        if (arr[i] > 0)
            positive++;
        else if (arr[i] < 0)
            negative++;
    }

    cout << "\n\nКількість додатних чисел: " << positive << endl;
    cout << "Кількість від'ємних чисел: " << negative << endl;

    // звільнення пам'яті
    delete[] arr;

    return 0;
}