# Addition
## Purpose
This was a project assignment in an Operating Systems class, Fall 2018. The goal was to use **fork()** to split a "master" program into a parent/child process. The child process would execute a "slave" program, while the parent would wait for the slave to return a value. The master program was meant to accept a list of numbers and calculate the sum, with the restriction of only being able to add 2 numbers at a time (which the slave program would do).

This was an introduction to multi-processing for me, and I had a lot of fun getting this to work. It runs and works for a variety of combinations of numbers passed in. The nums[] array (which holds the numbers to be added) is set to be a size of 20, which means editing of that size is necessary if the list of numbers to be added exceeds 20.
## How to Run
This was designed to work in a Linux environment (fork, execvp, etc.). Compile the program using the included makefile, and call the master program with a list of numbers like **./master 1 2 3 4** to get the total sum :)
