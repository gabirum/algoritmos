#include <stdio.h>

int main()
{
  int a, b, c;

  scanf("%d %d %d", &a, &b, &c);

  if (a == b && b == c)
  {
    printf("%s", a % 2 == 0 ? "PAR" : "IMPAR");
  }
  else
  {
    float media = (a + b + c) / 3.0;

    printf("%.2f", media);
  }

  return 0;
}
