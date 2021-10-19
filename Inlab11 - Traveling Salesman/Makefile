# Alisha Agrawal
# aa3se
# 05.03.2021
# Makefile

CXX = clang++ $(CXXFLAGS)
CXXFLAGS = -Wall -O2 -g

OFILES = traveling.cpp middleearth.cpp

.SUFFIXES: .o .cpp

main:	$(OFILES)
	$(CXX) $(OFILES)
	doxygen

.PHONY: clean
clean:
	-rm -f *,o *~a.out
