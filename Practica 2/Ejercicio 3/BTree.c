#include <stdlib.h>
#include "BTree.h"

BTree btree_create(int data, BTree left, BTree right)
{
	BTree newNode = malloc(sizeof(BTNode));
	btree_data(newNode) = data;
	btree_left(newNode) = left;
	btree_right(newNode) = right;
	return newNode;
}

void  btree_destroy(BTree node)
{
	if (node != NULL) {
		btree_destroy(btree_left(node));
		btree_destroy(btree_right(node));
		free(node);
	}
}

void  btree_foreach(BTree node, VisitorFuncInt visit, void *extra_data)
{
	if(node == btree_empty())
		return;

	if ((*(BTreeTraversalOrder *)  extra_data) == BTREE_TRAVERSAL_ORDER_PRE)
	{
		visit(btree_data(node), NULL);
		btree_foreach(btree_left(node), visit, extra_data);
		btree_foreach(btree_right(node), visit, extra_data);
	}

	if ((*(BTreeTraversalOrder *) extra_data) == BTREE_TRAVERSAL_ORDER_IN)
	{
		btree_foreach(btree_left(node), visit, extra_data);
		visit(btree_data(node), NULL);
		btree_foreach(btree_right(node), visit, extra_data);
	}

	if((*(BTreeTraversalOrder *) extra_data) == BTREE_TRAVERSAL_ORDER_POST)
	{
		btree_foreach(btree_left(node), visit, extra_data);
		btree_foreach(btree_right(node), visit, extra_data);
		visit(btree_data(node), NULL);
	}
}

int btree_suma_total(BTree node)
{
	static int sumTotal = 0;
	if(node != btree_empty())
	{
		sumTotal += btree_data(node);
		btree_suma_total(btree_left(node));
		btree_suma_total(btree_right(node));
	}
	return sumTotal;
}

int btree_cant_total_nodos(BTree node)
{
	static int nodosTotal = 0;
	if(node != btree_empty())
	{
		nodosTotal++;
		btree_cant_total_nodos(btree_left(node));
		btree_cant_total_nodos(btree_right(node));
	}
	return nodosTotal;
}

int btree_altura(BTree node)
{
	int altura = 0;
	if( node != btree_empty())
	{
		altura++;
		if(btree_altura(btree_left(node)) > btree_altura(btree_right(node)))
			altura += btree_altura(btree_left(node));
		else
			altura += btree_altura(btree_right(node));
	}
	else
		altura = 0;
	return altura;
}

void btree_mi_foreach(BTree list, VisitorFuncInt visit, BTreeTraversalOrder orden)
{
	if(list == btree_empty())
		return;
}
