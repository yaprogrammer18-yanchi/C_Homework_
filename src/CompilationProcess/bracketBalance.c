#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool checkBrackets(char* stringWithBrackets, int len)
{
    if (len == 0) {
        return false;
    }
    // специальный счетчик, "(" это +1 ")" это -1. Если скобочная посл-ть
    // правильная, counter == 0
    int counter = 0;
    for (int i = 0; i < len; i++) {
        if (stringWithBrackets[i] == '(') {
            counter++;
        }
        if (stringWithBrackets[i] == ')') {
            counter--;
        }
        if (counter < 0) {
            break;
        }
    }
    if (counter == 0) {
        return true;
    }
    return false;
}

int main()
{
    // подразумеватся, что пользователь может ввести не только скобки и в кол-ве
    // символов он должен указать всё кол-во символов включая скобки и не скобки.
    int len = 0;
    printf("Введите, сколько символов Вы хотите ввести, закончите ввод, нажав "
           "enter\n");
    printf("На следующей строке введите скобочную последовательность\n");
    scanf("%d", &len);
    // отловим этот '\n'
    getchar();
    char* stringWithBrackets = malloc(len * sizeof(char));
    // счетчик чтобы считать кол-во скобок
    int counter = 0;
    for (int i = 0; i < len; i++) {
        char tmp = ' ';
        scanf("%c", &tmp);
        if (tmp == ')' || tmp == '(') {
            stringWithBrackets[counter] = tmp;
            ++counter;
        }
    }
    bool isCorrect = checkBrackets(stringWithBrackets, counter);
    if (isCorrect) {
        printf("Скобочная последовательность правильная\n");
    } else {
        printf("Скобочная последовательность неправильная или не было введено ни "
               "одной скобки\n");
    }
    free(stringWithBrackets);
    return 0;
}
