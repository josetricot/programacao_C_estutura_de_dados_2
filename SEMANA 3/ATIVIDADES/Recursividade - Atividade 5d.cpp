/*Recursividade - Atividade 05 (D)
Qual será a saída gerada das funções dos algoritmos abaixo, considerando o valor inicial
 de n=4:
d) func (int n)
   {
     if (n == 0)
      printf(“fim”);
     else
     {
      func(n-1);
      printf(n);
      func(n-1);
     }
   }
*/

/*
Introduz um conceito chamado Recursividade em Árvore (Tree Recursion) . Como a função
 chama a si mesma duas vezes dentro do else, ela não forma mais uma linha reta descendo
  e subindo na memória. Ela se bifurca, dobrando de tamanho a cada passo.

Tentar rastrear isso de cima para baixo (começando do 4) dá um nó no cérebro gigantesco.
 O truque dos programadores para resolver testes de mesa de recursividade dupla é fazer o caminho inverso: resolver de baixo para cima (do menor para o maior).

Vamos construir a saída tijolo por tijolo:

Teste de Mesa (De baixo para cima)
Sabemos que a estrutura de qualquer número maior que zero é sempre:
 [Resultado do func(n-1)] + n + [Resultado do func(n-1)]

Para n = 0 (O Caso Base):
Imprime apenas: fim
Saída: fim

Para n = 1:
Ele faz: func(0) + imprime 1 + func(0)
Substituindo pelo que já sabemos: fim + 1 + fim
Saída: fim1fim

Para n = 2:
Ele faz: func(1) + imprime 2 + func(1)
Substituindo: fim1fim + 2 + fim1fim
Saída: fim1fim2fim1fim

Para n = 3:

Ele faz: func(2) + imprime 3 + func(2)
Substituindo: fim1fim2fim1fim + 3 + fim1fim2fim1fim
Saída: fim1fim2fim1fim3fim1fim2fim1fim

Para n = 4 (O pedido pelo exercício):
Ele faz: func(3) + imprime 4 + func(3)
Substituindo: Pega aquele bloco gigante do passo anterior, coloca o número 4 no meio,
 e repete o bloco gigante de novo!

Saída Final
A saída gerada pelo algoritmo na tela será este monstro aqui:
fim1fim2fim1fim3fim1fim2fim1fim4fim1fim2fim1fim3fim1fim2fim1fim

O que essa atividade ensina?
Ela ensina sobre o crescimento exponencial. Repare que para n=1 tivemos 2 "fims".
 Para n=2 tivemos 4. Para n=3 tivemos 8. Para n=4 tivemos 16 impressões da palavra "fim".
  O esforço do computador dobra a cada número que você sobe.
Se você tentasse rodar um func(40) com esse código, o seu computador travaria
 completamente, pois ele tentaria criar mais de 1 trilhão de chamadas na pilha de
  memória! É por isso que algoritmos recursivos bifurcados exigem muito cuidado na
   engenharia de software.
*/
