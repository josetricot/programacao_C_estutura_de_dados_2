/*Considerando o algoritmo abaixo e analisando o seu comportamento, qual será o conteúdo do arquivo Arquivo.txt no final da execução?


main(){
int i;
unsigned int ex;


 FILE *txt;


 ex = ((unsigned) time(NULL)) ; 
 
 srand(ex) ; 
 
 i = 0;
    while(i < 100)
    {
      txt=fopen("Arquivo.txt", "w");
   float c = rand() % 100;
   fprintf(txt, "%d - Execução - %d\n",i, i+1);
      ++i;
   fclose(txt);
    }
}

*/

//Arquivo é aberto com "w", conteúdo anterior é apagado (se existia), escreve a linha 0 - Execução - 1 , fecha
//faz isso até o final na i=99, apagando tudo e no fim vai escrever só a última linha, 99 - Execução - 100

//correto

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i;
    unsigned int ex;
    FILE *txt;
    
    ex = (unsigned) time(NULL);
    srand(ex);
    
    txt = fopen("Arquivo.txt", "w");  // abre uma vez só
    
    for (i = 0; i < 100; i++) {
        float c = rand() % 100;  // ainda não usada
        fprintf(txt, "%d - Execução - %d\n", i, i + 1);
    }
    
    fclose(txt);
    return 0;
}
