#include <stdio.h>

int main(int argc, char const *argv[])
{
  int sum = 0;
  int in = 0;
  int counter = 0;

  while ((sum + in) <= 20)
  {
    sum += in;
    counter++;

    scanf("%d", &in);
  }

  printf("%.2f", ((float) sum / (float) counter));
  
  return 0;
}
