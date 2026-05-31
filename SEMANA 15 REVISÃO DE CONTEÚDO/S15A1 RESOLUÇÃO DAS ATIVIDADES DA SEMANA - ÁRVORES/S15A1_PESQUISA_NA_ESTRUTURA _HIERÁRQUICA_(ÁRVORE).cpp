/*Considere o arquivo dados.txt apresentado na Semana 12. Faça dois programas:

1. um programa que carregue os dados na memória e implemente a pesquisa binária em uma estrutura linear;
2. outro programa que implemente a pesquisa em uma estrutura hierárquica.
Os programas devem:

iniciar automaticamente;
carregar os dados;
ordená-los, se necessário;
pesquisar o nome "Valentina Moura";
encerrar automaticamente.
Todos os processos devem ser executados sem interação com o usuário.

Ao final, cada programa deve apresentar:

o tempo total necessário para executar todos os processos;
o número de acessos realizados durante a pesquisa.*/
/*
1 Definir a estrutura de dados (struct).

2 Ler o arquivo e armazenar as linhas em um vetor.

3 Ordenar o vetor.

4 Aplicar a busca binária para encontrar "Valentina Moura".*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h> //biblioteca para idiomas e caracteres especiais
#include <time.h>
#include "arvore1.h"

int main(void) {

setlocale(LC_ALL, "Portuguese"); //configura o programa para usar o idioma português
//ouve conflito de codificação então usei um comendo direto
//system("chcp 65001"); //força o terminal do Windows a exibir UTF-8
TArvore *raiz = NULL; //declara ponteiro que será o ponto de partida (a raiz) da nossa árvore, iniciada como vazio
int matricula;
char nome[128];
int cont = 0;

FILE *arquivo;
arquivo = fopen("dados.txt", "r");
	
	if (arquivo == NULL) { printf("Erro!"); }

	while(!feof(arquivo)){
			fscanf(arquivo, "%d %[^\n]", &matricula, nome); //lê do arquivo
			
			raiz = insere_binario(raiz, matricula, nome);   //insere na árvore
		}
	
	fclose(arquivo);
 
 	clock_t inicio = clock();
 
	printf("\n---------------- RESULTADO PESQUISA NA ESTRUTURA HIERÁRQUICA (ÁRVORE) ----------------\n");

	cont = 0; // não sei se pode ficar aqui ou tem que ir para o início
	Busca_Nome_Conta_Acessos(raiz, "Valentina Moura", &cont);

	clock_t fim = clock();
	
	//calcula o tempo em segundos (como é um número quebrado, usamos double e %f)
    double tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC; //para converter para segundos
    printf("Tempo total de execução: %f segundos\n", tempo_gasto);


Destroi(raiz); 

return(0);
}

