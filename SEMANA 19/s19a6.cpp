/******************************************************************************

Desenvolva um programa em linguagem C que solicite ao usuário a quantidade de
posições de uma estrutura para armazenar números inteiros dinamicamente na 
memória.

Após a entrada do tamanho da estrutura, o programa deve criar uma rotina para 
leitura de números inteiros  positivos informados pelo usuário.

Para cada número digitado, o programa deve verificar e informar se:

o número já existe na estrutura, ou
o número é inédito (ainda não foi inserido).
O programa deve continuar permitindo novas inserções até que o usuário decida 
encerrar a execução, informando -1.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>


int n = 0; //numero de posicoes

struct inteiro {
	int numero;
};
typedef struct inteiro Inteiro;

typedef Inteiro** Hash; 

//Inteiro* dados[n]; nao podemos criar um vetor de ponteiros assim pois n é digitado pelo usuario
//eh preciso usar alocacao dinamica, malloc, vetor de "alguma coisa" e usa ponteiro para essa "alguma coisa", ex int*, float*, Inteiro*
//primeiro asterisco diz que aponta para um endereco e o segundo que lá tem outro ponteiro

int hash (int numero) { //calcula o indice na tabela
	return (numero%n);
}

int hash2 (int numero) //calcula o tamanho so "salto" para encontrar nova posicao caso indice ja esteja ocupado (colisao)
{
	return n - 2 - numero%(n-2);
}

void insere2 (Hash tab, int numero)
{
	int h = hash(numero);
	int h2 = hash2(numero);
	int tentativas = 0;
	
	while (tab[h] != NULL) {
		if (tab[h]->numero == numero) { //Se numeroe Igual, atualiza os dados
			printf("O numero %d ja existe.\n", numero);
			return;
		}
		//se nao eh o numero teve colisao, calcular o salto
		h = (h+h2) % n;
		tentativas++;
	
		if (tentativas == n) {
        	printf("Tabela cheia!");
        	return;
		}
	}
	//se while acabou eh porque achou NULL
	tab[h] = (Inteiro*) malloc(sizeof(Inteiro));
	tab[h]->numero = numero;
	printf("O numero %d eh inedito. Inserido com sucesso!\n", numero);
}

int main(){

	int numero = 0;

	printf("Digite quantas posicoes quer armazenar na memoria\n-> ");
	scanf("%d", &n);

	if (n <= 0) {
        printf("Tamanho invalido.\n");
        return 1;
    }

	//vetor de ponteiros (ponteiro de ponteiro)
    Hash dados = (Hash) malloc(n * sizeof(Inteiro*));
    
	if (dados == NULL) {
        printf("Erro na alocacao.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {    
        dados[i] = NULL;
    }
    
	do {

		printf("\nDigite um numero para inserir ou -1 para sair:\n-> ");
		scanf("%d", &numero);

		if (numero == -1) {
            printf("Encerrando programa...\n");
            break;
        }
        
		if (numero < 0) {
            printf("Numero invalido. Tente novamente.\n");
            continue; //nao faz a insercao de baixo e vai para proxima rodadada do laco
		}
		
		insere2 (dados, numero);
	
	} while (numero!=-1);

	free(dados); 
	return 0;

}

