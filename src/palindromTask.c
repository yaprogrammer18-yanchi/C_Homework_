#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool palindrom(char *line, int counter) {
  if ((counter % 2) == 0) {
    for (int i = 0; i < (counter / 2); i++)
      if (line[i] != line[counter - i - 1]) {
        return false;
      }
  } else {
    for (int i = 0; i < (counter / 2); i++)
      if (line[i] != line[counter - i - 1]) {
        printf("%c %c\n", line[i], line[counter - i - 1]);
        return false;
      }
  }
  return true;
}

int main() {
  printf("Введите число символов, которое хотите ввести, завершите ввод нажав "
         "enter\n");
  printf("На след строке введите строку и завершите ввод enter\n");
  int len = 0;
  scanf("%d", &len);
  getchar();
  char *arrayWithString = malloc(len * sizeof(char));
  // счетчик чтобы считать кол-во не пробелов
  int counter = 0;
  for (int i = 0; i < len; i++) {
    char tmp = ' ';
    scanf("%c", &tmp);
    if (tmp != ' ') {
      arrayWithString[counter] = tmp;
      ++counter;
    }
  }
  if (palindrom(arrayWithString, counter)) {
    printf("Строка является палиндромом\n");
  } else {
    printf("Строка не является палиндромом\n");

    return 0;
  }
}
