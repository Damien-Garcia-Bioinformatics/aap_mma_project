# Advanced Algorithmics and Programming & Models, Methods and Programming Project
# Damien GARCIA, Florian ECHELARD
# M2BB
 


# ---------------------------------------------------------------------------- #
#            Makefile compiling and testing quality analysis program           #
# ---------------------------------------------------------------------------- #


# Ignored if not specificaly called
.PHONY: clean rebuild


# Variables
EXE = main
MAIN = main.cpp
CXX = g++
CXXFLAGS = -std=c++17 -Wall -O2
OBJECTS = scoring_functions.o file_handling.o miscellaneous.o


# Creates executable file
all: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(EXE) $(MAIN) $(OBJECTS)

scoring_functions.o:
	$(CXX) $(CXXFLAGS) -c scoring_functions.cpp

file_handling.o:
	$(CXX) $(CXXFLAGS) -c file_handling.cpp

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


# Generates scores for all files in examples/alignment files
test_scoring:
	./$(EXE) ../datasets/examples/alignment/ ../datasets/examples/scoring/scores.csv

file_scoring_simple:
	./$(EXE) ../datasets/examples/alignment/simple.txt 

file_scoring_complex:
	./$(EXE) ../datasets/examples/alignment/complex.txt