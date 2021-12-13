/*
Crie um programa, em linguagem C, que faça sugestões automáticas de jogos para a Mega
Sena. Deverá ser informado quantos jogos (de seis números) o usuário deseja (no máximo vinte
jogos).

✓ Crie um registro para armazenar cada jogo.
✓ Crie um vetor para armazenar os jogos gerados.
✓ Verifique se não existem números repetidos no jogo.
✓ Verifique se não existem jogos repetidos.

Ao final mostre os jogos na tela e pergunte ao usuário se ele deseja gerar um arquivo com os jogos.
Os jogos deverão ser armazenados em um arquivo formato CSV, com cada número em um
campo diferente. O arquivo CSV é um arquivo que utiliza um separador entre os campos. Utilize o ;
(ponto e vírgula) para separador e campo. O nome do arquivo deve ser o seu número de RU.
Para demonstrar o funcionamento utilize a soma do segundo dígito com o quarto digito do seu
RU como a quantidade de jogos. Coloque a imagem da tela com os números gerados e imagem do
arquivo aberto no Bloco de Notas ou no Excel com os jogos gerados (caso não disponha do Bloco
de Notas ou Excel utilize o programa equivalente disponível em seu computador).
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_NUMBERS_PER_GAME 6
#define MAX_GAMES 20
#define MIN_GAMES 1

int getValidAmountOfGames();
void generateGame(int *array, int gameStartIndex);
int isIntInArray(int value, int *array, int len);
void printMatrix(int array[20][6], int rows, int columns);
int gameIsNotUnique(int array[20][6], int rows);
void sortArray(int *array);
void swap(int *a, int *b);
char getValidChoice();
void writeGamesToFile(int array[20][6], int rows);

int main()
{
  srand(time(NULL));
  int amountOfGames, games[MAX_GAMES][MAX_NUMBERS_PER_GAME], rows;
  char choice;
  amountOfGames = getValidAmountOfGames();

  for (size_t i = 0; i < amountOfGames; i++)
  {
    int gameStartIndex = i * MAX_NUMBERS_PER_GAME;
    rows = i + 1;
    generateGame(&games, gameStartIndex);
    while (gameIsNotUnique(games, rows))
    {
      generateGame(&games, gameStartIndex);
    }
  }

  printMatrix(games, amountOfGames, MAX_NUMBERS_PER_GAME);

  printf("Deseja salvar os jogos em um arquivo?\nS / N\n");
  choice = getValidChoice();

  if (choice == 'S')
  {
    writeGamesToFile(games, rows);
  }

  return 0;
}

void writeGamesToFile(int array[20][6], int rows)
{
  FILE *file;
  file = fopen("3764895.csv", "w");
  for (size_t i = 0; i < rows; i++)
  {
    for (size_t j = 0; j < MAX_NUMBERS_PER_GAME; j++)
    {
      fprintf(file, "%d;", array[i][j]);
    }
    fputc(10, file);
  }

  fclose(file);
}

char getValidChoice()
{
  char choice;
  getchar();
  scanf("%c", &choice);
  while (choice != 'S' && choice != 'N')
  {
    printf("Escolha inválida, tente novamente.\n");
    printf("Deseja salvar os jogos em um arquivo?\nS / N\n");
    getchar();
    scanf("%c", &choice);
  }
  return choice;
}

int getValidAmountOfGames()
{
  int amountOfGames;
  printf("Digite a quantidade de jogos que serão criados.\nMínimo: %d\nMáximo: %d\n", MIN_GAMES, MAX_GAMES);
  scanf("%d", &amountOfGames);
  while (amountOfGames < MIN_GAMES || amountOfGames > MAX_GAMES)
  {
    system("clear");
    printf("Quantidade inválida, tente novamente.");
    printf("Digite a quantidade de jogos que serão criados.\nMínimo: %d\nMáximo: %d\n", MIN_GAMES, MAX_GAMES);
    scanf("%d", &amountOfGames);
  }
  return amountOfGames;
}

void generateGame(int *array, int gameStartIndex)
{
  int random_number;

  for (size_t i = 0; i < MAX_NUMBERS_PER_GAME; i++)
  {
    random_number = (rand() % 60) + 1;
    while (isIntInArray(random_number, array + gameStartIndex, MAX_NUMBERS_PER_GAME))
    {
      random_number = (rand() % 60) + 1;
    }
    *(array + gameStartIndex + i) = random_number;
  }
  sortArray(array + gameStartIndex);
}

int isIntInArray(int value, int *array, int len)
{
  int arrayValue;
  for (size_t i = 0; i < len; i++)
  {
    arrayValue = *(array + i);
    if (value == arrayValue)
    {
      return 1;
    }
  }
  return 0;
}

void sortArray(int *array)
{
  int smallestIdx;

  for (int i = 0; i < MAX_NUMBERS_PER_GAME; i++)
  {

    smallestIdx = i;
    for (int j = i + 1; j < MAX_NUMBERS_PER_GAME; j++)
    {
      if (*(array + j) < *(array + smallestIdx))
      {
        smallestIdx = j;
      }
    }

    swap(array + smallestIdx, array + i);
  }
}

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

int gameIsNotUnique(int array[20][6], int rows)
{
  if (rows > 1)
  {
    int lastGame = rows - 1;
    for (int i = rows - 2; i >= 0; i--)
    {
      int result = memcmp(array[lastGame], array[i], MAX_NUMBERS_PER_GAME);
      if (result == 0)
      {
        return 1;
      }
    }
  }

  return 0;
}

void printMatrix(int array[20][6], int rows, int columns)
{
  for (size_t i = 0; i < rows; i++)
  {
    for (size_t j = 0; j < columns; j++)
    {
      printf("%d ", array[i][j]);
    }
    printf("\n");
  }
}