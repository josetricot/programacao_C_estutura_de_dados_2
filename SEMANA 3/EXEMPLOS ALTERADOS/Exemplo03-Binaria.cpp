#include <stdio.h>
#include <stdlib.h>
#define TAMANHO 20

int main() 
{ 
	//dados precisam estar ordenados
    int x, vetor[TAMANHO] = {3,5,6,7,8,9,10,12,14,16,19,20,21,22,33,35,37,39,44,53};
    int Cont = 0; 
	
    printf("Qual Numero deseja localizar?: "); 
    scanf("%d", &x);
	
    int meio=0, esquerda = 0, direita = TAMANHO - 1; 
    int encontrado = 0;

    while (esquerda <= direita) { //enquanto conseguir dividir no conjunto
        Cont++; //contador de acesso
        meio = (esquerda + direita)/2; //0 até 19
        
        if (vetor[meio] == x) { //(0+19)/2
            encontrado = 1;
            break; //primeiro verifica se é o valor do meio
        }
        else if (vetor[meio] < x) //esta na parte de baixo
            esquerda = meio + 1;
        else 
            direita = meio - 1; //direita avança
    }
    
    //quantidade max de acessos é sempre 5
   	
    if (encontrado)
        printf("\nValor %d localizado", x); 
    else
        printf("\nValor %d NAO localizado", x); 

    printf("\nAcessos ao Array: %d\n", Cont); 
    return 0;
}

