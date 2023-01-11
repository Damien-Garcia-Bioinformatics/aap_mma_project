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
OBJECTS = read_traces.o wirematrix.o dissimilarity.o write_results.o miscellaneous.o


# Creates executable file
all: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(EXE) $(MAIN) $(OBJECTS)


# Creation of object files of data generation functions
read_traces.o:
	$(CXX) $(CXXFLAGS) -c read_traces.cpp

wirematrix.o:
	$(CXX) $(CXXFLAGS) -c wirematrix.cpp

dissimilarity.o:
	$(CXX) $(CXXFLAGS) -c dissimilarity.cpp

write_results.o:
	$(CXX) $(CXXFLAGS) -c write_results.cpp

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
	./$(EXE) ../examples/traces/simple.txt ../examples/alignment/simple.txt

# Complex alignment test
test_complex:
	./$(EXE) ../examples/traces/complex.txt ../examples/alignment/complex.txt