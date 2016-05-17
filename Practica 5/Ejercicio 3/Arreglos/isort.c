#include "isort.h"

void isort_a(void *arreglo, int len, cmpFunc cmp, swapFunc swap)
{
  int i, j;
  for( j = 1; j < len; j++)
  {
    for(i = 0; i < j; i++)
    {
      if (cmp(&arreglo[j], &arreglo[i]))
        swap(&arreglo[i], &arreglo[j]);
    }
  }
}
