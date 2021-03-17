#include <stdio.h>
#include <string.h>

#define NUMBER_OF_USERS 10

typedef struct user
{
  int id;
  char name[55];
  char password[16];
} User;

int main(int argc, char const *argv[])
{
  User users[NUMBER_OF_USERS];

  for (int i = 0; i < NUMBER_OF_USERS; i++)
    scanf("%d %s %s", &users[i].id, users[i].name, users[i].password);

  char name[55];
  char password[16];

  scanf("%s %s", name, password);

  for (int i = 0; i < NUMBER_OF_USERS; i++)
  {
    if (strcmp(name, users[i].name) == 0 && strcmp(password, users[i].password) == 0)
    {
      printf("ID:%d\n", users[i].id);
      return 0;
    }
  }

  return 0;
}
