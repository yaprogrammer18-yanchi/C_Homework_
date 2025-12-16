#include "stack.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool checkBrackets(char* stringWithBrackets)
{
    bool isBalanced = true;
    Stack* stack = newStack();
    int length = strlen(stringWithBrackets);
    for (int i = 0; i < length; i++) {
        char ch = stringWithBrackets[i];
        if ((ch == '(') || (ch == '{') || (ch == '[')) {
            push(stack, ch);
        }
        // если встретилась закрывающаяся и стек не пустой
        else if ((ch == ')' || ch == '}' || ch == ']') && (!isEmpty(stack))) {
            char previousBracket = pop(stack);
            if ((previousBracket == '(' && ch == ')') || (previousBracket == '[' && ch == ']') || (previousBracket == '{' && ch == '}')) {
                continue;
            } else {
                isBalanced = false;
                break;
            }
        }
        // закрывающаяся и пустой стек
        else if ((ch == ')' || ch == '}' || ch == ']') && (isEmpty(stack))) {
            isBalanced = false;
            break;
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
