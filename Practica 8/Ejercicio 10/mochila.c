#include <stdio.h>
#include <stdlib.h>

typedef struct _elementos
{
	int peso;
	int costo;
	int numero;
}elementos;

void generar_tabla(elementos elem[], int cantElem, int pesoMax)
{
	//Declaración de variables
	int tabla[cantElem + 1][pesoMax + 1];
	//tabla = malloc(sizeof(int) * (cantElem + 1) * (pesoMax + 1));
	int i, j, k;
	int beneficio, pesoAux;

	//Inicializo la tabla
	for(k = 0; k <= pesoMax; k++)
		tabla[0][k] = 0;
	for(k = 0; k  <= cantElem; k++)
		tabla[k][0] = 0;
	k = 0;

	for(i = 1; i <= cantElem; i++)
	{
		for(j = 1; j <= pesoMax; j++)
		{
			if(elem[k].peso <= j)
			{
				beneficio = elem[k].costo;
				pesoAux = j - elem[k].peso;
				if(beneficio + tabla[i-1][pesoAux] > tabla[i-1][j])
					tabla[i][j] = beneficio + tabla[i-1][pesoAux];
				else
					tabla[i][j] = tabla[i-1][j];
			}
			else
				tabla[i][j] = tabla[i -1][j];
		}
		k++;
	}

	//Imprimir tabla
	 for(i = 0; i <= cantElem; i++)
	{
		for(j = 0; j <= pesoMax; j++)
			printf("%d ", tabla[i][j]);
		printf("\n");
	}

	//Calcular max beneficio
	i = cantElem, j = pesoMax, beneficio = 0;
	while( i > 0 && j > 0)
	{
		if(tabla[i][j] != tabla[i-1][j])
		{
			beneficio+=elem[i-1].costo;
			printf("Item %d, ", elem[i-1].numero);
			j -= elem[i-1].peso;
			i--;
		}
		else
			i--;
	}
	printf("\nBeneficio total = %d\n", beneficio);
}

int main(void)
{
	const int cantElem = 5;
	const int maxWeight = 10;
	elementos *elem = malloc(sizeof(cantElem + 1));

	elem[0].peso = 2;
	elem[0].costo = 3;
	elem[0].numero = 1;

	elem[1].peso = 3;
	elem[1].costo = 4;
	elem[1].numero = 2;

	elem[2].peso = 4;
	elem[2].costo = 5;
	elem[2].numero = 3;

	elem[3].peso = 5;
	elem[3].costo = 6;
	elem[3].numero = 4;

	elem[4].peso = 8;
	elem[4].costo = 10;
	elem[4].numero = 5;

	generar_tabla(elem, 4, 5);
	return 0;
}
