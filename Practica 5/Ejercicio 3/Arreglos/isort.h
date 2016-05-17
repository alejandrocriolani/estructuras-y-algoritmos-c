#ifndef ISORT_H
#define ISORT_H

typedef void (*swapFunc) (void *, void *);
typedef int (*cmpFunc) (void *, void *);

void isort_a(void *, int, cmpFunc, swapFunc);


#endif
