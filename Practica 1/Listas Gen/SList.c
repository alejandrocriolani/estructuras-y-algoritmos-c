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

SList slist_insert(SList list, void *data, size_t size, unsigned int pos)
{
  if( pos == 0)
    list = slist_preppend(list, data, size);
  if( pos > 0 && pos <= slist_length(list))
  {
    int i;
    SList aux_list = list;
    SList new_node = slist_create();
    new_node = slist_preppend(new_node, data, size);

    for(i = 0; i <= pos; i++)
    {
        if( i == pos - 1)
        {
          slist_next(new_node) = slist_next(aux_list);
          slist_next(aux_list) = new_node;
        }
        aux_list = slist_next(aux_list);
    }
  }
  return list;
}

SList slist_remove(SList list, unsigned int pos, RemoveFunc remove)
{
  SList list_aux = list;

  if(pos == 0)
  {
    list = slist_next(list);
    //remove(&slist_data(list_aux));
    //free(list_aux->data);
    free(list_aux);
  }
  else
  {
    int i;
    for( i = 0; i < slist_length(list); i++)
    {
      if(i == pos - 1)
      {
        SList node_aux = slist_next(list_aux);
        slist_next(list_aux) = slist_next(slist_next(list_aux));
        //remove(&slist_data(node_aux));
        free(node_aux);
      }
      list_aux = slist_next(list_aux);
    }
  }
  return list;
}

bool slist_contain(SList list, void *data, CompareFunc func)
{
  SList aux_list = list;

  while(aux_list != slist_empty())
  {
    if(func(slist_data(aux_list), data) == TRUE)
      return TRUE;
    aux_list = slist_next(aux_list);
  }
  return FALSE;
}

unsigned int slist_index(SList list, void *data, CompareFunc func)
{
  SList aux_list = list;
  unsigned int index = 0;

  while(aux_list != slist_empty())
  {
      if(func(slist_data(aux_list), data) == TRUE)
        return index;
      ++index;
      aux_list = slist_next(aux_list);
  }
  return index;
}

SList slist_interect_custom(SList list1, SList list2, CompareFunc func, size_t size)
{
  SList aux_list1 = list1;
  SList aux_list2 = list2;
  SList new_list = slist_create();

  while (aux_list1 != slist_empty())
  {
    while(aux_list2 != slist_empty())
    {
      if(func(slist_data(aux_list1), slist_data(aux_list2)) && !slist_contain(new_list, slist_data(aux_list1), func))
        new_list = slist_append(new_list, slist_data(aux_list1), size);
      aux_list2 = slist_next(aux_list2);
    }
    aux_list2 = list2;
    aux_list1 = slist_next(aux_list1);
  }
  return new_list;
}
