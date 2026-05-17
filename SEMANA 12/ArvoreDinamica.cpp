#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main(void)
{
 TArvore *raiz;
 int valor;

 
 printf("Informe o Valor da Raiz: "); 
 scanf("%d",&valor);
 
 raiz = Cria(NULL, valor, NULL);
 
 while (valor!=0)
 {
  	printf("Digite o Valor da Folha: "); 
 	scanf("%d",&valor);
 	
	 if (valor != 0)
 		raiz = insere_binario(raiz, valor); 
}
  
 printf("Caminhamentos na Arvore:\n\n");
 
 printf("\n - Pre-Ordem: \t");
 Caminhamento_Pre_Ordem(raiz);
 
 printf("\n - In-Fixado: \t");
 Caminhamento_In_Fixado(raiz);
 
 printf("\n - Pos-Fixado: \t");
 Caminhamento_Pos_Fixado(raiz);
 
 Destroi(raiz); 

return(0);
}

