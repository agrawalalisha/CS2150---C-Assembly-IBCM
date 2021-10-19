// Name: Alisha Agrawal
// ID: aa3se
// Date: 02/21/2021
// Filename: ListItr.cpp

#include <iostream>
#include <string>
#include "ListItr.h"
#include "ListNode.h"

using namespace std;

ListItr::ListItr(){
  current = NULL;
}

ListItr::ListItr(ListNode* theNode){
  current = theNode;
}

bool ListItr::isPastEnd() const {
  if(current->next == NULL) { //if iterator points to dummy tail
    return true;
  }

  return false; 

}

bool ListItr::isPastBeginning() const {
  if(current->previous == NULL) { // if iterator points to dummy head
    return true;
  }
  return false;

}

void ListItr::moveForward() {
  if(isPastEnd() == false) { // iterator is not at the dummy tail
    current = current->next;
  }
}

void ListItr::moveBackward() {
  if(isPastBeginning() == false) { // iterator is not at the dummy head
    current = current->previous;
  }
}

  int ListItr::retrieve() const{
  return current->value;
}
