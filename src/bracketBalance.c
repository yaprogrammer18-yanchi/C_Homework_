#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int *stek = calloc(100, sizeof(int)); // сделаем большой стек состоящий из 100 нулей
    char *string = calloc(100, sizeof(char)); // строка из 100 символов
    scanf("%100[^\n]", string); // ввели строку (огранчение 100 символов)

    int count = 0; // счетчик того, сколько позиций занято в стеке
    char str1 = ' '; // здесь будут символы из строки
    char str2 = '(';
    char str3 = ')';

    bool isEverythingOk = true; // флаг, что все скобки пока идут правильно

    for (int i = 0; i < 100; i++) // перебор символов введенной строки
    {
        str1 = string[i];

        if (str1 == str2) // Ищем окрывающие скобки
        {
            stek[count] = 2; // пусть 2 - это открывающая скобка
            count += 1;
        }

        else if (str1 == str3) // если скобка закрывающаяся
        {
            if (stek[count - 1] == 2) // то все ок
            {
                stek[count - 1] = 0;
                count -= 1;
                // этими действиями мы убрали закрытые скобки, будто их и не было
            } else {

                isEverythingOk = false;
                break;
            }
        }
    }
    // Если скобочная последовательность правильная, то стек в конце будет состоять только из нулей
    if (isEverythingOk == true && stek[0] == 2) {
        printf("Скобочная последовательность неправильная\n");
    }

    else if (isEverythingOk == true) {
        printf("Скобочная последовательность правильная\n");
    }

    else {
        printf("Скобочная последовательность неправильная\n");
    }

    return 0;
}
