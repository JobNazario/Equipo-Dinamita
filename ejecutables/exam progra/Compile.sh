#!/bin/bash

echo "Compiling with Script"

gcc -c App1.c -o App1.o
gcc -c App2.c -o App2.o
gcc -c App3.c -o App3.o
gcc -c BML.c -o BML.o
gcc -c Main.c -o Main.o


gcc -o MyApp Main.o BML.o App1.o App2.o App3.o

./MyApp