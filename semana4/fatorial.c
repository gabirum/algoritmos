#include <stdio.h>

int fatorial(int number)
{
  if (number < 0)
    return 0;
  if (number == 1 || number == 0)
    return 1;
  return number * fatorial(number - 1);
}

int main(int argc, char const *argv[])
{
  int num = 0;
  scanf("%d", &num);

  if (num < 0)
  {
    printf("Numero invalido");
    return 0;
  }

  printf("%d\n", fatorial(num));

  return 0;
}
