#ifndef ASTACK_H
#define ASTACK_H

typedef struct _AStack_
{
  int *list;
  int cantElementos;
  int cantMaxElem;
} _AStack;

typedef _AStack *AStack;

AStack astack_create(int);
void astack_realloc(AStack *);
int astack_top(AStack);
void astack_push(AStack *, int);
void astack_pop(AStack *);
AStack astack_reverse(AStack);
void astack_print(AStack);
void astack_destroy(AStack *);

#endif
