/*

Submeta no FÓRUM as evidencias dos Programas (Prints dos Resultados) e os códigos fontes.
(arquivos CPP). 

Considerando o Exemplo05.cpp, altere o programa que modo que para cada parágrafo ao 
arquivo seja impresso uma linha em branco. 

Não se esqueça, submeta no FÓRUM as evidencias dos Programas
(Prints dos Resultados) e os códigos fontes. (arquivos CPP). 

*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    
    char linha[1024]; //vetor para linha inteira
    
    FILE *arquivo; //ponteiro para fazer ponte com arquivo
    
    //tenta abrir o arquivo de texto para leitura "r"
    if ((arquivo = fopen("texto_tecnologia.txt", "r")) == NULL) {
        printf("Erro ao abir arquivo.\n");
    
    } else {
        
        printf("***Lendo o Arquivo***\n\n");
        
        while(!feof(arquivo)) { //continua lendo até o final do arquivo
                
            if (fgets(linha, 1024, arquivo) != NULL) { //fgets lê linha di arquivo e joga na
                                                    //variável 'linha'
                                                    //!= NULL só imprime se conseguir ler
                printf("%s\n", linha); //'\n' insere linha após parágrafo
            }  
        }        
    
        fclose(arquivo); //terminou de ler o arquivo todo, fecha pra liberar memória
    }
    
    system("pause"); //pausa tela para ver texto inteiro
    
    return 0;
}