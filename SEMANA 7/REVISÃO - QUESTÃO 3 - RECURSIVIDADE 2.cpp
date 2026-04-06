/*a ) Faça um programa recursivo de conte de 1 até 100, apresentando os valores de forma Crescente.

b ) Altere programa recursivo que conte de 1 até 100, apresentando os valores de forma Decrescente

*/

/*
#include <stdio.h>

// função recursiva para contar de 1 até N (crescente)
void contarCrescente(int atual, int limite) {
    // caso base: se atual ultrapassou o limite PARA
    if (atual > limite) {
        return;
    }
    
    // imprime o número atual
    printf("%d ", atual);
    
    // chamada recursiva com o próximo número
    contarCrescente(atual + 1, limite);
}

int main() {
    printf("Contagem crescente de 1 ate 100:\n");
    contarCrescente(1, 100);
    printf("\n");
    return 0;
}
*/
#include <stdio.h>

// função recursiva para contar de N até 1 (decrescente)
void contarDecrescente(int atual, int limite) {
    // caso base: se atual ultrapassou o limite PARA
    if (atual < limite) {
        return;
    }
    
    // imprime o número atual
    printf("%d ", atual);
    
    // chamada recursiva com o próximo número (decrescendo)
    contarDecrescente(atual - 1, limite);
}

int main() {
    printf("Contagem decrescente de 100 ate 1:\n");
    contarDecrescente(100, 1);
    printf("\n");
    return 0;
}
