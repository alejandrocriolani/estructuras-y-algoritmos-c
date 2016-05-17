#ifndef SLSTACK_H
#define SLSTACK_H

typedef struct _SLStackNode
{
  int data;
  struct _SLStackNode *next;
} SLStackNode;

typedef SLStackNode *SLStack;

#define slstack_data(l) (l)->data
#define slstack_next(l) (l)->next
#define slstack_empty() NULL

SLStack slstack_create(void);
SLStack slstack_push(SLStack , int);
SLStack slstack_pop(SLStack);
int slstack_top(SLStack );
void slstack_print(SLStack);
void slstack_destroy(SLStack);

#endif
