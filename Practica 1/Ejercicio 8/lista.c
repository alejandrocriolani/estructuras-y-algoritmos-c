#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

list_extend(list *lista)
{
  list_cant_max((*lista)) *= 2;
  (*lista)->lst = realloc((*lista)->lst, sizeof(int) * list_cant_max((*lista)));
}

list list_crear()
{
  list nuevaLista = malloc(sizeof(list));
  list_cant_max(nuevaLista) = LONGINICIAL;
  int *arr = malloc(sizeof(int) * list_cant_max(nuevaLista));
  nuevaLista->lst = arr;
  list_cant(nuevaLista) = 0;
  return nuevaLista;
}

void list_append(list *lista, int dato)
{
  if(list_cant((*lista)) < list_cant_max((*lista)))
  {
    (*lista)->lst[(*lista)->cant] = dato;
    list_cant((*lista))++;
  }
  else
  {
    list_extend(lista);
    (*lista)->lst[(*lista)->cant] = dato;
    list_cant((*lista))++;
  }
}

void list_print(list lista)
{
  auto i = 0;
  for( ; i < lista->cant; i++)
    printf("%d, ", lista->lst[i] );
}
