#include <stdio.h>

int main(int argc, char const *argv[])
{
  int sum = 0;
  int in = 0;
  int counter = -1;

  while (in <= 20)
  {
    sum += in;
    counter++;

    scanf("%d", &in);
  }

  if (counter <= 0)
  {
    printf("Divisao por zero");
    return 0;
  }

  printf("%.2f", ((float)sum / (float)counter));

  return 0;
}
