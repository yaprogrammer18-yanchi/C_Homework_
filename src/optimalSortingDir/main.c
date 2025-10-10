#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

  int *ArrayWithNumbers = calloc(100, sizeof(int));
  int length = 0;
  char nextSymbol = 0;
  while (nextSymbol != '\n') {
    int inputNumber = 0;
    int input = scanf("%d", &inputNumber);
    if (input == 1) // scanf успешно прочитал введенное число
    {
      ArrayWithNumbers[length++] = inputNumber; // добавляем число в список
    } else {
      return 1;
    }
    nextSymbol = getchar(); // читаем символ, который был введен дальше
    if (nextSymbol == '\n') {
      break;
    }
  }

  printf("%d\n", sort(ArrayWithNumbers, length));

  return 0;
}

// пример: ввод 4 3 2 1
// должно вернуть : 4, так как каждая цифра изменила свою позицию
