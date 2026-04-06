/*Do mesmo modo que dizemos que o endereço da variável x é E2, podemos dizer que o endereço do array a é E100. Isto é, o endereço do array é o endereço do primeiro byte que o array ocupa.


De fato, quando declararmos:

int a[10];

int a[10];      

int *p;      

p = a;      

*p = 10;   é equivalente:   (Faça um exemplo e publique o código)

a) a[0] = 10 ; 
b) *a[0] = 10;
c) a= 10;
d) &a = 10;
e) NDA
*/


#include <stdio.h>

int main() {
    int a[10];
    int *p;
    
    p = a;        // p aponta para a[0]
    *p = 7;      // mesmo que a[0] = 7
    
    printf("a[0] = %d\n", a[0]);   // saída: a[0] = 7
    
    return 0;
}

