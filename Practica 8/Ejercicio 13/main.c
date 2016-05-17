#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 10

double mindist = 1e10;

typedef struct _Punto_
{
  int x;
  int y;
} _Punto;

typedef _Punto *punto;

punto c1, c2;


double dist(punto a, punto b)
{
  return sqrt((a->x - b->x)*(a->x - b->x) + (a->y - b->y)*(a->y - b->y));
}

int cmp_punto(const void *p1, const void *p2)
{
  punto *x1 = (punto *) p1;
  punto *x2 = (punto *) p2;
  return ((*x1)->x - (*x2)->x);
}

void buscar(punto *p, int num)
{
  double d;
  int desde, hasta, a, b;

  if(num <= 1)
    return;

  qsort(p, num, sizeof(punto), cmp_punto);

  buscar(p, num / 2);
  buscar(p + num / 2, (num + 1) / 2);

  for(desde = num / 2; desde > 0 && p[num / 2]->x - p[desde]->x < mindist; desde--)
    ;
  for(hasta = num / 2; hasta < num-1 && p[hasta]->x - p[num/2]->x < mindist; hasta++)
    ;

  for( a = desde; a <= hasta; a++)
  {
    for( b = a + 1; b <= hasta; b++)
    {
      if((d = dist(p[a], p[b])) < mindist)
      {
        mindist = d;
        c1->x = p[0]->x;
        c1->y = p[0]->y;
        c2->x = p[1]->x;
        c2->y = p[2]->y;
      }
    }
  }
}

int main(void)
{
  printf("%ld\n", sizeof(punto));
  _Punto *serie;
  serie = malloc(sizeof(punto) * 10);

  serie[0].x = 3;
  serie[0].y = -2;

  serie[1]->x = 7;
  serie[1]->y = 4;

  serie[2]->x = -3;
  serie[2]->y = 1;

  serie[3]->x = 0;
  serie[3]->y = -5;

  serie[4]->x = 7;
  serie[4]->y = 7;

  serie[5]->x = 0;
  serie[5]->y = 1;

  serie[6]->x = -2;
  serie[6]->y = 3;

  serie[7]->x = 5;
  serie[7]->y = -1;

  serie[8]->x = -3;
  serie[8]->y = 0;

  serie[9]->x = 2;
  serie[9]->y = -2;

  buscar(serie, MAX);

  printf("Distancia minima: %.31f\n", mindist );
  printf("Puntos: (%d,%d), (%d,%d)\n", c1->x, c1->y, c2->x, c2->y);

  return 0;
}
