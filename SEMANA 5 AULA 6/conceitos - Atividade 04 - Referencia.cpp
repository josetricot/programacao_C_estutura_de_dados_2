/*O que imprime o programa a seguir? (Faça uma análise antes de executar). 

void func(int aa, int bb)
{
int temp;
temp = aa;
aa = bb;
bb = temp;
}

int  main()
{
int a = 10, b = 20;
func(a, b);
printf("a = %d, b = %d", a, b);
}

O que deve ser alterado para realmente realizar a troca de valores? (apresente um código de exemplo). */

void func(int aa, int bb) {
    int temp;
    temp = aa;   // temp recebe o valor de aa
    aa = bb;     // aa recebe o valor de bb
    bb = temp;   // bb recebe o valor antigo de aa (guardado em temp)
}

/*
Na chamada:
O valor de a (10) é copiado para o parâmetro aa
O valor de b (20) é copiado para o parâmetro bb
Dentro de func, aa e bb são trocados entre si:
aa passa a ser 20
bb passa a ser 10
*/

int main() {
    int a = 10, b = 20;
    func(a, b);
    printf("a = %d, b = %d", a, b); //saída: a = 10, b = 20
}

/*Não ocorre troca porque a passagem de parâmetros em C é por valor (cópia).
A função troca as cópias, mas as originais a e b não são alteradas.*/

/*O que deve ser alterado?
Passar os endereços de a e b para a função e usar ponteiros nos parâmetros para modificar diretamente as variáveis originais*/

#include <stdio.h>

void func(int *aa, int *bb) {
    int temp;
    temp = *aa;    // temp recebe o valor apontado por aa
    *aa = *bb;     // o valor apontado por aa recebe o valor apontado por bb
    *bb = temp;    // o valor apontado por bb recebe temp
}

int main() {
    int a = 10, b = 20;
    func(&a, &b);  // passando os endereços de a e b
    printf("a = %d, b = %d", a, b); //saída a = 20, b = 10
    return 0;
}

