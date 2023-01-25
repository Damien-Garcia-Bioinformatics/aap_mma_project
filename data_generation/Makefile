# Advanced Algorithmics and Programming & Models, Methods and Programming Project
# Damien GARCIA, Florian ECHELARD
# M2BB
 


# ---------------------------------------------------------------------------- #
#            Makefile compiling and testing data generation program            #
# ---------------------------------------------------------------------------- #


# Ignored if not specificaly called
.PHONY: clean rebuild test_simple test_complex test_semantic1 test_semantic2 test_semantic3 test_semantic4


# Variables
EXE = main
MAIN = main.cpp
CXX = g++
CXXFLAGS = -Wall -O2
OBJECTS = parsing_functions.o generation_functions.o miscellaneous.o semantic_check_functions.o file_handling_functions.o


# Creates executable file
all: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(EXE) $(MAIN) $(OBJECTS)


# Creation of object files of data generation functions
file_handling_functions.o:
	$(CXX) $(CXXFLAGS) -c file_handling_functions.cpp

parsing_functions.o:
	$(CXX) $(CXXFLAGS) -c parsing_functions.cpp

semantic_check_functions.o:
	$(CXX) $(CXXFLAGS) -c semantic_check_functions.cpp

generation_functions.o: 
	$(CXX) $(CXXFLAGS) -c generation_functions.cpp

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

# Simple generation test
test_simple:
	./$(EXE) ../datasets/examples/parameters/simple.txt ../datasets/examples/traces/simple.txt

# Complex generation test
test_complex:
	./$(EXE) ../datasets/examples/parameters/complex.txt ../datasets/examples/traces/complex.txt

# Semantic error test 1
test_semantic1:
	./$(EXE) ../datasets/examples/parameters/semanticError1.txt ../datasets/examples/traces/semanticError1.txt

# Semantic error test 2
test_semantic2:
	./$(EXE) ../datasets/examples/parameters/semanticError2.txt ../datasets/examples/traces/semanticError2.txt

# Semantic error test 3
test_semantic3:
	./$(EXE) ../datasets/examples/parameters/semanticError3.txt ../datasets/examples/traces/semanticError3.txt

# Semantic error test 4
test_semantic4:
	./$(EXE) ../datasets/examples/parameters/semanticError4.txt ../datasets/examples/traces/semanticError4.txt