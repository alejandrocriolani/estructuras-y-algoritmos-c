#include <stdlib.h>
#include "SList.h"

SList slist_create()
{
  return NULL;
}

SList slist_append(SList list, void *data, size_t size)
{
  SList new_node = malloc(sizeof(SList));
  new_node->next = slist_empty();
  SList aux = list;
  void *new_data = malloc(sizeof(size));
  new_data = data;
  new_node->data = new_data;

  if(list == slist_empty())
  {
    list = new_node;
    return list;
  }

  while(aux->next != slist_empty())
    aux = aux->next;

  aux->next = new_node;
  return list;
}

SList slist_preppend(SList list, void *data, size_t size)
{
  SList new_node = malloc(sizeof(SList));
  void *new_data = malloc(sizeof(size));
  new_data = data;
  new_node->data = new_data;
  new_node->next = list;
  return new_node;
}

void slist_foreach(SList list, VisitorFunc func)
{
  SList aux_list = list;
  while (aux_list != slist_empty())
  {
    func(aux_list->data,NULL);
    aux_list = aux_list->next;
  }
}
