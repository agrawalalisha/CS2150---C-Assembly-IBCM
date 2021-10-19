// Name: Alisha Agrawal
// ID: aa3se
// Date: 03/04/2021
// Stack.cpp

#include <iostream>
#include <string>
#include "Stack.h"
#include "stackNode.h"

Stack::Stack() { // default  constructor
  head = new StackNode;
  tail = new StackNode;
  head->next = tail;
  tail->previous = head;
  count = 0;
}

Stack::~Stack() { // deconstructor
  while(!isEmpty()) {
    pop();
  }

  delete head;
  delete tail;

}

// if stack is empty-> return true
bool Stack::isEmpty() {
  if(head->next == tail || count == 0) {
    return true;
  }
  
  return false;
}

// adds element to tail (top of stack)
void Stack::push(int x) {
  StackNode* newNode = new StackNode;
  newNode->value = x;
  newNode->previous = tail->previous;
  newNode->next = tail;
  tail->previous->next = newNode;
  tail->previous = newNode;
  count++;
}

// removes element at tail (top of stack)
void Stack::pop(){
  StackNode* t = new StackNode;
  // top of the stack is at the tail
  t = tail->previous;
  tail->previous->previous->next = tail;
  tail->previous = tail->previous->previous;
  delete t;
  count--;
}

// returns value at top of stack
int Stack::top() const {
  // top of the stack is inserted at the tail end
  return tail->previous->value;

}

// returns size of stack
int Stack::size() const {
  return count;

}

