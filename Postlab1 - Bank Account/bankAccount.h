// Name: Alisha Agrawal
// ID: aa3se
// Date: 2/17/2021
// bankAccount.h

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <iostream>
#include <string>
using namespace std;

class bankAccount{
public:
  bankAccount();
  bankAccount(double amount);
  ~bankAccount();

  double withdraw(double amount);
  double deposit(double amount);
  double getBalance();
private:
  double balance;

};

#endif
  
  
