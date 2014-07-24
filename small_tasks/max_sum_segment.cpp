#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
  // random array
  int size = 10;
  // cout<< "Size: " << endl;
  // cin >> size;

  int array[size];

  srand(time(0));

  int rnd;
  for(int i=0; i<size; i++) {
    rnd = rand();
    array[i] = (rnd%100)+1;
    if (rnd%2) array[i] = -array[i];

    cout << array[i] << endl;
  }

  // summing
  int tmp_begin=0, tmp_end=0, max_begin=0, max_end=0, tmp_sum=array[0], max_sum=array[0];

  for(int i=1; i<size; i++) {
    tmp_end = i;
    tmp_sum += array[i];
    cout << "----" << i << "----" << endl;
    cout << "tmp_sum=" << tmp_sum << endl;
    cout << "max_sum=" << max_sum << endl;
    if (max_sum < tmp_sum) {
      max_sum = tmp_sum;
      max_begin = i;
      max_end = tmp_end;
      tmp_begin = i;
    }
  }

  cout << max_sum;
}
