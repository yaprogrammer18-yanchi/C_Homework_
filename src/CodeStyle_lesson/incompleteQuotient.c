#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 0;
    int b = 0;
    int howManyTimesBInA = 0;
    scanf("%d %d", &a, &b);

    int underZero = false; // флаг, чтобы понять какие значения введены
    // 0 - положит
    if ((a * b) < 0) {
        underZero = true; // впоследствии учтем, что ответ должен быть < 0
    }

    a = abs(a);
    b = abs(b);
    int rememberA = abs(a);

    if (b == 0) {
        printf("devision by zero\n");
        return 1;
    }

    while (a - b > 0) {
        a = a - b;
        howManyTimesBInA += 1;
    }
    if (b * howManyTimesBInA + a == rememberA) {
        if (underZero == true) {
            printf("%d\n", howManyTimesBInA * (-1) - 1);
        } else {
            printf("%d\n", howManyTimesBInA);
        }
    }

    return 0;
}
