#include <stdio.h>

int main() {
  float v0;
  float a;
  float t;

  scanf("%f", &v0);
  scanf("%f", &a);
  scanf("%f", &t);

  float vf = v0 + a*t;

  printf("%.2f", vf);

  return 0;
}