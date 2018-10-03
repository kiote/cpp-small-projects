#include <iostream>
#include <vector>

using namespace std;

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int get_fibonacci_last_digit_fast(int n) {
  if (n <= 1) {
    return n;
  }

  vector<int> fibon;
  fibon.push_back(0);
  fibon.push_back(1);

  for (int i=2; i<=n; ++i) {
    fibon.push_back((fibon[i-1] + fibon[i-2])%10);
  }

  return fibon[n];
}

int main() {
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit_fast(n);
    std::cout << c << '\n';
}
