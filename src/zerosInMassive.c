#include <stdio.h>

int main()
{
    // пусть массив задан в программе
    int list[] = { 0, 1, 3, 0, 6, 0, 7, 4, 6, 2, 0, 0 };
    int count = 0;
    size_t length = sizeof(list) / sizeof(int);

    for (int i = 0; i < length; i++) {
        if (list[i] == 0) {
            count += 1;
        }
    }
    printf("%d\n", count);
    return 0;
}
