#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    int t;
    scanf("%d", &x);
    t = x * x;
    int result = (t + x) * (t + 1) + 1;
    printf("%d", result);
    return 0;
}
