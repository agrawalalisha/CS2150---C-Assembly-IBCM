// Name: Alisha Agrawal
// ID: aa3se
// 03/13/2021
// prelab4.cpp

#ifndef PRELAB4
#define PRELAB4

#include <iostream>
#include <string>
#include <climits>

using namespace std;

class Prelab4 {
public:
  Prelab4(); //constructor

  //prints sizes of various types
  void sizeOfTest();

  //handle integer overflow
  void overflow();

  //display the binary representation of integers
  void outputBinary(unsigned int i);
};

Prelab4::Prelab4() { // constructor
}

void Prelab4::sizeOfTest() {
  float f = 1.0;
  double d = 1.0;
  int* i = NULL;
  char* c = NULL;
  double* d2 = NULL;
  cout << "Size of int:  " << sizeof(-4) << endl;         // 4
  cout << "Size of unsigned int:  " << sizeof(5) << endl; // 4
  cout << "Size of float:  " << sizeof(f) << endl;        // 4
  cout << "Size of double:  " << sizeof(d) << endl;       // 8
  cout << "Size of char:  " << sizeof('a') << endl;       // 1
  cout << "Size of bool:  " << sizeof(true) << endl;      // 1
  cout << "Size of int*:  " << sizeof(i) << endl;         // 8
  cout << "Size of char*:  " << sizeof(c) << endl;        // 8
  cout << "Size of double*:  " << sizeof(d2) << endl;     // 8
	
}

void Prelab4::overflow() {
  // UINT_MAX is the maximum value for an object of type unsigned int;
  unsigned int a = UINT_MAX; 
  cout << a << " + 1 = " << a + 1 << endl;
}

void Prelab4::outputBinary(unsigned int i) {
  int dec = i;
  char bin[] = "0000 0000 0000 0000 0000 0000 0000 0000";
  
  // traverse through array using for loop
  for(int len = 38; len >=0; len--) { // traverse backward
    // every index at a whitespace / 5 has a remainder of 4
    // ex. 34 % 5 = 4 and 29 % 5 = 4
    if((len%5) == 4) { // checks for blank space to
      bin[len] = ' ';             // skip conversion algorithm 
    }
    else {
      if(dec%2 == 1){           // if there is a remainder
	bin[len] = '1';           // set position with 1
      }
      dec /= 2;                 // divide by 2 
    }
    
  }
    
  cout << bin << endl;

}


int main() {
  int x;
  cin >> x;                    // takes in user input

  Prelab4 test;
  test.sizeOfTest();
  test.overflow();
  test.outputBinary(x);

  return 0;

}

#endif
