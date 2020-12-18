#include <stdio.h>

int main(int argc, char const *argv[])
{
  for (int i = 0; i <= 1000; i++)
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
