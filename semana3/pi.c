#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
  int x = 0;

  scanf("%d", &x);

  float pi = 0;

  for (int i = 0; i < x; i++)
  {
    pi += powf(-1.0, (float)i) * (4.0 / (1.0 + (2.0 * (float)i)));
  }

  printf("%.5f", pi);

  return 0;
}
