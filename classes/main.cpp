#include <iostream>
#include "burrito.h"

using namespace std;

void printCrap(int x) {
    cout << "my favorite number is " << x << endl;
}

class MySuperClass {
private:
    string name;

public:
    MySuperClass(string n) {
        name = n;
    }
    void coolSaying() {
        cout << "some crap" << endl;
    }

    MySuperClass setName(string x) {
        name = x;
        return *this;
    }

    string getName() {
        return name;
    }
};

int main() {
    printCrap(20);
    MySuperClass Obj("hola!");

    cout << Obj.getName() << endl;
    Obj.coolSaying();

    Burrito b;

    return 0;
}

