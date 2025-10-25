#include "stack.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdbool.h>

// структура обыкновенного элемента в стеке
struct StackNode {
    int value;
    struct StackNode* next;
};

// сам стек (структура содержащая указатель на первый элемент стека)
struct Stack {
  struct StackNode* head;
};


Stack* newStack(void)
{
    Stack* stack = calloc(1, sizeof(*stack));
    return stack;
}

void push(Stack* stack, int value)
{
    StackNode* node = malloc(sizeof(StackNode));
    node->value = value;
    node->next = stack->head;
    stack->head = node;
}

int pop(Stack* stack)
{
    if (stack->head==NULL)
    {
        return '\0';
    }
    StackNode* oldNode = stack->head;
    int res = oldNode->value;
    stack->head = oldNode->next;
    free(oldNode);
    return res;
}

int peek(struct Stack* stack)
{
    StackNode* headNode = stack->head;
    int res = headNode->value;
    return res;
}

bool isEmpty(Stack* stack)
{
    return stack->head==NULL;
}

void deleteStack(Stack* stack)
{
    while (!isEmpty(stack)) {
        pop(stack);
    }
}
