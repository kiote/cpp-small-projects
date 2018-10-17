#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> numbers;
    int curNum = 0;
    
    while (curNum != 42) {
        cin >> curNum;
        numbers.push_back(curNum);
    }

    cin >> curNum;
    numbers.push_back(curNum);
    
    for (int i=0; i<numbers.size()-1; ++i) {
        cout << numbers[i] << endl;
    }

    return 0;
}
