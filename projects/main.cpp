#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main ()
{
  int pres = 2;
  string str;
  double pi;

  std::cout << "Please, enter precision: ";
  std::cin >> pres;

  pi = (4 * (4 * atan(1.0f / 5.0f) - atan(1.0f / 239.0f)));

  str = "%." + to_string(pres) + "f";

  std::cout << str << endl;

  // printf ("pi = %s\n", str);
  return 0;
}
