# Advanced Algorithmics and Programming & Models, Methods and Programming Project
# Damien GARCIA, Florian ECHELARD
# M2BB
 


# ---------------------------------------------------------------------------- #
#                               General Makefile                               #
# ---------------------------------------------------------------------------- #


# Ignored if not specificaly called
.PHONY: clean rebuild data_generation alignment quality_analysis test_simple test_complex test_semantic1 test_semantic2 test_semantic3 test_semantic4 test_scoring


all:
	cd data_generation && $(MAKE) all && cd ../alignment && $(MAKE) all && cd ../quality_analysis && $(MAKE) all

data_generation:
	cd data_generation && $(MAKE) rebuild

alignment:
	cd alignment && $(MAKE) rebuild

quality_analysis:
	cd quality_analysis && $(MAKE) rebuild

rebuild:
	cd data_generation && $(MAKE) rebuild && cd ../alignment && $(MAKE) rebuild && cd ../quality_analysis && $(MAKE) rebuild

clean:
	cd data_generation && $(MAKE) clean && cd ../alignment && $(MAKE) clean && cd ../quality_analysis && $(MAKE) clean



# ---------------------------------------------------------------------------- #
#                           Test Execution of program                          #
# ---------------------------------------------------------------------------- #


test_simple:
	cd data_generation && $(MAKE) -s test_simple && cd ../alignment && $(MAKE) -s test_simple

test_complex:
	cd data_generation && $(MAKE) -s test_complex && cd ../alignment && $(MAKE) -s test_complex

test_semantic1:
	cd data_generation && $(MAKE) -s test_semantic1

test_semantic2:
	cd data_generation && $(MAKE) -s test_semantic2

test_semantic3:
	cd data_generation && $(MAKE) -s test_semantic3

test_semantic4:
	cd data_generation && $(MAKE) -s test_semantic4

test_scoring:
	cd quality_analysis && $(MAKE) -s test_scoring