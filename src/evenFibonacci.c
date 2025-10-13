#include <stdio.h>

// рекурсивная функция просто считающая числа фиббоначи, принимает номер числа
// возвращает число фибоначчи
int fibonacci(int n) {
  if (n == 0 || n == 1) {
    return n;
  }
  return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
  int summ = 0;
  // временная переменная, она будет содержать в себе числа фибоначчи
  int tmp = 0;
  // номер числа фибоначчи
  // первый номер равен 0, так что его можно не считать отдельно
  int number = 1;
  while (tmp <= 1000000) {
    if ((tmp % 2) == 0) {
      summ += tmp;
    }
    number++;
    tmp = fibonacci(number);
  }
  printf("%d\n", summ);
  return 0;
}
