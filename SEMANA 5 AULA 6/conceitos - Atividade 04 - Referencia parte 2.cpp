/* O que imprime o programa a seguir?
void func(int *aa, int *bb)
{
int temp;
temp = *aa;
*aa = *bb;
*bb = temp;
}

int  main()
{
int a = 10, b = 20;
func(&a, &b);
printf("a = %d, b = %d", b, a);
} */

#include <stdio.h>
#include <stdlib.h>

void func(int *aa, int *bb) {
    int temp;
    temp = *aa;   // temp recebe o valor apontado por aa
    *aa = *bb;    // o valor apontado por aa recebe o valor apontado por bb
    *bb = temp;   // o valor apontado por bb recebe temp
}

int main() {
    int a = 10, b = 20;
    func(&a, &b);      // passa os endereços de a e b
    printf("a = %d, b = %d", b, a); //imprime a = 10 e b = 20
    //apesar de a valer 20 e b valer 10 na memória, o printf imprime na ordem inversa (primeiro b, depois a)
}
