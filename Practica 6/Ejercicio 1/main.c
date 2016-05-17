#include <stdio.h>

int particion(int *, int);
void quicksort(int *, int);
void print_int(int *, int);
void swap(int *, int *);

int main(void)
{
    int lista[] = {10, 5, 7, 2, 9, 8, 1, 3, 4, 6};
    const int tam = 10;

    int l1[] = {5, 4, 3, 2, 1};
    const int tam2 = 5;

    print_int(lista, tam);
    quicksort(lista, tam);
    print_int(lista, tam);

    print_int(l1, tam2);
    quicksort(l1, tam2);
    print_int(l1, tam2);
    return 0;
}

void quicksort(int *l, int tam)
{
  if(tam <= 1)
    return;
  int part = particion(l, tam);
  quicksort(l, part);
  quicksort(&l[part + 1], tam - (part + 1));
}

int particion(int *l, int tam)
{
  int i = -1;
  int j = tam;
  int pivot = l[0];

  while(1)
  {
    do
    {
      j--;
    } while(pivot < l[j]);
    do {
      i++;
    } while(pivot > l[i]);

    if( i < j)
      swap(&l[i], &l[j]);
    else
      return j;
  }
}

void swap(int *x, int *y)
{
  int aux = *x;
  *x = *y;
  *y = aux;
}

void print_int(int *l, int tam)
{
  int i;
  for(i = 0; i < tam; i++)
    printf("%d, ", l[i] );
  printf("\n");
}
