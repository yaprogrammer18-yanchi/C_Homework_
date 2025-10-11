#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool checkBrackets(char *stringWithBrackets, int len) {
  // специальный счетчик, "(" это +1 ")" это -1. Если скобочная посл-ть
  // правильная, counter == 0
  int counter = 0;
  // переменная, чтобы сказать пользователю, что нет скобок вообще или что
  // скобочная последовательность неверная
  bool bracketsExist = false;
  for (int i = 0; i < len; i++) {
    if (stringWithBrackets[i] == '(') {
      counter++;
      bracketsExist = true;
    }
    if (stringWithBrackets[i] == ')') {
      counter--;
      bracketsExist = true;
    }
    if (counter < 0) {
      break;
    }
  }
  if (bracketsExist && counter == 0) {
    return true;
  }
  return false;
}

int main() {
  int len = 0;
  printf("Введите, сколько символов Вы хотите ввести, закончите ввод, нажав "
         "enter\n");
  scanf("%d", &len);
  char *stringWithBrackets = malloc(len * sizeof(char));
  getchar();
  for (int i = 0; i < len; i++) {
    scanf("%c", &stringWithBrackets[i]);
  }
  bool isCorrect = checkBrackets(stringWithBrackets, len);
  if (isCorrect) {
    printf("Скобочная последовательность правильная\n");
  } else {
    printf("Скобочная последовательность неправильная или не было введено ни "
           "одной скобки\n");
  }
  free(stringWithBrackets);
  return 0;
}
