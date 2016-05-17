#include <stdio.h>
#include <stdlib.h>

#include "astack.h"

AStack astack_create(int cant)
{
  int *l = malloc(sizeof(int) * (cant + 1));
  AStack stack = malloc(sizeof(AStack));
  stack->list = l;
  stack->cantMaxElem = cant;
  stack->cantElementos = 0;
  return stack;
}

void astack_realloc(AStack *stack)
{
  (*stack)->cantMaxElem *= 2;
  (*stack)->list = realloc((*stack)->list, sizeof(int) * ((*stack)->cantMaxElem) + 1);
}

int astack_top(AStack stack)
{
  return stack->list[stack->cantElementos - 1];
}

void astack_push(AStack *stack, int dato)
{
  if((*stack)->cantElementos == (*stack)->cantMaxElem)
  {
    astack_realloc(stack);
  }
  (*stack)->list[(*stack)->cantElementos++] = dato;
}

void astack_pop(AStack *stack)
{
  (*stack)->cantElementos--;
}

AStack astack_reverse(AStack stack)
{
  AStack stackNuevo = astack_create(stack->cantElementos);
  int i = 0;
  int j = stack->cantElementos - 1;
  for( ; j >= 0; i++, j-- )
    stackNuevo->list[i] = stack->list[j];
  stackNuevo->cantElementos = i;
  return stackNuevo;
}

void astack_print(AStack stack)
{
  int i = 0;
  for( ; i < stack->cantElementos; i++)
    printf("%d, ", stack->list[i] );
}

void astack_destroy(AStack *stack)
{
  free((*stack)->list);
  free((*stack));
  stack = NULL;
}
