#include <stdio.h>

int main(int argc, char const *argv[])
{
  for (int i = 0; i < 5; i++)
  {
    int idade = 0;

    scanf("%d", &idade);

    if (idade < 0)
    {
      printf("idade invalida\n");
    }
    else if (idade >= 18)
    {
      printf("maior de idade\n");
    }
    else if (idade < 18 && idade >= 0)
    {
      printf("menor de idade\n");
    }
  }

  return 0;
}
