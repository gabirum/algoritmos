#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int count(const char *text)
{
  int i;

  for (i = 0; text[i] != 0; i++);

  return i;
}

char *trim(const char *text)
{
  int trimCount = 0;
  char *trimmedText = malloc(sizeof(char));

  for (int i = 0; text[i] != 0; i++)
  {
    if (!isspace(text[i]))
    {
      trimmedText = realloc(trimmedText, (sizeof(char) * (++trimCount)));
      trimmedText[trimCount - 1] = toupper(text[i]);
    }
  }

  return trimmedText;
}

int main(int argc, char const *argv[])
{
  char text[100];

  scanf("%[^\n]%*c", text);

  char *trimmedText = trim(text);
  int length = count(trimmedText);
  int it = length / 2;

  for (int i = 0; i < it; i++)
  {
    if (trimmedText[i] != trimmedText[(length - 1) - i])
    {
      printf("Nao eh palindromo\n");
      return 0;
    }
  }

  printf("Eh palindromo\n");

  return 0;
}
