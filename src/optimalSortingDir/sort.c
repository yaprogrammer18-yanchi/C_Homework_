#include "sort.h"
#include <stdlib.h>
#include <string.h>

int sort(int *array, int length) {
  // c помощью этого списка будем считать элементы, изменившие свою позицию
  int *unsortedArray = calloc(length, sizeof(int));
  memcpy(unsortedArray, array, sizeof(int) * length);
  // сортировка пузырьком
  for (int i = 0; i < length; i++) {
    for (int j = 0; j < length - 1 - i; j++) {
      if (array[j] > array[j + 1]) {
        int tmp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = tmp;
      }
    }
  }
  int count = 0;
  // смотрим какие элементы изменили свою позицию
  for (int k = 0; k < length; k++) {
    if (array[k] != unsortedArray[k]) {
      ++count;
    }
  }
  free(unsortedArray);
  return count;
}
