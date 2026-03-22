#include <stdio.h>
#include <time.h>
#include <unistd.h> 
#include <stdlib.h>

int main() {

    // Inicialização do Vetor
    FILE *txt;
    txt = fopen("Arquivo.txt", "r");
    
    if (txt == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return 1;
    }
    
    float v[100000], n = 100000;
    float aux;
    int j = 0;
    long int i = 0;
    
    // Ler os dados do arquivo
    for(i = 0; i < n; i++) {
        fscanf(txt, "%f", &v[i]);
    }
    fclose(txt);
    
    // Algoritmo de Ordenação BubbleSort - CRESCENTE
    while (j < n) {
        for(i = 0; i < n-1; i++) {
            if(v[i] > v[i + 1]) {
                aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
            }
        }
        j++;
    }
    
    printf("\nImprimindo Vetor ordenado\n");
    
    txt = fopen("Arquivo_ordenado.txt", "w");
    
    // Laço de impressão do Vetor
    for (i = 0; i < n; i++) {
        fprintf(txt, "%.0f\n", v[i]);
    }
    fclose(txt);
    
    printf("Arquivo ordenado criado com sucesso!\n");
    
    return 0;
}
