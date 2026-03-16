/*Recursividade - Atividade 04
Escreva uma função recursiva que determine quantas vezes um CARATERE X ocorre em um
 STRING Y.
Por exemplo, o caractere A ocorre 3 vezes em "abacate".
Implementar usando laço de repetição (while ou for) e outra usando recursividade.*/

/*
Para resolver a Atividade 04, precisamos lembrar de uma regra vital da linguagem C:
 toda string termina obrigatoriamente com o caractere nulo '\0'. Ele será o nosso
  "Caso Base" perfeito para avisar a recursividade que a palavra acabou!

Além disso, na versão recursiva, nós vamos usar aquela Aritmética de Ponteiros
 que revisamos lá atrás. Em vez de passar um índice i para a função, nós vamos
  simplesmente passar string + 1, fazendo o ponteiro pular para a próxima letra.
*/

#include <stdio.h>
#include <stdlib.h>

// ==========================================
// 1. SOLUÇÃO ITERATIVA (COM LAÇO WHILE)
// ==========================================
int contar_iterativo(char *str, char alvo) {
    int contagem = 0;
    int i = 0;
    
    // O laço roda até encontrar o terminador nulo da string ('\0')
    while (str[i] != '\0') {
        if (str[i] == alvo) {
            contagem++; // Achou a letra, soma 1 na contagem
        }
        i++; // Pula para a próxima letra
    }
    
    return contagem;
}

// ==========================================
// 2. SOLUÇÃO RECURSIVA
// ==========================================
int contar_recursivo(char *str, char alvo) {
    
    // CASO BASE: Chegou no terminador nulo ('\0')? 
    // Significa que a palavra acabou. Retorna 0.
    if (*str == '\0') {
        return 0;
    }

    // PASSO RECURSIVO: A letra atual (*str) é igual à letra alvo?
    if (*str == alvo) {
        // Retorna 1 (pois achamos a letra) + o resultado do resto da palavra.
        // str + 1 faz o ponteiro "andar" para a próxima letra!
        return 1 + contar_recursivo(str + 1, alvo);
    } else {
        // Retorna 0 (não é a letra) + o resultado do resto da palavra.
        return 0 + contar_recursivo(str + 1, alvo);
    }
}

// ==========================================
// PROGRAMA PRINCIPAL
// ==========================================
int main() {
    // Usando exatamente o exemplo do material da aula
    char palavra[] = "abacate";
    char letra = 'a';

    printf("--- Contador de Caracteres ---\n\n");
    printf("Palavra alvo: %s\n", palavra);
    printf("Letra buscada: %c\n\n", letra);

    // Testando o método iterativo
    int resultado_iterativo = contar_iterativo(palavra, letra);
    printf("1. Metodo Iterativo: Encontrou %d vezes.\n", resultado_iterativo);

    // Testando o método recursivo
    int resultado_recursivo = contar_recursivo(palavra, letra);
    printf("2. Metodo Recursivo: Encontrou %d vezes.\n", resultado_recursivo);

    printf("\n");
    system("pause");
    
    return 0;
}

/*
Como a Mágica Acontece na Memória?
Diferente da atividade do binário (onde deixamos o printf para o final para inverter
 a ordem), aqui nós estamos somando os valores no momento do retorno (a "subida" da
  pilha).

Quando chamamos contar_recursivo passando a palavra "abacate" e a letra 'a':
Letra 'a': É igual! Retorna 1 + contar_recursivo("bacate")
Letra 'b': Não é. Retorna 0 + contar_recursivo("acate")
Letra 'a': É igual! Retorna 1 + contar_recursivo("cate")
Letra 'c': Não é. Retorna 0 + contar_recursivo("ate")
Letra 'a': É igual! Retorna 1 + contar_recursivo("te")
Letra 't': Não é. Retorna 0 + contar_recursivo("e")
Letra 'e': Não é. Retorna 0 + contar_recursivo("\0")
Fim (\0): Caso Base. Retorna 0.

Na volta, ele resolve a matemática: 1 + 0 + 1 + 0 + 1 + 0 + 0 + 0 = 3.
 Exatamente as 3 vezes que o 'a' aparece em "abacate"!
*/
