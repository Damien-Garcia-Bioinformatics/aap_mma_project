#! /usr/bin/env python3


# Advanced Algorithmics and Programming & Models, Methods and Programming Project
# Damien GARCIA, Florian ECHELARD
# M2BB


# ---------------------------------------------------------------------------- #
#                                  Pipeline 1                                  #
# ---------------------------------------------------------------------------- #


import sys
import os
import subprocess


def main() :
    # Programs
    dataGen = "data_generation/main"
    align   = "alignment/main"
    score   = "quality_analysis/main"

    # Data
    root = "datasets/data1/"
    parameters = f"{root}parameters/"
    traces     = f"{root}traces/"
    alignment  = f"{root}alignment/"

    # Generation and alignement of traces
    for filename in os.listdir(parameters) :
        subprocess.run(f"./{dataGen} {parameters}{filename} {traces}{filename}", shell=True)
        subprocess.run(f"./{align} {traces}{filename} {alignment}{filename}"   , shell=True)

    # Scoring alignment
    subprocess.run(f"./{score} {alignment} {root}/scores.csv", shell=True)


# ----------------------------------- Main ----------------------------------- #

if __name__ == "__main__" :
    main()