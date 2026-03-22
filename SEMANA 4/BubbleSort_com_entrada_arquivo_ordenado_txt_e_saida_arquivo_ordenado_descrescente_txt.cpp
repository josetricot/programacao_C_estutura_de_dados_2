#include <stdio.h>
#include <time.h>
#include <unistd.h> 
#include <stdlib.h>

int main() {

	//Inicializaçã do Vetor
	FILE *txt;
	txt = fopen("Arquivo_ordenado.txt", "r");

	// Verifica se o arquivo foi aberto corretamente
    if (txt == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }
    
    float v[100000], n = 100000;
    float aux;
    long int i = 0;
    
    // Lê os dados do arquivo
    for(i = 0; i < n; i++) {
        fscanf(txt, "%f", &v[i]);
    }
    fclose(txt);

    // Algoritmo de Ordenação BubbleSort - DECRESCENTE
    int j = 0;
    while (j < n) {
        for(i = 0; i < n-1; i++) {
            // Para ordem decrescente: troca quando o anterior é MENOR que o próximo
            if(v[i] < v[i + 1]) {  // Alterado de > para <
                aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
            }
        }
        j++;
    }
    
    printf("\nImprimindo Vetor ordenado decrescente\n");
    
    // Abre arquivo para escrita
    txt = fopen("Arquivo_ordenado_decrescente.txt", "w");
    
    // Laço de impressão do Vetor
    for (i = 0; i < n; i++) {
        fprintf(txt, "%.0f\n", v[i]);
    }
    fclose(txt);
    
    printf("Arquivo 'Arquivo_ordenado_decrescente.txt' criado com sucesso!\n");
    
    return 0;
}
