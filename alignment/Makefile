# Advanced Algorithmics and Programming & Models, Methods and Programming Project
# Damien GARCIA, Florian ECHELARD
# M2BB
 

######################################################################################
#                 Makefile for compiling and testing the MSA program                 #
######################################################################################


# Ignored if not specificaly called
.PHONY: clean rebuild 

# Variables
EXE = main
MAIN = main.cpp
CXX = g++
CXXFLAGS = -Wall -O2
OBJECTS = read_traces.o wirematrix.o dissimilarity.o write_results.o


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


##############################################################################
#                    Shortcuts (use : "main [shortcut]")                     #
##############################################################################

# Removes all generated files by previous compilations
clean:
	-rm -f *.o *.gch $(EXE)

# Combination of "make clean" and "make all" commands
rebuild:
	$(MAKE) clean all