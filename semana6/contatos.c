#include <stdio.h>
#include <string.h>

#define PEOPLE 10

typedef struct contact
{
  char name[55];
  char address[100];
  char email[55];
  char telephone[25];
} Contact;

void sort(Contact *contacts)
{
  for (int i = 0; i < PEOPLE; i++)
  {
    for (int j = i + 1; j < PEOPLE; j++)
    {
      if (strcmp(contacts[i].name, contacts[j].name) > 0)
      {
        Contact aux = contacts[i];
        contacts[i] = contacts[j];
        contacts[j] = aux;
      }
    }
  }
}

int main(int argc, char const *argv[])
{
  Contact contacts[PEOPLE];

  for (int i = 0; i < PEOPLE; i++)
    scanf("%s %s %s %s", contacts[i].name, contacts[i].address, contacts[i].email, contacts[i].telephone);

  sort(contacts);

  for (int i = 0; i < PEOPLE; i++)
    printf("%s - %s - %s - %s\n", contacts[i].name, contacts[i].address, contacts[i].email, contacts[i].telephone);

  return 0;
}
