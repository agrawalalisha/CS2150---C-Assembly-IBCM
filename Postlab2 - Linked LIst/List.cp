// Name: Alisha Agrawal
// ID: aa3se
// Date: 02/21/2021
// Filename: List.cpp

#include <iostream>
#include <string>
#include "List.h"
#include "ListNode.h"
#include "ListItr.h"


using namespace std;

// Default Constructor
//    initalizes all private data members
//    sets up basic list structure w/ dummy head/tail nodes
List::List() {
  head = new ListNode();
  tail = new ListNode();
  head->next = tail;
  tail->previous = head;
  count = 0;

}

// Copy Constructor
//    creates a new list of ListNodes with the same values as in source
List::List(const List& source){
  head = new ListNode();
  tail = new ListNode();
  head->next = tail;
  tail->previous = head;
  count = 0;

  // Make a deep copy of the list
  ListItr iter(source.head->next);
  while (!iter.isPastEnd()) {
    insertAtTail(iter.retrieve());
    iter.moveForward();
  }
}

// Destructor
//    empty the list & reclaim memory allocated in constructor for head/tail
List::~List() {
  makeEmpty();
  delete head;
  delete tail;

}

// Copy Assignment Operator
List& List::operator=(const List& source) {
  if (this == &source) {
    return *this;
  } else {
    makeEmpty();
    
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {
      insertAtTail(iter.retrieve());
      iter.moveForward();
    }
  }
  return *this;
}

// Returns true if empty; else false
bool List::isEmpty() const {
  if(count == 0) { 
    return true;
  }
  return false; 
}

// deletes all ListNodes except dummy head/tail
void List::makeEmpty(){
  ListItr iterator =  first(); // iterator.current = node after head
  while(iterator.isPastEnd() == false) { // until at dummy tail node
    iterator.moveForward(); // first move forward
    delete iterator.current->previous; // delete the previous node
  }
  head->next = tail; // empty list
  tail->previous = head; // empty list
  count = 0;
}

// returns an iterator pointing to the first node after the dummy head node
ListItr List::first() {
  return ListItr(head->next);
}

// returns an interator pointing the last node before the dummy tail node
ListItr List::last() {
  return ListItr(tail->previous);
}

// inserts ListNode w/ value x after current iterator position
void List::insertAfter(int x, ListItr position){
  ListNode* newNode = new ListNode;
  newNode->value = x;
  //POSITION-> <- NEWNODE -><- NODE
  newNode->next = position.current->next; // NEWNODE -> NODE
  newNode->previous = position.current; // POSITION <- NEWNODE
  position.current->next->previous = newNode; // NEWNODE <- NODE
  position.current->next = newNode; // POSITION -> NEWNODE
  count++;
}

// inserts ListNode w/ value x before current iterator position
void List::insertBefore(int x, ListItr position) {
  ListNode* newNode = new ListNode();
  newNode->value = x;
  //NODE-> <- NEWNODE -> <- POSITION
  newNode->next = position.current; // NEWNODE -> POSITION
  newNode->previous = position.current->previous; // NODE <- NEWNODE
  position.current->previous->next = newNode; // NODE -> NEWNODE
  position.current->previous = newNode; // NEWNODE <- POSITION
  count++;
}

// inserts ListNode w/ value x at tail of the list
void  List::insertAtTail(int x) {
  ListNode* newNode = new ListNode();
  newNode->value = x;
  //NODE-> <-  NEWNODE-> <- TAIL
  newNode->next = tail; // NEWNODE -> TAIL
  newNode->previous = tail->previous; // NODE <- NEWNODE
  tail->previous->next = newNode; // NODE -> NEWNODE
  tail->previous = newNode; // NEWNODE <-TAIL
  count++;

}

// returns an iterator that points to the first occurrence of x
ListItr List::find(int x) {
  ListItr iterator = first(); // iterator.current = node after head
  while(iterator.isPastEnd() == false && iterator.retrieve() != x) {
    iterator.moveForward();
    // while loop continues until parameter occurs
    // or until at the dummy tail node
  }

  if(iterator.current == NULL) { //parameter is not in the list
    iterator.current = tail; // points iterator to dummy tail node
  }

  return iterator;

}

// removes the first occurrence of ListNode w/ value x
void List::remove(int x) {
  ListItr iterator = find(x);
  // PREVNODE-> <- NODE -> <- NEXTNODE
  iterator.current->previous->next = iterator.current->next; // PREVNODE -> NEXTNODE
  iterator.current->next->previous = iterator.current->previous; // PREVNODE <- NEXTNODE
  delete iterator.current;
  count--;

}

// returns the number of elements in the List
int List::size() const {
  return count;
}

// prints list forwards; when forward is true; else prints list backward
void printList(List& source, bool forward) {
  ListItr iterator;
  if(forward == true) {    // printing forward
    iterator = source.first();    // gets first node after head
    while(iterator.isPastEnd() == false){   // iterates until at  dummy tail
      cout << iterator.retrieve() << " "; // prints value iterator is at
      iterator.moveForward();
    }
  }
  else { // printing backward
    iterator = source.last(); // gets last node before tail
    while(iterator.isPastBeginning() == false){ // iterates until at dummy head
      cout << iterator.retrieve() << " "; // prints value iterator is at
      iterator.moveBackward();
    }
    

  }

  cout << endl; //blank line

}
  
