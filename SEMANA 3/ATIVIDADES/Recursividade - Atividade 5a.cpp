/*
Recursividade - Atividade 05 (A)
Qual será a saída gerada das funções dos algoritmos abaixo, considerando o valor inicial
 de n=4:
a) func (int n)
   {
   if (n == 0)
     printf(“fim”);
   else
   {
    printf(n);
    func(n-1);
   }
  }
*/

/*
A "pegadinha" (ou o ponto de atenção) é verificar exatamente onde o printf está
 localizado em relação à chamada recursiva. Como o printf(n) vem antes de func(n - 1),
  o programa vai imprimir os números durante a descida da recursividade.

(Nota: O código no PDF usa printf(n) de forma simplificada, assumiremos que ele funciona
 como printf("%d", n) para imprimir o número na tela).

Vamos ao teste de mesa:

Teste de Mesa: func(4)
1ª Chamada: func(4)
n vale 4. O if (4 == 0) é Falso.
Executa printf(4);  TELA: 4
Chama func(3); e pausa.

2ª Chamada: func(3)
n vale 3. O if (3 == 0) é Falso.
Executa printf(3); TELA: 43
Chama func(2); e pausa.

3ª Chamada: func(2)
n vale 2. O if (2 == 0) é Falso.
Executa printf(2); TELA: 432
Chama func(1); e pausa.

4ª Chamada: func(1)
n vale 1. O if (1 == 0) é Falso.
Executa printf(1); TELA: 4321
Chama func(0); e pausa.

5ª Chamada: func(0)
n vale 0. O if (0 == 0) é Verdadeiro! (Caso Base atingido)
Executa printf("fim"); TELA: 4321fim

A função não chama mais nada, começa a voltar desempilhando.
 Como não há mais nenhum comando após a chamada recursiva no bloco else,
  ela apenas encerra em cascata sem imprimir mais nada.

Saída Final
A saída gerada pelo algoritmo na tela será:
4321fim
*/
