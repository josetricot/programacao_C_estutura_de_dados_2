/*
| AULA 2 | Desafio em Aula - Alocação Dinâmica - Atividade 02 |

Execute e descreva o que o programa imprime? 

Após executar o programa, altere a função malloc para calloc (veja a sintaxe/diferença-a)
e execute. 

Qual foi a mudança? 

anexo o código (CPP) e um print da tela

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main (void) {

	char *letras = (char*) malloc(100);
	
	strcpy (letras, "Linguagem C - Eu adoro programar em C \n");

	int i = 0;

	while (i<100) {
		printf("%c", *letras);
		i++;
		letras++;
	}

return 0;

}
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void) {

    //troquei malloc por calloc
    // calloc pede 2 parâmetros: (quantidade_de_itens, tamanho_de_cada_item)
    char *letras = (char*) calloc(100, sizeof(char));
    
    //criado backup de ponteiro inicial para dar o  'free' depois
    char *inicio_da_memoria = letras;
    
    strcpy (letras, "Linguagem C - Eu adoro programar em C \n");

    int i = 0;

    while (i < 100) {
        printf("%c", *letras);
        i++;
        
        // faz o ponteiro pular para a próxima "bloco" de memória
        letras++; 
    }
    
    // libera a memória usando o endereço original
    free(inicio_da_memoria);

    printf("\n\n");
    system("pause"); //pausa a tela

    return 0;
}

/*
Ao rodar No código original frase + lixo, pois pedimos para o malloc reservar 100 bytes na memória. O laço while força o programa a imprimir todos os 100 espaços. malloc só "separa" a memória mas não a limpa então acaba lendo e imprimindo esse lixo na tela.

O calloc pede dois parâmetros: a quantidade de itens e o tamanho de cada item. Ele limpa a memória, preenchendo todos os blocos com o valor zero (\0 - caractere nulo) no momento da alocação.

Ao rodar com calloc, o lixo de memória desaparece. O programa imprime a frase + "vazio" (pois o caractere \0 não tem representação visual na tela).
*/
