#include "lib.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int convertToDecimal8bits(int* binary)
{
    int decimal = 0;
    int power = 128;
    for (int i = 0; i < 8; i++) {
        if (binary[i] == 1) {
            decimal += power;
        }
        power /= 2;
    }
    return decimal;
}

int* convertBoolElementsToInt(bool* arr, int length)
{
    int* newArr = malloc(sizeof(int) * length);
    for (int i = 0; i < length; i++) {
        if (arr[i] == false) {
            newArr[i] = 0;
        } else {
            newArr[i] = 1;
        }
    }
    return newArr;
}

int compareTwoDecimalNumbers(bool* arr1, bool* arr2)
{
    bool* p1 = arr1;
    bool* p2 = arr2;
    int* newArr1 = convertBoolElementsToInt(p1, 8);
    int decimal1 = convertToDecimal8bits(newArr1);
    int* newArr2 = convertBoolElementsToInt(p2, 8);
    int decimal2 = convertToDecimal8bits(newArr2);
    free(newArr1);
    free(newArr2);
    if (decimal1 > decimal2) {
        return 1;
    } else if (decimal2 > decimal1) {
        return -1;
    } else {
        return 0;
    }
}

void printResults(int res)
{
    if (res == 1) {
        printf("Первое число больше чем второе число\n");
    } else if (res == -1) {
        printf("Второе число больше чем первое число\n");
    } else if (res == 0) {
        printf("Числа равны");
    }
    return;
}

// так как в условии ничего не сказано про длину масиива, пусть она будет всего 8 элементов (8 бит)
int main(int argc, char* argv[])
{
    if (argc == 2 && strcmp(argv[1], "--test") == 0) {
        bool allTestsPassed = tests();
        if (allTestsPassed) {
            printf("Все тесты прошли успешно");
        } else {
            printf("Некоторые тесты не были пройдены");
        }
        printf("\n");
        return 0;
    }

    bool arr1[] = { false, false, false, false, true, false, false, false };
    bool arr2[] = { false, false, false, false, false, false, true, false };
    bool* p1 = arr1;
    bool* p2 = arr2;
    int res = compareTwoDecimalNumbers(p1, p2);
    printResults(res);
    return 0;
}
