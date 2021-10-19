# Name: Alisha Agrawal
# ID: aa3se
# Date: 03/25/2021
# Makefile

CXX = clang++ $(CXXFLAGS)
CXXFLAGS = -Wall #Enable all warnings
DEBUG = -g

AVLPathTest: AVLPathTest.o AVLTree.o AVLNode.o
	$(CXX) $(DEBUG) AVLPathTest.o AVLTree.o AVLNode.o

AVLPathTest.o: AVLPathTest.cpp

AVLTree.o: AVLTree.cpp AVLTree.h

AVLNode.o: AVLNode.cpp AVLNode.h

.PHONY: clean
clean:
	-rm -f *.o *~ a.out
