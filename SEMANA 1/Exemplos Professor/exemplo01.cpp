#include <stdio.h>
#include <stdlib.h>

main()
{
int codigo;
char empresa[10]; 
char sobre[12]; 
char nome[10]; 
char funcao[10]; 

FILE *txt;

if((txt = fopen("arquivo_colunas.txt","r")) == NULL)
    {
        printf("Erro ao abrir arquivo");
    }
 else
     {
        while (!feof(txt)) {
               fscanf(txt, "%d %s %s %s %s ", &codigo, empresa, sobre, nome, funcao);
               printf("%d \t %-10s %-12s %-10s %-10s \n", codigo, empresa, sobre, nome, funcao);
              }
          fclose(txt);
      }
system("pause"); 
}


    
