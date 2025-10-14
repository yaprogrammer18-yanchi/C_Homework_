#include "stack.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// функция для определения приоритета операнда +- это 1, * / это 2
int getPreoritite(char operand)
{
    if (operand == '+' || operand == '-') {
        return 1;
    } else if (operand == '*' || operand == '/') {
        return 2;
    }
    return 0;
}

char* convertString(char* string, int len)
{
    struct Stack stack = newStack();
    char* queue = malloc(101 * sizeof(char));
    // не все значения будут идти в очередь, а надо, чтобы элементы в ней располагались один за другим, для этого пусть будет этот счетчик
    int countForQueue = 0;
    int i = 0;

    while (i != len) {
        // если число
        if (isdigit(string[i])) {
            queue[countForQueue] = string[i];
            ++countForQueue;
        }
        // если открывающаяся скобка, добавляем ее в стек
        if (string[i] == '(') {
            push(&stack, string[i]);
        }
        // если закрывающаяся, то переберем все значения стека и разместим их в очереди, пока не встретится открывающая скобка
        else if (string[i] == ')') {
            while ((stack.head != NULL) && (peek(&stack) != '(')) {
                queue[countForQueue] = pop(&stack);
                ++countForQueue;
            }
            if ((stack.head != NULL) && (peek(&stack) == '(')) {
                pop(&stack);
            } else if (stack.head == NULL) {
                deleteStack(&stack);
                return "ERROR: you missed openning bracket symbol";
            }
        }

        // если операторы + - * /
        if ((string[i] == '+') || (string[i] == '-') || (string[i] == '*') || (string[i] == '/')) {
            // если оператор, но по приоритету такой же или меньший чем в стеке
            while ((stack.head != NULL) && (getPreoritite(string[i]) <= getPreoritite(peek(&stack)))) {
                queue[countForQueue] = pop(&stack);
                ++countForQueue;
            }
            push(&stack, string[i]);
        }
        ++i;
    }
    if (stack.head != NULL) {
        while (stack.head != NULL) {
            if (peek(&stack) == '(') {
                deleteStack(&stack);
                return "ERROR: you missed closing bracket symbol";
            }
            queue[countForQueue] = pop(&stack);
            ++countForQueue;
        }
    }
    deleteStack(&stack);
    // чтобы строка была корректной
    queue[countForQueue] = '\0';
    return queue;
}

/*
 Предполагается, что пользователь вводит корректное арифметическое выражение.
 Но в программе предусмотрено, если пользователь забудет одну из скобок.
*/

int main()
{
    char* arifmeticExpression = malloc(101 * sizeof(char));
    // 101 так как последний символ отводится для \0
    printf("Введите выражение, не превышающее по длине 100 символов\n");
    fgets(arifmeticExpression, 101, stdin);
    char* queue = convertString(arifmeticExpression, strlen(arifmeticExpression));
    for (unsigned i = 0; i <= strlen(queue); i++) {
        if (i == 0) {
            printf("%c", queue[i]);

        } else if (i == strlen(queue)) {
            printf("%c\n", queue[i]);
        } else {
            printf(" %c ", queue[i]);
        }
    }
    free(arifmeticExpression);
    return 0;
}
