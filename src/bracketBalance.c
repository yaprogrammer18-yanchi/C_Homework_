#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool checkBrackets(char* stringWithBrackets)
{
    //специальный счетчик, "(" это +1 ")" это -1. Если скобочная посл-ть правильная, counter == 0
    int counter = 0;
    bool bracketsExist = false;

    for (int i = 0; i < 100; i++) {
        if (stringWithBrackets[i] == '(') {
            counter++;
            bracketsExist = true;
        }
        if (stringWithBrackets[i] == ')') {
            counter--;
            bracketsExist = true;
        }
        if (counter < 0) {
            break;
        }
    }
    if (bracketsExist && counter == 0) {
        return true;
    }
    return false;
}

int main()
{
    char* stringWithBrackets = calloc(100, sizeof(char));
    scanf("%100[^\n]", stringWithBrackets);
    bool isCorrect = checkBrackets(stringWithBrackets);

    if (isCorrect) {
        printf("Скобочная последовательность правильная\n");
    } else {
        printf("Скобочная последовательность неправильная\n");
    }
    free(stringWithBrackets);
    return 0;
}
