#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int get_freq(vector<int> &a, int x) {
  if (x == -1) {
    return 0;
  }
  int count = 0, i = 0, end = a.size()-1;
  while (i <= end) {
    if (a[i] == x) {
      ++count;
    }
    ++i;
  }
  // cout << "freq of " << x << ": " <<count << endl;
  return count;
}

int get_majority_element(vector<int> &a, int left, int right) {
  int n = right-left-1;
  // cout << endl << "major: left=" << left << ";right="<< right <<";n=" <<n;
  if (n <= 0) {
    return -1;
  }
  if (n == 1) {
    return a[0];
  }

  int k = right / 2;
  // cout << ";k=" << k <<endl;

  if (left > 0) {
    k = left + (right-left)/2;
  }

  // cout << "major: lElem for " << "left="<<0<<";right="<<k<<";n="<< n << endl;
  int lElem = get_majority_element(a, 0, k);
  // cout << "major: rElem for " << "left="<<k+1<<";right="<<right<<";n="<<n << endl;
  int rElem = get_majority_element(a, k+1, right);

  if (lElem == rElem) {
    return lElem;
  }

  int lCount = get_freq(a, lElem);
  // cout << endl << "major: k=" << k << ";lCount="<< lCount << endl;
  if (lCount >= k+1) {
    return lElem;
  }

  int rCount = get_freq(a, rElem);
  
  if (rCount >= k+1) {
    return rElem;
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
