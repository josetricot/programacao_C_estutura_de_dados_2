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

// busca binária
int BuscaBinaria(int vetor[], int tamanho, int x, int &acessos) {
    int esquerda = 0;
    int direita = tamanho - 1;
    int meio;
    acessos = 0;

    while (esquerda <= direita) {
        acessos++; 
        meio = (esquerda + direita) / 2;
        
        if (vetor[meio] == x) {
            return meio; 
        } 
        else if (vetor[meio] < x) {
            esquerda = meio + 1; 
        } 
        else {
            direita = meio - 1;  
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
    
    int total_acessos_bin = 0;
    
    printf("---------------- RESULTADOS DA BUSCA BINÁRIA ----------------\n");
    
    for (int i = 0; i < qtd_valores; i++) {
        int alvo = valores[i];
        int acessos_bin = 0;
        
        BuscaBinaria(vetor, tamanho, alvo, acessos_bin);
        
        total_acessos_bin += acessos_bin;
        
        printf("Valor: %-8d | Acessos Bin: %-4d\n", alvo, acessos_bin);
    }
    
    // relatório final
    printf("\n------------------- RESUMO GERAL --------------------\n");
    printf("Total de Acessos (Binaria).. : %d\n\n", total_acessos_bin);
    
    // devolve memória para o sistema
    free(vetor);
    
    system("pause");
    return 0;
}
