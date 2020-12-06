#include <stdio.h>

int verifyHigher(int _x, int _y) {
  return _x > _y ? _x : _y;
}

int main() {
  int a, b, c;

  scanf("%d %d %d", &a, &b, &c);

  printf("%d", verifyHigher(a, verifyHigher(b, c)));
  
  return 0;
}
