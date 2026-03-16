/*
Recursividade - Atividade 03

Faça um algoritmo recursivo que dado um valor decimal, imprime seu correspondente
 em binário.
Implementar usando laço de repetição (while ou for) e outra usando recursividade.
*/

/*
Converter um número decimal para binário é o exemplo perfeito para provar que, em alguns
 casos, a recursividade é muito mais fácil e elegante do que usar o laço de repetição
  (while ou for).

A Lógica Matemática (Decimal para Binário)
Para converter um número (ex: 13) para binário, nós dividimos ele por 2 repetidas
 vezes e anotamos o resto da divisão (que sempre será 0 ou 1). O segredo é que o
  número binário final é formado lendo os restos de trás para frente .

13 / 2 = 6 (Resto 1)
6 / 2 = 3 (Resto 0)
3 / 2 = 1 (Resto 1)
1 / 2 = 0 (Resto 1)

Lendo de baixo para cima: 1101

Por que a Recursividade ganha aqui?
No método iterativo (com while), nós calculamos os restos, mas como precisamos
 imprimi-los de trás para frente, somos obrigados a criar um Vetor para guardar
  todos os números e depois fazer um for invertido para imprimir na tela. Dá trabalho!
Na recursividade, nós usamos a própria Pilha de Memória (aquela dos pratos que vimos
 antes) a nosso favor! Se nós mandarmos a função "chamar a si mesma" PRIMEIRO e 
 só mandarmos o printf imprimir o resto DEPOIS, ela vai pausar todas as impressões e,
  quando voltar desempilhando, vai imprimir exatamente de trás para frente sem
   precisarmos de vetor nenhum!
*/

#include <stdio.h>
#include <stdlib.h>

// ==========================================
// 1. SOLUÇÃO ITERATIVA (COM LAÇO WHILE)
// ==========================================
void binario_iterativo(int n) {
    if (n == 0) {
        printf("0");
        return;
    }

    int vetor_binario[32]; // Vetor para guardar os restos
    int i = 0;

    // Calcula os restos e guarda no vetor
    while (n > 0) {
        vetor_binario[i] = n % 2; // Guarda o resto (0 ou 1)
        n = n / 2;                // Divide o número por 2
        i++;
    }

    // Imprime o vetor de trás para frente!
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", vetor_binario[j]);
    }
}

// ==========================================
// 2. SOLUÇÃO RECURSIVA (A MÁGICA)
// ==========================================
void binario_recursivo(int n) {
    
    // CASO BASE: Se o número chegou a zero, para a descida.
    // Detalhe: se o número for 0 logo de cara, nós simplesmente não fazemos nada e a pilha volta.
    if (n == 0) {
        return;
    }
    
    // PASSO RECURSIVO: Chama a função passando a metade do número
    // O pulo do gato: o printf fica DEPOIS da chamada recursiva!
    binario_recursivo(n / 2);
    
    // Quando a função atingir o caso base, ela volta desempilhando e imprimindo os restos.
    printf("%d", n % 2);
}

// ==========================================
// PROGRAMA PRINCIPAL
// ==========================================
int main() {
    int numero = 13;

    printf("--- Conversao de Decimal para Binario ---\n\n");
    printf("Numero decimal: %d\n\n", numero);

    printf("1. Metodo Iterativo (com laco): ");
    
    // Pequeno tratamento caso o usuário digite 0, já que o iterativo lida com isso dentro da função
    binario_iterativo(numero); 
    
    printf("\n\n");

    printf("2. Metodo Recursivo: ");
    
    // Tratamento para o 0 no recursivo (pois a nossa recursão baseada em divisão ignora o 0 direto)
    if (numero == 0) {
        printf("0");
    } else {
        binario_recursivo(numero);
    }
    
    printf("\n\n");

    system("pause");
    return 0;
}

/*
Repare no tamanho absurdo da diferença entre o bloco de código do binario_iterativo
 e o binario_recursivo. Na versão recursiva, com apenas 2 linhas de lógica,
  nós resolvemos o problema inteiro! O computador usa a própria natureza de
   "voltar de baixo para cima" para inverter a ordem dos números para nós.
*/

/*
1ª Chamada: binario_recursivo(13)
n vale 13. É zero? Não.
O computador encontra a chamada binario_recursivo(13 / 2). Como na divisão de inteiros
 em C ele ignora a vírgula, o resultado é 6.
O programa PAUSA a execução desta função na linha 2. A linha do printf("%d", 13 % 2)
 fica "guardada" na memória para ser executada depois.

2ª Chamada: binario_recursivo(6)
n vale 6. É zero? Não.
O computador encontra a chamada binario_recursivo(6 / 2). O resultado é 3.
O programa PAUSA aqui. A linha do printf("%d", 6 % 2) fica guardada.

3ª Chamada: binario_recursivo(3)
n vale 3. É zero? Não.
O computador chama binario_recursivo(3 / 2). O resultado é 1.
O programa PAUSA aqui. A linha do printf("%d", 3 % 2) fica guardada.

4ª Chamada: binario_recursivo(1)
n vale 1. É zero? Não.
O computador chama binario_recursivo(1 / 2). O resultado é 0.
O programa PAUSA aqui. A linha do printf("%d", 1 % 2) fica guardada.

5ª Chamada: binario_recursivo(0)
n vale 0. É zero? Sim!
Ele entra no if (n == 0) e encontra o return;.
Bateu no fundo do poço (Caso Base)! Agora a função para de descer e começa a
 "desempilhar" e resolver os printf que ficaram pausados, de trás para frente.

A SUBIDA (Desempilhando e Imprimindo)
O computador volta exatamente para onde cada chamada tinha parado:

Volta para a 4ª Chamada (n = 1):
Executa a linha que estava pausada: printf("%d", 1 % 2). O resto de 1 por 2 é 1.

Tela: 1

Volta para a 3ª Chamada (n = 3):
Executa a linha pausada: printf("%d", 3 % 2). O resto de 3 por 2 é 1.

Tela: 11
Volta para a 2ª Chamada (n = 6):
Executa a linha pausada: printf("%d", 6 % 2). O resto de 6 por 2 é 0.

Tela: 110
Volta para a 1ª Chamada (n = 13):
Executa a linha pausada: printf("%d", 13 % 2). O resto de 13 por 2 é 1.

Tela: 1101
A 1ª chamada finalmente termina, e o controle volta para a função main.

Resultado Final na Tela: 1101

Conseguiu visualizar? Como o printf foi escrito depois da chamada recursiva,
 o computador foi obrigado a "descer" dividindo tudo primeiro, para só conseguir
  imprimir na "subida". Isso inverte a ordem dos números de forma perfeita, 
  sem precisarmos de um vetor!
*/
