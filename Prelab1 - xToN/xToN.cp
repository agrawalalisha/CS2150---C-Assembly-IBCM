// Name: ALisha Agrawal
// ID: aa3se
// Date: 02/15/2021
// xToN.cpp
#include <iostream>
using namespace std;

int xton(int base, int power){
  if (power != 0)
    return base*xton(base, power - 1);
  else
    return 1;
 }

int main(){
  int x, y, z;
  cin >> x;
  cin >> y;
  z = xton(x,y);
  cout << z << endl;
  return 0;
}



