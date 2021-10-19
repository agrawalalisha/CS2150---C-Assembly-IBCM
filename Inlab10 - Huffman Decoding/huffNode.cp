// Alisha Agrawal
// aa3se
// 04/26/2021
// huffNode.cpp

#include "huffNode.h"
#include <iostream>

using namespace std;

huffNode::huffNode(){ // Default Constructor
  ch = 'z';
  freq = 1;
  prefix = "";
  left = NULL;
  right = NULL;
}

huffNode::huffNode(int freq1, char ch1){ // Constructor
  ch = ch1;
  freq = freq1;
  prefix = "";
  left = NULL;
  right = NULL;
}

huffNode::~huffNode(){ // Deconstructor
  delete left;
  delete right;
}

int huffNode::getFreq(){
  return freq;
}

char huffNode::getChar(){
  return ch;
}

string huffNode::getPrefix() {
  return prefix;
}

bool huffNode::operator<(const huffNode& n) const {
  return freq < n.freq;

}

					   
