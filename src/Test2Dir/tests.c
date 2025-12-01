#include "lib.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool testConverToDecimal8bits()
{

    int num1[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    int* p1 = num1;
    if (convertToDecimal8bits(p1) != 0) {
        printf("Тесты сломались на проверке перевода в десятичную сс (00000000 -> 0)\n");
        return false;
    }

    int num2[] = { 1, 1, 1, 1, 1, 1, 1, 1 };
    int* p2 = num2;
    if (convertToDecimal8bits(p2) != 255) {
        printf("Тесты сломались на проверке перевода в десятичную сс (11111111 -> 31)\n");
        return false;
    }

    int num3[] = { 0, 0, 0, 0, 0, 1, 0, 1 };
    int* p3 = num3;
    if (convertToDecimal8bits(p3) != 5) {
        printf("Тесты сломались на проверке перевода в десятичную сс (00000101 -> 5)\n");
        return false;
    }
    return true;
}

bool testConvertBoolToInt()
{

    bool arr1[] = { false, true, false, true, false, true, false, true };
    int correctArr1[] = { 0, 1, 0, 1, 0, 1, 0, 1 };
    int* pointet_to_correctArr = correctArr1;
    bool* p1 = arr1;
    int* testArr = convertBoolElementsToInt(p1, 8);

    for (int i = 0; i < 8; i++) {
        if (testArr[i] != pointet_to_correctArr[i]) {
            printf("Тесты сломались на проверке перевода массивов с булевыми значениями в целочисленные\n");
            return false;
        }
    }
    return true;
}

bool testcompareElements()
{
    bool arr1[] = { false, false, false, false, false, false, false, true };
    bool arr2[] = { false, false, false, false, false, false, true, false };
    bool* p1 = arr1;
    bool* p2 = arr2;
    int res1 = compareTwoDecimalNumbers(p1, p2);
    if (res1 != -1) {
        printf("Тесты сломались на стандартной проверке (первое число больше второго)\n");
        return false;
    }

    bool arr3[] = { false, false, false, false, true, true, false, false };
    bool arr4[] = { false, false, false, false, false, false, true, false };
    bool* p3 = arr3;
    bool* p4 = arr4;
    int res2 = compareTwoDecimalNumbers(p3, p4);
    if (res2 != 1) {
        printf("Тесты сломались на стандартной проверке (второе число больше первого)\n");
        return false;
    }

    bool arr5[] = { false, false, false, false, true, true, true, false };
    bool arr6[] = { false, false, false, false, true, true, true, false };
    bool* p5 = arr5;
    bool* p6 = arr6;
    int res3 = compareTwoDecimalNumbers(p5, p6);
    if (res3 != 0) {
        printf("Тесты сломались на стандартной проверке (числа равны)\n");
        return false;
    }
    return true;
}

bool tests()
{
    bool allTestsPassed = false;
    if (testConvertBoolToInt() && testcompareElements() && testConverToDecimal8bits()) {
        allTestsPassed = true;
    }
    return allTestsPassed;
}
