#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NUMBER_OF_LETTERS 26

typedef struct
{
  char letter;
  int quantity;
} Item;

void fillItemsArray(Item data[NUMBER_OF_LETTERS])
{
  for (int i = 0; i < NUMBER_OF_LETTERS; i++)
  {
    data[i].letter = 'A' + i;
    data[i].quantity = 0;
  }
}

void addToData(Item data[NUMBER_OF_LETTERS], char c)
{
  for (int i = 0; i < NUMBER_OF_LETTERS; i++)
    if (data[i].letter == c)
      data[i].quantity++;
}

void printData(Item data[NUMBER_OF_LETTERS])
{
  for (int i = 0; i < NUMBER_OF_LETTERS; i++)
    if (data[i].quantity > 0)
      printf("%c = %d\n", data[i].letter, data[i].quantity);
}

int main(int argc, char const *argv[])
{
  Item data[NUMBER_OF_LETTERS];
  fillItemsArray(data);

  char text[100];

  scanf("%[^\n]%*c", text);

  for (int i = 0; text[i] != 0; i++)
  {
    char charToWork = text[i];

    if (isspace(charToWork) || !isalpha(charToWork))
      continue;

    char upperChar = toupper(charToWork);

    addToData(data, upperChar);
  }

  printData(data);

  return 0;
}
