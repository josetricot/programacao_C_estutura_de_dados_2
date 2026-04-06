/*
Considerando a estrutura Cproduto, como é possível armazenar os valores (fazer o usuário digitar o nome) e mostrar o que o usuário digitou, usando somente a estrutura já disponibilizada? (Faça um exemplo atribuindo valores e mostrando os valores atribuídos). 

typedef struct Cproduto
{

        char descricao[20];
        float preco;
} ;

int main(void)
{


    Cproduto *palgumacoisa; 
...

}
*/
// temos apenas um ponteiro para Cproduto, mas ele ainda não aponta para nenhuma área de memória válida
// precisa Alocar memória para ele (usando malloc)
// usar fgets para ler a string do usuário (mais seguro que scanf para char[])
// usar scanf para ler o float do preço
// mostrar os valores armazenados

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Cproduto {
    char descricao[20];
    float preco;
} Cproduto;

int main(void) {
    Cproduto *palgumacoisa;
    
    // Aloca memória para uma estrutura Cproduto
    palgumacoisa = (Cproduto *) malloc(sizeof(Cproduto));
    
    if (palgumacoisa == NULL) {
        printf("Erro de alocacao de memoria!\n");
        return 1;
    }
    
    // --- Lendo os valores do usuário ---
    printf("Digite a descricao do produto: ");
    fgets(palgumacoisa->descricao, 20, stdin);
    
    // Remove o '\n' que o fgets captura no final
    size_t len = strlen(palgumacoisa->descricao);
    if (len > 0 && palgumacoisa->descricao[len-1] == '\n') {
        palgumacoisa->descricao[len-1] = '\0';
    }
    
    printf("Digite o preco do produto: ");
    scanf("%f", &palgumacoisa->preco);
    
    // --- Mostrando os valores digitados ---
    printf("\n--- Produto cadastrado ---\n");
    printf("Descricao: %s\n", palgumacoisa->descricao);
    printf("Preco: R$ %.2f\n", palgumacoisa->preco);
    
    // Libera a memória alocada
    free(palgumacoisa);
    
    return 0;
}
