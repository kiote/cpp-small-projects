#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int get_freq(vector<int> &a, int x, int begin, int end) {
  int count = 0, i = begin;
  while (i < end) {
    if (a[i] == x) {
      ++count;
    }
    ++i;
  }
  cout << "freq of " << x << ": " <<count << endl;
  return count;
}

int get_majority_element(vector<int> &a, int left, int right, int n) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  int middle = left + (right-left)/2;
  cout << "left: " << left << ";right=" << right << ";middle=" << middle << endl;
  
  int leftElem = get_majority_element(a, left, middle, n);
  cout << "leftElem: " << leftElem << endl;
  int rightElem = get_majority_element(a, middle+1, right, n);
  cout << "rightElem: " << rightElem << endl;

  if (leftElem == rightElem) {
    return leftElem;
  }

  int lCount = get_freq(a, leftElem, left, middle);
  int rCount = get_freq(a, rightElem, middle+1, right);

  if (lCount > n) {
    return leftElem;
  } else if (rCount > n) {
    return rightElem;
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
  std::cout << (get_majority_element(a, 0, a.size(), n/2) != -1) << '\n';
}
