#include <stdio.h>

int main(int argc, char const *argv[])
{
  int x = 0;
  int y = 0;

  scanf("%d %d", &x, &y);
  int count = 0;

  if (x > y && x <= 0)
  {
    printf("Intervalo invalido");
    return 0;
  }

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
      count++;
      printf("%d\n", i);
    }
  }

  return 0;
}
