#include <stdio.h>
#include <stdlib.h>

main()
{
char linha[1024]; 

FILE *txt;

if((txt = fopen("arquivo_texto.txt","r")) == NULL)
    {
        printf("Erro ao abrir arquivo");
    }
 else
     {
        while (!feof(txt)) {
               fgets(linha, 1024, txt);
               printf("%s", linha);
               system("pause");
              }
          fclose(txt);
      }
system("pause"); 
}


