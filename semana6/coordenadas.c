#include <stdio.h>
#include <math.h>

#define NUMBER_OF_COORDINATES 10

typedef struct coordinates
{
  float x;
  float y;
} Coordinate;

float calcDistance(Coordinate c1, Coordinate c2)
{
  return sqrtf(powf(c2.x - c1.x, 2) + powf(c2.y - c1.y, 2));
}

int main(int argc, char const *argv[])
{
  Coordinate coordinates[NUMBER_OF_COORDINATES];

  for (int i = 0; i < NUMBER_OF_COORDINATES; i++)
    scanf("%f %f", &coordinates[i].x, &coordinates[i].y);

  Coordinate *min;

  float sumOfDistance = 0;
  float minSum;

  for (int i = 0; i < NUMBER_OF_COORDINATES; i++)
  {
    sumOfDistance = 0;

    for (int j = 0; j < NUMBER_OF_COORDINATES; j++)
    {
      if (i == j)
        continue;

      sumOfDistance += calcDistance(coordinates[i], coordinates[j]);
    }

    if (i == 0 || sumOfDistance < minSum)
    {
      min = &coordinates[i];
      minSum = sumOfDistance;
    }
  }

  printf("(%.2f, %.2f)\n", min->x, min->y);

  return 0;
}
