#include <stdio.h>

int main(int argc, char const *argv[])
{
  int x = 0;
  int y = 0;

  scanf("%d %d", &x, &y);

  for (int i = x; i <= y; i++)
  {
    int sum = 0;
    for (int j = 1; j < i; j++)
    {
      if (i % j == 0)
      {
        sum += j;
      }
    }

    if (i == sum)
    {
      printf("%d\n", i);
    }
  }

  return 0;
}
