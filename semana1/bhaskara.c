#include <stdio.h>
#include <math.h>

int main() {
  float b = 0;
  float c = 0;
  float a = 0;
  
  scanf("%f", &a);
  scanf("%f", &b);
  scanf("%f", &c);

  float delta = pow(b, 2) - 4 * a * c;

  float x[2] = {0, 0};

  x[0] = ((-b + sqrtf(delta)) / (2 * a));
  x[1] = ((-b - sqrtf(delta)) / (2 * a));

  printf("%.2f %.2f %.2f", delta, x[0], x[1]);

  return -1;
}