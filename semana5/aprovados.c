#include <stdio.h>

int main(int argc, char const *argv[])
{
  char names[10][20];
  float grades[10];

  for (int i = 0; i < 10; i++)
  {
    scanf(" %s %f", names[i], &grades[i]);
  }

  for (int i = 0; i < 10; i++)
  {
    if (grades[i] >= 6.0)
      printf("%s\n", names[i]);
  }

  return 0;
}
