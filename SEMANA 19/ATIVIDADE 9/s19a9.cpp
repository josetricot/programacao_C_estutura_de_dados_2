/*Usando o programa da Atividade 08, altere para que mostra a quantidade de acessos utolizada para cada registro:

Exemplo:
Posição | Hash Simples | Acessos | Hash Duplo | Acessos
-------------------------------------------------------
1       | 10001        |   1     |            |        
2       | -            | 1002    |   2        |        
3       | 5003         |  1      |3001        |  3    
...*/

#include <stdio.h>
#include <time.h>
#include <unistd.h> 
#include <stdlib.h>
#include <string.h>

//como cada matricula vai ter o seu proprio numero de acessos, tentativas ate achar a vaga
//o melhor lugar para guardar a informação eh dentro da struct

//nas funcoes de insercao, criado contador que começa em 1, tentativa inicial
//acada vez que o while roda, ocorre uma colisão, aumenta o contador
//quando acha a vaga, tab[h] == NULL, salva o numero


#define N 200

struct aluno {
	int mat;
	char nome[81];
	int acessos; //variavel para guardar quantos acessos foram necessario
};
typedef struct aluno Aluno;

//tabela hash eh um vetor de ponteiros para Aluno
typedef Aluno* Hash[N];

//hash princiapal
int hash (int mat) //calcula o indice na tabela
{
	return (mat%N);
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
	int contAcessos = 1; //comeca no 1 (primeira tentativa)
	while (tab[h] != NULL) {
		if (tab[h]->mat == mat) //Se matricula Igual, atualiza os dados
			break;
		h = (h+1) % N;
		contAcessos++; //teve colisao, soma um acesso
	}
	if (tab[h]==NULL) { /* não encontrou o elemento */
		tab[h] = (Aluno*) malloc(sizeof(Aluno));
		tab[h]->mat = mat;
		tab[h]->acessos = contAcessos; //salva a quantidade de acessos
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
	int contAcessos = 1; //comeca no 1 (primeira tentativa)
	while (tab[h] != NULL) {
		if (tab[h]->mat == mat) //Se matricula Igual, atualiza os dados
			break;
		h = (h+h2) % N;
		contAcessos++; //teve colisao, soma um acesso
	}
	if (tab[h]==NULL) { /* não encontrou o elemento */
		tab[h] = (Aluno*) malloc(sizeof(Aluno));
		tab[h]->mat = mat;
		tab[h]->acessos = contAcessos; //salva a quantidade de acessos
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


    printf("%-7s | %-12s | %-7s | %-10s | %-7s\n", "Posicao", "Hash Simples", "Acessos", "Hash Duplo", "Acessos");
    printf("-----------------------------------------------------------\n");

    for (int i = 0; i < N; i++) {
        //imprime a coluna posicao
        printf("%-7d | ", i);
        
        //imprime a coluna hash simples verificando se ocupada
		if (dados1[i] != NULL) {
            printf("%-12d | %-7d | ", dados1[i]->mat, dados1[i]->acessos);
        } else {
            printf("%-12s | %-7s | ", "-", "-");
        }
        
        //imprime a coluna hash duplo verificando se ocupada
		if (dados2[i] != NULL) {
            printf("%-10d | %-7d\n", dados2[i]->mat, dados2[i]->acessos);
        } else {
            printf("%-10s | %-7s\n", "-", "-");
        }
    }

    //libera memoria
    for (int i = 0; i < N; i++) {
        if (dados1[i] != NULL) free(dados1[i]);
        if (dados2[i] != NULL) free(dados2[i]);
    }

    return 0;
}
