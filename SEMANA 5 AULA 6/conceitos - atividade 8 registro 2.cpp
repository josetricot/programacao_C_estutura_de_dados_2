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
    
    // atribuindo valores sem ponteiro
    strcpy(algumacoisa.descricao, "Monitor Ultrawide");
    algumacoisa.preco = 1899.90;
    
    // mostra valores
    printf("Descricao: %s\n", algumacoisa.descricao);
    printf("Preco: R$ %.2f\n", algumacoisa.preco);
       
    return 0;
}
