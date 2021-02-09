#include <stdio.h>

int main(int argc, char const *argv[])
{
  int first = 0;

  scanf("%d", &first);

  int sum = first;

  while (sum <= 100)
  {
    int aux;

    scanf("%d", &aux);

    sum += aux;
  }

  if (first == 0)
  {
    printf("%.2f", sum / 10.0);
  }
  else
  {
    printf("%.2f", (float)sum / (float)first);
  }

  return 0;
}
