#include <stdio.h>
#include "slist.h"

bool esPar(int d1, int d2)
{
  if((d1 % 2) == 0)
    return TRUE;
  return FALSE;
}

int main()
{
  slist l1 = slist_create();
  slist l2 = slist_create();
  slist l3 = slist_create();
  slist l4 = slist_create();
  slist l5 = slist_create();

  l1 = slist_preppend(l1, 1);
  l1 = slist_preppend(l1, 2);
  l1 = slist_preppend(l1, 3);
  l1 = slist_preppend(l1, 4);
  l1 = slist_preppend(l1, 5);

  l2 = slist_append(l2, 1);
  l2 = slist_append(l2, 2);
  l2 = slist_append(l2, 3);
  l2 = slist_append(l2, 4);
  l2 = slist_append(l2, 5);

  slist_print(l1);
  printf("\n");

  slist_print(l2);
  printf("\n");

  bool tieneSiguiente;
  tieneSiguiente = slist_has_next(l2);
  printf("l2[0] tiene proximo elemento? %d\n", tieneSiguiente );

  tieneSiguiente = slist_has_next(slist_next(slist_next(slist_next(slist_next(l2)))));
  printf("l2[4] tiene proximo elemento? %d\n", tieneSiguiente);

  printf("Cantidad de elementos de l2: %d\n", slist_length(l2));

  l3 = slist_concat(l1, l2);
  printf("l1 ++ l2 = ");
  slist_print(l3);
  printf("\n");

  l3 = slist_insert(l3, 10, 100);
  l3 = slist_insert(l3, 0, -100);
  l3 = slist_insert(l3, 1, -1);
  l3 = slist_insert(l3, 2, -2);
  l3 = slist_insert(l3, slist_length(l3) - 1, -3);

  printf("l3 = ");
  slist_print(l3);
  printf("\n");

  l3 = slist_remove(l3, 0);
  printf("l3 = ");
  slist_print(l3);
  printf("\n");

  l3 = slist_remove(l3, slist_length(l3) - 1);
  printf("l3 = ");
  slist_print(l3);
  printf("\n");

  l3 = slist_remove(l3, 5);
  printf("l3 = ");
  slist_print(l3);
  printf("\n");

  printf("Esta \"50\"? %d\n", slist_contain(l3, 50) );
  printf("Esta \"3\"? %d\n", slist_contain(l3, 3) );
  printf("Posicion de \"3\": %d\n", slist_index(l3, 3) );

  printf("l3 = ");
  slist_print(l3);
  printf("\n");

  l4 = slist_concat(l1, l1);
  printf("l4 = ");
  slist_print(l4);
  printf("\n");

  slist_destroy(l4);
  l5 = slist_intersec(l1, l2);
  printf("l5 = ");
  slist_print(l5);
  printf("\n");

  slist l6 = slist_create();
  l6 = slist_intersec_custom(l1, l2, &esPar);
  printf("l6 = ");
  slist_print(l6);
  printf("\n");

  return 0;

}
