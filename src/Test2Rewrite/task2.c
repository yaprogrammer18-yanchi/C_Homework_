#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getLength(int num)
{
    int numDigits = 0;
    while (num > 0) {
        numDigits++;
        num /= 10;
    }
    return numDigits;
}

void selectionSort(int* arr, int size)
{
    int tmp = 0;
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            tmp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = tmp;
        }
    }
}

int* convertNumToArr(int num)
{
    int length = getLength(num);
    int temp = num;
    int* arr = malloc(sizeof(int) * length);
    temp = num;
    for (int i = length - 1; i >= 0; i--) {
        arr[i] = temp % 10;
        temp /= 10;
    }
    return arr;
}

int arrToNumber(int* arr, int numDigits)
{
    int result = 0;
    for (int i = 0; i < numDigits; i++) {
        result = result * 10 + arr[i];
    }
    return result;
}

int getMinNumberFromDigits(unsigned num, int length)
{
    if (num == 0)
        return 0;

    int* arr = convertNumToArr(num);
    selectionSort(arr, length);
    if (arr[0] == 0) {
        for (int i = 1; i < length; i++) {
            if (arr[i] != 0) {
                int temp = arr[0];
                arr[0] = arr[i];
                arr[i] = temp;
                break;
            }
        }
    }
    int result = arrToNumber(arr, length);
    free(arr);
    return result;
}

bool tests()
{
    unsigned num1 = 321;
    int length1 = getLength(num1);
    int result1 = getMinNumberFromDigits(num1, length1);
    if (result1 != 123) {
        return false;
    }

    unsigned num2 = 10203;
    int length2 = getLength(num2);
    int result2 = getMinNumberFromDigits(num2, length2);
    if (result2 != 10023) {
        return false;
    }

    unsigned num3 = 54321;
    int length3 = getLength(num3);
    int result3 = getMinNumberFromDigits(num3, length3);
    if (result3 != 12345) {
        return false;
    }

    unsigned num4 = 0;
    int length4 = getLength(num4);
    int result4 = getMinNumberFromDigits(num4, length4);
    if (result4 != 0) {
        return false;
    }

    unsigned num5 = 301;
    int length5 = getLength(num5);
    int result5 = getMinNumberFromDigits(num5, length5);
    if (result5 != 103) {
        return false;
    }

    unsigned num6 = 110;
    int length6 = getLength(num6);
    int result6 = getMinNumberFromDigits(num6, length6);
    if (result6 != 101) {
        return false;
    }

    unsigned num7 = 5;
    int length7 = getLength(num7);
    int result7 = getMinNumberFromDigits(num7, length7);
    if (result7 != 5) {
        return false;
    }
    return true;
}

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
    return 0;
}
