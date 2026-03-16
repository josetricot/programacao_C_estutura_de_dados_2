/*Busca Sequencial x Busca Binária (Conteúdo EAD)

Considerando o arquivo DADOS.TXT, cujo conteúdo está ordenado, altere os códigos de
 busca sequencial e busca binária para carregar o conteúdo do arquivo ASCII para um vetor. 

Logo após o carregamento, faça a contagem de acessos necessários para localizar os
 seguintes valores:
 7341488
 85
 265654
732765
8313596
45744

Considerando todos as pesquisas, quantas acessos (no total) cada método de busca teve?
Qual foi o ganho de desempenho do algoritmo mais eficiente em relação ao algoritmo menos
 eficiente?
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_TAMANHO 2000000 

// busca sequencial (otimizada para vetores ordenados)
int BuscaSequencial(int vetor[], int tamanho, int x, int &acessos) {
    acessos = 0;
    for (int i = 0; i < tamanho; i++) {
        acessos++; 
        if (vetor[i] == x) {
            return i; 
        }
        if (vetor[i] > x) {
            return -1; 
        }
    }
    return -1;
}

int main() {
    // usando alocação dinâmica (pede memória segura ao sistema)
    int *vetor = (int *) malloc(MAX_TAMANHO * sizeof(int));
    
    // verifica se o computador conseguiu liberar a memória
    if (vetor == NULL) {
        printf("Erro fatal: Memoria RAM insuficiente para carregar o arquivo!\n");
        return 1;
    }

    int tamanho = 0;
    
    FILE *arquivo = fopen("dados.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo dados.txt! Verifique se esta na mesma pasta.\n");
        free(vetor); // libera a memória antes de fechar
        return 1;
    }
    
    // trava de segurança (lê até o fim do arquivo, desde que não passe de 2 milhões)
    while (tamanho < MAX_TAMANHO && fscanf(arquivo, "%d", &vetor[tamanho]) != EOF) {
        tamanho++;
    }
    fclose(arquivo);
    
    printf("Arquivo carregado com sucesso! Total de registros lidos: %d\n\n", tamanho);
    
    // realiza buscas
    int valores[] = {7341488, 85, 265654, 732765, 8313596, 45744};
    int qtd_valores = 6;
    
    int total_acessos_seq = 0;
    
    printf("---------------- RESULTADOS DA BUSCA SEQUENCIAL ----------------\n");
    
    for (int i = 0; i < qtd_valores; i++) {
        int alvo = valores[i];
        int acessos_seq = 0;
        
        BuscaSequencial(vetor, tamanho, alvo, acessos_seq);
        
        total_acessos_seq += acessos_seq;
        
        printf("Valor: %-8d | Acessos Seq: %-7d\n", alvo, acessos_seq);
    }
    
    // relatório final
    printf("\n------------------- RESUMO GERAL --------------------\n");
    printf("Total de Acessos (Sequencial): %d\n\n", total_acessos_seq);
    
    // devolve memória para o sistema
    free(vetor);
    
    system("pause");
    return 0;
}
