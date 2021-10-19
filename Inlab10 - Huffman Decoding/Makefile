# Name: Alisha Agrawal
# ID: aa3se
# Date: 04/27/2021
# Makefile

CXX = clang++ $(CXXFLAGS)
CXXFLAGS = -Wall #Enable all warnings
DEBUG = -g

huffmanenc: huffmandec.o huffNode.o
	$(CXX) $(DEBUG) huffmandec.o huffNode.o

huffmandec.o: huffmandec.cpp

huffNode.o: huffNode.cpp huffNode.h

.PHONY: clean
clean:
	-rm -f *.o *~ a.out
