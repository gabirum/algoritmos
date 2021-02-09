#include <stdio.h>

int isPrimeNumber(int number)
{
  int counter = 0;

  for (int i = 1; i <= number; i++)
  {
    if (number % i == 0)
    {
      counter++;
    }
  }

  return counter == 2;
}

int main(int argc, char const *argv[])
{
  int num = 0;

  scanf("%d", &num);

  if (num <= 0)
  {
    printf("Numero invalido\n");
    return 0;
  }

  if (isPrimeNumber(num))
  {
    printf("Eh primo\n");
  }
  else
  {
    printf("Nao eh primo\n");
  }

  return 0;
}
