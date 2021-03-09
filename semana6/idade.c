#include <stdio.h>

#define NUMBER_OF_PEOPLE 10

typedef struct person
{
  char name[55];
  int age;
} Person;

int main(int argc, char const *argv[])
{
  Person people[NUMBER_OF_PEOPLE];

  for (int i = 0; i < NUMBER_OF_PEOPLE; i++)
  {
    scanf("%s %d", people[i].name, &people[i].age);

    if (people[i].age < 30)
      printf("%s", people[i].name);
  }

  return 0;
}
