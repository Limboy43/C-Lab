#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Fraction {
public:
    Fraction(int numerator, int denominator) {
        this->numerator = numerator;
        this->denominator = denominator;
    }

    string toString() {
        int whole = numerator / denominator;
        int rem = numerator % denominator;

        // знак
        if ((denominator < 0 && numerator > 0) || (numerator < 0 && denominator > 0)) {
            numerator = -abs(numerator);
            denominator = abs(denominator);
        }

        if (rem == 0) return to_string(whole);
        if (whole != 0) return to_string(whole) + " " + to_string(abs(rem)) + "/" + to_string(abs(denominator));
        return to_string(numerator) + "/" + to_string(denominator);
    }

    double toDouble() {
        return (double)numerator / denominator;
    }

private:
    int numerator;
    int denominator;
};

int main() {
    string input;
    getline(cin, input);
    int num, den;
    char slash;
    stringstream ss(input);
    ss >> num >> slash >> den;

    Fraction fraction(num, den);
    cout << fraction.toString() << " is " << fraction.toDouble() << " in decimal" << endl;
    return 0;
}