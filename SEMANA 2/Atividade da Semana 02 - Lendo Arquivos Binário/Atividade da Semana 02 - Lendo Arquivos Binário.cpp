/* Atividade da Semana 02 - Lendo Arquivos Binário

Considerando que o arquivo "dados.dat" é formado pela estrutura abaixo:

*    char [35]
*    int 
*    float  

Leia o conteúdo do arquivo e apresente na tela.*/

#include <stdio.h>
#include <stdlib.h>

// criada estrutura
typedef struct {
    char nome[35];
    int codigo;
    float preco;
} Produto;

int main() {
    
    Produto item;  // Variável que vai guardar um produto por vez na memória
    FILE *arquivo; // Ponteiro para manipular o arquivo
    
    //tenta abrir o arquivo no modo "rb" read binary
    if ((arquivo = fopen("dados.dat", "rb")) == NULL) {
        
        printf("Erro ao abrir o arquivo dados.dat. Verifique se ele esta na mesma pasta.\n");
        
    } else {
        
        printf("--- Conteudo do Arquivo Binario ---\n\n");
        
        // lê o arquivo binário
        // fread(&variavel_destino, tamanho_do_bloco, quantidade_de_blocos, ponteiro_do_arquivo)
        // retorna '1' se conseguiu ler o bloco com sucesso. Quando chega no fim, retorna '0' e o laço para
        while (fread(&item, sizeof(Produto), 1, arquivo) == 1) {
            
            // imprime, %-35s alinha o espaço de 35 caracteres da Struct
            printf("Nome: %-35s | Codigo: %-6d | Valor: %.2f\n", item.nome, item.codigo, item.preco);
            
        }
        
        /*
        while (!feof(arquivo)) {
            
            // Tenta ler o bloco binário
            if (fread(&item, sizeof(Produto), 1, arquivo) == 1) {
                
                // só entra aqui e imprime se a leitura foi um sucesso
                // se ele bateu no final do arquivo o fread retorna 0 não entra no if
                // e na próxima volta o feof() encerra o laço
                printf("Nome: %-35s | Codigo: %-6d | Valor: %.2f\n", item.nome, item.codigo, item.preco);
            }
        }
        */
        
        // terminou de ler fecha o arquivo para liberar memória
        fclose(arquivo); 
    }
    
    printf("\n");
    system("pause"); // pausa a tela
    
    return 0;
}

/*Detalhes Importantes:
no fopen, se colocar apenas "r" o C tentará ler o arquivo como texto
isso quebraria os dados do int e do float, pois em binário eles não estão salvos como letras, mas sim como códigos computacionais

fread() == 1 vs feof()
no exemplo 07 da aula, o professor usou !feof()
porém usar o fread() == 1 direto no while é uma prática muito mais segura e profissional em C
evita o "bug fantasma" do C que lê o último item do arquivo duas vezes
*/
