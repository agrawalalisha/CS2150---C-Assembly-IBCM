// Name: Alisha Agrawal
// ID: aa3se
// Date: 03/04/2021
// Stack.h

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "stackNode.h"
using namespace std;


class Stack {
public:
  Stack(); // constructor
  ~Stack(); // destructor
  bool isEmpty(); // checks if stack is empty
  void push(int value); //add value to top of stack
  void pop(); // remove top value from stack
  int top() const; // returns value at top of stack
  int size() const; // returns size of stack

private:
  StackNode *head;
  StackNode *tail;
  int count;


  friend class StackNode;
  friend class postfixCalculator;
};

#endif
