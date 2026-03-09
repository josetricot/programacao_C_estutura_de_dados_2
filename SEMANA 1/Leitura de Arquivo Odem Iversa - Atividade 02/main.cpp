/*

Submeta no FÓRUM as evidencias dos Programas (Prints dos Resultados) e os códigos fontes.
(arquivos CPP). 

Considerando o arquivo cidades.txt, formado por três colunas (Nome da cidade, População e UF), gere um programa que leia o arquivo e mostre o conteúdo na tela.
Mostre o conteúdo do Arquivo na ordem inversa a leitura do arquivo (mostrar do final para o inicio). 

Não se esqueça, submeta no FÓRUM as evidencias dos Programas
(Prints dos Resultados) e os códigos fontes. (arquivos CPP). 

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct { //cria o molde para agrupar 3 informações
    char nomeCidade[50];
    int populacao;
    char estadoBr[3];
} Cidade; //apelida mode de "Cidade"

int main() {
    
    Cidade listaDeCidades[100]; //vetor para armazenar até 100 "Cidades" na memória
    int quantCidadesLidas = 0; //variável para contar cidades no arquivo
    
    FILE *arquivo; //ponteiro para programa char o arquivo
    
    if ((arquivo = fopen("cidades.txt", "r")) == NULL) {  //tenta abrir para leirura, de der errado retona NULL
        printf("Erro de leitura. Arquivo não encontrado na pasta do programa");
    
    } else {
        while(!feof(arquivo)) { //leitura do arquivo linha por linha até o fim (feof)
            if (fscanf(arquivo, "%s %d %s",
                listaDeCidades[quantCidadesLidas].nomeCidade,
                &listaDeCidades[quantCidadesLidas].populacao,
                listaDeCidades[quantCidadesLidas].estadoBr) == 3) {
                
                quantCidadesLidas++; //se leu 3 colunas aumenta contador
            }
        }    
        fclose(arquivo); //fecha arquivo para liberar memória
    
            printf("***Relatório de Cidades (Ordem Invesa)***\n");
        for (int i = quantCidadesLidas -1; i >= 0; i--) {
            printf("Nome da Cidade:  %-15s | Habitantes: %-10d | Estado do Brasil: %s\n",
                listaDeCidades[i].nomeCidade,
                listaDeCidades[i].populacao,
                listaDeCidades[i].estadoBr);
        }
    }
    
    printf("\n");
    system("pause"); //pausa tela do terminal para ler
    
    return 0;
}