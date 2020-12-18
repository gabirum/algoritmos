#include <stdio.h>
#include <math.h>

int main()
{
  float x = 0;

  scanf("%f", &x);

  for (int i = 1; i <= x; i++)
  {
    printf("O quadrado de %d eh %.2f\n", i, powf((float)i, 2));
  }

  return 0;
}
