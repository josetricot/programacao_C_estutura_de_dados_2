#include <stdio.h>
#include <time.h>
#include <unistd.h> 
#include <stdlib.h>

main () {
 //Inicialização do Vetor
    int num[5]= {1,7,4,3,5}, tam=5;

//Algoritmo de Ordenação
  int i, j, min;
  for (i = 0; i < (tam-1); i++) {
    min = i;
    for (j = (i+1); j < tam; j++) {
      if(num[j] < num[min]) {
        min = j;
      }}
    if (i != min) {
      int swap = num[i];
      num[i] = num[min];
      num[min] = swap;}}
	
//Laço de impressão do Vetor
for (int q=0; q<5; q++)
{
        printf("%d \n",num[q]);    }
}

