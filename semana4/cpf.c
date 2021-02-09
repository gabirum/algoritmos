#include <stdio.h>

int deepCompare(int numbers[11])
{
  int counter = 1;

  for (int i = 0; i < 10; i++)
  {
    if (numbers[i] == numbers[i + 1])
      counter++;
  }

  return counter >= 11;
}

void verifyCPF(char cpf[11])
{
  int cpfNum[11];
  int rest = 0;
  int acc = 0;

  for (int i = 0; i < 11; i++)
  {
    if (cpf[i] < '0' || cpf[i] > '9')
    {
      printf("Numero invalido\n");
      return;
    }

    cpfNum[i] = cpf[i] - '0';
  }

  if (deepCompare(cpfNum))
  {
    printf("Nao eh valido");
    return;
  }

  for (int i = 0; i < 9; i++)
    acc += (10 - i) * cpfNum[i];

  rest = acc % 11;
  int j = rest == 0 || rest == 1 ? 0 : 11 - rest;

  if (j != cpfNum[9])
  {
    printf("Nao eh valido\n");
    return;
  }

  acc = 0;

  for (int i = 0; i < 10; i++)
    acc += (11 - i) * cpfNum[i];

  rest = acc % 11;
  int k = rest == 0 || rest == 1 ? 0 : 11 - rest;

  if (k != cpfNum[10])
  {
    printf("Nao eh valido\n");
    return;
  }

  printf("Eh valido\n");
}

int main(int argc, char const *argv[])
{
  char cpf[11];

  // esse for só é necessário pois o run.codes não compila com scanf("%s", cpf);
  for (int i = 0; i < 11; i++)
    scanf("%c", (cpf + i));

  verifyCPF(cpf);

  return 0;
}
