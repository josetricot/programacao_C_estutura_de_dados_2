/* Atividade da Semana 02 - Lendo Aquivos de Texto - Atividade 02

Faça um programa em C que leia o arquivo "dados.txt" (Código, Produto, Preço e Quantidade) e mostre os dados na tela. */

#include <stdio.h>  // Biblioteca padrão para entrada e saída (printf, fopen, fgets)
#include <stdlib.h> // Biblioteca para usar o comando system("pause")

int main() {
    
    // vetor para guardar uma linha inteira do arquivo
    // 256 posições pois as linhas do "dados.txt" são bem longas
    char linha[256]; 

    FILE *arquivo; // ponteiro para fazer a ponte de comunicação com o arquivo no disco

    // tenta abrir o arquivo "dados.txt" para leitura "r" 
    if ((arquivo = fopen("dados.txt", "r")) == NULL) {
        
        printf("Erro ao abrir arquivo. Verifique se o dados.txt esta na pasta correta.\n");
        
    } else {
        
        printf("--- Relatorio de Produtos ---\n\n");
        
        // a função fgets continua puxando linhas até chegar ao fim do arquivo onde retorna NULL
        // parâmetros do fgets: variável de destino, tamanho máximo da leitura, ponteiro do arquivo
        while (fgets(linha, sizeof(linha), arquivo) != NULL) {
            
            // fgets lê a linha inteira com todos os espaços e já inclui o "Enter" (\n) original do texto
            // printf imprime a string lida diretamente na tela
            printf("%s", linha);
            
        }
        
        // terminou de ler o arquivo todo fecha para liberar a memória
        fclose(arquivo);
    }

    printf("\n\n------------------------------------\n");
    
    // pausa a tela do terminal
	system("pause"); 
    
    return 0;
}

/*
"pegadinha" sobre a estrutura do arquivo dados.txt que define qual função da linguagem C deve se utilizar
no arquivo dados.txt a coluna "Produto" contém textos longos e com muitos espaços em branco
utilizando o fscanf com o %s (Exemplo 01 da aula 1) o programa para a leitura quando encontra o primeiro espaço em branco da palavra "SONY" quebrando toda a leitura do preço e da quantidade
para arquivos de texto com espaços (Exemplo 05) melhor usar fgets()
lê a linha inteira de uma vez só respeitando os espaços e o alinhamento original do bloco de notas
*/
