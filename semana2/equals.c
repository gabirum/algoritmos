#include <stdio.h>

int verifySmall(int a, int b)
{
  return a < b ? a : b;
}

int main()
{
  int a, b, c;

  scanf("%d %d %d", &a, &b, &c);

  if (a == b && b == c)
  {
    printf("Iguais");
  }
  else
  {
    printf("%d", verifySmall(a, verifySmall(b, c)));
  }

  return 0;
}
