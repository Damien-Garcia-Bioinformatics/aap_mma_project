# Advanced Algorithmics and Programming & Models, Methods and Programming Project
# Damien GARCIA, Florian ECHELARD
# M2BB
 

##############################################################################
#                Makefile for compiling the encoder program                  #
##############################################################################


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
	$(CXX) $(CXXFLAGS) -c data_generation/file_handling_functions.cpp

parsing_functions.o:
	$(CXX) $(CXXFLAGS) -c data_generation/parsing_functions.cpp

semantic_check_functions.o:
	$(CXX) $(CXXFLAGS) -c data_generation/semantic_check_functions.cpp

generation_functions.o: 
	$(CXX) $(CXXFLAGS) -c data_generation/generation_functions.cpp

miscellaneous.o:
	$(CXX) $(CXXFLAGS) -c data_generation/miscellaneous.cpp


##############################################################################
#                    Shortcuts (use : "main [shortcut]")                     #
##############################################################################

# Removes all generated files by previous compilations
clean:
	-rm -f *.o *.gch $(EXE)

# Combination of "make clean" and "make all" commands
rebuild:
	$(MAKE) clean all


##############################################################################
#                          Test Execution of program                         #
##############################################################################

# Simple generation test
test_simple:
	./$(EXE) examples/test_simple.txt examples/result_simple.txt

# Complex generation test
test_complex:
	./$(EXE) examples/test_complex.txt examples/result_complex.txt

# Semantic error test 1
test_semantic1:
	./$(EXE) examples/test_semanticError1.txt examples/result_semanticError1.txt

# Semantic error test 2
test_semantic2:
	./$(EXE) examples/test_semanticError2.txt examples/result_semanticError2.txt

# Semantic error test 3
test_semantic3:
	./$(EXE) examples/test_semanticError3.txt examples/result_semanticError3.txt

# Semantic error test 4
test_semantic4:
	./$(EXE) examples/test_semanticError4.txt examples/result_semanticError4.txt