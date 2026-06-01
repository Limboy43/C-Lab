#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));

    int rows = 3;
    int cols = 3;

    // створення двовимірного динамічного масиву
    int** arr = new int* [rows];

    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }

    int even = 0;
    int odd = 0;

    // заповнення масиву випадковими числами
    cout << "Масив:\n";

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = rand() % 100; // числа від 0 до 99

            cout << arr[i][j] << "\t";

            if (arr[i][j] % 2 == 0)
                even++;
            else
                odd++;
        }
        cout << endl;
    }

    // головна діагональ
    cout << "\nЕлементи головної діагоналі:\n";
    for (int i = 0; i < rows; i++) {
        cout << arr[i][i] << " ";
    }

    // побічна діагональ
    cout << "\n\nЕлементи побічної діагоналі:\n";
    for (int i = 0; i < rows; i++) {
        cout << arr[i][cols - 1 - i] << " ";
    }

    // кількість парних та непарних
    cout << "\n\nКількість парних елементів: " << even << endl;
    cout << "Кількість непарних елементів: " << odd << endl;

    // звільнення пам'яті
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }

    delete[] arr;

    return 0;
}