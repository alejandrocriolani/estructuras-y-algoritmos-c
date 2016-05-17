#include <stdio.h>
#include <stdlib.h>
#include "slist.h"

slist slist_preppend(slist lista, int dato)
{
  slist nodoNuevo = malloc(sizeof(slist));
  slist_data(nodoNuevo) = dato;
  slist_next(nodoNuevo) = lista;
  return nodoNuevo;
}

slist slist_append(slist lista, int dato)
{
  slist nodoNuevo = malloc(sizeof(slist));
  slist aux = lista;

  slist_data(nodoNuevo) = dato;
  slist_next(nodoNuevo) = slist_empty();

  if(lista == slist_empty())
  {
    return nodoNuevo;
  }
  else
  {
    for( ; slist_next(lista) != slist_empty(); lista = slist_next(lista))
      ;
    slist_next(lista) = nodoNuevo;
  }

  return aux;
}

void slist_print(slist lista)
{
  for( ; lista != NULL ; lista = slist_next(lista))
    printf("%d, ", slist_data(lista) );
}

bool slist_has_next(slist nodo)
{
  if(slist_next(nodo) != slist_empty())
    return TRUE;
  return FALSE;
}

slist slist_create()
{
  return NULL;
}

int slist_length(slist lista)
{
  int longitud = 0;
  for( ; lista != slist_empty(); lista = slist_next(lista) )
    longitud++;
  return longitud;
}

slist slist_concat(slist l1, slist l2)
{
  slist listaNueva = slist_create();

  for( ; l1 != slist_empty(); l1 = slist_next(l1))
    listaNueva = slist_append(listaNueva, slist_data(l1));
  for( ; l2 != slist_empty(); l2 = slist_next(l2))
    listaNueva = slist_append(listaNueva, slist_data(l2));

  return listaNueva;
}

slist slist_insert(slist lista, int ind, int dato)
{
  int lon = slist_length(lista);
  int i;
  slist nodoAux = slist_create();
  slist nodoNuevo = slist_create();
  slist listaAux = lista;

  if( ind == 0)
  {
    lista = slist_preppend(lista, dato);
    return lista;
  }

  if( ind == lon)
  {
    lista = slist_append(lista, dato);
    return lista;
  }

  if( ind > 0 && ind < lon)
  {
    nodoNuevo = slist_append(nodoNuevo, dato);
    for(i = 0; i < ind - 1; lista = slist_next(lista), i++)
      ;
    nodoAux = slist_next(lista);
    slist_next(lista) = nodoNuevo;
    slist_next(nodoNuevo) = nodoAux;
  }
  return listaAux;
}

void slist_destroy(slist lista)
{
  slist nodoAux;
  for( ; lista != slist_empty(); )
  {
    nodoAux = lista;
    lista = slist_next(lista);
    free(nodoAux);
  }
}

slist slist_remove(slist lista, int ind)
{
  int lon = slist_length(lista);
  slist listaAux = lista;
  slist nodoAux;
  int i;

  if(ind < 0 || ind >= lon)
    return lista;

  if(ind == 0)
  {
    nodoAux = lista;
    lista = slist_next(lista);
    free(nodoAux);
    return lista;
  }
  else
  {
    for( i = 0; i < ind - 1; lista = slist_next(lista), i++)
      ;
    nodoAux = slist_next(lista);
    slist_next(lista) = slist_next(nodoAux);
    free(nodoAux);
  }

  return listaAux;
}

bool slist_contain(slist lista, const int elem)
{
  for( ; lista != slist_empty(); lista = slist_next(lista))
  {
    if(elem == slist_data(lista))
      return TRUE;
  }
  return FALSE;
}

int slist_index(slist lista, const int elem)
{
  int index = 0;
  for( ; lista != slist_empty(); lista = slist_next(lista), index++)
  {
    if(slist_data(lista) == elem)
      return index;
  }
  return -1;
}

int slist_elem(slist lista, const int index)
{
  slist aux = lista;
  int i, dato;
  for(i = 0; i <= index; lista = slist_next(lista), i++ )
  {
    if( i == index)
    {
      dato = slist_data(lista);
      lista = aux;
      return dato;
    }
  }

}

slist slist_intersec(slist l1, slist l2)
{
  slist listaNueva = slist_create();
  slist l2Aux = l2;
  for( ; l1 != slist_empty(); l1 = slist_next(l1))
  {
    for( ; l2 != slist_empty(); l2 = slist_next(l2))
    {
      if( slist_data(l1) == slist_data(l2))
      {
        if(slist_contain(listaNueva, slist_data(l1)) == FALSE)
          listaNueva = slist_append(listaNueva, slist_data(l1));
      }
    }
    l2 = l2Aux;
  }
  return listaNueva;
}

slist slist_intersec_custom(slist l1, slist l2, bool (*f)(int, int))
{
  slist listaNueva = slist_empty();
  slist l2Aux = l2;

  for( ; l1 != slist_empty(); l1 = slist_next(l1))
  {
    for( ; l2 != slist_empty(); l2 = slist_next(l2))
    {
      if ((slist_data(l1) == slist_data(l2)) && f(slist_data(l1), slist_data(l2)))
      {
        if(slist_contain(listaNueva, slist_data(l1)) == FALSE)
          listaNueva = slist_append(listaNueva, slist_data(l1));
      }
    }
    l2 = l2Aux;
  }

  return listaNueva;
}

slist slist_ssort(slist lista)
{
  slist listaNueva = slist_create();
  slist aux = slist_create();

  int i,j, lonLista;

  lonLista = slist_length(lista);

  for(i = 0; i < lonLista; i++)
    aux = slist_append(aux, slist_elem(lista, i));

  slist aux2 = aux;
  int posMenor = 0;
  int menor = slist_data(aux);

  for(j = 0; j < lonLista; j++)
  {
    posMenor = 0;
    menor = slist_data(aux);
    for(i = 0 ; aux != slist_empty(); aux = slist_next(aux), i++)
    {
      if(slist_data(aux) < menor)
      {
        posMenor = i;
        menor = slist_data(aux);
      }
    }
    aux = aux2;

    listaNueva = slist_append(listaNueva, menor);
    aux = slist_remove(aux, posMenor);
    aux2 = aux;
  }

  return listaNueva;
}
