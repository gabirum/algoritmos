#include <stdio.h>

int main()
{
  float a, b, c;

  scanf("%f %f %f", &a, &b, &c);

  float exp = (3 * (a + b)) / (a * c) - c + b;
  float pro = a * b * c;

  if (exp > pro)
  {
    printf("MAIOR");
  }
  else
  {
    printf("MENOR OU IGUAL");
  }

  return 0;
}
