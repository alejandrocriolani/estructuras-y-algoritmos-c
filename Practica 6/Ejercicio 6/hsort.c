#include <stdio.h>
#include <stdlib.h>

#include "hsort.h"

void swap(int *x, int *y)
{
  int aux = *x;
  *x = *y;
  *y = aux;
}

HSort hsort_create(int elem)
{
  HSort newHeap = malloc(sizeof(newHeap));
  int *l = malloc(sizeof(int) * (elem + 1));

  newHeap->max = elem;
  newHeap->elems = 0;
  newHeap->lista = l;
  return newHeap;
}

void hsort_insert(HSort *hp, int dato)
{
  int pos = (*hp)->elems + 1;
  if( pos < (*hp)->max)
  {
    (*hp)->elems++;
    (*hp)->lista[(*hp)->elems] = dato;
    while((*hp)->lista[pos] < (*hp)->lista[pos / 2] && pos > 1)
    {
      swap(&((*hp)->lista[pos]), &((*hp)->lista[pos / 2]));
      pos /= 2;
    }
  }
}

void hsort_eliminar_minimo(HSort *hp)
{
  int indCambio;
  if( (*hp)->elems < 1)
    return;

  if( (*hp)->elems == 1)
  {
    (*hp)->elems--;
    return;
  }

  else if ((*hp)->elems > 1)
  {
    indCambio = 1;
    swap(&((*hp)->lista[1]), &((*hp)->lista[(*hp)->elems]));
    (*hp)->elems--;
    while(1)
    {
      if(indCambio * 2 > (*hp)->elems)
        return;

      if(indCambio * 2 == (*hp)->elems)
      {
        if((*hp)->lista[indCambio] > (*hp)->lista[indCambio * 2])
          swap(&((*hp)->lista[indCambio]), &((*hp)->lista[indCambio * 2]));
        return;
      }

      if( indCambio * 2 + 1 <= (*hp)->elems)
      {
        if((*hp)->lista[indCambio * 2] < (*hp)->lista[indCambio * 2 + 1])
        {
          swap(&((*hp)->lista[indCambio]), &((*hp)->lista[indCambio * 2]));
          indCambio *= 2;
        }
        else
        {
          swap(&((*hp)->lista[indCambio]), &((*hp)->lista[indCambio * 2 + 1]));
          indCambio = (indCambio * 2) + 1;
        }
      }
    }
  }
}

void hsort_imprimir(const HSort *hp)
{
  int i;
  for(i = 1; i <= (*hp)->elems; i++)
    printf("%d, ", (*hp)->lista[i] );
}

int hsort_minimo(const HSort *hp)
{
  if((*hp)->elems > 0)
    return (*hp)->lista[1];
  else
    return -1;
}
