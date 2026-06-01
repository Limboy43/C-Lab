#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int gcd(int a, int b) {
    return b == 0 ? abs(a) : gcd(b, a % b);
}

class Fraction {
public:
    Fraction(int numerator, int denominator) {
        this->numerator = numerator;
        this->denominator = denominator;
        reduce();
    }

    string toString() {
        int whole = numerator / denominator;
        int rem = numerator % denominator;
        if (rem == 0) return to_string(whole);
        if (whole != 0) return to_string(whole) + " " + to_string(abs(rem)) + "/" + to_string(abs(denominator));
        return to_string(numerator) + "/" + to_string(denominator);
    }

    double toDouble() {
        return (double)numerator / denominator;
    }

    bool isGreaterThan(Fraction that) {
        return numerator * that.denominator > that.numerator * denominator;
    }

    bool isLessThan(Fraction that) {
        return numerator * that.denominator < that.numerator * denominator;
    }

    bool isEqual(Fraction that) {
        return numerator * that.denominator == that.numerator * denominator;
    }

private:
    int numerator;
    int denominator;

    void reduce() {
        int g = gcd(numerator, denominator);
        numerator /= g;
        denominator /= g;
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }
};

int main() {
    string input1, input2;
    getline(cin, input1);
    getline(cin, input2);

    int num1, den1, num2, den2;
    char slash;
    stringstream ss1(input1), ss2(input2);
    ss1 >> num1 >> slash >> den1;
    ss2 >> num2 >> slash >> den2;

    Fraction f1(num1, den1), f2(num2, den2);

    if (f1.isGreaterThan(f2))
        cout << f1.toString() << " > " << f2.toString() << endl;
    else if (f1.isLessThan(f2))
        cout << f1.toString() << " < " << f2.toString() << endl;
    else
        cout << f1.toString() << " = " << f2.toString() << endl;

    return 0;
}