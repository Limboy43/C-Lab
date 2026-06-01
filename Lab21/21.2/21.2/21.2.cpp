#include <iostream>
#include <string>
using namespace std;

class FlightBooking {
public:
    FlightBooking(int id, int capacity, int reserved);
    void printStatus();
    bool reserveSeats(int number_of_seats);
    bool cancelReservations(int number_of_seats);

private:
    int id;
    int capacity;
    int reserved;
};

FlightBooking::FlightBooking(int id, int capacity, int reserved) {
    this->id = id;
    this->capacity = capacity;
    if (reserved < 0) reserved = 0;
    if (reserved > capacity * 1.05) reserved = capacity * 1.05;
    this->reserved = reserved;
}

void FlightBooking::printStatus() {
    double percentage = (capacity == 0) ? 0 : (100.0 * reserved / capacity);
    cout << "Flight " << id << " : " << reserved << "/" << capacity
        << " (" << percentage << "%) seats reserved" << endl;
}

bool FlightBooking::reserveSeats(int number_of_seats) {
    if (reserved + number_of_seats <= capacity * 1.05) {
        reserved += number_of_seats;
        return true;
    }
    return false;
}

bool FlightBooking::cancelReservations(int number_of_seats) {
    if (reserved - number_of_seats >= 0) {
        reserved -= number_of_seats;
        return true;
    }
    return false;
}

int main() {
    int reserved, capacity;
    cout << "Provide flight capacity: ";
    cin >> capacity;
    cout << "Provide number of reserved seats: ";
    cin >> reserved;

    FlightBooking booking(1, capacity, reserved);

    string command;
    while (command != "quit") {
        booking.printStatus();
        cout << "What would you like to do?: ";
        cin >> command;
        if (command == "add") {
            int n; cin >> n;
            if (!booking.reserveSeats(n)) cout << "Cannot perform this operation" << endl;
        }
        else if (command == "cancel") {
            int n; cin >> n;
            if (!booking.cancelReservations(n)) cout << "Cannot perform this operation" << endl;
        }
    }
    return 0;
}