#include <stdio.h>
#include <time.h>
#include <unistd.h> 
#include <stdlib.h>

main(){
int i;
unsigned int ex;

FILE *txt;

if((txt = fopen("arquivo.txt", "w")) == NULL)    {
        printf("Erro ao abrir arquivo");
    }
 else {
       
	  	//Definindo a Semente Inicial do Gerador Aleatório
		ex = ((unsigned) time(NULL)) ; 
		
		srand(ex) ; 
		
	     i = 0;
         while(i < 100000)
         {
               float c = rand() % 100000;
			   fprintf(txt, "%.0f\n",c);
               ++i;
          }
		fclose(txt);
      }
}

