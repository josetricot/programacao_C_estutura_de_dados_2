#include <stdio.h>

main(){
int i;
FILE *txt;

if((txt = fopen("Arquivo.txt", "a+")) == NULL)    {
        printf("Erro ao abrir arquivo");
    }
 else {
         i = 50;
         while(i < 100)
         {
               fprintf(txt, "%d\n", i);
               ++i;
          }
		fclose(txt);
      }
}

