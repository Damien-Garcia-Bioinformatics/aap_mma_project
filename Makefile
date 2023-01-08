# Advanced Algorithmics and Programming & Models, Methods and Programming Project
# Damien GARCIA, Florian ECHELARD
# M2BB
 

####################################################
#                General Makefile                  #
####################################################


# Ignored if not specificaly called
.PHONY: clean rebuild

all:
	cd data_generation && $(MAKE) all && cd ../alignment && $(MAKE) all && cd ../quality_analysis && $(MAKE) all

rebuild:
	cd data_generation && $(MAKE) rebuild && cd ../alignment && $(MAKE) rebuild && cd ../quality_analysis && $(MAKE) rebuild

clean:
	cd data_generation && $(MAKE) clean && cd ../alignment && $(MAKE) clean && cd ../quality_analysis && $(MAKE) clean


####################################################
#                General Makefile                  #
####################################################

test_simple:
	cd data_generation && $(MAKE) test_simple && cd ../alignment && $(MAKE) test_simple

test_complex:
	cd data_generation && $(MAKE) test_complex && cd ../alignment && $(MAKE) test_complex

test_semantic1:
	cd data_generation && $(MAKE) test_semantic1

test_semantic2:
	cd data_generation && $(MAKE) test_semantic2

test_semantic3:
	cd data_generation && $(MAKE) test_semantic3

test_semantic4:
	cd data_generation && $(MAKE) test_semantic4