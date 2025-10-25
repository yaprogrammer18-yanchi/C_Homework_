#include "cyclicList.h"
#include "list.h"
#include <stdbool.h>
#include <stdio.h>
// решение через односвязный список
// знаю, что не по условию, но тоже как вариант реализации
int simpleListRealisation() {
  printf("Введите n и m через пробел\n");
  int n = 0;
  int m = 0;
  scanf("%d %d", &n, &m);
  List *list = newList();
  for (int i = 1; i <= n; i++) {
    insert(list, i - 1, i);
  }
  int count = 1;
  int index = 0;
  while (!oneElement(list)) {
    if ((count % m) == 0) {
      removeElement(list, index);
      // откатываем назад индекс
      index--;
    }
    count++;
    index++;

    if (index == getLength(list)) {
      index = 0;
    }
  }
  printList(list);
  return 0;
}

// решение через циклический список
int main() {
  printf("Введите n и m через пробел\n");
  int n = 0;
  int m = 0;
  scanf("%d %d", &n, &m);
  List *list = newList();
  for (int i = 1; i <= n; i++) {
    insert(list, i - 1, i);
  }
  printf("%d", findTheSafeIndex(list, m));

  return 0;
}
