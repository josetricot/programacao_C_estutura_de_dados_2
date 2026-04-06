/*

Qual é a alternativa Correta? Justifique e apresente um exemplo de código. 

Se você quiser usar o conteúdo do ponteiro *p 15 posições adiante, deverá escrever: 
a)    *(p+15); 
b)    *P[15]; 
c)    &p[15];
d)    (*p+15);
e)    NDA; 

*/

#include <stdio.h>

int main() {
    int vet[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17};
    int *p = vet;   // p aponta para arr[0] (conteúdo 0)
    
    // Quero vet[15]
    int valor = *(p + 15);
    
    printf("*(p+15) = %d\n", valor);   // saída: 15
    
    return 0;
}
