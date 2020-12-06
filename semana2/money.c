#include <stdio.h>

int main()
{
  const int integerTypes[7] = {100, 50, 20, 10, 5, 2, 1};
  const int decimalTypes[5] = {50, 25, 10, 5, 1};

  int integerInput = 0;
  int decimalInput = 0;

  scanf("%d.%d", &integerInput, &decimalInput);

  for (int i = 0; i < 7; i++)
  {
    int qtt = integerInput / integerTypes[i];
    integerInput -= qtt * integerTypes[i];

    if (qtt > 0)
    {
      if (integerTypes[i] > 1)
      {
        printf("%d nota(s) de %d reais\n", qtt, integerTypes[i]);
      }
      else
      {
        printf("%d moeda(s) de 1 real\n", qtt);
      }
    }
  }

  for (int i = 0; i < 5; i++)
  {
    int qtt = decimalInput / decimalTypes[i];
    decimalInput -= qtt * decimalTypes[i];

    if (qtt > 0)
    {
      if (decimalTypes[i] > 1)
      {
        printf("%d moeda(s) de %d centavos\n", qtt, decimalTypes[i]);
      }
      else
      {
        printf("%d moeda(s) de 1 centavo\n", qtt);
      }
    }
  }

  return 0;
}
