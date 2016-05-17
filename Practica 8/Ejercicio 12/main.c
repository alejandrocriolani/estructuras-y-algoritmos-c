#include <stdio.h>
#include <stdlib.h>

const int INT_MAX = 32766;

void print(int **l, int i, int j)
{
  if(j-i == 1)
  {
    printf("( %d * %d )", i, j );
    return;
  }
  else if(i - j == 0)
  {
    printf("%d", i );
    return;
  }

  int k = l[i][j];
  printf("(");
  print(l, i, k);
  print(l, k+1, j);
  printf(")");
}

void solve (int m[], int len)
{
  int t_len = len - 1;
  int tabla[len][len];
  int **sol;
  sol = malloc(sizeof(int) * len);

  int i, j, k, l, min, current;

  for(i = 0; i < len; i++)
    sol[i] = malloc(sizeof(int) * len);

  for(i = 1; i < len; i++)
  {
    for(j = 1; j < len; j++)
    {
      tabla[i][j] = 0;
      sol[i][j] = 0;
    }
  }


  for(l = 2; l < len; l++)
  {
    for( i = 1; i < len - l + 1 ; i++)
    {
      j = i + l - 1;
      min = INT_MAX;
      for(k = i; k < j; k++)
      {
        current = tabla[i][k] + tabla[k+1][j] + m[i-1]*m[k]*m[j];
        if (current < min)
        {
          min = current;
          sol[i][j] = k;
        }
        tabla[i][j] = min;
      }
    }
    print(sol, 1, len - 1 );
  }

  for(i = 1; i < len; i++)
  {
    for(j = 1; j < len; j++)
      printf("%d \t", tabla[i][j] );
    printf("\n");
  }

}

int main(void)
{
  int len = 6;
  int mtx[] = {4, 10, 3, 12, 20, 7};
  solve(mtx, len);

  return 0;
}
