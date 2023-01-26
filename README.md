# aap_mma_project
Mutualised project between "Advanced Algorithmic and Programming" and "Models, Methods and Programming".
The project consists in implementing a modified version of pairwise alignement of sequence in a multiple sequence alignment context.


# Objectives
- [x] Implementation of Multiple Sequence Alignment algorithm (MSA).
- [x] Construction of tree and MSA in parallele to facilitate access of data (UPGMA).
- [x] Makefile for compilation.
- [x] Python script (pipeline) to execute sequence of algorithms.
- [x] 20 datasets containing each 20 sequences.


# Compilation
In order to facilitate usage of the ptogram, a Makefile is provided in the projects archive allowing easy compilation of the diverse segments of the project.
- ```make all``` : Compiles the complete project
- ```make clean``` : Removes all the compiled files and potential precompiled headers.
- ```make rebuild``` : Combination of make clean and make all (Mostly useful for the development process).
- ```make data_generation``` : Compiles the traces generation program.
- ```make alignment``` : Compiles the alignment program.
- ```make quality_analysis``` : Compiles the scoring program.

# Testing the program
To make sure the compilation process was successful, six exemples are at disposal.
The program runs syntaxic and semantic checks on the expression to avoid errors and unpredictable behavior during traces generation.
Working examples and basic syntaxic/semantic error case scenarios can be executed with the commands:
- ```make test_simple``` : Working trace generation using simple generative regions.
- ```make test_complex``` : Working trace generation using complex generative regions.
- ```make test_semantic[1-4]``` : Execution returns syntaxic and semantic errors handled by the data_generation program. (make test_semantic4 generates traces yet should return an error... [Unresolved])

# Execution
Each section of the project can be executed independently with the same command line structure : ```./main [inputFile] [outputFile]```
Input file is either the parameters file for the data_generation program, the traces to align for the alignment program, or the aligned traces for the quality_analysis program.
Output file is the path where the result should be written.

A python3 script is also at disposal for easy and efficient complete execution of the project.
Use the command line ```python3 pipeline.py [pathToDatasetDirectory]```.
The pipeline will handle necessary compilation, execute the program accordingly to previously explained process and create the results directories if necessary.

# Authors
Damien GARCIA,
Florian ECHELARD,
2nd year Master students in Bioinformatics at Nantes University.
