# Name: Alisha Agrawal
# ID: aa3se
# Date: 03/25/2021
# Makefile

CXX = clang++ $(CXXFLAGS)
CXXFLAGS = -O2 -Wall #Enable all warnings
DEBUG = -g

wordPuzzle: wordPuzzle.o hashTable.o timer.o
	$(CXX) $(DEBUG) wordPuzzle.o hashTable.o timer.o

wordPuzzle.o: wordPuzzle.cpp

hashTable.o: hashTable.cpp hashTable.h

timer.o: timer.cpp timer.h

.PHONY: clean
clean:
	-rm -f *.o *~ a.out

