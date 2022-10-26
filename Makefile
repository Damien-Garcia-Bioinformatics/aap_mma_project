# ---  Makefile for compiling the encoder program  --- #
.PHONY: clean

EXE = main
MAIN = main.cpp
CXX = g++
CXXFLAGS = #-Wall -O2 -std=c++17
OBJECTS = parsing_functions.o

#To create the executable file, we need the object files
main: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(EXE) $(MAIN) $(OBJECTS)

#To create the object file read_pdb.o, we need the source
parsing_functions.o:
	$(CXX) $(CXXFLAGS) -c parser/parsing_functions.cpp

#To start over from scratch, use 'make clean'
clean:
	-rm -f *.o *.gch $(EXE)