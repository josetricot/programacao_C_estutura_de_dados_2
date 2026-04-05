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

int main() 
{ 
    int *vetor;
    int tamanho = 0;
    int i, Cont;
    FILE *arquivo;
    
    // Aloca memória
    vetor = (int *)malloc(MAX_TAMANHO * sizeof(int));
    
    if(vetor == NULL)
    {
        printf("Erro de memoria!\n");
        return 1;
    }
    
    // Abre o arquivo
    arquivo = fopen("dados.txt", "r");
    
    if(arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo dados.txt!\n");
        free(vetor);
        return 1;
    }
    
    // Carrega o vetor
    while(tamanho < MAX_TAMANHO && fscanf(arquivo, "%d", &vetor[tamanho]) != EOF)
    {
        tamanho++;
    }
    
    fclose(arquivo);
    
    printf("Arquivo carregado! %d registros lidos.\n\n", tamanho);
    
    // ===== TESTANDO OS 6 VALORES =====
    int valores[] = {7341488, 85, 265654, 732765, 8313596, 45744};
    int total_acessos = 0;
    
    printf("--- BUSCA SEQUENCIAL ---\n");
    
    for(int j = 0; j < 6; j++)
    {
        int x = valores[j];
        
        i = 0;
        Cont = 0;
        
        // Mesmo while do seu exemplo
        while (i < tamanho && vetor[i] != x && vetor[i] <= x) 
        {
            Cont++;
            i++;
        }
        
        Cont++; // última comparação
        
        total_acessos += Cont;
        
        if (vetor[i] == x)
            printf("Valor %d: ENCONTRADO (acessos: %d)\n", x, Cont);
        else
            printf("Valor %d: NAO ENCONTRADO (acessos: %d)\n", x, Cont);
    }
    
    printf("\nTotal de acessos: %d\n", total_acessos);
    
    free(vetor);
    system("pause");
    return 0;
}
