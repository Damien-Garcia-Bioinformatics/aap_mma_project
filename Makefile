# Advanced Algorithmics and Programming & Models, Methods and Programming Project
# Damien GARCIA, Florian ECHELARD
# M2BB
 

####################################################
#                General Makefile                  #
####################################################


# Ignored if not specificaly called
.PHONY: clean rebuild


all:
	cd data_generation && $(MAKE) all && cd ../alignment && $(MAKE) all

rebuild:
	cd data_generation && $(MAKE) rebuild && cd ../alignment && $(MAKE) rebuild

clean:
	cd data_generation && $(MAKE) clean && cd ../alignment && $(MAKE) clean