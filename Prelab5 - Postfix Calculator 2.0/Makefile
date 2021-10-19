# Name: Alisha Agrawal
# ID: aa3se
# Date: 03/23/2021
# Makefile

CXX = clang++ $(CXXFLAGS)
CXXFLAGS = -Wall #Enable all warnings
DEBUG = -g

TreeCalcTest: TreeCalcTest.o TreeCalc.o TreeNode.o
	$(CXX) $(DEBUG) TreeCalcTest.o TreeCalc.o TreeNode.o

TreeCalcTest.o: TreeCalcTest.cpp

TreeCalc.o: TreeCalc.cpp TreeCalc.h

TreeNode.o: TreeNode.cpp TreeNode.h

.PHONY: clean
clean:
	-rm -f *.o *~ a.out
