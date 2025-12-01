#include "lib2.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool testExample1()
{
    printf("Тестирование примера 1 (-2.5)\n");

    Number num;
    num.value = -2.5;

    const char* result = parseDouble(num);
    assert((strcmp(result, "-1.25*2^1") == 0) && "Ошибка: парсинг числа -2.5 неверный\n");
    printf("Пример 1 тест пройден\n");
    return true;
}

bool testExample2()
{
    printf("Тестирование примера 2 (12312.323)\n");

    Number num;
    num.value = 12312.323;

    const char* result = parseDouble(num);
    assert((strcmp(result, "+1.50296911621093754*2^13") == 0) && "Ошибка: парсинг числа 12312.323 неверный\n");
    printf("Пример 2 тест пройден\n");
    return true;
}

bool testSimpleNumbers()
{
    printf("Тестирование простых чисел\n");

    Number num;

    num.value = 8.0;
    const char* result = parseDouble(num);
    assert((strcmp(result, "+1*2^3") == 0) && "Ошибка: парсинг числа 8.0 неверный\n");

    num.value = 0.15625;
    result = parseDouble(num);
    assert((strcmp(result, "+1.25*2^-3") == 0) && "Ошибка: парсинг числа 0.15625 неверный\n");

    num.value = 0.0;
    result = parseDouble(num);
    assert((strcmp(result, "+0*2^-1022") == 0) && "Ошибка: парсинг числа 0.0 неверный\n");

    printf("тесты простых чисел пройдены\n");
    return true;
}

void runTests()
{
    printf("===!!! ЗАПУСК ТЕСТОВ ДЛЯ ПАРСИНГА DOUBLE !!!===\n");
    testExample1();
    testExample2();
    testSimpleNumbers();
    printf("\n===!!! ВСЕ ТЕСТЫ ПРОЙДЕНЫ УСПЕШНО! !!!===\n");
}