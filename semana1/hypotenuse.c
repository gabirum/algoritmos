#include <stdio.h>
#include <math.h>

int main()
{
  float sides[2] = {0, 0};

  scanf("%f", &sides[0]);
  scanf("%f", &sides[1]);

  float hypotenuse = hypotf(sides[0], sides[1]);

  printf("%.2f", hypotenuse);

  return 0;
}
