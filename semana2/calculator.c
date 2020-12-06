#include <stdio.h>

int main()
{
  float x, y;
  char op;

  scanf("%f %c %f", &x, &op, &y);

  switch (op)
  {
  case '+':
    printf("%.2f", x + y);
    break;

  case '-':
    printf("%.2f", x - y);
    break;

  case '*':
    printf("%.2f", x * y);
    break;

  case '/':
    if (y != 0) {
      printf("%.2f", x / y);
    } else {
      printf("Divisao por zero");
    }
    break;

  default:
    printf("Operacao Invalida");
    break;
  }

  return 0;
}
