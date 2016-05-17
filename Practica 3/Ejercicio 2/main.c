#include <stdio.h>
#include "astack.h"

int main(void)
{
  AStack pila = astack_create(2);

  astack_push(&pila, 1);
  astack_push(&pila, 2);
  astack_push(&pila, 3);
  astack_push(&pila, 4);
  astack_push(&pila, 5);
  astack_push(&pila, 6);
  astack_push(&pila, 7);
  astack_push(&pila, 8);
  astack_push(&pila, 9);
  astack_push(&pila, 10);
  astack_push(&pila, 11);
  astack_push(&pila, 12);
  astack_push(&pila, 13);

  AStack pilaRe = astack_reverse(pila);

  while(pila->cantElementos != 0)
  {
    printf("Top: %d  --> stack: ", astack_top(pila) );
    astack_print(pila);
    printf("\n");
    astack_pop(&pila);
  }

  astack_print(pilaRe);
  printf("\n");
  return 0;
}
