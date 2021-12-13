/*
A cidade de Springfield possui um único posto telefônico. Por este posto são feitas todas as
ligações interurbanas da cidade. O valor a ser pago é calculado seguindo as seguintes regras:
– Taxa de R$ 2,00 pela ligação, R$ 1,00 para os 3 primeiros minutos;
– Acima de três primeiros minutos as regras são de R$1,50 para cada intervalo de 5 minutos e
R$ 0,25 para cada minuto abaixo disto.
Para demonstrar o funcionamento mostre o resultado informando como tempo de ligação
a) Tempo de ligação igual ao 4 digito do seu RU.
b) Tempo de ligação igual a soma do terceiro com o sexto digito do seu RU.
c) Tempo de ligação igual a soma do primeiro com o terceiro digito do seu RU.
Atenção: Se o dígito solicitado do seu RU for zero utilize o dígito a direita.
*/

#include <stdio.h>
#define FIX_TAX 2
#define TAX_UNTIL_3_MIN 1

void main()
{
  double time, price = FIX_TAX + TAX_UNTIL_3_MIN;
  printf("Tempo de ligação: ");
  scanf("%le", &time);
  if (time > 3)
  {
    const int TIME_OVER_3_MIN = time - 3;
    if (TIME_OVER_3_MIN < 5)
    {
      price += TIME_OVER_3_MIN * 0.25;
    }
    else
    {
      price += (TIME_OVER_3_MIN / 5) * 1.5;
    }
  }
  printf("Valor total: R$%.2f\n", price);
}
