// Name: Alisha Agrawal
// ID: (aa3se)
// Date: 02/17/2021
// bankAccount.cpp

#include <iostream>
#include <string>
#include "bankAccount.h"
using namespace std;

bankAccount::bankAccount() {
  balance = 0;

}

bankAccount::bankAccount(double amount) {
  balance = amount;

}

bankAccount::~bankAccount() {

}

double bankAccount::withdraw(double amount) {
  if (amount > balance) {
    return balance;
  }
  else {
    balance = balance - amount;
  }
  return balance;
}

double bankAccount::deposit(double amount) {
  balance += amount;
  return balance;

}

double bankAccount::getBalance() {
  return balance;

}



