#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    int b;
    int r = 0; // сколько раз вмещается b в a
    scanf("%d %d", &a, &b);
    int remember_a = a;
    int under_zero = 0; // флаг, чтобы понять какие значения введены
    // 0 - положит
    if ((a < 0 | b < 0) && !(a < 0 && b < 0)) {
        under_zero = 1; // впоследствии учтем, что ответ должен быть < 0
    }

    a = abs(a);
    b = abs(b);
    remember_a = abs(remember_a);

    if (b == 0) {
        printf("devision by zero\n");
    }

    else {
        while (a - b > 0) {
            a = a - b;
            r += 1;
        }
        if (b * r + a == remember_a) {
            if (under_zero == 1) {
                printf("%d\n", r * (-1) - 1);
            } else {
                printf("%d\n", r);
            }
        }
    }

    return 0;
}
