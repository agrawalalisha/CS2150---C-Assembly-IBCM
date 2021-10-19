# Name: Alisha Agrawal
# ID: aa3se
# Date: 03/23/2021
# Makefile

CXX = clang++ $(CXXFLAGS)
CXXFLAGS = -Wall #Enable all warnings
DEBUG = -g

BSTPathTest: BSTPathTest.o BinarySearchTree.o BinaryNode.o
	$(CXX) $(DEBUG) BSTPathTest.o BinarySearchTree.o BinaryNode.o

BSTPathTest.o: BSTPathTest.cpp

BinarySearchTree.o: BinarySearchTree.cpp BinarySearchTree.h

BinaryNode.o: BinaryNode.cpp BinaryNode.h

.PHONY: clean
clean:
	-rm -f *.o *~ a.out
