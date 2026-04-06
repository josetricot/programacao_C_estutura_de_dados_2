/*
onsiderando o programa abaixo, responda:


#include <stdio.h>
#include <stdlib.h>
main (void)
{
int *p, a, *i;
i=&a; 
p=&a;
a = 30;
p=(int *)malloc(a*sizeof(int));
if (!p)
{
printf ("** Erro: Memoria Insuficiente **");
exit (1);
}
}


Quantos bytes ocupam o ponteiro p?

Qual é resultado de impressão de *(i) no final do programa?

(Justifique a resposta, apresentando a execução com os valores). 
*/

#include <stdio.h>
#include <stdlib.h>

main (void)
{
    int *p, a, *i;      // p é ponteiro para int, a é int, i é ponteiro para int
    i = &a;             // i aponta para a
    p = &a;             // p aponta para a
    a = 30;             // a recebe 30 (tanto i quanto p apontam para a, que agora vale 30)
    
    p = (int *) malloc(a * sizeof(int));
   // malloc(30 * 4) = malloc(120 bytes) (em sistemas com int=4 bytes, 32 bits)
    
    // se malloc falhou (p == NULL)
	if (!p) {
        printf("** Erro: Memoria Insuficiente **");
        exit(1);
    }
    
    printf("*(i) = %d\n", *i);  // Imprime 30
    printf("Tamanho do ponteiro p: %lu bytes\n", sizeof(p));
    
    return 0;
}

/*Quantos bytes ocupam o ponteiro p?

Em sistemas 32 bits: 4 bytes

Em sistemas 64 bits: 8 bytes

Qual é resultado de impressão de (i) no final do programa?

O programa não imprime nada (não há printf), mas o valor de *(i) é 30.*/
