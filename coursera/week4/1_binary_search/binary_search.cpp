#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

using namespace std;


int binarySearch(const vector<int> &arr, int l, int r, int x) 
{ 
  if (r < l) {
    return -1;
  }

  int mid = l + (r - l)/2; 

  if (arr[mid] == x)   
      return mid; 
  if (arr[mid] > x) {
      return binarySearch(arr, l, mid-1, x);
  }
  return binarySearch(arr, mid+1, r, x); 
} 

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  int i = 0;
  int size = a.size()-1;
  while (i < m) {
    cout << binarySearch(a, 0, size, b[i]) << ' ';
    ++i;
  }
}
