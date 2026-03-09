/*

Submeta no FÓRUM as evidencias dos Programas (Prints dos Resultados) e os códigos fontes.
(arquivos CPP). 

Considerando o arquivo cidades.txt, formado por três colunas
(Nome da cidade, População e UF), gere um programa que leia o arquivo e mostre o conteúdo na tela.

Não se esqueça, submeta no FÓRUM as evidencias dos Programas
(Prints dos Resultados) e os códigos fontes. (arquivos CPP). 

*/

#include <stdio.h>
#include <stdlib.h> //para usar system("pause")

int main() {
    
    char nomeCidade[50]; //guarda nome das cidades
    int populacao;
    char estadoBr[3]; //sigla 2 + /0
    
    FILE *arquivo; //ponteiro para programa char o arquivo
    
    if ((arquivo = fopen("cidades.txt", "r")) == NULL) {  //tenta abrir para leirura, de der errado retona NULL
        printf("Erro de leitura. Arquivo não encontrado na pasta do programa");
    
    } else {
        while(!feof(arquivo)) { //leitura do arquivo linha por linha até o fim (feof)
            if (fscanf(arquivo, "%s %d %s",
                        nomeCidade, &populacao, estadoBr) == 3) { //só imprime se ler 3 colunas
                printf("Nome da Cidade: %-15s | Habitantes: %-10d | Estado do Brasil: %s\n", nomeCidade, populacao, estadoBr);}
        }    
        fclose(arquivo); //fecha arquivo para liberar memória
    }
    
    printf("\n");
    
    system("pause"); //pausa tela do terminal para ler
    
    return 0;
}