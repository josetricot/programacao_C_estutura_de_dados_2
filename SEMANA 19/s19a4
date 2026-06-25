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

int hash (int mat) //calcula o indice na tabela{
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
