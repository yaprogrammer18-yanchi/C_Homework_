#include <stdio.h>

int main()
{
    // пусть массив задан в программе
    int arrayWithNumbers[] = { 0, 1, 3, 0, 6, 0, 7, 4, 6, 2, 0, 0 };
    int zeroCounter = 0;
    size_t lengthOfArray = sizeof(arrayWithNumbers) / sizeof(int);

    for (int i = 0; i < lengthOfArray; i++) {
        if (arrayWithNumbers[i] == 0) {
            ++zeroCounter;
        }
    }
    printf("%d\n", zeroCounter);
    return 0;
}

// выводит 5 - кол-во нулей
