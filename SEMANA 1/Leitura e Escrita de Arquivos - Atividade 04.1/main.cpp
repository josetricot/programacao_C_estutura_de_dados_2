/*

Submeta no FÓRUM as evidencias dos Programas (Prints dos Resultados) e os códigos fontes.
(arquivos CPP). 

Considerando o Exemplo03.cpp, altere o programa que nodo de leia dez (10) nomes de pessoas e suas respectivas idades e grave em um arquivo chamado lista.txt. 

Não se esqueça, submeta no FÓRUM as evidencias dos Programas
(Prints dos Resultados) e os códigos fontes. (arquivos CPP). 

*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    
    char nome[50]; //guarda nome até 49 letras
    int idade; //guarda idade
    int i; //var contadora para laço de repetição
    
    FILE *arquivo; //ponteiro para criar e manipular o arquivo
    
    //tenta criar (ou abrir para sobrescrever) o arquivo lista.txt usando o modo w (write)
    if ((arquivo = fopen("lista.txt", "w")) == NULL) {
        printf("Erro ao criar o arquivo!\n");
    
    } else {
        printf("***Cadastro de Pessoas***\n\n");
        
        i = 0;
        
        while(i < 2) {
            printf("***Cadastro %d de 10***\n", i + 1);
            
            printf("Digite o nome: ");
            scanf(" %[^\n]", nome);
            // %[^\n] é um truque do scanf para ler nomes com espaços
            // oespaço antes do % limpa o 'enter' da leitura anterior da idade
            
            printf("Digite a idade: ");
            scanf("%d", &idade);
            
            fprintf(arquivo, "%s %d\n", nome, idade);
            // gavanado arquivo: funciona igual ao printf, mas manda o texto para o arquivo
            // O \n no final é para pular a linha no arquivo de texto
            
            printf("Gravado com sucesso!\n\n");
            
            i++; //aumenta contatador para próxima pessoa
        }    
            
            fclose(arquivo); //fecha arquivo para salvar no disco
            
        printf("Todos os 10 cadastros foram salvos no arquivo 'lista.txt'.\n\n");
    }
    
    system("pause"); //pausa tela para ver mensagem final
    
    return 0;
}