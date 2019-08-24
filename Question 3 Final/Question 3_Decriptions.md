Program Objectives:

This C program invokes external applications and prints their outputs. The mentioned applications are the programs developed in questions 1 and 2. 

Code Structure:

The masetr program execute application 1. To this end, the number of input text files is read (nfile), and their names are set as arguments to main function (Code::Blocks:
Project>Set Program's arguments>file name with txt format). The name of arguments are transformed to strings and then set as arguments of application 1 using spawnv() function.
So far, the application 1 has been executed by the master program. The excecutable form (.exe) of the C program for question 1 is needed. It is avialable in the same directory of the 
the program 1 at: bin>Debug>Program name. This exe. file shold be copied to the program location of question 3. Similar to application 1, the arguments for application 2 should be set.
In this case, the output file name of application 1 is set for application 2. 
It should be noted that after end of each run of the program, the generated output of application 1 (Result_Application_1) should be removed to supress excessive input data for
application 2.      

The description commnets for diffrent parts of the program are included in the source code.

Verification Example:

One example is solved using this program, and the results are shown in figure (Output). In this case, two input files are introduced into the main program.