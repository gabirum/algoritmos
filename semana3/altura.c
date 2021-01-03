#include <stdio.h>

int calcular(float alturaDoMaior, float alturaDoMenor, float taxaDoMaior, float taxaDoMenor)
{
  float alt0 = alturaDoMaior;
  float alt1 = alturaDoMenor;

  int i = 0;

  for (; alt1 <= alt0; i++)
  {
    alt0 += taxaDoMaior;
    alt1 += taxaDoMenor;
  }

  return i;
}

int main(int argc, char const *argv[])
{
  float altura0 = 0;
  float altura1 = 0;
  float taxa0 = 0;
  float taxa1 = 0;

  scanf("%f %f", &altura0, &taxa0);
  scanf("%f %f", &altura1, &taxa1);

  if (altura0 == altura1)
  {
    printf("dados invalidos");
    return 0;
  }

  if (altura0 > altura1)
  {
    if (taxa1 < taxa0) {
      printf("dados invalidos");
    } else {
      printf("%d", calcular(altura0, altura1, taxa0, taxa1));
    }
  }
  else
  {
    if (taxa0 < taxa1) {
      printf("dados invalidos");
    } else {
      printf("%d", calcular(altura1, altura0, taxa1, taxa0));
    }
  }

  return 0;
}
