#include <stdio.h> 
#include <stdlib.h> 
#define TAMANHO 20
main() 
{ 
 	int x, i=0, vetor[TAMANHO] = {21,12,3,14,5,20,50,10,35,9,19,33,44,16,37,8,39,22,6,7};
	
	printf("Qual Número deseja localizar?:"); 
	scanf("%d",&x);
	
	while (i < TAMANHO && vetor[i]!=x) 
	{
	i++;
	}
	if (vetor[i]==x)
		printf("Valor %d Localizado!", x ); 
	else
		printf("Valor %d NAO Localizado!", x); 
}
