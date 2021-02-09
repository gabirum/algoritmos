#include <stdio.h>

void printFibonacci(unsigned int number)
{
  if (number < 1)
  {
    printf("Numero invalido");
    return;
  }

  int aux = 0;
  int ant = 1;
  int now = 0;

  for (int i = 0; i < number; i++)
  {
    if (i == 0)
    {
      printf("0");
      continue;
    }

    aux = now + ant;
    ant = now;
    now = aux;

    printf(" %d", now);
  }
}

int main(int argc, char const *argv[])
{
  unsigned int number = 0;
  scanf("%d", &number);

  printFibonacci(number);

  return 0;
}
