#include <stdio.h>
#include <math.h>

int main() {
  const float PI = 3.14;
  float radix;

  scanf("%f", &radix);

  float volume = (4 * PI * powf(radix, 3)) / 3;

  printf("%.2f", volume);
  
  return 0;
}