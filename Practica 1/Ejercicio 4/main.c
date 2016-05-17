#include <stdio.h>
#include "dlist.h"

int main(void)
{
  dlist l1 = dlist_create();
  l1 = dlist_preppend(l1, 1);
  l1 = dlist_preppend(l1, 2);
  l1 = dlist_preppend(l1, 3);
  l1 = dlist_preppend(l1, 4);
  l1 = dlist_preppend(l1, 5);

  printf("l1 (->) = ");
  dlist_foreach(l1, DLIST_TRAVERSAL_ORDER_FORDWARD);
  printf("\n");

  printf("l1 (<-) = ");
  dlist_foreach(l1, DLIST_TRAVERSAL_ORDER_REWARD);
  printf("\n");

  dlist l2 = dlist_create();
  l2 = dlist_append(l2, -1);
  l2 = dlist_append(l2, -2);
  l2 = dlist_append(l2, -3);
  l2 = dlist_append(l2, -4);
  l2 = dlist_append(l2, -5);

  printf("l2 (->) = ");
  dlist_foreach(l2, DLIST_TRAVERSAL_ORDER_FORDWARD);
  printf("\n");

  printf("l2 (<-) = ");
  dlist_foreach(l2, DLIST_TRAVERSAL_ORDER_REWARD);
  printf("\n");

  return 0;
}
