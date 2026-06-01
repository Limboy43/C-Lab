#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class IPAddress {
public:
    IPAddress(string value) : value(value) {}
    IPAddress(const IPAddress& other) { value = other.value; }

    virtual void print() {
        cout << value << endl;
    }

protected:
    string value;
};

class IPAddressChecked : public IPAddress {
public:
    IPAddressChecked(string value) : IPAddress(value) {
        correct = checkValid(value);
    }

    IPAddressChecked(const IPAddressChecked& other) : IPAddress(other) {
        correct = other.correct;
    }

    void print() override {
        cout << value << " - " << (correct ? "Correct" : "Not Correct") << endl;
    }

private:
    bool correct;

    bool checkValid(string ip) {
        stringstream ss(ip);
        string part;
        int count = 0;
        while (getline(ss, part, '.')) {
            count++;
            if (count > 4) return false;
            if (part.empty()) return false;
            int num = stoi(part);
            if (num < 0 || num > 255) return false;
        }
        return count == 4;
    }
};

int main() {
    string ip1, ip2, ip3;
    getline(cin, ip1);
    getline(cin, ip2);
    getline(cin, ip3);

    IPAddress addr(ip1);
    IPAddressChecked addr2(ip2);
    IPAddressChecked addr3(ip3);

    addr.print();
    addr2.print();
    addr3.print();

    return 0;
}