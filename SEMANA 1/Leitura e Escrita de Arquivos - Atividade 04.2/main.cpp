/*

Submeta no FÓRUM as evidencias dos Programas (Prints dos Resultados) e os códigos fontes.
(arquivos CPP). 

Considerando o Exemplo04.cpp, altere o Programa que modo que ao mostrar o conteúdo do Arquivo,
coloque todas as vogais em Maiúsculas na tela e em uma novo arquivo, chamado Texto_Alterado.txt

Não se esqueça, submeta no FÓRUM as evidencias dos Programas
(Prints dos Resultados) e os códigos fontes. (arquivos CPP). 

*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    
    char caractere; // para guardar um letra por vez
    
    FILE *arquivoEntrada; //ponteiro para arquivo de leitura
    FILE *arquivoSaida; //ponteiro par o novo
    
    //tenta abrir o original para leitura "r"
    if ((arquivoEntrada = fopen("arquivo.txt", "r")) == NULL) {
        printf("Erro ao abir arquivo de entrada.\n");
    
    } else {
        //se abriu o arquivo de entrada tenta criar um novo para gravação ("w")
        if ((arquivoSaida = fopen("Texto_Alterado.txt", "w")) == NULL) {
            printf("Erro ao criar arquivo de saida.\n");
        
        } else {
            printf("***Conteúdo Alterado***\n\n");

            while(!feof(arquivoEntrada)) { //inicia laço até o final do arquivo de entrada
                
                caractere = fgetc(arquivoEntrada); //lê letra e avança para próxima
                
                if (caractere != EOF) { //previne impressão do caractere de fim de arquivo (OEF)
                                    //na última rodada do laço
               
                    if (caractere == 'a') caractere = 'A';
                    else if (caractere == 'e') caractere = 'E';
                    else if (caractere == 'i') caractere = 'I';
                    else if (caractere == 'o') caractere = 'O';
                    else if (caractere == 'u') caractere = 'U';
                
                    printf ("%c", caractere); //mostra o caractere (alterado ou original) na tela
            
                    fputc(caractere, arquivoSaida); //grava esse caractere no novo arquivo
                                                    //fputc funciona como fgtec, mas grava um por vez
                }
            }    
            
            fclose(arquivoSaida); //fecha arquivo para salvar no disco
        }        
    
        fclose(arquivoEntrada); //terminou de ler fecha o arquivo de entrada
        
        printf("\n\n*****************************************\n");
        printf("Alterações salvas com sucesso no arquivo 'Texto_Alterado.txt'.\n");
    }
    
    system("pause"); //pausa tela para ver reultado final
    
    return 0;
}