#include <stdio.h>

#define NUMBER_OF_PEOPLE 10

typedef struct person
{
  char name[20];
  int age;
} Person;

int main(int argc, char const *argv[])
{
  Person people[NUMBER_OF_PEOPLE];

  for (int i = 0; i < NUMBER_OF_PEOPLE; i++)
    scanf("%s %d", people[i].name, &people[i].age);

  for (int i = 0; i < NUMBER_OF_PEOPLE; i++)
    if (people[i].age < 31)
      printf("%s\n", people[i].name);

  return 0;
}
