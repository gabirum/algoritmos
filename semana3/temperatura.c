#include <stdio.h>

int main(int argc, char const *argv[])
{
  for (int i = 0; i <= 100; i++)
  {
    float f = (i * 9.0 / 5.0) + 32.0;
    printf("%d C = %.2f F\n", i, f);
  }

  return 0;
}
