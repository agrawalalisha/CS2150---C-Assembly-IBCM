// Name: Alisha Agrawal
// ID: aa3se
// Date: 03/04/2021
// stackNode.h

#ifndef STACKNODE_H
#define STACKNODE_H

#include <iostream>
using namespace std;

class StackNode {
 public:
  StackNode();     // constructor

 private:
  int value;       // integer value of node
  StackNode *next; // next node in the stack
  StackNode * previous; // previous node in the stack

  friend class Stack;
  friend class postfixCalculator;

  //Not writing a destructor is fine in this case since there is no
  // dynamically allocated memory in this class
  
};

#endif
