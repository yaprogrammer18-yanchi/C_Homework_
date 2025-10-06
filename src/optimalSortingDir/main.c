#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{

    int* onlyNumbersList = calloc(200, sizeof(int));
    int length = 0;
    char nextSymbol = 0;
    while (nextSymbol != '\n') {
        int inputNumber = 0;
        int input = scanf("%d", &inputNumber);
        if (input == 1) // scanf успешно прочитал введенное число
        {
            onlyNumbersList[length++] = inputNumber; // добавляем число в список
        }

        else {
            return 1;
        }

        nextSymbol = getchar(); // читаем символ, который был введен дальше
        if (nextSymbol == '\n') {
            break;
        }
    }

    // for (int i = 0; i<length; i++)
    // {
    //     printf("%d ", onlyNumbersList[i]);
    // }

    printf("%d\n", sort(onlyNumbersList, length));

    return 0;
}


// пример: ввод 1 2 3 4
// должно вернуть : 4, так как каждая цифра изменила свою позицию
