#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
Я выбрала 8ми битное представление чисел, сответственно,
диапазон выбора числа огранчен. от - 128 до 127 - безопасный диапазон.
*/

int* simpleConvertion(int n)
{
    int* binary = calloc(8, sizeof(int));
    int i = 7;
    while (n > 0 && i >= 0) {
        binary[i] = n % 2;
        n = n / 2;
        i--;
    }
    return binary;
}

void addOne(int* binary)
{
    int carry = 1;
    int sum = 0;
    for (int i = 7; i >= 0; i--) {
        int sum = binary[i] + carry;
        binary[i] = sum % 2;
        if (sum >= 2) {
            carry = 1;
        } else {
            break;
        }
    }
    return;
}

void invertBits(int* binary)
{
    for (int i = 0; i < 8; i++) {
        if (binary[i] == 1) {
            binary[i] = 0;
        } else {
            binary[i] = 1;
        }
    }
    return;
}

int* convertToBinary(int n)
{
    bool isNegative = false;
    if (n < 0) {
        isNegative = true;
        n = -n;
    }
    int* binary = simpleConvertion(n);
    if (isNegative) {
        invertBits(binary);
        addOne(binary);
    }
    return binary;
}

int* sumBinNumbers(int* fnum, int* snum)
{
    int* sum = calloc(8, sizeof(int));
    int carry = 0;
    int bit_sum = 0;
    for (int i = 7; i >= 0; i--) {
        int bit_sum = fnum[i] + snum[i] + carry;
        sum[i] = bit_sum % 2;
        carry = bit_sum / 2;
    }
    return sum;
}

int convertToDecimal(int* binary)
{
    bool isNegative = false;
    if (binary[1] == 1) {
        invertBits(binary);
        addOne(binary);
        isNegative = true;
    }
    int decimal = 0;
    int power = 128;
    for (int i = 0; i < 8; i++) {
        if (binary[i] == 1) {
            decimal += power;
        }
        power /= 2;
    }
    if (isNegative) {
        return -decimal;
    }
    return decimal;
}

int main(void)
{
    int firstNum = 0;
    int secNum = 0;
    printf("-----------------\n");
    printf("Введите два числа\n");
    scanf("%d %d", &firstNum, &secNum);
    int* firstNumBin = convertToBinary(firstNum);
    int* secNumBin = convertToBinary(secNum);
    printf("Первое число: ");
    for (int j = 0; j < 8; j++) {
        printf("%d", firstNumBin[j]);
    }
    printf("  Второе число: ");
    for (int j = 0; j < 8; j++) {
        printf("%d", secNumBin[j]);
    }
    printf("\n");
    int* sum = sumBinNumbers(firstNumBin, secNumBin);
    printf("Двоичная сумма: ");
    for (int j = 0; j < 8; j++) {
        printf("%d", sum[j]);
    }
    printf("\n");
    int sumDec = 0;
    sumDec = convertToDecimal(sum);
    printf("Десятичная сумма: %d\n", sumDec);
    printf("-----------------\n");

    free(firstNumBin);
    free(secNumBin);
    free(sum);
    return 0;
}