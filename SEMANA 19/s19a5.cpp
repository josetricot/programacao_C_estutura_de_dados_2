atividade 5

Considerando a função de busca da atividade 04, onde mat = 1088 e N = 100, qual será a posição retornada no vetor, sabendo que as chaves 4088 , 3089 e 1088 já foram inseridas?

considerando a dispersão simples
primeira inserção, mat 4088, ocuparia a posição h 88
segundo inserção, mat 3089, ocuparia a posição h 89
terceira inserção, mat 1088, tentaria posição h 88, ocupada, tentaria 89, ocupada, salvaria na 90

aí entra a função de busca para mat 1088, ou seja, testaria na posição 88, valor de mat não bate
tenta na próxima, na 89, também não bate, tenta na 90, opa, valor bate! retorna posição h 90


...

atividade 4
Considerando a função de busca abaixo, onde mat = 1087 e N = 100, qual será a posição acessada no vetor?

Aluno* busca(Hash tab, int mat) {
    int h = hash(mat);
    while (tab[h] != NULL) {
        if (tab[h]->mat == mat)
            return tab[h];
        h = (h + 1) % N;
    }
    return NULL;
}

como tem só h e não tem h2 é dispersão simples
nos códigos anteriores...

int hash (int mat) { //calcula o indice na tabela
	return (mat%N);
}

= 1087 % 100
= 87

seguindo...

Aluno* busca(Hash tab, int mat) {
    int h = hash(mat); //int h é o indice e recebe o valor de 87
    while (tab[h] != NULL) { //enquanto posição não vazia
        if (tab[h]->mat == mat) //verifica se o valor de mat bate e retorna a posição
            return tab[h];
        h = (h + 1) % N; //se valor não bate é porque teve colisão, então incrementa 1 na posição e 				 //contiua buscando dentro do laço
    }
    //laço acabou e achou uma posição vazia (NULL)
    return NULL; //não encontrou o valor
}
