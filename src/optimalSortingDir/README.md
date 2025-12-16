Инструкция по сборке

gcc -Wall -Wextra -pedantic -S -O2 sort.c -o sort.s

gcc -Wall -Wextra -pedantic main.c -c

gcc -Wall -Wextra -pedantic main.o sort.s -o main
