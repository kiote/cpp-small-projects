#include <iostream>

using namespace std;

int main() {
  static const int N = 10;
  int i, p, q, id[N];
  for (i = 0; i < N; i++) {
    id[i] = i;
  }
  while (cin >> p >> q) {
    int t = id[p];
    if (t == id[q]) {
      continue;
    }
    for (i = 0; i < N; i++) {
      if (id[i] == t) {
        id[i] = id[q];
      }
    }
  }
  for (i = 0; i < N; i++) {
    cout << id[i] << " ";
  }
  cout << endl;
  return 0;
}
