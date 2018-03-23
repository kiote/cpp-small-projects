#include <iostream>

using namespace std;

void printCrap(int x) {
    cout << "my favorite number is " << x << endl;
}

class mySuperClass {
private:
    string name;

public:
    void coolSaying() {
        cout << "some crap" << endl;
    }

    mySuperClass setName(string x) {
        name = x;
        return *this;
    }

    string getName() {
        return name;
    }
};

int main() {
    printCrap(20);
    mySuperClass obj;

    cout << obj.setName("hi2").getName() << endl;
    obj.coolSaying();
    return 0;
}

