// Name: Alisha Agrawal
// ID: aa3se
// 03/18/2021
// bitCounter.cpp

#ifndef BITCOUNTER
#define BITCOUNTER

#include <iostream>
#include <string>
using namespace std;

class BitCounter {
public:
  BitCounter();

  
  // returns the number of 1s in the binary representation of an integer
  int bitCounter(int n);

  // returns a integer converted from one base to another
  void baseConverter(string num, int startBase, int endBase);

  
  // helper method that returns a integer converted from characters to integers using ascii
  int charToInt(char c);

  // helper method that returns a character convereted from ascii
  char asciiConverter(char c);

  // helper method that returns an int converted from one base to decimal
  int startToDec(string num, int startBase);

};


BitCounter::BitCounter(){} // constructer

int BitCounter::bitCounter(int n) {
  // if n is even
  if(n%2 == 0 && n != 0) {
    return bitCounter(n/2);
  }
  // if n is odd
  if(n%2 == 1) {
    return 1 + bitCounter(n/2);
  }
  return 0;
}

void BitCounter::baseConverter(string num, int startBase, int endBase){
  
  int dec = startToDec(num, startBase); // convert from starting base to decimal using helper method

  
  string result = "";                   // will store output
  while (dec > 0) {
    char value = dec % endBase;         // gets converted value in decimal representation
    value = asciiConverter(value);      // convert to ascii representation using helper method
    result = value + result;            // add to end of result;
    dec /= endBase;                     // float division by base
    
  }
  
  cout << num << " (base " << startBase << ") = " << result << " (base " << endBase<< ")" << endl;

}


int BitCounter::charToInt(char c) {
  if(c >= '0' && c <= '9') {
    // value of '0' = 48
    return (int)c - '0';
  }
  else {
    // subtract 65 than add 10 to get postive number
    return ((int)c - 'A') + 10; 
  }

}

char BitCounter::asciiConverter(char value) {
 if(value >= 0 && value <= 9) {
      return value + '0';
    }
    else {
      // add 65 then subtract
      return (value + 'A') - 10; 
    }

}


int BitCounter::startToDec(string num, int startBase){
  int length = num.length(); // find length of number
  int pow = 1;               // the first digit is always to the 0th power = 1
  int dec = 0;               // sum all of the values to get decimal conversion
  for (int i = length - 1; i >= 0; i--) {
    dec += charToInt(num[i]) * pow;
    pow *= startBase;        // increase in power as we move a tens place
  }

  return dec;
}


int main(int argc, char *argv[]){

  // check if enough parameters were entered
  if(argv[1] == NULL || argv[2] == NULL || argv[3] == NULL || argv[4] == NULL) {
    cout << "Not enough parameters were entered" << endl;
    exit(-1);
  }
  
  
  BitCounter test;

  string bin(argv[1]);
  string num(argv[2]);
  string sBase(argv[3]);
  string eBase(argv[4]);

  int n = stoi(bin);
  int startBase = stoi(sBase);
  int endBase = stoi(eBase);

  cout << n << " has " << test.bitCounter(n) << " bit(s)" << endl;
  test.baseConverter(num, startBase, endBase);

  


}

#endif

