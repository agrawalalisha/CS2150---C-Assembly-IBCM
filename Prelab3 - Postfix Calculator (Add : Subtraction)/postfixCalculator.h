// Name: Alisha Agrawal
// ID: aa3se
// Date: 02/28/2021
// 'postfixCalculator.h'

#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

#include <iostream>
#include <cstdlib>
#include <stack>
using namespace std;

class PostfixCalculator {
 public:
  
  // Default Constructor
  PostfixCalculator();

  // Adds the passed element to the top of the stack
  void push(int x);

  // Returns the element at the top of the stack
  // Does not remove elemtn from the top
  // If stack is empty -> error message is printed
  int top();

  // Removes element on the top of the stack
  // Does not return element
  // If stack is empty -> error message is printed
  void pop();

  // Returns true if the stack is empty
  bool empty();

  
  void add();
  void sub();
  void multiply();
  void divide();
  void negate();

 private:
  stack<int> s;

};

#endif
  
