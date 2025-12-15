#include "cyclicList.h"
#include <stdbool.h>
#include <stdio.h>

int main()
{
    printf("Введите n и m через пробел\n");
    int n = 0;
    int m = 0;
    scanf("%d %d", &n, &m);
    List* list = newList();
    for (int i = 1; i <= n; i++) {
        insert(list, i - 1, i);
    }
    printf("%d\n", findTheSafeIndex(list, m));
    return 0;
}