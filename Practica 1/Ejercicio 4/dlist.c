#include <stdio.h>
#include "dlist.h"

dlist dlist_preppend(dlist lista, int dato)
{
  dlist nodoNuevo = malloc(sizeof(dlist));
  dlist_data(nodoNuevo) = dato;
  dlist_next(nodoNuevo) = lista;
  dlist_previous(nodoNuevo) = dlist_empty();
  if(lista != dlist_empty())
    dlist_previous(lista) = nodoNuevo;
  return nodoNuevo;
}

dlist dlist_create()
{
  return NULL;
}

dlist dlist_append(dlist lista, int dato)
{
  dlist nodoNuevo = malloc(sizeof(dlist));
  dlist_data(nodoNuevo) = dato;
  dlist_next(nodoNuevo) = dlist_empty();

  if(lista == dlist_empty())
  {
    dlist_previous(nodoNuevo) = dlist_empty();
    return nodoNuevo;
  }
  else
  {
    dlist listaAux = lista;
    for( ; dlist_next(lista) != dlist_empty(); lista = dlist_next(lista))
      ;
    dlist_previous(nodoNuevo) = lista;
    dlist_next(lista) = nodoNuevo;
    return listaAux;
  }
}

void dlist_foreach(dlist lista, DListTraversalOrder orden)
{
  if( orden == DLIST_TRAVERSAL_ORDER_FORDWARD)
  {
    for( ; lista != dlist_empty(); lista = dlist_next(lista))
      printf("%d, ", dlist_data(lista));
  }

  if(orden == DLIST_TRAVERSAL_ORDER_REWARD)
  {
    for( ; dlist_next(lista) != dlist_empty(); lista = dlist_next(lista))
      ;
    for( ; lista != dlist_empty(); lista = dlist_previous(lista))
      printf("%d, ", dlist_data(lista));
  }
}
