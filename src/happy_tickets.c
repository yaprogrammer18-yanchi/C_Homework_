#include <stdio.h>

int main()
{
    int count = 0;
    for (int i1 = 0; i1 < 10; i1++) {
        for (int i2 = 0; i2 < 10; i2++) {
            for (int i3 = 0; i3 < 10; i3++) {
                for (int i4 = 0; i4 < 10; i4++) {
                    for (int i5 = 0; i5 < 10; i5++) {
                        for (int i6 = 0; i6 < 10; i6++) {
                            if (i1 + i2 + i3 == i4 + i5 + i6) {
                                count += 1;
                            }
                        }
                    }
                }
            }
        }
    }

    printf("%d", count);
    return 0;
}
