#include "stack.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool checkBrackets(char* stringWithBrackets)
{
    bool isBalanced = true;
    Stack* stack = newStack();
    char tmp = ' ';
    int length = strlen(stringWithBrackets);
    for (int i = 0; i < length; i++) {
        tmp = stringWithBrackets[i];
        if ((tmp == '(') || (tmp == '{') || (tmp == '[')) {
            push(stack, tmp);
        }
        // если встретилась закрывающаяся и стек не пустой
        else if ((tmp == ')' || tmp == '}' || tmp == ']') && (!isEmpty(stack))) {
            char previousBracket = pop(stack);
            if ((previousBracket == '(' && tmp == ')') || (previousBracket == '[' && tmp == ']') || (previousBracket == '{' && tmp == '}')) {
                continue;
            } else {
                isBalanced = false;
                break;
            }
        }
        // закрывающаяся и пустой стек
        else if ((tmp == ')' || tmp == '}' || tmp == ']') && (isEmpty(stack))) {
            isBalanced = false;
        }
    }
    if (!isEmpty(stack)) {
        isBalanced = false;
    }
    deleteStack(stack);
    return isBalanced;
}

int main()
{
    char* stringWithBrackets = malloc(1000 * sizeof(char));
    printf("Введите скобочную последовательность: ");
    scanf("%s", stringWithBrackets);
    bool isCorrect = checkBrackets(stringWithBrackets);
    if (isCorrect) {
        printf("Скобочная последовательность правильная\n");
    } else {
        printf("Скобочная последовательность неправильная\n");
    }
    free(stringWithBrackets);
    return 0;
}
