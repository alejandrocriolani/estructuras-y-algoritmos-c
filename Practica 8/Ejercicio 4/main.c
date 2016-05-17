#include <stdio.h>
#include <stdlib.h>

int str_len(char *s)
{
  int i = 0;
  for( ; s[i] != '\0'; i++)
    ;
  return i;
}

int minimo(int x, int y)
{
  if (x < y)
    return x;
  else
    return y;
}

int distancia_subcadena(char *s1, char *s2) //Levenshtein
{
  int t1, t2, i, j, *m, costo, res, ancho;

  t1 = str_len(s1);
  t2 = str_len(s2);

  if( t1 == 0)
    return t2;
  if( t2 == 0)
    return t1;

  ancho = t1 + 1;

  m = malloc(sizeof(int) * (t1 + 1) * (t2 + 1)); // m[i,j] = m[j +ancho + i]

  //Rellena primera fila y primera columna
  for(i = 0; i <= t1; i++) //fila
    m[i] = i;
  for(j = 0; j <= t2; j++) //columna
    m[j*ancho] = j;

  //Recorremos la matriz
  for(i = 1; i<= t1; i++)
  {
    for(j = 1; j <= t2; j++)
    {
      if(s1[i-1] == s2[j-1])
        costo = 0;
      else
        costo = 1;
      m[j * ancho + i] = minimo(minimo(m[j*ancho + i - 1]+1, //Eliminacion
          m[(j-1) * ancho + i] + 1),                         //Insercion
          m[(j - 1)* ancho + i - 1] + costo);                //Sustitucion
    }
  }

  for(i = 0; i <= t1; i++)
  {
    for(j = 0; j <= t2; j++)
      printf("%d, ", m[j * ancho + i]);
    printf("\n");
  }

  //Devolvemos esquina final de la matriz
  res = m[t2*ancho + t1];
  free(m);
  return res;
}

int main(void)
{
  char *str1 = "casa";
  char *str2 = "caso";
  printf("%d\n", distancia_subcadena(str1, str2) );

  return 0;
}

/*
Sea esta tabla

|a|b|
|c|d|

Estoy en la posicion d
Se calcula el minimo costo de operaciones entre c, b, y a + 1 (si las letras son distintas) o 0 (si las letras son iguales)
*/
