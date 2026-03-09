#include "stdio.h"
#include "stdlib.h"



main (void)
{
int *p;
    //************************************************
	float a = 1000; /* Determina o valor de a */
    //************************************************
    
    
p= (int *)malloc (a * sizeof(float));
    if (!p)
	{
	printf ("** Erro: Memoria Insuficiente **");
	}
else
	{

	for (int count=0;count<a;count++)
		{
		*p=count;
		p++;
		}

	printf ("Memória alocada som sucesso!!!");
	system("pause");
	}
return 0;
}

