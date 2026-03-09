#include <stdlib.h>
#include <stdio.h>
main()
{
	int n=0;
	int *pn = &n; 
	n = 2015;
	printf("Valor de n: %d \n", n);
	printf("Endereco de n: %x \n", &n);
	
	
	printf("Conteudo do Ponteiro de n: %d \n", *pn);
	printf("Ponteiro de n: %x \n", pn);
	
	
	system("pause");
}

 
