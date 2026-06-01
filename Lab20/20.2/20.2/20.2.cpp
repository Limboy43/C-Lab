#include <iostream>
using namespace std;

class Square {
private:
    double side;
    double area;

public:
    Square(double side) {
        set_side(side);
    }

    void set_side(double s) {
        if (s >= 0) {
            side = s;
            area = side * side;
        }
    }

    void print() {
        cout << "Square: side=" << side << " area=" << area << endl;
    }
};