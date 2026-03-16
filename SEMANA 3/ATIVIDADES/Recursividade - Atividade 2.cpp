/*Recursividade - Atividade 02

Faça uma função que receba, por parâmetro, um valor inteiro e positivo e retorne o número
 de divisores do valor lido.
a) Implementar usando laço de repetição (while ou for) e outra usando recursividade.
b) Comparar o tempo gasto na execução de cada implementação.*/

/*
Para resolver a Atividade 02, precisamos construir as duas versões (iterativa e recursiva) e depois usar a biblioteca <time.h> do C para cronometrar qual delas é a mais rápida.

A Estratégia
Versão Iterativa (Laço): Usa um simples for que vai de 1 até o número desejado, testando
 se o resto da divisão é zero (n % i == 0).

Versão Recursiva: Como a função precisa testar todos os números de 1 até N, nossa função
 recursiva precisará de um segundo parâmetro (um "contador" i) para saber em qual número
  ela está no momento. O Caso Base será quando esse contador ultrapassar o número N.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Biblioteca necessária para medir o tempo

// ==========================================
// 1. SOLUÇÃO ITERATIVA (COM LAÇO FOR)
// ==========================================
int divisores_iterativo(int n) {
    int contagem = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            contagem++;
        }
    }
    return contagem;
}

// ==========================================
// 2. SOLUÇÃO RECURSIVA
// ==========================================
// Precisamos passar o 'i' iniciando em 1 para a função saber onde começar
int divisores_recursivo(int n, int i) {
    
    // CASO BASE: Se o divisor testado for maior que o número, pare e retorne 0
    if (i > n) {
        return 0;
    }
    
    // PASSO RECURSIVO: Se a divisão for exata, soma 1 e chama o próximo número
    if (n % i == 0) {
        return 1 + divisores_recursivo(n, i + 1);
    } 
    // Se não for exata, soma 0 e chama o próximo número
    else {
        return 0 + divisores_recursivo(n, i + 1);
    }
}

// ==========================================
// PROGRAMA PRINCIPAL E COMPARAÇÃO DE TEMPO
// ==========================================
int main() {
    // Usamos um número razoavelmente grande para podermos notar a diferença de tempo
    int numero = 30000; 
    int resultado;
    
    // Variáveis para guardar os tempos do relógio do processador
    clock_t inicio, fim;
    double tempo_gasto;

    printf("--- Testando Divisores do numero %d ---\n\n", numero);

    // --- TESTE 1: ITERATIVO ---
    inicio = clock(); // Dispara o cronômetro
    resultado = divisores_iterativo(numero);
    fim = clock();    // Para o cronômetro
    
    // Calcula o tempo em segundos
    tempo_gasto = ((double) (fim - inicio)) / CLOCKS_PER_SEC; 
    
    printf("1. METODO ITERATIVO:\n");
    printf("Resultado: %d divisores\n", resultado);
    printf("Tempo Gasto: %f segundos\n\n", tempo_gasto);


    // --- TESTE 2: RECURSIVO ---
    inicio = clock(); 
    resultado = divisores_recursivo(numero, 1); // Passamos 1 como o divisor inicial
    fim = clock();    
    
    tempo_gasto = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    
    printf("2. METODO RECURSIVO:\n");
    printf("Resultado: %d divisores\n", resultado);
    printf("Tempo Gasto: %f segundos\n\n", tempo_gasto);

    system("pause");
    return 0;
}

/*
b) Comparação do tempo gasto na execução (A Resposta Teórica)
Quando você rodar esse código no seu computador, notará duas coisas muito importantes
 que você deve colocar na sua resposta para o professor:

O Iterativo é sempre mais rápido: O método com o laço de repetição (for ou while)
 ganhará a corrida. Isso acontece porque a recursividade exige muito mais processamento
  do computador (ele precisa ficar criando e empilhando os "pratos" na memória RAM a 
  cada chamada da função). O laço for faz a conta direto no processador, 
  sem usar a pilha de memória.

O Risco de Estouro de Pilha (Stack Overflow): Lembra da sua dúvida no exercício
 anterior? Experimente mudar a variável numero de 30000 para 100000 e rode o código.
  O programa provavelmente vai travar (dar crash)! Como a nossa função recursiva 
  precisa testar número por número, ela tentará abrir 100 mil funções simultâneas
   na memória. A Pilha do Windows não aguenta esse tamanho e estoura. O método
    iterativo, por outro lado, rodaria tranquilamente até bilhões sem travar.
*/

