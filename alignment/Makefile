# Advanced Algorithmics and Programming & Models, Methods and Programming Project
# Damien GARCIA, Florian ECHELARD
# M2BB
 


# ---------------------------------------------------------------------------- #
#              Makefile for compiling and testing the MSA program              #
# ---------------------------------------------------------------------------- #


# Ignored if not specificaly called
.PHONY: clean rebuild test_simple test_complex test_semantic1 test_semantic2 test_semantic3 test_semantic4 


# Variables
EXE = main
MAIN = main.cpp
CXX = g++
CXXFLAGS = -Wall -O2
OBJECTS = file_handling.o wirematrix.o dissimilarity.o miscellaneous.o


# Creates executable file
all: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(EXE) $(MAIN) $(OBJECTS)


# Creation of object files of data generation functions
file_handling.o:
	$(CXX) $(CXXFLAGS) -c file_handling.cpp

wirematrix.o:
	$(CXX) $(CXXFLAGS) -c wirematrix.cpp

dissimilarity.o:
	$(CXX) $(CXXFLAGS) -c dissimilarity.cpp

miscellaneous.o:
	$(CXX) $(CXXFLAGS) -c miscellaneous.cpp



# ---------------------------------------------------------------------------- #
#                      Shortcuts (use : "main [shortcut]")                     #
# ---------------------------------------------------------------------------- #

# Removes all generated files by previous compilations
clean:
	-rm -f *.o *.gch $(EXE)

# Combination of "make clean" and "make all" commands
rebuild:
	$(MAKE) clean all



# ---------------------------------------------------------------------------- #
#                           Test Execution of program                          #
# ---------------------------------------------------------------------------- #


# Simple alignment test
test_simple:
	./$(EXE) ../datasets/examples/traces/simple.txt ../datasets/examples/alignment/simple.txt

# Complex alignment test
test_complex:
	./$(EXE) ../datasets/examples/traces/complex.txt ../datasets/examples/alignment/complex.txt