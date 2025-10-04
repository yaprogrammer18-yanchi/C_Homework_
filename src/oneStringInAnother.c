#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char listForBiggerString[] = "hellohellhellolllhello";
    char listForSmallerString[] = "hello";

    size_t lenForBiggerString = sizeof(listForBiggerString) / sizeof(char);
    size_t lenForSmallerString = sizeof(listForSmallerString) / sizeof(char) - 1; // так как последний символ нулевой

    int countingOfEntry = 0; // счетчик вхождений
    for (int i = 0; i < lenForBiggerString; i++) // i - индекс того эл-та с которого будем рассматривать большую строку
    {
        bool flag = true; // Это значит, что все символы строк совпадают, но если хотя бы один символ будет отличаться, будем менять на 0 и выходить из цикла
        for (int j = 0; j < lenForSmallerString; j++) {
            if (listForBiggerString[i + j] != listForSmallerString[j]) {
                flag = false; // опа, строчки отличаются
                break;
            }
        }
        if (flag) // все символы совпали
        {
            ++countingOfEntry;
        }
    }
    printf("%d\n", countingOfEntry);

    return 0;
}
