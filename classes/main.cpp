#include <iostream>
#include "burrito.h"

using namespace std;
int tuna = 69;

int bucky[5] = {1,2,3,4,5};

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

    cout << ::tuna << endl;

    cout << "array elem" << bucky[2] << endl;


    // pointers
    int fish = 5;
    int *fishPointer;

    fishPointer = &fish;

    cout << "fishPointer: " << fishPointer << endl;

    return 0;
}

