/*
Uma agência espiã deseja enviar mensagens secretas para seus agentes. O código dessas
mensagens é a substituição das vogais por números, sendo que as vogais A E I O U correspondem
a 2 3 4 5 6.
Nesse código a frase “EU ESTOU NA AULA” corresponde à frase: “36 3ST56 N2 26L2”. Caso
sejam encontrados números na frase original eles devem ser substituídos pelas suas vogais
correspondentes.
Faça um programa em C que receba uma frase e a codifique-a. A frase deve possuir no máximo
60 caracteres. Faça toda a manipulação da frase informada utilizando ponteiros.
Mostre o programa funcionando utilizando de entrada seu Nome completo e o seu RU
simultaneamente.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 61
#define CODE_LENGTH 5

int isValueInArray(char value, const char *array, size_t len);
void turnVowelToNumber(char *vowel);
void turnNumberToVowel(char *number);

int main()
{
  const char NUMBER_ARRAY[] = {'2', '3', '4', '5', '6'};
  const char VOWEL_ARRAY[] = {'A', 'E', 'I', 'O', 'U'};

  char sentence[MAX_SENTENCE_LENGTH];
  fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

  for (size_t i = 0; i < strlen(sentence); i++)
  {
    if (isValueInArray(sentence[i], VOWEL_ARRAY, CODE_LENGTH))
    {
      turnVowelToNumber(&sentence[i]);
    }
    else if (isValueInArray(sentence[i], NUMBER_ARRAY, CODE_LENGTH))
    {
      turnNumberToVowel(&sentence[i]);
    }
  }

  printf("%s", sentence);

  return 0;
}

int isValueInArray(char value, const char *array, size_t len)
{
  for (size_t i = 0; i < len; i++)
  {
    if (array[i] == value)
    {
      return 1;
    }
  }

  return 0;
}

void turnVowelToNumber(char *vowel)
{
  if (*vowel == 'A')
  {
    *vowel = '2';
  }
  else if (*vowel == 'E')
  {
    *vowel = '3';
  }
  else if (*vowel == 'I')
  {
    *vowel = '4';
  }
  else if (*vowel == 'O')
  {
    *vowel = '5';
  }
  else if (*vowel == 'U')
  {
    *vowel = '6';
  }
}

void turnNumberToVowel(char *number)
{
  if (*number == '2')
  {
    *number = 'A';
  }
  else if (*number == '3')
  {
    *number = 'E';
  }
  else if (*number == '4')
  {
    *number = 'I';
  }
  else if (*number == '5')
  {
    *number = 'O';
  }
  else if (*number == '6')
  {
    *number = 'U';
  }
}
