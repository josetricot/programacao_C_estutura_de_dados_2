#include <stdio.h> 
#include <stdlib.h> 
#define TAMANHO 20
main() 
{ 
 int x, i=0, vetor[20] = {3,5,6,7,8,9,10,12,14,16,19,20,21,22,33,35,37,39,44,50};
 
printf("Qual Numero deseja localizar?:"); 
scanf("%d",&x);
	while (i < TAMANHO && vetor[i]!=x && vetor[i]<= x ) 
	{
		i++;
	}
	if (vetor[i]==x)
		printf("Valor Localizado"); 
	else
		printf("Valor NAO Localizado"); 
}
