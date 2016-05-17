#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int costo;
  int peso;
} item;

int cmp_item(const void *x, const void *y)
{
  item *fst = (item *)x;
  item *snd = (item *)y;
  return -(fst->costo - snd->costo);
}

void maximizar_costo(item *elem, int cant, int pesoMax)
{
  qsort(elem, cant, sizeof(item), cmp_item);

  int i = 0;
  int costoTotal = 0;
  for( ; i < cant; )
  {
    if(elem[i].peso <= pesoMax)
    {
      pesoMax -= elem[i].peso;
      costoTotal += elem[i].costo;
      printf("Elemento %d, costo: %d, peso restante %d\n", i + 1, elem[i].costo, pesoMax );
      i++;
    }

    if(elem[i].peso > pesoMax && pesoMax > 0)
    {
      costoTotal += elem[i].costo;
      pesoMax = 0;
      printf("Elemento %d, costo: %d, peso restante %d\n", i + 1, elem[i].costo, pesoMax );
      i++;
    }

    if(pesoMax == 0)
      break;
  }

  printf("Costo total: %d\n", costoTotal );
}

int main(void)
{
  const unsigned int cantElem = 10;
  const unsigned int PesoMax = 20;
  item *elementos = malloc(sizeof(item));

  elementos[0].costo = 5;
  elementos[0].peso = 3;
  elementos[1].costo = 10;
  elementos[1].peso = 2;
  elementos[2].costo = 10;
  elementos[2].peso = 10;
  elementos[3].costo = 1;
  elementos[3].peso = 1;
  elementos[4].costo = 2;
  elementos[4].peso = 1;
  elementos[5].costo = 5;
  elementos[5].peso = 30;
  elementos[6].costo = 1;
  elementos[6].peso = 3;
  elementos[7].costo = 2;
  elementos[7].peso = 4;
  elementos[8].costo = 3;
  elementos[8].peso = 2;
  elementos[9].costo = 5;
  elementos[9].peso = 3;

  maximizar_costo(elementos, cantElem, PesoMax);

  return 0;
}
