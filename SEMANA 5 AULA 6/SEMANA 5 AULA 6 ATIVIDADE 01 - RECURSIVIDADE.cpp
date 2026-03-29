/*Dado um vetor de 20 números inteiros, implemente em linguagem C um programa que:

   1. Leia os 20 elementos do vetor.
   2. Utilize funções recursivas para:
        2.1. Determinar quantos elementos pares existem no vetor.
        2.2. Determinar quantos elementos ímpares existem no vetor.
   3. Exiba os resultados finais.

Requisitos:

    * A função recursiva deve receber como parâmetros o vetor, o índice atual e o tamanho total.
    * O caso base ocorre quando o índice ultrapassa o tamanho do vetor.
    * A cada chamada recursiva, o programa deve verificar se o elemento atual é par ou ímpar e acumular a contagem.
    * Não é permitido usar laços de repetição (for, while) para realizar a contagem.*/

	#include <stdio.h>
	#include <stdlib.h>
	#include <locale.h>
	
	#define TAMANHO 20

int contarPares(int vet[], int indice, int tamanhoTotal){

	if (indice>=tamanhoTotal) return 0; //ponto de parada, para evitar estouro de pilha
	
	if(vet[indice] % 2 == 0){
    	return 1 + contarPares(vet, indice + 1, tamanhoTotal);
	} else {
		return contarPares(vet, indice + 1, tamanhoTotal);
	}

}

int contarImpares(int vet[], int indice, int tamanhoTotal){

	if (indice>=tamanhoTotal) return 0; //ponto de parada, para evitar estouro de pilha
	
	if(vet[indice] % 2 != 0){
    	return 1 + contarImpares(vet, indice + 1, tamanhoTotal);
	} else {
		return contarImpares(vet, indice + 1, tamanhoTotal);
	}

}	

int main() {

	setlocale(LC_ALL, "portuguese");
	int vet[TAMANHO];
	
	for(int k=0; k<TAMANHO; k++) {
        printf("\nDigite o %d.º número para salvar o vetor: ", k+1);
    	scanf("%d",&vet[k]);
	} 
	
	printf("\nO número total de pares é %d.", contarPares(vet, 0, TAMANHO));
	printf("\nO número total de impares é %d.\n", contarImpares(vet, 0, TAMANHO));
	
	system("pause");
	return 0;
}
