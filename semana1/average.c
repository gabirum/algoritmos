#include <stdio.h>

int main() {
  float values[3] = {0, 0, 0};

  scanf("%f", &values[0]);
  scanf("%f", &values[1]);
  scanf("%f", &values[2]);

  float result = (values[0] * 2 + values[1] * 5 + values[2] * 7) / 14;

  printf("%.2f", result);

  return 0;
}