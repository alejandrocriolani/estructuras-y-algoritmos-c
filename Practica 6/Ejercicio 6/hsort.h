#ifndef HSORT_H
#define HSORT_H

typedef struct _HSort_
{
  int *lista;
  int elems;
  int max;
} _HSort;

typedef _HSort *HSort;

HSort hsort_create(int elems);
void hsort_insert(HSort *, int);
int hsort_minimo(const HSort *);
void hsort_imprimir(const HSort *);
void hsort_eliminar_minimo(HSort *);

#endif
