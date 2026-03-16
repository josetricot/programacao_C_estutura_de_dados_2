/*Recursividade - Atividade 01

Fazer uma função recursiva que receba um valor como parâmetro de mostre o somatório do valor.

Exemplo: Valor = 5

Calcular 5+4+3+2+1

Dúvida: Quando ocorre o estouro de pilha?*/

/*Para fazer o somatório (5 + 4 + 3 + 2 + 1), a nossa função precisa de:
Caso Base: Se o número chegar a 1 (ou 0), não precisamos mais somar nada.
 Apenas devolvemos o número.
Passo Recursivo: Pegamos o número atual e somamos com o resultado da própria função
 passando o número anterior (n - 1).*/
 
#include <stdio.h>
#include <stdlib.h>

// Função Recursiva para calcular o somatório
int somatorio(int n) {
    
    // CASO BASE: Se chegar em 1 (ou 0), a descida acaba e ele retorna o próprio 1
    if (n <= 1) {
        return n;
    } 
    // PASSO RECURSIVO: O número atual + o somatório dos anteriores
    else {
        return n + somatorio(n - 1);
    }
}

int main() {
    int valor = 5;
    int resultado = somatorio(valor);
    
    printf("O somatorio de %d eh: %d\n", valor, resultado);
    
    system("pause");
    return 0;
}

/*
Teste de Mesa (Como o C calcula isso?)
Quando você chama somatorio(5), o computador não sabe a resposta de imediato.
 Ele deixa as somas "pendendentes" na memória:
somatorio(5) retorna 5 + somatorio(4) (Pausa e aguarda)
somatorio(4) retorna 4 + somatorio(3) (Pausa e aguarda)
somatorio(3) retorna 3 + somatorio(2) (Pausa e aguarda)
somatorio(2) retorna 2 + somatorio(1) (Pausa e aguarda)
somatorio(1) retorna 1 (Bateu no Caso Base!)

Agora ele volta de baixo para cima resolvendo as pendências:
A linha 4 descobre que somatorio(1) é 1. Então faz 2 + 1 = 3.
A linha 3 descobre que somatorio(2) é 3. Então faz 3 + 3 = 6.
A linha 2 descobre que somatorio(3) é 6. Então faz 4 + 6 = 10.
A linha 1 descobre que somatorio(4) é 10. Então faz 5 + 10 = 15.

Resposta final entregue ao main: 15!

A sua dúvida: Quando ocorre o Estouro de Pilha?
Imagine que a "Pilha de Chamadas" (Call Stack) é uma pilha de pratos reais. 
Toda vez que uma função é chamada e fica "pausada aguardando o resultado"
 (como mostrei no teste de mesa acima), o computador coloca um "prato" na memória RAM
  para guardar o estado daquela função. Quando a função termina, o computador retira 
  o prato.
O Estouro de Pilha (Stack Overflow) acontece quando os pratos chegam ao teto 
e o computador fica sem memória RAM para guardar novas chamadas pendentes. 
Isso faz o seu programa fechar abruptamente (dar crash).

Quais são os 2 motivos que causam isso?
Esquecer o Caso Base (ou fazer a lógica errada): Se no código acima eu não colocasse 
o if (n <= 1), a função iria calcular 0, -1, -2, -3... e continuaria se chamando 
infinitamente rumo ao infinito negativo. Como a memória do computador é finita, 
uma hora a pilha lota e estoura.
Um número absurdamente grande: Mesmo com o código perfeito, se você chamar 
somatorio(1000000), o computador tentará empilhar 1 milhão de "pratos" (chamadas 
pendentes) de uma vez só. O Windows vai perceber o consumo excessivo de memória 
daquela pilha e vai matar o seu programa por segurança, gerando um estouro.*/
