/*
Recurividade - Atividade 05 (C)
Qual será a saída gerada das funções dos algoritmos abaixo, considerando o valor inicial de n=4:
c) func (int n)
   {
     if (n == 0)
     printf(“fim”);
    else
    {
     printf(n);
     func(n-1);
     printf(n);
    }
   }
*/

/*
O professor colocou um printf(n) antes da chamada recursiva (na descida) e outro 
printf(n) depois da chamada recursiva (na subida).
Isso significa que o programa vai imprimir os números tanto enquanto empilha quanto
 enquanto desempilha! Vamos ao nosso último teste de mesa para ver essa mágica dupla
  acontecendo:

Teste de Mesa: func(4)
A DESCIDA (Imprimindo e Empilhando)

1ª Chamada: func(4)
Imprime 4  TELA: 4
Chama func(3) e PAUSA o resto. (O segundo printf(4) fica guardado).

2ª Chamada: func(3)
Imprime 3  TELA: 43
Chama func(2) e PAUSA. (O segundo printf(3) fica guardado).

3ª Chamada: func(2)
Imprime 2  TELA: 432
Chama func(1) e PAUSA. (O segundo printf(2) fica guardado).

4ª Chamada: func(1)
Imprime 1   TELA: 4321
Chama func(0) e PAUSA. (O segundo printf(1) fica guardado).

5ª Chamada: func(0) (O Fundo do Poço)
Atingiu o Caso Base (n == 0)!
Imprime fim  TELA: 4321fim
A função encerra e começa a voltar.

A SUBIDA (Desempilhando e Imprimindo o resto)
O computador agora volta para cada função pausada e executa a linha que faltava
 (o segundo printf):
Volta para a 4ª Chamada e executa o printf(1)  TELA: 4321fim1
Volta para a 3ª Chamada e executa o printf(2)  TELA: 4321fim12
Volta para a 2ª Chamada e executa o printf(3)  TELA: 4321fim123
Volta para a 1ª Chamada e executa o printf(4)  TELA: 4321fim1234

Saída Final
A saída gerada pelo algoritmo na tela será um "espelho" com o fim no meio:
4321fim1234
*/
