#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  unsigned int tam;
} file;

int cmp_file(const void *x, const void *y)
{
  file *fst = (file *)x;
  file *scn = (file *)y;
  return fst->tam - scn->tam;
}

int maximizar(file * arc, int cant_arc, int tamDisk)
{
  int i;
  qsort(arc, cant_arc, sizeof(file), cmp_file );

  for(i = 0; i < cant_arc; i++)
  {
    if(arc[i].tam <= tamDisk)
    {
      tamDisk -= arc[i].tam;
      printf("Archivo %d, tamanio %d, tamanio del disquete restante: %d\n", i + 1, arc[i].tam, tamDisk );
    }
  }
}


int main(void)
{
  const unsigned int cant_archivos = 12;
  const unsigned int tam_diskete = 100;
  file *archivos = malloc(sizeof(file));

  archivos[0].tam = 2;
  archivos[1].tam = 10;
  archivos[2].tam = 7;
  archivos[3].tam = 15;
  archivos[4].tam = 12;
  archivos[5].tam = 2;
  archivos[6].tam = 25;
  archivos[7].tam = 8;
  archivos[8].tam = 20;
  archivos[9].tam = 33;
  archivos[10].tam = 15;
  archivos[11].tam = 19;

  maximizar(archivos, cant_archivos, tam_diskete);

  return 0;
}
