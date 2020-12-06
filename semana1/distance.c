#include <stdio.h>

int main() {
  float values[2] = {0, 0};

  scanf("%f", &values[0]);
  scanf("%f", &values[1]);

  float distance = values[0] * values[1];

  printf("%.2f km", distance);

  return 0;
}