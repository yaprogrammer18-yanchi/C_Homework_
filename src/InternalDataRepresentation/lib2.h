#pragma once
#include <stdint.h>
#include <stdio.h>

void runTests();

typedef union {
    double value;
    uint64_t bits;
} Number;

const char* parseDouble(Number num);