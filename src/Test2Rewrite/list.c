#include "list.h"
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

bool isEmpty(List* list) { return list->head == NULL; }

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

bool oneElement(List* list) { return list->head->next == NULL; }

/*
Эта функция копирования спика
на вход принимает два списка и копирует один в другой
*/
void copy(List* listToCopy, List* listToPut)
{
    int length = getLength(listToCopy);
    int element = 0;
    for (int i = 0; i < length; i++) {
        element = get(listToCopy, i);
        insert(listToPut, i, element);
    }
}

List* reverse(List* list)
{
    if (list == NULL || isEmpty(list)) {
        return NULL;
    }

    List* newOneList = newList();
    copy(list, newOneList);

    if (newOneList == NULL || isEmpty(newOneList)) {
        return NULL;
    }
    ListNode* prev = NULL;
    ListNode* current = newOneList->head;
    ListNode* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    newOneList->head = prev;
    return newOneList;
}

bool testReverse()
{
    List* list1 = newList();
    insert(list1, 0, 1);
    insert(list1, 1, 2);
    insert(list1, 2, 3);
    List* newOne1 = reverse(list1);
    int arr[3] = { 3, 2, 1 };
    int* p = arr;
    for (int i = 0; i < 3; i++) {
        if (get(newOne1, i) != p[i]) {
            deleteList(list1);
            deleteList(newOne1);
            return false;
        }
    }
    deleteList(list1);
    deleteList(newOne1);

    List* list2 = newList();
    insert(list2, 0, 3);
    insert(list2, 1, 2);
    insert(list2, 2, 1);
    List* newOne2 = reverse(list2);
    int arr2[3] = { 1, 2, 3 };
    int* p2 = arr2;
    for (int i = 0; i < 3; i++) {
        if (get(newOne2, i) != p2[i]) {
            deleteList(list2);
            deleteList(newOne2);
            printf("Сломалось на стандартной проверке\n");
            return false;
        }
    }
    deleteList(list2);
    deleteList(newOne2);

    List* list3 = newList();
    insert(list3, 0, 1);
    List* newOne3 = reverse(list3);
    printList(newOne3);
    if (get(newOne3, 0) != 1) {
        printf("Сломалось на списке из одного элемента\n");
        deleteList(list3);
        deleteList(newOne3);
        return false;
    }
    deleteList(list3);
    deleteList(newOne3);

    List* list4 = newList();
    List* newOne4 = reverse(list4);
    if (newOne4 != NULL) {
        deleteList(list4);
        deleteList(newOne4);
        printf("Сломалось на пустом изначальном списке\n");
        return false;
    }
    deleteList(list4);
    deleteList(newOne4);

    List* list5 = newList();
    insert(list5, 0, 1);
    insert(list5, 1, 1);
    insert(list5, 2, 1);
    List* newOne5 = reverse(list5);
    int arr5[3] = { 1, 1, 1 };
    int* p5 = arr5;
    for (int i = 0; i < 3; i++) {
        if (get(newOne5, i) != p5[i]) {
            deleteList(list5);
            deleteList(newOne5);
            printf("Сломалось на проверке из одинаковых элементов\n");
            return false;
        }
    }
    deleteList(list5);
    deleteList(newOne5);

    return true;
}

int main()
{
    bool isOk = testReverse();
    if (!isOk) {
        printf("Некоторые тесты не прошли\n");
    } else {
        printf("Все тесты прошли успешно!\n");
    }
    return 0;
}