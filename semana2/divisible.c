#include <stdio.h>

int main() {
  int a, b;

  scanf("%d %d", &a, &b);

  if (a%b == 0) {
    printf("Eh divisivel");
  } else {
    printf("Nao eh divisivel");
  }

  return 0;
}
