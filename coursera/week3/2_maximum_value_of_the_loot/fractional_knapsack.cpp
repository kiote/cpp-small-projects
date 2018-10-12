#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Product {
  int weight;
  int value;
  double price;
};

bool sortByPrice(const Product &lhs, const Product &rhs) { return lhs.price > rhs.price; };

double get_optimal_value(int n, int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;

  // calculate prices list
  vector<Product> products(weights.size());
  for (int i=0; i<weights.size(); ++i) {
    products[i].weight = weights[i];
    products[i].value = values[i];
    products[i].price = (double)values[i] / weights[i];
  }

  // sort
  sort(products.begin(), products.end(), sortByPrice);

  //for (int i=0; i<weights.size(); ++i) {
  //  cout << endl << "i=" << i << "; weigth=" << products[i].weight << endl;
  //  cout << "i=" << i << "; value=" << products[i].value << endl;
  //  cout << "i=" << i << "; price=" << products[i].price << endl;
  //}

  // put stuff to the knapsack
  int curN = 0;
  int curCapacity = 0;
  int capacityLeft = capacity-curCapacity;
  while ((curN < n) && (capacityLeft > 0)) {
    // try to get the whole of the most expensive product
    if (products[curN].weight <= capacityLeft) {
      curCapacity += products[curN].weight;
      value += (double)products[curN].value;
      capacityLeft = capacity-curCapacity;
    }
    // try to get the biggest chunk if the most expensive product
    else {
      value += products[curN].price * (double)capacityLeft;
      capacityLeft = 0; 
    }
    curN++;
  }

  return (double)value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(n, capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
