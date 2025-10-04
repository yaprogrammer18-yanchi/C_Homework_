#include <stdio.h>

int main()
{
    // пусть массив задан в программе
    int listWithNumbers[] = { 0, 1, 3, 0, 6, 0, 7, 4, 6, 2, 0, 0 };
    int countOfZeros = 0;
    size_t lengthOfMassive = sizeof(listWithNumbers) / sizeof(int);

    for (int i = 0; i < lengthOfMassive; i++) {
        if (listWithNumbers[i] == 0) {
            ++countOfZeros;
        }
    }
    printf("%d\n", countOfZeros);
    return 0;
}

// выводит 5 - кол-во нулей
