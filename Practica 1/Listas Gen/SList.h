#ifndef SLIST_H
#define SLIST_H

typedef void (*VisitorFunc) (void *data, void *extra_data);

typedef struct _node
{
  void *data;
  struct _node *next;
} node;

typedef node *SList;

typedef enum _bool {TRUE, FALSE} bool;

#define slist_next(l) (l)->next
#define slist_data(l) (l)->data
#define slist_empty() NULL

SList slist_create();
SList slist_append(SList, void *, size_t);
SList slist_preppend(SList, void *, size_t);
void slist_foreach(SList, VisitorFunc);

#endif
