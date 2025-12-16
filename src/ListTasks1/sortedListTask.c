#include "list.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void runTests();

void printMenu()
{
    printf("\n=== МЕНЮ КОМАНД ===\n");
    printf("1 - Добавить элемент (с сортировкой по возрастанию)\n");
    printf("2 - Удалить элемент по индексу\n");
    printf("3 - Вывести список\n");
    printf("0 - Выход из программы\n");
}

void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n') { }
}

void addElementInList(List* list)
{
    int element = 0;
    printf("Введите элемент который хотите добавить\n");

    if (scanf("%d", &element) != 1) {
        printf("Ошибка: введено некорректное значение!\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();
    insert_sorted_in_ascending_order(list, element);
    printf("Элемент успешно добавлен\n");
}

void removeElemetFromList(List* list)
{
    int index = 0;
    printf("Введите индекс элемента, который хотите удалить: ");
    if (scanf("%d", &index) != 1) {
        printf("Ошибка: введен некорректный индекс!\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    if (removeElement(list, index)) {
        printf("Элемент успешно удален.\n");
    } else {
        printf("Что-то пошло не так. Возможно введен неправильный индекс.\n");
    }
}

void printTheList(List* list)
{
    printf("Список элементов:\n");
    printList(list);
}

void handleCommands()
{
    printf("Вводите команды. После каждой введенной команды нажимайте Enter\n");
    printf("Чтобы завершить работу с программой, введите 0\n\n");
    List* list = newList();
    int command = 0;
    while (1) {
        printf("Введите команду: ");
        if (scanf("%d", &command) != 1) {
            printf("Ошибка: пожалуйста, введите число от 0 до 3!\n");
            clearInputBuffer();
            continue; // Пропускаем остаток цикла и начинаем заново
        }
        clearInputBuffer();
        if (command == 0) {
            break;
        }
        switch (command) {
        case 1:
            addElementInList(list);
            break;
        case 2:
            removeElemetFromList(list);
            break;
        case 3:
            printTheList(list);
            break;
        default:
            printf("Вероятно, такой команды не существует\n");
        }
    }
    deleteList(list);
    printf("Работа с программой завершена. Память очищена\n");
}

int main(int argc, char* argv[])
{
    if (argc == 2 && strcmp(argv[1], "--test") == 0) {
        bool allTestsPassed = runTests();
        if (allTestsPassed) {
            printf("Все тесты прошли успешно");
        } else {
            printf("Некоторые тесты не были пройдены");
        }
        printf("\n");
        return 0;
    }

    printMenu();
    handleCommands();

    return 0;
}

bool checkAscendingOrder(List* list)
{
    int size = getLength(list);
    for (int i; i < size - 1; i++) {
        int current = get(list, i);
        int next = get(list, i + 1);
        if (current > next) {
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
    printf("ТЕСТ 1 ПРОШЕЛ УСПЕШНО\n");
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
    printf("ТЕСТ 2 ПРОШЕЛ УСПЕШНО\n");
    return true;
}

bool testSameElements()
{
    List* list = newList();
    insert_sorted_in_ascending_order(list, 2);
    insert_sorted_in_ascending_order(list, 2);
    assert(getLength(list) == 2 && "(Один из тестов не прошел) Должно быть 2 элемента");
    deleteList(list);
    printf("ТЕСТ 3 ПРОШЕЛ УСПЕШНО\n");
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
    printf("ТЕСТ 4 ПРОШЕЛ УСПЕШНО\n");
    return true;
}

bool testRemoveFromEmptyList()
{
    List* list = newList();
    assert(!removeElement(list, 0) && "Удаление из пустого списка не должно выполняться");
    deleteList(list);
    printf("ТЕСТ 4 ПРОШЕЛ УСПЕШНО\n");
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
    printf("ТЕСТ 5 ПРОШЕЛ УСПЕШНО\n");
    return true;
}

void runTests()
{
    printf("ЗАПУСК ТЕСТОВ ДЛЯ СОРТИРОВАННОГО СПИСКА\n");
    testCreateList();
    testAscendingOrder();
    testSameElements();
    testRemoveElement();
    testRemoveFromEmptyList();
    testRemoveNonexistingIndexFromList();
    printf("\nВСЕ ТЕСТЫ ПРОЙДЕНЫ УСПЕШНО!\n");
}