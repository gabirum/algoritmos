#include <stdio.h>

int main() {
  int number = 0;

  scanf("%d", &number);

  if (number >= 100 && number < 1000) {
    printf("%s", (number/100) % 2 == 0 ? "PAR" : "IMPAR");
  } else {
    printf("Numero Invalido");
  }

  return 0;
}
