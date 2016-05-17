#include <stdlib.h>
#include <stdio.h>

int fib_bu(int);
int fib_td(int);
int fib_aux(int);

int fib_bu(int n)
{
  if(n <= 1)
    return n;

  int tabla[n];
  tabla[0] = 0;
  tabla[1] = 1;
  int i;
  for(i = 2; i < n; i++)
  {
    tabla[i] = tabla[i-1] + tabla[i-2];
  }
  return tabla[n-1];
}

int fib_td(int n)
{
  if( n <= 1)
    return n;

  static int tabla_td[100] = {-1};
  return fib_aux(n);
}

int fib_aux(int n)
{
  if(n <= 1)
    return n;

  int tabla_td[n];

  if(tabla_td[n-2] == -1)
    tabla_td[n-2] = fib_aux(n-1);
  if(tabla_td[n-3] == -1)
    tabla_td[n-3] = fib_aux(n-2);

  tabla_td[n-1] = tabla_td[n-2] + tabla_td[n-3];
  return tabla_td[n-1];
}

int main(void)
{
  printf("Fibonacci de 10: ");
  int resultado = fib_bu(10);
  printf("%d\n", resultado );
  resultado = fib_td(10);
  printf("%d\n", resultado );
  return 0;
}
