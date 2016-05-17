#include <stdio.h>

void ssort(int *arreglo, int len)
{
  int i, j, posMinimo, aux;
  for(i = 0; i < len - 1; i++)
  {
    posMinimo = i;

    for( j = i + 1; j < len; j++)
    {
      if(arreglo[j] < arreglo[posMinimo])
        posMinimo = j;
    }

    if( i != posMinimo)
    {
      aux = arreglo[i];
      arreglo[i] = arreglo[posMinimo];
      arreglo[posMinimo] = aux;
    }
  }
}

void printInt(int *arreglo, int len)
{
  int i = 0;
  for( ; i < len; i++)
    printf("%d, ", arreglo[i] );
  printf("\n");
}

int main(void)
{
  int arr[] = { 10, 5, 8, 2, 9, 3, 1, 4, 6, 5};
  const int longitud = 10;

  printInt(arr, longitud);
  ssort(arr, longitud);
  printInt(arr, longitud);

  return;
}
