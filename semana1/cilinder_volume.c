#include <stdio.h>
#include <math.h>

int main() {
  const float PI = 3.14;
  float radix, height;

  scanf("%f %f", &radix, &height);

  float volume = PI * powf(radix, 2) * height;

  printf("%.2f", volume);

  return 0;
}