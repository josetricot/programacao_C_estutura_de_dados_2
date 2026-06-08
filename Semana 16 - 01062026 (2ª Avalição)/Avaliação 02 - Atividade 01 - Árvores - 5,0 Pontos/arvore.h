#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nodo {
		         struct Nodo *esq;
		         char palavra[128];
		         int contRepetPalavra;
		         struct Nodo *dir;
		        } TNodo;

typedef TNodo TArvore;

TArvore *Cria(TArvore *esq, char palavra[], int contRepetPalavra, TArvore* dir)
{
TArvore *p;

p = (TArvore*) malloc(sizeof(TArvore));
if (p == NULL)
     {
      printf("ERRO FATAL: Falta de Memória\n");
      getchar();
      exit(0); 

     }
else
     {
      strcpy(p->palavra, palavra);
      p->contRepetPalavra = contRepetPalavra;
	  p->esq = esq;
      p->dir = dir;
     }
 return p;
}

int Vazia(TArvore *a)
{
 if (a == NULL)
     return(1);
 else
     return(0);
}

void Caminhamento_In_Fixado(TArvore *a)
{
 if (!Vazia(a))
    {
     Caminhamento_In_Fixado(a->esq);     
     printf("%s - %d\n", a->palavra, a->contRepetPalavra); 			
     Caminhamento_In_Fixado(a->dir);     
    }
}

TArvore *Destroi(TArvore *a)
{
 if (!Vazia(a))
    {
     Destroi(a->esq); 
     Destroi(a->dir); 
     free(a);         
    }
 return(NULL);
}

TArvore *insere_binario(TArvore *a, char palavra[], int contRepetPalavra) {
    if (a == NULL) {
        a = Cria(NULL, palavra, contRepetPalavra, NULL);
    } else if (strcmp(palavra, a->palavra) < 0) { // nome vem ANTES alfabeticamente
        a->esq = insere_binario(a->esq, palavra, contRepetPalavra);
    } else if (strcmp(palavra, a->palavra) > 0) { // nome vem DEPOIS alfabeticamente
        a->dir = insere_binario(a->dir, palavra, contRepetPalavra);
    } else if (strcmp(palavra, a->palavra) == 0) {
    	a->contRepetPalavra++;
	}  
    return a;
}

//busca era por matrícula, agora é por nome que conta a quantidade de acessos/comparações
//void Busca_Matricula_Conta_Acessos(TArvore *a, int matricula, int *cont)
void Busca_Palavra_Conta_Acessos(TArvore *a, char palavra_buscada[], int *cont)
{
	// soma +1 no contador de acessos
    (*cont)++; 
    
    //condições de busca
    if (a == NULL) {
        printf("\nNome não encontrado!\n");
    } else if (strcmp(palavra_buscada, a->palavra) < 0) { 
		Busca_Palavra_Conta_Acessos(a->esq, palavra_buscada, cont);
    } else if (strcmp(palavra_buscada, a->palavra) > 0) { 
		Busca_Palavra_Conta_Acessos(a->dir, palavra_buscada, cont);
	} else {
		printf("\nPalavra encontrada! Palavra: %s, Acessos: %d, Aparece %d vezes!\n", a->palavra, *cont, a->contRepetPalavra); 
	}  
}

//remoção - nó pode não ter fihos, ter 1 ou 2
//original do professor
/*
TArvore* remove_binario(TArvore* a, int info) {
    if (a == NULL) return NULL;

    if (info < a->info) {
        a->esq = remove_binario(a->esq, info);
    } else if (info > a->info) {
        a->dir = remove_binario(a->dir, info);
    } else {
        // Encontrou o nó a remover
        if (a->esq == NULL && a->dir == NULL) {
            free(a);
            return NULL;
        } else if (a->esq == NULL) {
            TArvore* temp = a->dir;
            free(a);
            return temp;
        } else if (a->dir == NULL) {
            TArvore* temp = a->esq;
            free(a);
            return temp;
        } else {
            // Dois filhos: encontrar o menor da subárvore direita
            TArvore* temp = a->dir;
            while (temp->esq != NULL)
                temp = temp->esq;
            a->info = temp->info;
            a->dir = remove_binario(a->dir, temp->info);
        }
    }
    return a;
}

*/

/* não utlizado
//nova
TArvore* remove_binario(TArvore* a, char nome_remover[]) {
    if (a == NULL) return NULL;

    if (strcmp(nome_remover, a->nome) < 0) {
        a->esq = remove_binario(a->esq, nome_remover);
    } else if (strcmp(nome_remover, a->nome) > 0) {
        a->dir = remove_binario(a->dir, nome_remover);
    } else {
        // Encontrou o nó a remover
        if (a->esq == NULL && a->dir == NULL) { //nó folha, 0 filhos
            free(a);
            return NULL;
        } else if (a->esq == NULL) { //1 filho, à direita
            TArvore* temp = a->dir;
            free(a);
            return temp;
        } else if (a->dir == NULL) {//1 filho, à esquerda
            TArvore* temp = a->esq;
            free(a);
            return temp;
        } else {
            // Dois filhos: encontrar o menor da subárvore direita
            TArvore* temp = a->dir;
            while (temp->esq != NULL)
                temp = temp->esq;

        //aqui ajustado por ser string    
	//a->nome = temp->info; 
	//strcpy(destino, origem)
	//se faz a copia separada para String e para o Inteiro

	strcpy(a->nome, temp->nome);
	a->matricula = temp->matricula;
		
	// Remove o nó substituto lá de baixo
        a->dir = remove_binario(a->dir, temp->nome);
        }
    }
    return a;
}
*/
