// Name: Alisha Agrawal
// ID: aa3se
// Date: 02/28/2021
// 'postfixCalculator.cpp'

#include <iostream>
#include <cstdlib>
#include <stack>
#include "postfixCalculator.h"


using namespace std;

PostfixCalculator::PostfixCalculator(){
}

void PostfixCalculator::push(int x) {
  s.push(x);
}

int PostfixCalculator::top() {
  if (s.empty()){ // checks if stack is empty
    exit(-1);
  }
  return s.top();
}

void PostfixCalculator::pop(){
  if(s.empty()){ // checks if stack is empty
    exit(-1);
  }
  s.pop();

}

bool PostfixCalculator::empty() {
  return s.empty();
}

void PostfixCalculator::add() {
  int x = s.top(); // stores integer at top of stack into x
  s.pop(); // removes x from stack
  int y = s.top(); // stores new integer at top stack into y
  s.pop(); // removes y from stack
  s.push(x+y); // adds x+y to top of the stack
}

void PostfixCalculator::sub() {
  int x = s.top(); // stores integer at top of stack into x
  s.pop(); // removes x from stack
  int y = s.top(); // stores new integer at top of stack into y
  s.pop(); // removes y from stack
  s.push(y-x); // adds y-x to top of stack

}

void PostfixCalculator::multiply() {
  int x = s.top(); // stores integer at top of stack into x
  s.pop(); // removes x from stack
  int y = s.top(); // stores new integer at top of stack into y
  s.pop(); // removes y from stack
  s.push(x*y); // adds x*y  to top of stack

}


void PostfixCalculator::divide() {
  int x = s.top(); // stores integer at top of stack into x
  s.pop(); // removes x from stack
  int y = s.top(); // stores new integer at top of stack into y
  s.pop(); // removes y from stack
  s.push(y/x); // adds y/x to top of stack

}

void PostfixCalculator::negate() {
  int x = s.top(); // stores integer at top of stack into x
  s.pop(); // removes x from stack
  s.push((-1)*x); // adds -x to top of stack

}






