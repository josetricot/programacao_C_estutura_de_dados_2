/*
Refaça a atividade da semana 12, agora utilizando o nome do estudante

Menu interativo:
Implemente um menu com as seguintes opções:

[1]Inserir Novo valor na árvore
[2]Remover valor da árvore
[3]Pesquisar valor na árvore
[4]Imprimir a árvore (utilizando caminhamento in-fixado). 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h> //biblioteca para idiomas e caracteres especiais
#include "arvore1.h"


int main(void) {

setlocale(LC_ALL, "Portuguese"); //configura o programa para usar o idioma português
TArvore *raiz = NULL; //declara ponteiro que será o ponto de partida (a raiz) da nossa árvore, iniciada como vazio
int matricula;
char nome[128];
int cont = 0;
int opcao;

FILE *arquivo;
arquivo = fopen("dados.txt", "r");
	
	if (arquivo == NULL) { printf("Erro!"); }

	while(!feof(arquivo)){
			fscanf(arquivo, "%d %[^\n]", &matricula, nome); //lê do arquivo
			
			raiz = insere_binario(raiz, matricula, nome);   //insere na árvore
		}
	
	fclose(arquivo); //sempre fechamos o arquivo após o uso
 
	do {
	  	printf("Digite: \n");
		printf("[1] Inserir estudante pelo nome\n");
		printf("[2] Remover estudante por nome\n");
		printf("[3] Buscar estudante por nome\n");
		printf("[4] Listar todos os estudantes\n");
	  	printf("[0] Sair\n");
	 	scanf("%d",&opcao);
	 	
		switch(opcao) {
			
			case 1: {
				printf("Digite a matrícula para inserir: \n");
				scanf("%d", &matricula);
				printf("Digite o nome para inserir: \n");
				scanf(" %[^\n]", nome);
				
				//chama a funcao passando variáveis e atualiza a raiz
				raiz = insere_binario(raiz, matricula, nome);
				break;
			}
			
			case 2: {
				printf("Digite o nome para remover: \n");
				scanf(" %[^\n]", nome;

				raiz = remove_binario(raiz, nome);
				break;
			}	
				
			case 3: {
				printf("Digite o nome para pesquisa: \n");
				scanf(" %[^\n]", nome);
				cont = 0; //para não somar nas buscas anteriores
				Busca_Nome_Conta_Acessos(raiz, nome, &cont);
				break;
			}
			
			case 4: {
				//problema pede que a lista seja apresentada em ordem crescente de nome, alfabética
				printf("\n*** Lista de Estudantes ***\n");
				Caminhamento_In_Fixado(raiz);
				break;
			}	 	
			
			case 0: {
			    printf("\nEncerrando programa...\n");
			    break;
			}
		    
			default:
		        printf("\nOpção inválida! Tente novamente.\n");
			}
	 	
	} while (opcao!=0);

Destroi(raiz); 

return(0);
}

