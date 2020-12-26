#include <stdio.h>
#include <math.h>

int main()
{
  float x = 0;

  scanf("%f", &x);

  if (x <= 0)
  {
    printf("Numero invalido");
    return 0;
  }

  for (int i = 1; i <= x; i++)
  {
    printf("O quadrado de %d eh %.0f\n", i, powf((float)i, 2));
  }

  return 0;
}
