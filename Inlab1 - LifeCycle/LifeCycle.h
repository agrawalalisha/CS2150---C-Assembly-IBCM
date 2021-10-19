// Name: Alisha Agrawal
// ID: aa3se
// Date: 2/16/2021
// LifeCycle.h

#ifndef LIFECYCLE_H
#define LIFECYCLE_H
#include <iostream>
#include <string>
using namespace std;

class MyObject {
public:
    static int numObjs;

    MyObject();                    // default constructor
    MyObject(string n);            // constructor with name parameter
    MyObject(const MyObject& rhs); // copy constructor
    ~MyObject();                   // destructor

    string getName() const;
    void setName(const string& newName);

    friend ostream& operator<<(ostream& output, const MyObject& obj);
private:
    string name;
    int id; public:
};


#endif
