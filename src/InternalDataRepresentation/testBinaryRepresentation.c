#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void testConverToDecimal()
{
    printf("Тестирование convertToDecimal...\n");
    int positive[] = { 0, 0, 0, 0, 0, 1, 0, 1 };
    assert((convertToDecimal(positive) == 5) && "Ошибка в функции перевода в десятичную СС положительного числа");
    int negative[] = { 1, 1, 1, 1, 1, 0, 1, 1 }; // -5
    assert((convertToDecimal(negative) == -5) && "Ошибка в функции перевода в десятичную СС отрицательного числа");
    int zero[] = { 0, 0, 0, 0, 0, 0, 0, 0 }; // 0
    assert((convertToDecimal(zero) == 0) && "Ошибка в функции перевода в десятичную СС нуля");
    printf("convertToDecimal тесты пройдены\n");
}

void testSimpleConvertionToBin()
{
    printf("Тестирование simpleConvertiontoBin...\n");
    int* result = simpleConvertiontoBin(5);
    int expected[] = { 0, 0, 0, 0, 0, 1, 0, 1 };
    for (int i = 0; i < 8; i++) {
        assert((result[i] == expected[i]) && "Ошибка в функции простого перевода в двоичную СС");
    }
    free(result);
    printf("simpleConvertiontoBin тесты пройдены\n");
}

void testAddOne()
{
    printf("Тестирование addOne...\n");
    int test1[] = { 1, 1, 1, 1, 1, 0, 1, 0 }; // -6 в обратном коде
    addOne(test1);
    int expected1[] = { 1, 1, 1, 1, 1, 0, 1, 1 }; // -5 в доп. коде
    for (int i = 0; i < 8; i++) {
        assert((test1[i] == expected1[i]) && "Ошибка в функции добавления 1 в дв.сс.");
    }

    int test2[] = { 0, 0, 0, 0, 0, 1, 1, 1 }; // 7
    addOne(test2);
    int expected2[] = { 0, 0, 0, 0, 1, 0, 0, 0 }; // 8
    for (int i = 0; i < 8; i++) {
        assert((test2[i] == expected2[i]) && "Ошибка в функции добавления 1 в дв.сс.");
    }
    printf("addOne тесты пройдены\n");
}

// Тест функции invertBits
void testInvertBits()
{
    printf("Тестирование invertBits...\n");

    int zeros[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    invertBits(zeros);
    int expected_ones[] = { 1, 1, 1, 1, 1, 1, 1, 1 };
    for (int i = 0; i < 8; i++) {
        assert((zeros[i] == expected_ones[i]) && "Ошибка в функции инвертирования");
    }

    int mixed[] = { 0, 1, 0, 1, 0, 1, 0, 1 };
    invertBits(mixed);
    int expected_mixed[] = { 1, 0, 1, 0, 1, 0, 1, 0 };
    for (int i = 0; i < 8; i++) {
        assert((mixed[i] == expected_mixed[i]) && "Ошибка в функции инвертирования");
    }
    printf("invertBits тесты пройдены\n");
}

void testConvertToBinary()
{
    printf("Тестирование convertToBinary...\n");

    int* result_positive = convertToBinary(10);
    int expected_positive[] = { 0, 0, 0, 0, 1, 0, 1, 0 };
    for (int i = 0; i < 8; i++) {
        assert((result_positive[i] == expected_positive[i]) && "Ошибка в функции полного перевода в двоичную сс положит. числа");
    }
    free(result_positive);

    int* result_negative = convertToBinary(-10);
    int expected_negative[] = { 1, 1, 1, 1, 0, 1, 1, 0 };
    for (int i = 0; i < 8; i++) {
        assert((result_negative[i] == expected_negative[i]) && "Ошибка в функции полного перевода в двоичную сс отриц. числа");
    }
    free(result_negative);

    int* result_zero = convertToBinary(0);
    int expected_zero[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    for (int i = 0; i < 8; i++) {
        assert((result_zero[i] == expected_zero[i]) && "Ошибка в функции полного перевода в двоичную сс нуля");
    }
    free(result_zero);
    printf("convertToBinary тесты пройдены\n");
}

void testSumBinNumbers()
{
    printf("Тестирование sumBinNumbers...\n");
    int num1[] = { 0, 0, 0, 0, 0, 1, 0, 1 }; // 5
    int num2[] = { 0, 0, 0, 0, 0, 0, 1, 1 }; // 3
    int* result = sumBinNumbers(num1, num2);
    int expected[] = { 0, 0, 0, 0, 1, 0, 0, 0 }; // 8
    for (int i = 0; i < 8; i++) {
        assert((result[i] == expected[i]) && "Ошибка в функции побитового сложения двух положит. чисел");
    }
    free(result);

    int num3[] = { 0, 0, 0, 0, 0, 1, 0, 1 }; // 5
    int num4[] = { 1, 1, 1, 1, 1, 0, 1, 1 }; // -5
    result = sumBinNumbers(num3, num4);
    int expected_zero[] = { 0, 0, 0, 0, 0, 0, 0, 0 }; // 0
    for (int i = 0; i < 8; i++) {
        assert((result[i] == expected_zero[i]) && "Ошибка в функции побитового сложения отриц. и полож. чисел");
    }
    free(result);

    int num5[] = { 1, 1, 1, 1, 1, 0, 1, 1 }; // -5
    int num6[] = { 1, 1, 1, 1, 1, 1, 0, 1 }; // -3
    result = sumBinNumbers(num5, num6);
    int expected_negative[] = { 1, 1, 1, 1, 1, 0, 0, 0 }; // -8
    for (int i = 0; i < 8; i++) {
        assert((result[i] == expected_negative[i]) && "Ошибка в функции побитового сложения двух отриц. чисел");
    }
    free(result);
    printf("sumBinNumbers тесты пройдены\n");
}
void runTests()
{
    printf("===!!! ЗАПУСК ТЕСТОВ ДЛЯ ЗАДАЧИ ДВОИЧНОЕ ПРЕДСТАВЛЕНИЕ !!!===\n\n");
    testConverToDecimal();
    testSimpleConvertionToBinary();
    testAddOne();
    testInvertBits();
    testConvertToBinary();
    testSumBinNumbers();
    printf("\n===!!! ВСЕ ТЕСТЫ ПРОЙДЕНЫ УСПЕШНО! !!!===\n");
}
