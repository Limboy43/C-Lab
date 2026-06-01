#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    string name;
    int age;
    string hobby;   // новий член класу
};

void print(Person* person) {
    cout << person->name << " is " << person->age
        << " years old and likes " << person->hobby << endl;
}

int main() {
    Person p1;
    p1.name = "Harry";
    p1.age = 23;
    p1.hobby = "football";

    Person p2;
    p2.name = "Kate";
    p2.age = 19;
    p2.hobby = "painting";

    Person p3;
    p3.name = "Alex";
    p3.age = 30;
    p3.hobby = "coding";

    print(&p1);
    print(&p2);
    print(&p3);

    return 0;
}