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

bool slist_has_next(SList list)
{
  if(list == slist_empty())
    return FALSE;

  if(slist_next(list) != NULL)
    return TRUE;
  return FALSE;
}

unsigned int slist_length(SList list)
{
  SList aux_list = list;
  unsigned int length = 0;

  while (aux_list != slist_empty())
  {
    ++length;
    aux_list = slist_next(aux_list);
  }
  return length;
}

SList slist_concat(SList list1, SList list2, size_t size)
{
  SList new_list = slist_create();
  SList aux_list1 = list1;
  SList aux_list2 = list2;

  while(aux_list1 != slist_empty())
  {
    new_list = slist_append(new_list, slist_data(aux_list1), size);
    aux_list1 = slist_next(aux_list1);
  }

  while(aux_list2 != slist_empty())
  {
    new_list = slist_append(new_list, slist_data(aux_list2), size);
    aux_list2 = slist_next(aux_list2);
  }

  return new_list;
}
