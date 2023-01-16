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


def help() :
    print("  ╔═══════════════════════════════════════════════════════════════════════════════╗")
    print("  ║                             PROGRAM EXECUTION                                 ║")
    print("  ║                                                                               ║")
    print("  ║  Use : 'python3 pipeline.py [path_to_dataset]'                                ║")
    print("  ║                                                                               ║")
    print("  ║  If programs called by the pipeline are not comipled, the Makefile is called  ║")
    print("  ║  if it exists. If not, you will have to compile the programs by yourself.     ║")
    print("  ║                                                                               ║")
    print("  ╚═══════════════════════════════════════════════════════════════════════════════╝")


def main() :
    # ----------------------------------- PATHS ---------------------------------- #

    if len(sys.argv) != 2 :
        help()
        exit(1)
    root = sys.argv[1]
    
    parameters = f"{root}parameters/"
    if not os.path.exists(parameters) :
        help()
        print("\n[Err] Path to parameters doesn't exist")
        exit(1)
    
    traces = f"{root}traces/"
    if not os.path.exists(traces) :
        os.makedirs(traces)

    alignment = f"{root}alignment/"
    if not os.path.exists(alignment) :
        os.makedirs(alignment)
    
    # --------------------------------- PROGRAMS --------------------------------- #

    dataGen = "data_generation/main"
    if not os.path.exists(dataGen) :
        if os.path.exists("Makefile") :
            subprocess.run(f"make data_generation", shell=True)
        else :
            help()
            print("\n[Err] Can't compile data_generation program (Missing makefile)")
            exit(1)

    align   = "alignment/main"
    if not os.path.exists(align) :
        if os.path.exists("Makefile") :
            subprocess.run(f"make alignment", shell=True)
        else :
            help()
            print("\n[Err] Can't compile alignment program (Missing makefile)")
            exit(1)

    score   = "quality_analysis/main"
    if not os.path.exists(score) :
        if os.path.exists("Makefile") :
            subprocess.run(f"make quality_analysis", shell=True)
        else :
            help()
            print("\n[Err] Can't compile scoring program (Missing makefile)")
            exit(1)


    # --------------------------------- EXECUTION -------------------------------- #

    # Generation and alignement of traces
    for filename in os.listdir(parameters) :
        subprocess.run(f"./{dataGen} {parameters}{filename} {traces}{filename}", shell=True)
        subprocess.run(f"./{align} {traces}{filename} {alignment}{filename}"   , shell=True)

    # Scoring alignment
    subprocess.run(f"./{score} {alignment} {root}/scores.csv", shell=True)


# ----------------------------------- Main ----------------------------------- #

if __name__ == "__main__" :
    main()