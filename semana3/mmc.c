#include <stdio.h>

int mdc(int x, int y);
int mmc(int x, int y);

int mdc(int x, int y)
{
  if (y == 0)
    return x;
  return mdc(y, x % y);
}

int mmc(int x, int y)
{
  return x * (y / mdc(x, y));
}

int main(int argc, char const *argv[])
{
  int x = 0;
  int y = 0;

  scanf("%d %d", &x, &y);

  printf("%d", mmc(x, y));

  return 0;
}
