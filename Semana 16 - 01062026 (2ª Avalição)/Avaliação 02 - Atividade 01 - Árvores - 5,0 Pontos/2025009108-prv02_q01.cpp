/*contagem de palavras utilizando uma estrutura hierárquica.

a) Ao iniciar, carregar automaticamente os dados do arquivo em uma estrutura hierárquica;

b) Permitir a inserção de uma nova palavra após o término da carga inicial;

c) Permitir a pesquisa de uma palavra, informando se ela existe na estrutura e a quantidade de vezes em que aparece. Caso a palavra não seja localizada, o programa deverá informar essa condição;

d) Listar todas as palavras, em ordem alfabética, e o numero de ocorrências. 

e) Possuir opção para encerrar o programa.

Para cada pesquisa realizada, o programa deverá apresentar o número de acessos realizados na estrutura.

O menu do programa deverá conter as seguintes opções:
1) Pesquisar palavra
2) Inserir nova palavra
3) Mostrar Árvore
4) Sair

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

int main(void)
{
 TArvore *raiz = NULL;
 char linha[1024];
 char * ultima;
 int cont =0;
 int opcao;
 char palavraPesquisada[1024];
 char palavraInserida[1024];

FILE *txt;
if((txt = fopen("poema_horizonte.txt","r")) == NULL)
 {
 printf("Erro ao abrir arquivo");
 }
else {
 while (!feof(txt)) {
 fgets(linha, 1024, txt); // Lê uma linha inteira do arquivo
/* ultima = strtok (linha, " ");
while (ultima != NULL) {
 printf ("\n%s ",ultima);
 ultima = strtok (NULL, " ");
}
 raiz = insere_binario(raiz, ultima);
 }
 */
 ultima = strtok(linha, " \n"); // Pega a primeira palavra (também limpando a quebra de linha)
 
 while (ultima != NULL) {
    //printf ("\n%s ", ultima);
    raiz = insere_binario(raiz, ultima, 1); // Passamos 1 pois acabamos de achar a palavra 1 vez
    ultima = strtok (NULL, " ");
}

}

 fclose(txt);
system("pause");}	

	do{
		printf("Digite \n");
		printf("[1] Pesquisar palavra\n");
		printf("[2] Inserir palavra\n");
		printf("[3] Mostrar Árvore\n");
		printf("[4] Sair\n");
		scanf("%d", &opcao);
		
		switch (opcao){
			case 1: {
			    printf("\nDigite a palavra para pesquisa: ");
			    scanf(" %[^\n]", palavraPesquisada);
			    
			    cont=0;
			    Busca_Palavra_Conta_Acessos(raiz, palavraPesquisada, &cont);		
			    break;
			}
			
			case 2: {
				printf("\nDigite a palavra para inserir: ");
				scanf(" %[^\n]", palavraInserida);
				
				raiz = insere_binario(raiz, palavraInserida, 1);
				break;
			}
			
			case 3: {
				printf("\nLista de palavras: ");
				Caminhamento_In_Fixado(raiz);
				break;
			}
			
			case 4: {
				printf("Fechando programa...");
				break;
			}
			
			default:
				printf("\nOpção inválida! Tente novamente.");
		}
		
	} while (opcao!=4);


 
/* printf("Informe o Valor da Raiz: "); 
 scanf("%d",&valor);
 
 raiz = Cria(NULL, valor, NULL);
 
 while (valor!=0)
 {
  	printf("Digite o Valor da Folha: "); 
 	scanf("%d",&valor);
 	
	 if (valor != 0)
 		raiz = insere_binario(raiz, valor); 
}
*/
  
 //printf("Caminhamentos na Arvore:\n\n");
 
// printf("\n - Pre-Ordem: \t");
// Caminhamento_Pre_Ordem(raiz);

 //printf("\n - In-Fixado: \t");
 //Caminhamento_In_Fixado(raiz);
 
 //printf("\n - Pos-Fixado: \t");
 //Caminhamento_Pos_Fixado(raiz);
 
 Destroi(raiz); 

return(0);
}
