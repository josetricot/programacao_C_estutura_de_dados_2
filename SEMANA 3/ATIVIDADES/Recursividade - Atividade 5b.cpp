/*
Recursividade - Atividade 05 (B)
Qual será a saída gerada das funções dos algoritmos abaixo,
 considerando o valor inicial de n=4:
b) func (int n)
   {
     if (n == 0)
     printf(“fim”);
    else
    {
     func(n-1);
     printf(n);
	}
   }
*/

/*
Como o professor inverteu a ordem e colocou o printf(n) depois da chamada 
recursiva func(n-1), o programa é obrigado a "descer" até o fundo da pilha primeiro,
 para só conseguir imprimir os números na hora de "subir" (desempilhar).
Vamos ao teste de mesa para vermos isso acontecendo na memória:

Teste de Mesa: func(4)
A DESCIDA (Empilhando)

1ª Chamada: func(4)
n vale 4. Entra no else.
Chama func(3); e PAUSA a execução. A instrução printf(4); fica guardada na memória.

2ª Chamada: func(3)
n vale 3. Entra no else.
Chama func(2); e PAUSA. A instrução printf(3); fica guardada.

3ª Chamada: func(2)
n vale 2. Entra no else.

Chama func(1); e PAUSA. A instrução printf(2); fica guardada.
4ª Chamada: func(1)
n vale 1. Entra no else.
Chama func(0); e PAUSA. A instrução printf(1); fica guardada.

5ª Chamada: func(0)
n vale 0. O if (0 == 0) é Verdadeiro (Caso Base)!
Executa printf("fim"); ?? TELA: fim

A função encerra e começa a voltar de onde parou.

A SUBIDA (Desempilhando e Imprimindo)
O computador agora volta resolvendo as pendências de trás para frente:

Volta para a 4ª Chamada e executa o printf(1); TELA: fim1
Volta para a 3ª Chamada e executa o printf(2); TELA: fim12
Volta para a 2ª Chamada e executa o printf(3); TELA: fim123
Volta para a 1ª Chamada e executa o printf(4); TELA: fim1234

Saída Final
A saída gerada pelo algoritmo na tela será exatamente o inverso da Atividade A:
fim1234
*/
