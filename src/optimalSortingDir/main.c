#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

  int *arrayWithNumbers = calloc(100, sizeof(int));
  int length = 0;
  char nextSymbol = 0;
  while (nextSymbol != '\n') {
    int inputNumber = 0;
    int input = scanf("%d", &inputNumber);
    // scanf успешно прочитал введенное число
    printf("%d", input);
    if (input == 1)
    {
      // добавляем число в список
      arrayWithNumbers[length++] = inputNumber;
    } else {
      return 1;
    }
    // читаем символ, который был введен дальше
    nextSymbol = getchar();
    if (nextSymbol == '\n') {
      break;
    }
  }

  printf("%d\n", sort(arrayWithNumbers, length));
  return 0;
}

// пример: ввод 4 3 2 1
// должно вернуть : 4, так как каждая цифра изменила свою позицию
