#include "cyclicList.h"
#include "stdio.h"
#include <stdbool.h>
#include <stdlib.h>

// структура обычного элемента в списке
typedef struct ListNode ListNode;

typedef struct ListNode {
    int value;
    ListNode* next;

} ListNode;

typedef struct List {
    ListNode* head;
} List;

List* newList()
{
    List* new = calloc(1, sizeof(*new));
    return new;
}

bool insert(List* list, int index, int value)
{
    if (list == NULL) {
        return false;
    }
    if (isEmpty(list)) {
        ListNode* newNode = calloc(1, sizeof(ListNode));
        newNode->value = value;
        newNode->next = newNode;
        list->head = newNode;
        return true;
    }
    if (index == 0) {
        ListNode* newNode = calloc(1, sizeof(ListNode));
        newNode->value = value;
        ListNode* current = list->head;
        while (current->next != list->head) {
            current = current->next;
        }
        newNode->next = list->head;
        list->head = newNode;
        current->next = newNode;
        return true;
    }

    ListNode* current = list->head;
    int counter = 0;
    // условия для while нет, чтобы пользователь мог вставлять элемент на любой
    // индекс (так как список цикличный, ему нет разницы какой индекс указали)
    while (1) {
        if (counter == index - 1) {
            ListNode* newNode = calloc(1, sizeof(ListNode));
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

bool removeElement(List* list, int index)
{
    if (list == NULL || isEmpty(list)) {
        return false;
    }

    if (index == 0) {
        ListNode* elemToRemove = list->head;
        if (elemToRemove->next == elemToRemove) {
            free(elemToRemove);
            list->head = NULL;
            return true;
        }

        ListNode* current = list->head;
        while (current->next != elemToRemove) {
            current = current->next;
        }
        list->head = elemToRemove->next;
        current->next = list->head;
        free(elemToRemove);
        return true;
    }

    ListNode* current = list->head;
    int counter = 0;
    // условия для while нет, чтобы пользователь мог вставлять элемент на любой
    // индекс (так как список цикличный, ему нет разницы какой индекс указали)
    while (1) {
        if (counter == index - 1) {
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

bool isEmpty(List* list) { return list->head == NULL; }

bool oneElement(List* list) { return list->head->next == list->head; }

void printList(List* list)
{
    if (list == NULL || isEmpty(list)) {
        printf("Список пустой\n");
        return;
    }
    ListNode* current = list->head;
    do {
        printf("%d ", current->value);
        current = current->next;
    } while (current != list->head);
    printf("\n");
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
    } while (current != list->head);
    return counter;
}

int findTheSafeIndex(List* list, int m)
{
    ListNode* current = list->head;
    ListNode* prev = NULL;
    while (!oneElement(list)) {
        for (int i = 0; i < m; i++) {
            prev = current;
            current = current->next;
        }
        if (current == list->head) {
            list->head = current->next;
        }

        prev->next = current->next;
        free(current);
        current = prev->next;
    }
    return list->head->value;
}
