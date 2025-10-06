Инструкция по сборке

gcc -S -O2 sort.c -o sort.s
gcc main.c -c
gcc main.o sort.s -o main

