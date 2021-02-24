#include <stdio.h>

int getBigger(int *numbers, int length)
{
  int bigger = numbers[0];

  for (int i = 1; i < length; i++)
    bigger = numbers[i] > bigger ? numbers[i] : bigger;

  return bigger;
}

int getSmaller(int *numbers, int length)
{
  int smaller = numbers[0];

  for (int i = 1; i < length; i++)
    smaller = numbers[i] < smaller ? numbers[i] : smaller;

  return smaller;
}

float average(int _x, int _y)
{
  return (float)(_x + _y) / 2.0;
}

int main(int argc, char const *argv[])
{
  const int length = 10;
  int arr[10] = {};

  for (int i = 0; i < length; i++)
    scanf("%d", &arr[i]);

  int small = getSmaller(arr, length);
  int big = getBigger(arr, length);

  printf("%.2f\n", average(small, big));

  return 0;
}
