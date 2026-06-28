/*Desenvolva um programa em linguagem C que leia dados a partir de um arquivo texto chamado dados_nomes.txt.

Esses valores deverão ser inseridos em uma Tabela de Dispersão (Hash Table) utilizando dois métodos distintos:

Dispersão simples (hashing simples)
Dispersão dupla (double hashing)
Ao final da execução, o programa deve gerar uma saída formatada mostrando a ocupação das tabelas, contendo:

posição do vetor
valor armazenado na posição
indicação de ocupação para cada método
Exemplo:
Posição | Hash Simples | Hash Duplo
------------------------------------
1       | 10001        | -
2       | -            | 1002
3       | 5003         | 3001
...*/

#include <stdio.h>
#include <time.h>
#include <unistd.h> 
#include <stdlib.h>
#include <string.h>

#define N 200

//int contBusca1=0;
//int contBusca2=0;

struct aluno {
	int mat;
	char nome[81];
};
typedef struct aluno Aluno;

//tabela hash eh um vetor de ponteiros para Aluno
typedef Aluno* Hash[N];

//hash princiapal
int hash (int mat) //calcula o indice na tabela
{
	return (mat%200);
}

//calcula o tamanho so "salto" para encontrar nova posicao caso indice ja esteja ocupado (colisao)
int hash2 (int mat) 
{
	return N - 2 - mat%(N-2);
}

/*
Aluno* busca1 (Hash tab, int mat)
{
	int h = hash(mat);
	while (tab[h] != NULL) {
	contBusca1++;
	if (tab[h]->mat == mat)
	return tab[h];
	h = (h+1) % N;
}
	return NULL;
}
*/

Aluno* insere1 (Hash tab, int mat, char* nome)
{
	int h = hash(mat);
	while (tab[h] != NULL) {
		if (tab[h]->mat == mat) //Se matricula Igual, atualiza os dados
			break;
		h = (h+1) % N;
	}
		if (tab[h]==NULL) { /* não encontrou o elemento */
		tab[h] = (Aluno*) malloc(sizeof(Aluno));
		tab[h]->mat = mat;
	}
	/* atribui propriedade */
	strcpy(tab[h]->nome,nome);
	return tab[h];
}

/*
Aluno* busca2 (Hash tab, int mat)
{
	int h = hash(mat);
	int h2 = hash2(mat);
	while (tab[h] != NULL) {
	contBusca2++;
	if (tab[h]->mat == mat)
	return tab[h];
	h = (h+h2) % N;
}
	return NULL;
}
*/

Aluno* insere2 (Hash tab, int mat, char* nome)
{
	int h = hash(mat);
	int h2 = hash2(mat);
	while (tab[h] != NULL) {
		if (tab[h]->mat == mat) //Se matricula Igual, atualiza os dados
			break;
		h = (h+h2) % N;
	}
		if (tab[h]==NULL) { /* não encontrou o elemento */
		tab[h] = (Aluno*) malloc(sizeof(Aluno));
		tab[h]->mat = mat;
	}
	/* atribui propriedade */
	strcpy(tab[h]->nome,nome);
	return tab[h];
}

int main(){

	Hash  dados1; 
	//Inicializando - Set NULL para todas as entradas
	for(int i = 0; i < N; i++)
	  dados1[i] = NULL;
	
	int mat= 0; 
	char nome[81];  
	
	Hash  dados2; 
	//Inicializando - Set NULL para todas as entradas
	for(int i = 0; i < N; i++)
	  dados2[i] = NULL;
	
	FILE *arquivo = fopen("dados_nomes.txt", "r");
	if (arquivo == NULL) {
	    printf("Erro ao abrir o arquivo!\n");
	    return 1;
	}
	
	while(!feof(arquivo)){
		if(fscanf(arquivo, " %d %[^\n]", &mat, nome) == 2) {
			insere1 (dados1, mat, nome);
			insere2 (dados2, mat, nome);
		}	 
	}
	fclose(arquivo);


    printf("%-7s | %-12s | %-10s\n", "Posicao", "Hash Simples", "Hash Duplo");
    printf("------------------------------------\n");

    for (int i = 0; i < N; i++) {
        //imprime a coluna posicao
        printf("%-7d | ", i);
        
        //imprime a coluna hash simples verificando se ocupada
        if (dados1[i] != NULL) {
            printf("%-12d | ", dados1[i]->mat);
        } else {
            printf("%-12s | ", "-");
        }
        
        //imprime a coluna hash duplo verificando se ocupada
        if (dados2[i] != NULL) {
            printf("%-10d\n", dados2[i]->mat);
        } else {
            printf("%-10s\n", "-");
        }
    }

    //libera memoria
    for (int i = 0; i < N; i++) {
        if (dados1[i] != NULL) free(dados1[i]);
        if (dados2[i] != NULL) free(dados2[i]);
    }

    return 0;
}
