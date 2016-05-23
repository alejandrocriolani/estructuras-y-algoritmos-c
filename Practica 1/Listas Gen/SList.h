#ifndef SLIST_H
#define SLIST_H

typedef void (*VisitorFunc) (void *data, void *extra_data);
typedef void (*RemoveFunc) (void *data);
typedef int (*CompareFunc) (void *data1, void *data2);

typedef struct _node
{
  void *data;
  struct _node *next;
} node;

typedef node *SList;

typedef enum _bool {FALSE, TRUE} bool;

#define slist_next(l) (l)->next
#define slist_data(l) (l)->data
#define slist_empty() NULL

SList         slist_create();
SList         slist_append(SList, void *, size_t);
SList         slist_preppend(SList, void *, size_t);

void          slist_foreach(SList, VisitorFunc);

bool          slist_has_next(SList);
unsigned int  slist_length(SList);
SList         slist_concat(SList, SList, size_t);
SList         slist_insert(SList, void *, size_t, unsigned int);
SList         slist_remove(SList, unsigned int, RemoveFunc);
bool          slist_contain(SList, void *, CompareFunc);
unsigned int  slist_index(SList, void *, CompareFunc);
SList         slist_interect_custom(SList, SList, CompareFunc, size_t size);

#endif
