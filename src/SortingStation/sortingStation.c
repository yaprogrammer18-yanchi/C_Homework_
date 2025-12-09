#include "stack.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// функция для определения приоритета операнда +- это 1, * / это 2
int getPriority(char operand)
{
    if (operand == '+' || operand == '-') {
        return 1;
    } else if (operand == '*' || operand == '/') {
        return 2;
    }
    return 0;
}

char* convertString(char* string)
{
    struct Stack* stack = newStack();
    char* queue = malloc(1000 * sizeof(char));
    int len = strlen(string);
    int queueEndPtr = 0;
    int i = 0;
    while (i != len) {
        // если число
        if (isdigit(string[i])) {
            queue[queueEndPtr] = string[i];
            ++queueEndPtr;
            queue[queueEndPtr] = ' ';
            ++queueEndPtr;
        }
        // если открывающаяся скобка, добавляем ее в стек
        if (string[i] == '(') {
            push(stack, string[i]);
        }
        // если закрывающаяся, то переберем все значения стека и разместим их в очереди, пока не встретится открывающая скобка
        else if (string[i] == ')') {
            while ((!isEmpty(stack)) && (peek(stack) != '(')) {
                queue[queueEndPtr] = pop(stack);
                ++queueEndPtr;
                queue[queueEndPtr] = ' ';
                ++queueEndPtr;
            }
            if ((!isEmpty(stack)) && (peek(stack) == '(')) {
                pop(stack);
            } else if (!isEmpty(stack)) {
                deleteStack(stack);
                return "ERROR: you missed openning bracket symbol";
            }
        }
        // если операторы + - * /
        if ((string[i] == '+') || (string[i] == '-') || (string[i] == '*') || (string[i] == '/')) {
            // если оператор, но по приоритету такой же или меньший чем в стеке
            while ((!isEmpty(stack)) && (getPriority(string[i]) <= getPriority(peek(stack)))) {
                queue[queueEndPtr] = pop(stack);
                ++queueEndPtr;
                queue[queueEndPtr] = ' ';
                ++queueEndPtr;
            }
            push(stack, string[i]);
        }
        ++i;
    }
    while (!isEmpty(stack)) {
        if (peek(stack) == '(') {
            deleteStack(stack);
            return "ERROR: you missed closing bracket symbol";
        }
        queue[queueEndPtr] = pop(stack);
        ++queueEndPtr;
        queue[queueEndPtr] = ' ';
        ++queueEndPtr;
    }

    deleteStack(stack);
    // чтобы строка была корректной
    queue[queueEndPtr] = '\0';
    char* queue_realloced = realloc(queue, sizeof(char) * (strlen(queue) + 1));
    free(stack);
    return queue_realloced;
}

/*
 Предполагается, что пользователь вводит корректное арифметическое выражение.
 Но в программе предусмотрено, если пользователь забудет одну из скобок.
*/

int main()
{
    char* arifmeticExpression = malloc(1001 * sizeof(char));
    // 1001 так как последний символ отводится для \0
    printf("Введите выражение, не превышающее по длине 1001 символов\n");
    fgets(arifmeticExpression, 1001, stdin);
    char* queue = convertString(arifmeticExpression);
    int queueLength = strlen(queue);
    printf("%s\n", queue);
    free(queue);
    free(arifmeticExpression);
    return 0;
}