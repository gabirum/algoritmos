#include <stdio.h>

int main(int argc, char const *argv[])
{
  int x;

  scanf("%d", &x);

  for (int i = 0; i <= x; i++)
  {
    printf("%d centimetro = %.2f polegadas\n", i, i / 2.54);
  }
  
  return 0;
}
