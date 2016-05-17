#ifndef DLIST_H
#define DLIST_H

#include <stdlib.h>

typedef enum { DLIST_TRAVERSAL_ORDER_FORDWARD, DLIST_TRAVERSAL_ORDER_REWARD} DListTraversalOrder;

typedef struct _nodo
{
  int data;
  struct _nodo *next;
  struct _nodo *previous;
} nodo;

typedef nodo *dlist;

#define dlist_next(l)     (l)->next
#define dlist_previous(l) (l)->previous
#define dlist_data(l)     (l)->data
#define dlist_empty(l)    NULL

dlist dlist_create();
dlist dlist_preppend(dlist, int);
dlist dlist_append(dlist, int);
void dlist_foreach(dlist, DListTraversalOrder);

#endif
