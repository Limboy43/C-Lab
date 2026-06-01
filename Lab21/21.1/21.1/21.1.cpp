#include <iostream>
using namespace std;

class FlightBooking {
public:
    FlightBooking(int id, int capacity, int reserved);
    void printStatus();

private:
    int id;
    int capacity;
    int reserved;
};

FlightBooking::FlightBooking(int id, int capacity, int reserved) {
    this->id = id;
    this->capacity = capacity;
    this->reserved = reserved;
}

void FlightBooking::printStatus() {
    double percentage = (capacity == 0) ? 0 : (100.0 * reserved / capacity);
    cout << "Flight " << id << " : " << reserved << "/" << capacity
        << " (" << percentage << "%) seats reserved" << endl;
}

int main() {
    int reserved, capacity;
    cout << "Provide flight capacity: ";
    cin >> capacity;
    cout << "Provide number of reserved seats: ";
    cin >> reserved;

    FlightBooking booking(1, capacity, reserved);
    booking.printStatus();

    return 0;
}