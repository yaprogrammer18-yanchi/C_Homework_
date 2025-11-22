#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  char biggerString[] = "hellohellhellolllhello";
  char smallerString[] = "hello";
  size_t lenForBiggerString = sizeof(biggerString) / sizeof(char) - 1;
  size_t lenForSmallerString = sizeof(smallerString) / sizeof(char) - 1;
  int entryCounter = 0;
  // i - индекс эл-та с которого будем рассматривать большую строку
  for (unsigned i = 0; i <= lenForBiggerString - lenForSmallerString; i++) {
    bool flag = true;
    for (unsigned j = 0; j < lenForSmallerString; j++) {
      if (biggerString[i + j] != smallerString[j]) {
        flag = false;
        break;
      }
    }
    if (flag) {
      ++entryCounter;
    }
  }
  printf("%d\n", entryCounter);
  return 0;
}
// Должно вывести 3
