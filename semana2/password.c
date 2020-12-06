#include <stdio.h>
#include <string.h>

int main()
{
  const char *pass = "nX4%";
  char input[5] = "";

  scanf("%s", input);

  if (strcmp(input, pass) == 0)
  {
    printf("Acesso concedido");
  }
  else
  {
    printf("Acesso nao concedido");
  }

  return 0;
}
