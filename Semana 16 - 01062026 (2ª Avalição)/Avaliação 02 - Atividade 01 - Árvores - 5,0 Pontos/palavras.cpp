#include <stdio.h>
#include <stdlib.h>
#include <string.h>
main() {
char linha[1024];
char * ultima;
FILE *txt;
if((txt = fopen("texto.txt","r")) == NULL)
 {
 printf("Erro ao abrir arquivo");
 }
else {
 while (!feof(txt)) {
 fgets(linha, 1024, txt);
 ultima = strtok (linha, " ");
while (ultima != NULL)
 {
 printf ("\n%s ",ultima);
 ultima = strtok (NULL, " ");
 }
 }
 fclose(txt);}
system("pause"); }
