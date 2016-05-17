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

  l1 = slist_append(l1, 6);
  l1 = slist_append(l1, 1);
  l1 = slist_append(l1, 3);
  l1 = slist_append(l1, 7);
  l1 = slist_append(l1, 10);
  l1 = slist_append(l1, 2);
  l1 = slist_append(l1, 9);
  l1 = slist_append(l1, 8);
  l1 = slist_append(l1, 4);
  l1 = slist_append(l1, 5);

  slist_print(l1);
  printf("\n");

  l2 = slist_ssort(l1);

  slist_print(l2);
  printf("\n");

  slist_print(l1);
  printf("\n");

  return 0;

}
