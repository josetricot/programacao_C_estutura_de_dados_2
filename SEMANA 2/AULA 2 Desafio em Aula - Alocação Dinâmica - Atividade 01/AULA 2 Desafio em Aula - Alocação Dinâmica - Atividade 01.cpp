/*
| AULA 2 | Desafio em Aula - Alocação Dinâmica - Atividade 01 |

altere o codigo para alocação dinâmica e ponteiro
altere as linhas 10, 15, 17 e 18

anexo o código (CPP) e um print da tela

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define tamanho 100

int main (void) {

	char frase[tamanho]

	strcpy (fras, "IFRS - Instituto Federal de Educacao Tecnologica \n);

	int i = 0;

	while (frase[i] != '\n') {
		printf("%c", frase[i]);
		i++;
	}

return 0;

}
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tamanho 100

int main (void)
{
    // saiu o vetor estático e entra o ponteiro com alocação dinâmica
    // malloc reserva blocos na memória e devolve o endereço inicial para o ponteiro 'frase'
    char *frase = (char *) malloc(tamanho * sizeof(char));
    
    strcpy(frase, "IFRS - Instituto Federal de Educacao Tecnologica \n");
    
    int i = 0;
    
    // sai frase[i] entre *(frase + i)
    // assim pega o endereço inicial (frase) pula 'i' posições para frente e o '*' lê o que tem lá
    while (*(frase + i) != '\n') 
    {
        // '*' (desreferência) acessa o caractere exato da posição da memória
        printf("%c", *(frase + i)); 
        
        //incrementando o "deslocamento"
        i++; 
    }
    
    // boa prática
    free(frase); 

    return 0;
}
