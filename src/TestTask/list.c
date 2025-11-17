#include "list.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// структура обычного элемента в списке
struct ListNode {
    int value;
    struct ListNode* next;
};

// структура содержащая указатель на первый элемент списка
struct List {
    ListNode* head;
};

List* newList()
{
    List* list = calloc(1, sizeof(*list));
    return list;
}

bool insert(List* list, int index, int value)
{
    if (list == NULL || index < 0) {
        return false;
    }
    if (index == 0) {
        ListNode* newNode = malloc(sizeof(ListNode));
        newNode->value = value;
        newNode->next = list->head;
        list->head = newNode;
        return true;
    }
    ListNode* current = list->head;
    int counter = 0;
    while (current != NULL) {
        if (counter == index - 1) {
            ListNode* newNode = malloc(sizeof(ListNode));
            newNode->value = value;
            newNode->next = current->next;
            current->next = newNode;
            return true;
        }
        current = current->next;
        counter++;
    }
    return false;
}

int get(List* list, int index)
{
    if (list == NULL || isEmpty(list) || index < 0)
        return -1;
    if (index == 0) {
        return list->head->value;
    }
    ListNode* current = list->head;
    int counter = 0;
    while (current != NULL) {
        if (counter == index) {
            return current->value;
        }
        current = current->next;
        counter++;
    }
    return -1;
}

bool removeElement(List* list, int index)
{
    if (list == NULL || isEmpty(list) || index < 0) {
        return false;
    }
    ListNode* current = list->head;
    if (index == 0) {
        list->head = current->next;
        free(current);
        return true;
    }
    int counter = 0;
    while (current != NULL) {
        if (counter == index - 1) {
            if (current->next == NULL)
                return false;
            ListNode* nodeToDelete = current->next;
            current->next = nodeToDelete->next;
            free(nodeToDelete);
            return true;
        }
        current = current->next;
        counter++;
    }
    return false;
}

bool deleteList(List* list)
{
    if (list == NULL || isEmpty(list)) {
        return false;
    }
    while (!isEmpty(list)) {
        removeElement(list, 0);
    }
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

bool isEmpty(List* list)
{
    return list->head == NULL;
}

bool insert_sorted_in_ascending_order(List* list, int value)
{
    if (list == NULL) {
        return false;
    }
    // случай еще незаполненного списка
    if (isEmpty(list)) {
        return insert(list, 0, value);
    }
    ListNode* current = list->head;
    int counter = 0;
    // если элемент самый маленький и его надо вставить в начало
    if (current->value > value) {
        return insert(list, 0, value);
    }
    while (current != NULL && current->next != NULL) {
        if ((current->next->value > value) && (current->value <= value)) {
            return (insert(list, counter + 1, value));
        }
        current = current->next;
        counter++;
    }
    // если программа достигла этой строчки, то значит что элемент больше всех
    // остальных
    return insert(list, counter + 1, value);
}

int getLength(List* list)
{
    if (list == NULL || isEmpty(list)) {
        return -1;
    }
    int counter = 0;
    ListNode* current = list->head;
    do {
        counter++;
        current = current->next;
    } while (current != NULL);
    return counter;
}

bool oneElement(List* list)
{
    return list->head->next == NULL;
}