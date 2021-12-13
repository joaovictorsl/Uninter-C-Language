/*
Faça, em linguagem C, uma função recursiva que calcule a soma dos dígitos do seu RU. O RU deverá ser digitado pelo usuário.
Para demonstrar o funcionamento utilize o seu RU como entrada e mostre a saída da função.
*/

#include <stdio.h>
#include <stdlib.h>

#define RU_LENGTH 8

int *convertRUAsCharToIntArray(char *array);
int sumAllRUDigits(int *arrayOfInts, int sum, int index);

int main()
{
  char RUAsChar[RU_LENGTH];
  int *RUAsInt;
  printf("Digite seu RU: ");
  fgets(RUAsChar, RU_LENGTH, stdin);
  RUAsInt = convertRUAsCharToIntArray(RUAsChar);
  int sum = sumAllRUDigits(RUAsInt, 0, 0);

  printf("%d", sum);

  return 0;
}

int *convertRUAsCharToIntArray(char *array)
{
  static int intArray[7];
  for (size_t i = 0; i < 7; i++)
  {
    intArray[i] = array[i] - '0';
  }

  return intArray;
}

int sumAllRUDigits(int *arrayOfInts, int sum, int index)
{
  if (index <= 6)
  {
    sum += *(arrayOfInts + index);
    return sumAllRUDigits(arrayOfInts, sum, index + 1);
  }
  return sum;
}
