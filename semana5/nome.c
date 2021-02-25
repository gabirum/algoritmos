#include <stdio.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
  char name[100];

  scanf("%[^\n]%*c", name);

  for (int i = 0; name[i] != 0; i++)
  {
    if (isspace(name[i]))
      continue;

    if (i > 0)
    {
      if (isspace(name[i - 1]))
        printf("%c", name[i]);
    }
    else
    {
      printf("%c", name[i]);
    }
  }

  return 0;
}
