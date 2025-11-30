#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

bool checkAscendingOrder(List* list)
{
    int size = getLength(list);
    for (int i; i < size - 1; i++){
        int current = get(list, i);
        int next = get(list, i+1);
        if (current > next){
            return false;
        }
    }
    return true;
}

bool testCreateList()
{
    List* list = newList();
    assert(list != NULL && "Не создался список.\n");
    assert(isEmpty(list) && "Новый список должен быть пустым.\n");
    assert(isEmpty(list) && "Список не пустой при создании.\n");
    deleteList(list);
    printf("--- ТЕСТ 1 ПРОШЕЛ УСПЕШНО ---\n");
    return true;
}

bool testAscendingOrder()
{
    List* list = newList();
    insert_sorted_in_ascending_order(list, 5);
    insert_sorted_in_ascending_order(list, 4);
    insert_sorted_in_ascending_order(list, 3);
    insert_sorted_in_ascending_order(list, 2);
    insert_sorted_in_ascending_order(list, 1);
    assert(getLength(list) == 5 && "Должно быть 5 элементов");
    assert(checkAscendingOrder(list) && "Элементы не в отсортированном порядке");
    assert(get(list, 0) == 1 && "Список не отсортирован правильно");
    assert(get(list, 1) == 2 && "Список не отсортирован правильно");
    assert(get(list, 2) == 3 && "Список не отсортирован правильно");
    assert(get(list, 3) == 4 && "Список не отсортирован правильно");
    assert(get(list, 4) == 5 && "Список не отсортирован правильно");
    deleteList(list);
    printf("--- ТЕСТ 2 ПРОШЕЛ УСПЕШНО ---\n");
    return true;
}

bool testSameElements()
{
    List* list = newList();
    insert_sorted_in_ascending_order(list, 2);
    insert_sorted_in_ascending_order(list, 2);
    assert(getLength(list) == 2 && "(Один из тестов не прошел) Должно быть 2 элемента");
    deleteList(list);
    printf("--- ТЕСТ 3 ПРОШЕЛ УСПЕШНО ---\n");
    return true;
}

bool testRemoveElement()
{
    List* list = newList();
    insert_sorted_in_ascending_order(list, 3);
    insert_sorted_in_ascending_order(list, 2);
    insert_sorted_in_ascending_order(list, 1);

    bool result = removeElement(list, 1);
    assert(result == true && "Операция удаления элемента не прошла успешно");
    assert(getLength(list) == 2 && " (один из тестов не прошел) Должно быть два элемента после удаления");
    assert(get(list, 0) == 1 && "Проблема с удалением, остались не те элементы");
    assert(get(list, 1) == 3 && "Проблема с удалением, остались не те элементы");
    deleteList(list);
    printf("--- ТЕСТ 4 ПРОШЕЛ УСПЕШНО ---\n");
    return true;

}

bool testRemoveFromEmptyList()
{
    List* list = newList();
    assert(!removeElement(list, 0) && "Удаление из пустого списка не должно выполняться");
    deleteList(list);
    printf("--- ТЕСТ 4 ПРОШЕЛ УСПЕШНО ---\n");
    return true;
}

bool testRemoveNonexistingIndexFromList()
{
    List* list = newList();
    insert_sorted_in_ascending_order(list, 3);
    insert_sorted_in_ascending_order(list, 2);
    insert_sorted_in_ascending_order(list, 1);
    assert(!removeElement(list, 555) && "Удаление несуествующего индекса не должно осуществляться");
    deleteList(list);
    printf("--- ТЕСТ 5 ПРОШЕЛ УСПЕШНО ---\n");
    return true;
}

void runTests()
{
    printf("===!!! ЗАПУСК ТЕСТОВ ДЛЯ СОРТИРОВАННОГО СПИСКА !!!===\n\n");
    testCreateList();
    testAscendingOrder();
    testSameElements();
    testRemoveElement();
    testRemoveFromEmptyList();
    testRemoveNonexistingIndexFromList();
    printf("\n===!!! ВСЕ ТЕСТЫ ПРОЙДЕНЫ УСПЕШНО! !!!===\n");
}
