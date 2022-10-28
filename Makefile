 # ---  Makefile for compiling the encoder program  --- #
.PHONY: clean parser generator rebuild

EXE = main
MAIN = main.cpp
CXX = g++
CXXFLAGS = -Wall -O2
OBJECTS = parsing_functions.o generation_functions.o miscellaneous.o

# To create the executable file, we need the object files
all: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(EXE) $(MAIN) $(OBJECTS)

# To create the object file parsing_functions.o, we need the source
parsing_functions.o:
	$(CXX) $(CXXFLAGS) -c data_generation/parsing_functions.cpp

# To create the object file generation_functions.o, we need the source
generation_functions.o: 
	$(CXX) $(CXXFLAGS) -c data_generation/generation_functions.cpp

miscellaneous.o:
	$(CXX) $(CXXFLAGS) -c data_generation/miscellaneous.cpp


# --- Shortcuts (use : "main [shortcut]") --- #

# Compilation of parsing functions
parser: 
	$(CXX) $(CXXFLAGS) -c data_generation/parsing_functions.cpp

# Compilation of generation functions
generator: 
	$(CXX) $(CXXFLAGS) -c data_generation/generation_functions.cpp

# Removes all generated files by previous compilations
clean:
	-rm -f *.o *.gch $(EXE)

# Combination of "make clean" and "make all" commands
rebuild:
	$(MAKE) clean all
