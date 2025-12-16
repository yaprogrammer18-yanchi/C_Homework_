#include "OneLinkedList.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode ListNode;

struct ListNode {
    int value;
    struct ListNode* next;
};

struct List {
    ListNode* head;
};

List* newList()
{
    List* list = calloc(1, sizeof(*list));
    return list;
}

bool isEmpty(List* list) { return list->head == NULL; }

bool insert(List* list, int value)
{
    if (list == NULL) {
        return false;
    }
    ListNode* newNode = malloc(sizeof(ListNode));
    ListNode* current = list->head;

    if (isEmpty(list)) {
        newNode->value = value;
        newNode->next = list->head;
        list->head = newNode;
        return true;
    }
    // если элемент меньше самого маленького значения в голове
    if (current->value > value) {
        list->head = newNode;
        newNode->next = current;
        newNode->value = value;
        return true;
    }
    // если элемент должен быть где-то в середине
    while (current->next != NULL) {
        if ((current->next->value > value) && (current->value <= value)) {
            newNode->next = current->next;
            current->next = newNode;
            newNode->value = value;
            return true;
        }
        current = current->next;
    }

    // последний случай, когда элемент больше остальных
    newNode->next = NULL;
    current->next = newNode;
    newNode->value = value;
    return true;
}

bool removeElement(List* list, int value)
{
    if (list == NULL || isEmpty(list)) {
        return false;
    }
    ListNode* current = list->head;

    if (current->value == value) {
        list->head = current->next;
        free(current);
        return true;
    }

    while (current->next != NULL && current->next->value != value) {
        current = current->next;
    }
    if (current->next != NULL && current->next->value == value) {
        ListNode* toDelete = current->next;
        current->next = toDelete->next;
        free(toDelete);
        return true;
    }
    return false;
}

bool deleteList(List* list)
{
    if (list == NULL) {
        return false;
    }
    ListNode* current = list->head;
    while (current != NULL) {
        ListNode* toDelete = current;
        current = current->next;
        free(toDelete);
    }
    list->head = NULL;
    free(list);
    return true;
}

void printList(List* list)
{
    if (list == NULL || isEmpty(list)) {
        printf("Список пустой\n");
        return;
    }
    ListNode* current = list->head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}