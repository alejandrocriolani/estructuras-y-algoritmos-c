#include <stdio.h>

#include "lista.h"

int main(void)
{
  list l1 = list_crear();
  list_append(&l1, 1);
  list_append(&l1, 2);
  list_append(&l1, 3);
  list_append(&l1, 4);
  list_append(&l1, 5);
  list_append(&l1, 6);
  list_append(&l1, 7);
  list_append(&l1, 8);
  list_append(&l1, 9);
  list_append(&l1, 10);
  list_append(&l1, 11);
  list_append(&l1, 12);
  list_append(&l1, 13);
  list_append(&l1, 14);
  list_append(&l1, 15);
  list_append(&l1, 16);
  list_append(&l1, 17);
  list_append(&l1, 18);

  list_print(l1);
  printf("\n");

  return 0;
}
