#include <stdio.h>

#include "isort.h"

int cmpInt( void *a, void *b)
{
  int x = (int)*a;
  int y = (int)*b;
  if(x < y)
    return 1;
  return 0;
}

int cmpChar(void *a, void *b)
{
  char x = *(char *)a;
  char y = *(char *)b;
  if( x < y)
    return 1;
  return 0;
}

void swapInt( void *a, void *b)
{
  int *x = *(int *)a;
  int *y = *(int *)b;
  int aux = *x;
  *x = *y;
  *y = aux;
}

void swapChar(void *a, void *b)
{
  char *x = *(char *)a;
  char *y = *(char *)b;
  char aux = *x;
  *x = *y;
  *y = aux;
}

void printInt(int *a, int l)
{
  int i;
  for(i = 0; i < l; i++)
    printf("%d, ", a[i] );
  printf("\n");
}

void printChar(char *a, int l)
{
  int i;
  for(i = 0; i < l; i++)
    printf("%c, ", a[i] );
  printf("\n");
}

int main(void)
{
  int longitud = 10;
  int arr1[] = { 3, 5, 1, 10, 6, 2, 4, 8, 7 ,9};
  printInt(arr1, longitud);

  isort_a(arr1, longitud, cmpInt, swapInt);
  printInt(arr1, longitud);

  char arr2[] = {'a', 'g', 'p', 'm', 'e', 'h', 'w', 'z', 'p', 't'};
  printChar(arr2, longitud);
  isort_a(arr2, longitud, cmpChar, swapChar);
  printChar(arr2, longitud);

  return 0;
}
