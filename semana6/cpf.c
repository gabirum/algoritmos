#include <stdio.h>

#define NUMBER_OF_PEOPLE 10

int deepCompare(int numbers[11]);
int verifyCPF(char cpf[11]);

typedef struct person
{
  char name[55];
  int age;
  char cpf[11];
} Person;

int main(int argc, char const *argv[])
{
  Person people[NUMBER_OF_PEOPLE];

  for (int i = 0; i < NUMBER_OF_PEOPLE; i++)
    scanf("%s %d %s", people[i].name, &people[i].age, people[i].cpf);

  for (int i = 0; i < NUMBER_OF_PEOPLE; i++)
    if (verifyCPF(people[i].cpf))
      printf("%s - %d - %s\n", people[i].name, people[i].age, people[i].cpf);

  return 0;
}

int deepCompare(int numbers[11])
{
  int counter = 1;

  for (int i = 0; i < 10; i++)
    if (numbers[i] == numbers[i + 1])
      counter++;

  return counter >= 11;
}

int verifyCPF(char cpf[11])
{
  int cpfNum[11];
  int rest = 0;
  int acc = 0;

  for (int i = 0; i < 11; i++)
  {
    if (cpf[i] < '0' || cpf[i] > '9')
      return 0;

    cpfNum[i] = cpf[i] - '0';
  }

  if (deepCompare(cpfNum))
    return 0;

  for (int i = 0; i < 9; i++)
    acc += (10 - i) * cpfNum[i];

  rest = acc % 11;
  int j = rest == 0 || rest == 1 ? 0 : 11 - rest;

  if (j != cpfNum[9])
    return 0;

  acc = 0;

  for (int i = 0; i < 10; i++)
    acc += (11 - i) * cpfNum[i];

  rest = acc % 11;
  int k = rest == 0 || rest == 1 ? 0 : 11 - rest;

  if (k != cpfNum[10])
    return 0;

  return 1;
}
