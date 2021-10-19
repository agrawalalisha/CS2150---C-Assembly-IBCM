// Name: Alisha Agrawal
// ID: aa3ae
// Date: 04/12/2021
// mathfun.cpp

#include <iostream>
#include <cstdlib>

using namespace std;

extern "C" long product(long, long);
extern "C" long power(long, long);

int main() {
  int x;
  int y;
  int prodRes;
  int powRes;

  cout << "Enter integer: " << endl;
  cin >> x;

  cout << "Enter integer: " << endl;
  cin >> y;

  prodRes = product(x,y);
  powRes = power(x,y);

  cout << "Product: " << prodRes << endl;
  cout << "Power: " << powRes << endl;

  return 0;

}
