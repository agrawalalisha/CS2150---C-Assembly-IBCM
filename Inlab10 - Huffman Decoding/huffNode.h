// Alisha Agrawal
// aa3se
// 04/26/2021
// huffNode.h

#ifndef HUFFNODE_H
#define HUFFNODE_H

#include <iostream>
using namespace std;

class huffNode {
 public:
  huffNode(); // Default constructor
  huffNode(int freq, char ch); // Constructor
  ~huffNode(); // Deconstructor
  huffNode* left;
  huffNode* right;
  int freq; // frequency of character
  char ch; // character
  string prefix; // prefix code for character
  int getFreq(); // getter method for freqency
  char getChar(); // getter method for character
  string getPrefix(); // getter method for predix
  
  bool operator<(const huffNode& n) const;

};

#endif
