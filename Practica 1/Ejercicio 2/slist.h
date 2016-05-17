#ifndef SLIST_H
#define SLIST_H

typedef struct nodo
{
  int data;
  struct nodo *next;
} _slist;

typedef enum _bool {FALSE, TRUE} bool;

typedef _slist *slist;

#define slist_next(l) (l)->next
#define slist_data(l) (l)->data
#define slist_empty() NULL

slist slist_create();
slist slist_append(slist, int);
slist slist_preppend(slist, int);
void slist_print(slist);
bool slist_has_next(slist);
int slist_length(slist);
slist slist_concat(slist, slist);
slist slist_insert(slist, int, int);
slist slist_remove(slist, int);
bool slist_contain(slist, const int);
int slist_index(slist, const int);
slist slist_intersec(slist, slist);
slist slist_intersec_custom(slist, slist, bool (*f)(int, int));
slist slist_sort(slist);

void slist_destroy(slist);


#endif
