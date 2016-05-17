#ifndef LISTA_H
#define LISTA_H

typedef struct _lista
{
  int *lst;
  int cant;
  int cantMax;
} lista;

typedef lista *list;

#define list_data(l,i) (l)->lst[i]
#define list_cant(l)   (l)->cant
#define list_cant_max(l) (l)->cantMax

#define LONGINICIAL 4

list list_crear();
void list_append(list *, int);


void list_print(list);

#endif
