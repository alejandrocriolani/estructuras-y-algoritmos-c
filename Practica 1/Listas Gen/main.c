#include <stdio.h>
#include <stdlib.h>
#include "SList.h"

void print_int(void * data, void * extra_data)
{
  int x = *(int *)data;
  printf("%d, ", x);
}

void print_char(void *data, void *extra_data)
{
  char c = *(char *)data;
  printf("%c, ", c );
}

void remove_int(void *data)
{
  int *x = (int *)data;
  free(x);
}

int main(void)
{
  SList lista = slist_create();
  SList lista_char = slist_create();

  int d1 = 1;
  int d2 = 2;
  int d3 = 3;
  int d4 = 4;
  int d5 = 5;
  int d6 = 6;

  char c1 = 'a';
  char c2 = 'b';
  char c3 = 'c';

  lista = slist_preppend( lista, &d1, sizeof(int));
  lista = slist_preppend( lista, &d2, sizeof(int));
  lista = slist_preppend( lista, &d3, sizeof(int));
  lista = slist_append( lista, &d1, sizeof(int));
  lista = slist_append( lista, &d2, sizeof(int));
  lista = slist_append( lista, &d3, sizeof(int));

  slist_foreach(lista, print_int);
  printf("\n");

  lista_char = slist_append(lista_char, &c1, sizeof(char));
  lista_char = slist_append(lista_char, &c2, sizeof(char));
  lista_char = slist_append(lista_char, &c1, sizeof(char));
  lista_char = slist_append(lista_char, &c3, sizeof(char));
  lista_char = slist_append(lista_char, &c1, sizeof(char));
  lista_char = slist_append(lista_char, &c3, sizeof(char));
  lista_char = slist_append(lista_char, &c1, sizeof(char));
  lista_char = slist_append(lista_char, &c2, sizeof(char));
  lista_char = slist_append(lista_char, &c1, sizeof(char));

  slist_foreach(lista_char, print_char);
  printf("\n");

  SList lista_vacia = slist_create();
  bool has_next = slist_has_next(lista_vacia);
  printf("has_next?: %d\n", has_next );

  printf("longitud lista_char %d\n", slist_length(lista_char) );

  SList lista_nueva = slist_concat(lista, lista, sizeof(int));
  slist_foreach(lista_nueva, print_int);
  printf("\n");
  slist_foreach(lista, print_int);
  printf("\n");

  lista_nueva = slist_insert(lista_nueva, &d4, sizeof(int), 0);
  lista_nueva = slist_insert(lista_nueva, &d5, sizeof(int), 4);
  lista_nueva = slist_insert(lista_nueva, &d6, sizeof(int), 14);
  lista_nueva = slist_insert(lista_nueva, &d6, sizeof(int), 20);

  slist_foreach(lista_nueva, print_int);
  printf("\n");

  lista_nueva = slist_remove(lista_nueva, 0, remove_int);
  slist_foreach(lista_nueva, print_int);
  printf("\n");

  lista_nueva = slist_remove(lista_nueva, 5, remove_int);
  slist_foreach(lista_nueva, print_int);
  printf("\n");

  lista_nueva = slist_remove(lista_nueva, 20, remove_int);
  slist_foreach(lista_nueva, print_int);
  printf("\n");

  return 0;
}
