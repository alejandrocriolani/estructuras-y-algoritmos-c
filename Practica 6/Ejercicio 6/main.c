#include <stdio.h>
#include "hsort.h"

void print_int(int *a, int tam)
{
  int i;
  for(i = 0; i < tam; i++)
    printf("%d, ", a[i] );
  printf("\n");
}

int main(void)
{
  int i = 0;

  HSort h1 = hsort_create(20);
  hsort_insert(&h1, 10);
  hsort_insert(&h1, 2);
  hsort_insert(&h1, 3);
  hsort_insert(&h1, 1);
  hsort_insert(&h1, 5);
  hsort_insert(&h1, 7);
  hsort_insert(&h1, 12);
  hsort_insert(&h1, 4);
  hsort_insert(&h1, 6);

  hsort_imprimir(&h1);
  printf("\n");

  for( ; i < 9; i++)
  {
    hsort_eliminar_minimo(&h1);
    hsort_imprimir(&h1);
    printf("\n");
  }


  int arr[] = {1, 3, 5, 6, 10, 3, 2, 9, 0, 88, 120, 25};
  const int tam = 12;

  print_int(arr, tam);

  for(i = 0; i < tam; i++)
    hsort_insert(&h1, arr[i]);

  for(i = 0; i < tam; i++)
  {
    arr[i] = hsort_minimo(&h1);
    hsort_eliminar_minimo(&h1);
  }

  print_int(arr, tam);

  return 0;
}
