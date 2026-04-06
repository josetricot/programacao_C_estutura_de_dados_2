/*

Considerando o programa abaixo, qual será o valor de I no final do programa?

#include <stdlib.h>
#include <stdio.h>

void somaUm(int &x)
{
  x++;
}

main()
{
  int i=0;
  while (i<10)
  {
    somaUm(i);
  }
  printf("valor de i : %d \n",i);
}

*/

#include <stdlib.h>
#include <stdio.h>

void somaUm(int &x) //usa o símbolo & no parâmetro, é C++ (passagem por referência), em C puro, isso daria erro de compilação
//x é uma referência para um inteiro.
//modificar x dentro da função modifica diretamente a variável original passada na chamada
{
  x++; //incrementa a variável original
}

main()
{
  int i=0;
  while (i<10)
  {
    somaUm(i);
  }
  printf("valor de i : %d \n",i); //saída 10
}

//na primeira iteração: i = 0 , somaUm(i) dentro da função, x referencia i , x++ faz i passar de 0 para 1
//i agora é 1 , i < 10 , verdadeiro , chama somaUm(i) novamente
//Isso se repete até i chegar a 10
//Quando i = 10
//i < 10 é falso , sai do while

//i começa em 0, incrementa uma vez por iteração do loop
//O loop executa 10 vezes (para i = 0, 1, 2, ..., 9), cada vez incrementando i
//Ao final, i = 10

/* para fazer funcionar em c puro

void somaUm(int *x) {
    (*x)++;
}

// chamada: somaUm(&i);

*/
