#include <stdio.h>
#include <time.h>
#include <unistd.h> 
#include <stdlib.h>
#include <string.h>

#define N 200

int contBusca1=0;
int contBusca2=0;

struct aluno {
	int mat;
	char nome[81];
};
typedef struct aluno Aluno;

typedef Aluno* Hash[N];

int hash (int mat) //calcula o indice na tabela
{
	return (mat%200);
}

int hash2 (int mat) //calcula o tamanho so "salto" para encontrar nova posicao caso indice ja esteja ocupado (colisao)
{
	return N - 2 - mat%(N-2);
}

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

main(){

Hash  dados1; 
//Inicializando - Set NULL para todas as entradas
for(int i = 0; i < N; i++)
  dados1[i] = NULL;

int mat= 0; 
char nome[80];  

Hash  dados2; 
//Inicializando - Set NULL para todas as entradas
for(int i = 0; i < N; i++)
  dados2[i] = NULL;

FILE *arquivo = fopen("dados.txt", "r");
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

printf("Buscando o 1010 com metodo 1\n");
contBusca1=0;
busca1 (dados1, 1010);
printf("%d acessos\n",contBusca1);

printf("Buscando o 1011 com metodo 1\n");
contBusca1=0;
busca1 (dados1, 1011);
printf("%d acessos\n",contBusca1);

printf("Buscando 0 2010 com metodo 1\n");
contBusca1=0;
busca1 (dados1, 2010);
printf("%d acessos\n",contBusca1);

printf("Buscando o 1010 com metodo 2\n");
contBusca2=0;
busca2 (dados2, 1010);
printf("%d acessos\n",contBusca2);

printf("Buscando o 1011 com metodo 2\n");
contBusca2=0;
busca2 (dados2, 1011);
printf("%d acessos\n",contBusca2);

printf("Buscando o 2010 com metodo 2\n");
contBusca2=0;
busca2 (dados2, 2010);
printf("%d acessos\n",contBusca2);

printf("Escrevendo dados para o arquivo excel!\n");

//abre o arquivo em modo w write/escrever
FILE *arquivoCSV = fopen("saida.csv", "w");
if (arquivoCSV == NULL) {
    printf("Erro ao abrir o arquivo!\n");
    return 1;
} 

//escreve o cabecalho das colunas no excel
fprintf(arquivoCSV, "Indice;Mat_Simples;Mat_Dupla\n");

// varre toda a tabela para ver onde os dados cairam
for(int i = 0; i < N; i++) {
    //escreve o índice da linha
    fprintf(arquivoCSV, "%d;", i);
    
    //se tiver aluno na tabela 1 escreve a matrícula, se nao deixa em branco
    if (dados1[i] != NULL) {
        fprintf(arquivoCSV, "%d;", dados1[i]->mat);
    } else {
        fprintf(arquivoCSV, ";");
    }
    
    //se tiver aluno na tabela 2 escreve a matricula, se nao deixa em branco
    if (dados2[i] != NULL) {
        fprintf(arquivoCSV, "%d\n", dados2[i]->mat);
    } else {
        fprintf(arquivoCSV, "\n");
    }
}

fclose(arquivoCSV);
}
	 
 
