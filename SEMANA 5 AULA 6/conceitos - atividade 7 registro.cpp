#include <stdio.h>
#include <string.h>

typedef struct Cproduto {
    char descricao[20];
    float preco;
} Cproduto;

int main(void) {
    Cproduto algumacoisa;
    Cproduto *palgumacoisa;
    
    palgumacoisa = &algumacoisa;
    
    // atribuindo valores com ponteiro
    strcpy(palgumacoisa->descricao, "Monitor Ultrawide");
    palgumacoisa->preco = 1899.90;
    
    // mostra valores
    printf("Descricao: %s\n", palgumacoisa->descricao);
    printf("Preco: R$ %.2f\n", palgumacoisa->preco);
    
    // outro forma
    printf("Descricao: %s\n", (*palgumacoisa).descricao);
    printf("Preco: R$ %.2f\n", (*palgumacoisa).preco);
    
    return 0;
}
