#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 0;
    scanf("%d", &x);
    int t = x * x;
    int result = (t + x) * (t + 1) + 1;
    printf("%d\n", result);
    return 0;
}
