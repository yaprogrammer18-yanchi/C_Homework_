#include "list.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

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
  while ((c = getchar()) != '\n') {
  }
}

void addElementInList(List *list) 
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

void removeElemetFromList(List *list) 
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

void printTheList(List *list) 
{
  printf("Список элементов:\n");
  printList(list);
}

void handleCommands() 
{
  printf("Вводите команды. После каждой введенной команды нажимайте Enter\n");
  printf("Чтобы завершить работу с программой, введите 0\n\n");
  List *list = newList();
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

int main(int argc, char *argv[]) 
{
  if (argc == 2 && strcmp(argv[1], "--test") == 0) {
    runTests();
    return 0;
  }
  printMenu();
  handleCommands();
  return 0;
}
