#include <stdio.h>

int main()
{
  int t = 0;
  float v = 0;

  scanf("%d %f", &t, &v);

  switch (t)
  {
  case 1:
    printf("%.2f", (v * 1.03));
    break;

  case 2:
    printf("%.2f", (v * 1.04));
    break;

  default:
    printf("Tipo invalido");
    break;
  }

  return 0;
}
