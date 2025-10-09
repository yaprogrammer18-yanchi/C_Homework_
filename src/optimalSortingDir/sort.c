#include "sort.h"
#include <stdlib.h>

int sort(int *list, int length) {

  int *unsortedMassive =
      calloc(length, sizeof(int)); // c помощью этого списка будем счиатать
                                   // элементы, изменившие свою позицию
  for (int i = 0; i < length; i++) {
    unsortedMassive[i] = list[i];
  }
  // копируем переданный список

  // сортировка пузырьком
  for (int i = 0; i < length; i++) {
    for (int j = 0; j < length - 1 - i; j++) {
      if (list[j] > list[j + 1]) {
        int tmp = list[j];
        list[j] = list[j + 1];
        list[j + 1] = tmp;
      }
    }
  }

  int count = 0;
  // смотрим какие элементы изменили свою позицию
  for (int k = 0; k < length; k++) {
    if (list[k] != unsortedMassive[k]) {
      count += 1;
    }
  }
  free(unsortedMassive);
  return count;
}
