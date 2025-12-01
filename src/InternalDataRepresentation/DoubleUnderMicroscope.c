#include "lib2.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>

const char* parseDouble(Number num)
{
    static char result[100];
    uint64_t bits = num.bits;
    int sign = (bits >> 63) & 1;
    int exponent = (bits >> 52) & 0x7FF;
    uint64_t mantissa_bits = bits & 0xFFFFFFFFFFFFF;
    double mantissa = 1.0;
    double factor = 0.5;

    for (int i = 51; i >= 0; i--) {
        if ((mantissa_bits >> i) & 1) {
            mantissa += factor;
        }
        factor *= 0.5;
    }
    int exp = exponent - 1023;
    if (exponent == 0) {
        mantissa -= 1.0;
        exp = -1022;
    }
    if (exponent == 0x7FF) {
        if (mantissa_bits == 0) {
            snprintf(result, sizeof(result), "%cinf", sign ? '-' : '+');
        } else {
            snprintf(result, sizeof(result), "nan");
        }
        return result;
    }
    snprintf(result, sizeof(result), "%c%.18g*2^%d",
        sign ? '-' : '+', mantissa, exp);
    return result;
}

int main(int argc, char* argv[])
{
    if (argc == 2 && strcmp(argv[1], "--test") == 0) {
        runTests();
        return 0;
    }
    Number num;
    printf("Enter a number: ");
    if (scanf("%lf", &num.value) != 1) {
        printf("Invalid input\n");
        return 1;
    }
    const char* result = parseDouble(num);
    printf("Result: %s\n", result);
    return 0;
}