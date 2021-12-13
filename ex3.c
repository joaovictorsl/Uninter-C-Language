/*
Implementar a função cujo cabeçalho é apresentado a seguir:
unsigned int calculaParidade (unsigned char b);
Interferências, ruídos e outros fenômenos que prejudicam a integridade dos dados são
problemas fundamentais quando computadores se comunicam em rede. Para detectar alterações
em bits, os dados são sempre enviados com redundâncias computadas a partir dos bits originais.
Este tipo de técnica de detecção de erros costuma receber o nome de checksum, e segue o mesmo
princípio dos dígitos verificadores presentes em diversos documentos e identificadores numéricos
(por exemplo, números de contas e agências bancárias).
Uma das técnicas de detecção de erros mais simples e mais usadas é o teste de paridade.
Cada byte é enviado junto com um bit adicional, que indica se o número de bits com valor 1 no byte
é par (bit redundante = 0) ou ímpar (bit redundante = 1). Por exemplo um byte com o valor 8 tem os
bits 00001000, ou seja, apenas 1 bit “setado”, portanto a sua paridade é 1. Já um byte com o valor
0x55 é representado pelos bits 01010101 – 4 bits “setados”, portanto a sua paridade é 0 (zero). A
função calculaParidade deve receber como parâmetro um byte enviado ou recebido através de uma
conexão, e retornar o valor do bit redundante (0 ou 1).
Para demonstrar o funcionamento demonstre o cálculo de pariedade de cada dígito do seu
primeiro nome. Utilize o valor dos caracteres na tabela ASCII (disponível no anexo).
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int calculaParidade(unsigned char b);
int *convertDecimalToByte(int decimal);
int contarBits1EmByte(int *byte);

int main()
{
  char meuNome[5] = {'J', 'O', 'A', 'O'};
  for (size_t i = 0; i < strlen(meuNome); i++)
  {
    unsigned int paridade = calculaParidade(meuNome[i]);
    printf("Paridade do dígito %c é %d\n", meuNome[i], paridade);
  }

  return 0;
}

unsigned int calculaParidade(unsigned char b)
{
  int *byte = convertDecimalToByte((int)b);
  unsigned int qtdDeBits1 = contarBits1EmByte(byte);
  if (qtdDeBits1 % 2 == 0)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}

int *convertDecimalToByte(int decimal)
{
  static int byte[8];
  int quociente, resto, index = 7;

  quociente = decimal / 2;
  resto = decimal % 2;
  byte[index--] = resto;

  while (quociente >= 2)
  {
    resto = quociente % 2;
    quociente = quociente / 2;
    byte[index--] = resto;
  }

  byte[index] = quociente;

  return byte;
}

int contarBits1EmByte(int *byte)
{
  int amount = 0;
  for (size_t i = 0; i < 8; i++)
  {
    if (*(byte + i) == 1)
    {
      amount++;
    }
  }

  return amount;
}
