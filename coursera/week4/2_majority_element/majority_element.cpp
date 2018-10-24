#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int get_freq(vector<int> &a, int x, int left, int right) {
  if (x == -1) {
    return 0;
  }
  int count = 0, i = left;
  while (i <= right) {
    if (a[i] == x) {
      ++count;
    }
    ++i;
  }
  // cout << "freq of " << x << ": " << count << endl;
  return count;
}

int get_majority_element(vector<int> &a, int left, int right) {
  int size = a.size();

  int max = (right-left)/2;

  if (size%2 == 0) {
    ++max;
  }

  if (left == right) {
    return -1;
  }
  if ((left + 1) == right) {
    return a[left];
  }

  int k = (left + right - 1)/2 + 1;
  int leftM = get_majority_element(a, left, k);
  int rightM = get_majority_element(a, k, right);

  // cout << "max: " << max << endl;

  int leftCount = get_freq(a, leftM, left, right);
  if (leftCount > max) {
    return leftCount;
  }

  int rightCount = get_freq(a, rightM, left, right);
  if (rightCount > max) {
    return rightCount;
  }

  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()-1) != -1) << '\n';
}
