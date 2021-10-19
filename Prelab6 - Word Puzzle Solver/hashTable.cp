// Name: Alisha Agrawal
// Date: 03/30/2021
// ID: aa3se
// hashTable.cpp


#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "hashTable.h"

using namespace std;

hashTable::hashTable() {
  size = 500;
  table = new list<string>[size];
}

hashTable::hashTable(int n) {
  if(!checkprime(n)){
    size = getNextPrime(n*2);
  }
  else{
    size = n;
  }
  table = new list<string>[size];
}

void hashTable::insert(string s) {
  int key = hashFunction(s);
  table[key].push_back(s);
}

unsigned int hashTable::hashFunction(string s) {
  int key = 0;
  for (int i = 0; i < s.length() ; i++) {
    key += int(s[i]);
  }
  return key % size;
}

bool hashTable::find(string s) {
  int key = hashFunction(s);
  for (string word: table[key]) {
    if(word == s) {
      return true;
    }

  }
  return false; 
}

bool hashTable::checkprime(unsigned int p) {
  if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases
        return false;
    if ( p == 2 ) // 2 is prime
        return true;
    if ( p % 2 == 0 ) // even numbers other than 2 are not prime
        return false;
    for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p
        if ( p % i == 0 )
            return false;
    return true;
}

int hashTable::getNextPrime(unsigned int n) {
  while ( !checkprime(++n) );
  return n; // all your primes are belong to us
}
