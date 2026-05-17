/*
Dado o programa de exemplo "arvoredinamica.cpp", realize as seguintes alterações:

Modifique a estrutura do nó da árvore para armazenar:
matrícula do estudante;
nome do estudante.

Altere o programa para ler os dados do arquivo dados.txt
 e inserir todas as informações na árvore binária.

Após o carregamento dos dados, implemente um menu com as seguintes opções:
[1] Buscar estudante por matrícula
O usuário deverá informar uma matrícula.
O programa deverá localizar o estudante na árvore e apresentar:
a matrícula;
o nome do estudante;
a quantidade de acessos/comparações realizados durante a busca.

[2] Listar todos os estudantes
O programa deverá apresentar todos os dados armazenados na árvore em ordem crescente de
 matrícula.
Observação: Caso a matrícula informada não exista na árvore, o programa deverá apresentar 
uma mensagem informando que o estudante não foi encontrado.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h> //biblioteca para idiomas e caracteres especiais
#include "arvore.h"


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
		printf("[1] Buscar estudante por matrícula\n");
		printf("[2] Listar todos os estudantes\n");
	  	printf("[0] Sair\n");
	 	scanf("%d",&opcao);
	 	
		switch(opcao) {
	
			case 1: {
				printf("Digite o número da matrícula: \n");
				scanf("%d", &matricula);
				cont = 0; //para não somar nas buscas anteriores
				Busca_Matricula_Conta_Acessos(raiz, matricula, &cont);
				break;
			}
			
			case 2: {
				//problema pede que a lista seja apresentada em ordem crescente de matrícula
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

