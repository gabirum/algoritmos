#include <stdio.h>

int main()
{
  float x = 0;

  scanf("%f", &x);

  float exp = (x + 4) * (x - 6);

  printf("%.2f", exp);

  return 0;
}