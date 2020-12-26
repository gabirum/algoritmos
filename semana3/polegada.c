#include <stdio.h>

int main(int argc, char const *argv[])
{
  int x;

  scanf("%d", &x);

  if (x <= 0)
  {
    return 0;
  }

  for (int i = 1; i <= x; i++)
  {
    printf("%d centimetros = %.2f polegadas\n", i, i / 2.54);
  }

  return 0;
}
