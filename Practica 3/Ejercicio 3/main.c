#include <stdio.h>

#include "slstack.h"

int main(void)
{
  SLStack p1 = slstack_create();
  p1 = slstack_push(p1, 1);
  p1 = slstack_push(p1, 2);
  p1 = slstack_push(p1, 3);
  p1 = slstack_push(p1, 4);
  p1 = slstack_push(p1, 5);
  p1 = slstack_push(p1, 6);
  p1 = slstack_push(p1, 7);

  p1 = slstack_pop(p1);
  p1 = slstack_pop(p1);
  p1 = slstack_pop(p1);
  slstack_print(p1);
  printf("\n");
  return 0;
}
