#include <stdio.h>
#include <stdlib.h>

#include "slstack.h"

SLStack slstack_create(void)
{
  return NULL;
}

SLStack slstack_push(SLStack pila, int dato)
{
  SLStack nodo = malloc(sizeof(SLStack));
  slstack_next(nodo) = pila;
  slstack_data(nodo) = dato;
  return nodo;
}

void slstack_print(SLStack pila)
{
  for( ; pila != slstack_empty(); pila = slstack_next(pila))
    printf("%d, ", slstack_data(pila) );
}

SLStack slstack_pop(SLStack pila)
{
  if(pila != slstack_empty())
  {
    SLStack aux = pila;
    pila = slstack_next(pila);
    free(aux);
  }
  return pila;
}
