#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maxNumber(int* arr, int length)
{
    int maximum = 0;
    for (int i = 0; i < length; i++) {
    }
}

int main()
{
    int* list = malloc(sizeof(int) * 100);
    int i = 0;
    int num = 0;
    int count = 0;
    printf("Введите числа (до 100 штук) через пробел и нажмите Enter:\n");
    while (1) {
        int result = scanf("%d", &num);
        if (result) {
            list[i] = num;
            count++;
        }
        // взяли из ввода следующий символ
        int next_char = getchar();
        if (next_char == '\n') {
            break;
        }
        // вернули его на место, если он не перенос строки
        ungetc(next_char, stdin);
        i++;
    }
    // тут где-то realloc
    for (int i = 0; i < count; i++) {
        printf("%d\n", list[i]);
    }
}
