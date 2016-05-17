#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "hashtable.h"

int equals(void *key1, void *key2) {
  int *p = key1;
  int *q = key2;

  return *p == *q;
}

unsigned int hashnat(void *key, unsigned int buckets) {
  int *p = key;
  return *p % buckets;
}

unsigned int hashstring(void *key, unsigned int buckets)
{
  char *c = key;
  int key_n = 0;
  unsigned const int base = 128;
  unsigned int i;

  for(i = 0; c[i] != '\0'; i++)
  {
    key_n += c[i] * pow(base, i);
  }

  return hashnat(&key_n, buckets);
}

int main(void) {
  int x = 42, y = 42, z = 3;
  Hashtable *ht = hashtable_new(10, hashnat, equals);

  hashtable_insert(ht, &x, &z);

  printf("z : %d\n", *((int *)hashtable_lookup(ht, &x)));
  printf("z : %d\n", *((int *)hashtable_lookup(ht, &y)));

  hashtable_delete(ht, &x);

  hashtable_destroy(ht);

  return 0;
}
