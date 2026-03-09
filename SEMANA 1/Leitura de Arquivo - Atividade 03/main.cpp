/*

Submeta no FÓRUM as evidencias dos Programas (Prints dos Resultados) e os códigos fontes.
(arquivos CPP). 

Considerando o arquivo nomes.txt, composto por duas colunas (Nome e Idade), desenvolva um programa que leia o arquivo e exiba seu conteúdo na tela.

Atenção: a coluna Nome possui 22 caracteres. Ajuste o programa para ler corretamente essa coluna de 22 caracteres seguida da idade. Neste momento, evite utilizar inteligência artificial para gerar o código (você pode, no entanto, usar a IA para entender como ler uma coluna com 20 caracteres).

Todas as informações necessárias estão disponíveis no arquivo exemplo01.

Não se esqueça, submeta no FÓRUM as evidencias dos Programas
(Prints dos Resultados) e os códigos fontes. (arquivos CPP). 

*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    
    //nome possui 21 carateres de largura (nome+espaços)
    //coloquei 22 espaço na memória, 21 de texto + 1 para fechamento fechamento da string ('\0').
    char nome[22];
    int idade;
    
    FILE *arquivo; //ponteiro para programa char o arquivo
    
    if ((arquivo = fopen("nomes.txt", "r")) == NULL) {  //tenta abrir para leirura, de der errado retona NULL
        printf("Erro de leitura. Arquivo não encontrado na pasta do programa");
    
    } else {
        printf("***Lista de Nomes e Idades***\n");
        
        while(!feof(arquivo)) { //leitura do arquivo linha por linha até o fim (feof)
        // %21c vai ler exatamente 21 caracteres (pegando o nome inteiro e os espaços)
        // %d vai ler a idade logo em seguida
        // o espaço no final " " consome a quebra de linha (\n), igual no exemplo01
            if (fscanf(arquivo, "%21c %d ", nome, &idade) == 2) {
                nome[21] = '\0'; //quando usa %c no lugar de %s o C não colocar \0 no final automaticamente
                                 //precisa colocar no final manualmente na última posição para não imprimir lixo
                printf("Nome: %-21s | Idade: %d\n", nome, idade);
            }   
        }    
            
            fclose(arquivo); //fecha arquivo para liberar memória
    }
    
    printf("\n");
    system("pause"); //pausa tela do terminal para ler
    
    return 0;
}