#include <iostream>

int get_change(int m) {
  // 1. how many 10s
  int n10 = (m - (m % 10)) / 10;

  // 2. how many 5s
  int wo10 = m - n10*10;
  int n5 = (wo10 - (wo10 % 5)) / 5;

  int n1 = m - n10*10 - n5*5;
  int n = n1 + n10 + n5;
  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
