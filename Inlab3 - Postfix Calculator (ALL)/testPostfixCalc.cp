// Name: Alisha Agrawal
// ID: aa3se
// Date: 02/28/2021
// 'testPostfixCalc.cpp'

#include <iostream>
#include "postfixCalculator.h"
#include <string>
#include <cstdlib>
#include <stack>

using namespace std;


int main(){
  PostfixCalculator calc;
  
  string token;
  char neg = '-';

  while (cin >> token) {
    // integer check
    if(isdigit(token[0])) { 
      calc.push(stoi(token));
    }

    // negative integer check
    else if(token.size() > 1 && token[0] == neg) {
      calc.push(stoi(token));
    }

    // addition operator check	
    else if(token == "+") {
      calc.add();

    }
    // subtration operator check
    else if(token == "-") {
      calc.sub();
    }

    // multiplication operator check
    else if(token == "*") {
      calc.multiply();
	
    }

    // division operator check
    else if(token == "/") {
      calc.divide();

    }

    // negation operator check
    else if(token == "~") {
      calc.negate();

    }	  
  }
  
  cout << calc.top() << endl; // prints answer (value at top of stack)
  return 0;
}
