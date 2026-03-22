#include <stdio.h>
#include <time.h>
#include <unistd.h> 
#include <stdlib.h>

int main() {
    // Inicialização do Vetor - Lê o arquivo ORDENADO CRESCENTE
    FILE *txt;
    txt = fopen("Arquivo_ordenado.txt", "r");  // Lê o arquivo gerado pelo programa 1
    
    if (txt == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }
    
    float v[100000], n = 100000;
    long int i, j;
    float chave;
    
    // Lê os dados do arquivo
    for(i = 0; i < n; i++) {
        fscanf(txt, "%f", &v[i]);
    }
    fclose(txt);
    
    // Algoritmo de Ordenação Insertion Sort - DECRESCENTE
    for(j = 1; j < n; j++) {
        chave = v[j];
        i = j - 1;
        while(i >= 0 && v[i] < chave) {  // DECRESCENTE: v[i] < chave
            v[i + 1] = v[i];
            i--;
        }
        v[i + 1] = chave;
    }
    
    printf("\nImprimindo Vetor ordenado decrescentemente\n");
    
    // Abre arquivo para escrita - GERA Arquivo_ordenado_decrescente.txt
    txt = fopen("Arquivo_ordenado_decrescente.txt", "w");
    
    // Laço de impressão do Vetor
    for(i = 0; i < n; i++) {
        fprintf(txt, "%.0f\n", v[i]);
    }
    fclose(txt);
    
    printf("Arquivo 'Arquivo_ordenado_decrescente.txt' criado com sucesso!\n");
    
    return 0;
}
