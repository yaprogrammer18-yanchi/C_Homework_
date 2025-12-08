#include <stdio.h>
#include <stdlib.h>

int main()
{
    char list_s[] = "hellohellhellolllhello";
    char list_s1[] = "hello";

    size_t lenS = sizeof(list_s) / sizeof(char);
    size_t lenS1 = sizeof(list_s1) / sizeof(char) - 1;  // так как последний символ нулевой

    int count = 0; // счетчик вхождений
    for (int i = 0; i < lenS; i++) // i - индекс того эл-та с которого будем рассматривать строку s
    {
        int flag = 1; // Это значит, что все символы строк совпадают, но если хотя бы один символ будет отличаться, будем менять на 0 и выходить из цикла
        for (int j = 0; j < lenS1; j++) {
            if (list_s[i + j] != list_s1[j]) {
                flag = 0; // опа, строчки отличаются
                break; // собираем вещи и уходим
            }
        }
        if (flag == 1) // все символы совпали
        {
            count += 1;
        }
    }
    printf("%d\n", count);

    return 0;
}
