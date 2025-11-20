# SUPA c++ Assignment 1
## Alistair Bhatti
### 11.2025

# TLDR
1) type "make" in terminal to compile the project
2) "./AnalyseData_program" to run the program
3) enter "input2D_float.txt" when promptewd for input file
4) select option a/b/c/d - loops until user enters "q"

#  relevant to program operation
All files relevant to project breifly described below

## c++ code files
All code is contained in the files:

- CustomFunctions.cxx
- CustomFunctions.h
- AnalyseData.cxx

## Input data files
input data files - these are filed read into the program at variosu stages

- input2D_float.txt
- error2D_float.txt

## Makefile
The Makefile for this project is based heavily off the make file from the pre-existing assigment 2 make file (Excercises/Lab2and4). 

- Makefile

## output data files
Each of the subsequent files is created by running options b, c, and d respectively:

- fitted_line.txt
- vector_magnitudes.txt
- x_pow_y_resutls.txt

# Compiling and running the project
The project can be compiled by typing "make" in the terminal in Excercises/Lab1and2/Assignment. The program is called: 

- AnalyseData_program

# Brief evlauation of program fulfilment of specification

The program does all requested data reading / analysis, and incorporates limited user choice. Key info is printed to the screen, output has been validated - calcualtions are correct. Project does however deviate from project instructions in a few ways. There is less user customisabiltiy than was requested - e.g., magnitude data is always saved to file, user has no control over this. Some back end features were implmeented slightyl clunkily, e.g. I do not have a single yemplate for saving data to file, I use 2 separate functions to create 3 text files. Thee is very limitted error handling.