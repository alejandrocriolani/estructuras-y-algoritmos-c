#include <stdio.h>
#include <stdlib.h>
#include "BTree.h"

static void print_int (int data, void *extra_data)
{
	printf("%d ", data);
}

int main(int argc, char *argv[])
{
	BTree lll = btree_create(6, btree_empty(), btree_empty());
	BTree lrr = btree_create(7, btree_empty(), btree_empty());
	BTree lr = btree_create(5, btree_empty(), lrr);
  BTree ll = btree_create(1, lll, btree_empty());
  BTree l = btree_create(2, ll, lr);
  BTree r = btree_create(3, btree_empty(), btree_empty());
  BTree root = btree_create(4, l, r);

  btree_foreach(root, print_int, btree_empty());
  puts("");

	printf("La suma total es: %d\n", btree_suma_total(root) );
	printf("Cantidad total de nodos: %d\n", btree_cant_total_nodos(root) );
	printf("Altura del arbol: %d\n", btree_altura(root) );
  btree_destroy(root);

  return 0;
}
