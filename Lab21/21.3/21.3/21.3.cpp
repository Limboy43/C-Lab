#include <iostream>
#include <string>
using namespace std;

class FlightBooking {
public:
    FlightBooking(int id, int capacity, int reserved);
    FlightBooking();
    void printStatus();
    bool reserveSeats(int number_of_seats);
    bool cancelReservations(int number_of_seats);
    int getId() { return id; }

private:
    int id;
    int capacity;
    int reserved;
};

FlightBooking::FlightBooking() {
    id = 0; capacity = 0; reserved = 0;
}

FlightBooking::FlightBooking(int id, int capacity, int reserved) {
    this->id = id;
    this->capacity = capacity;
    if (reserved < 0) reserved = 0;
    if (reserved > capacity * 1.05) reserved = capacity * 1.05;
    this->reserved = reserved;
}

void FlightBooking::printStatus() {
    if (id == 0) return;
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
    FlightBooking flights[10];
    string command;

    while (command != "quit") {
        bool anyFlight = false;
        for (int i = 0; i < 10; i++) {
            if (flights[i].getId() != 0) {
                flights[i].printStatus();
                anyFlight = true;
            }
        }
        if (!anyFlight) cout << "No flights in the system" << endl;

        cout << "What would you like to do?: ";
        getline(cin, command);

        if (command.find("create") == 0) {
            int id, cap;
            sscanf(command.c_str(), "create %d %d", &id, &cap);
            for (int i = 0; i < 10; i++) {
                if (flights[i].getId() == 0) {
                    flights[i] = FlightBooking(id, cap, 0);
                    break;
                }
            }
        }
        else if (command.find("delete") == 0) {
            int id;
            sscanf(command.c_str(), "delete %d", &id);
            bool found = false;
            for (int i = 0; i < 10; i++) {
                if (flights[i].getId() == id) {
                    flights[i] = FlightBooking();
                    found = true;
                }
            }
            if (!found) cout << "Cannot perform this operation: flight " << id << " not found" << endl;
        }
        else if (command.find("add") == 0) {
            int id, n;
            sscanf(command.c_str(), "add %d %d", &id, &n);
            bool found = false;
            for (int i = 0; i < 10; i++) {
                if (flights[i].getId() == id) {
                    found = true;
                    if (!flights[i].reserveSeats(n))
                        cout << "Cannot perform this operation: capacity reached" << endl;
                }
            }
            if (!found) cout << "Cannot perform this operation: flight " << id << " not found" << endl;
        }
        else if (command.find("cancel") == 0) {
            int id, n;
            sscanf(command.c_str(), "cancel %d %d", &id, &n);
            bool found = false;
            for (int i = 0; i < 10; i++) {
                if (flights[i].getId() == id) {
                    found = true;
                    if (!flights[i].cancelReservations(n))
                        cout << "Cannot perform this operation" << endl;
                }
            }
            if (!found) cout << "Cannot perform this operation: flight " << id << " not found" << endl;
        }
    }
    return 0;
}