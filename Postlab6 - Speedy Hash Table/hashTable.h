// Name: Alisha Agrawal
// ID: aa3se
// Date: 03/27/2021
// hashTable.h

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

class hashTable {
 public:
  hashTable();
  hashTable(int n);

  bool find(string s);
  void insert(string s);
  unsigned int hashFunction(string key);
  bool checkprime(unsigned int p);
  int getNextPrime(unsigned int n);
  
  // maps a string to an integer value that can be used as index of hash table

 private:
  int size;
  list<string>* table;
  
  
};

#endif
