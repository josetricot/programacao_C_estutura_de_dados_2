typedef struct Nodo {
		         struct Nodo *esq;
		         int matricula;
		         char nome[128];
		         struct Nodo *dir;
		        } TNodo;

typedef TNodo TArvore;

TArvore *Cria(TArvore *esq, int matricula, char nome[], TArvore* dir)
{
 TArvore *p;

 p = (TArvore*) malloc(sizeof(TArvore));
 if (p == NULL)
     {
      printf("ERRO FATAL: Falta de Memória\n");
      getchar();
      exit(0); 

     }
 else
     {
      p->matricula = matricula;
      strcpy(p->nome, nome);
	  p->esq = esq;
      p->dir = dir;
     }
 return p;
}

int Vazia(TArvore *a)
{
 if (a == NULL)
     return(1);
 else
     return(0);
}

//mudou só ordem do print para melhor visualização
void Caminhamento_In_Fixado(TArvore *a)
{
 if (!Vazia(a))
    {
     Caminhamento_In_Fixado(a->esq);     
     printf("%s - %d\n", a->nome, a->matricula); 			
     Caminhamento_In_Fixado(a->dir);     
    }
}

TArvore *Destroi(TArvore *a)
{
 if (!Vazia(a))
    {
     Destroi(a->esq); 
     Destroi(a->dir); 
     free(a);         
    }
 return(NULL);
}

//ajustado para ser pelo nome agora ao ínves de número de matrícula
TArvore *insere_binario(TArvore *a, int matricula, char nome[]) {
    if (a == NULL) {
        a = Cria(NULL, matricula, nome, NULL);
    } else if (strcmp(nome, a->nome) < 0) { // nome vem ANTES alfabeticamente
        a->esq = insere_binario(a->esq, matricula, nome);
    } else if (strcmp(nome, a->nome) > 0) { // nome vem DEPOIS alfabeticamente
        a->dir = insere_binario(a->dir, matricula, nome);
    }
    return a;
}

//busca era por matrícula, agora é por nome que conta a quantidade de acessos/comparações
//void Busca_Matricula_Conta_Acessos(TArvore *a, int matricula, int *cont)
void Busca_Nome_Conta_Acessos(TArvore *a, char nome_buscado[], int *cont)
{
	// soma +1 no contador de acessos
    (*cont)++; 
    
    //condições de busca
    if (a == NULL) {
        printf("\nNome não encontrado!\n");
    } else if (strcmp(nome_buscado, a->nome) < 0) { 
		Busca_Nome_Conta_Acessos(a->esq, nome_buscado, cont);
    } else if (strcmp(nome_buscado, a->nome) > 0) { 
		Busca_Nome_Conta_Acessos(a->dir, nome_buscado, cont);
	} else {
		printf("\nNome encontado! Matricula: %d, Nome: %s, Acessos: %d\n", a->matricula, a->nome, *cont); 
	}  
}

//remoção - nó pode não ter fihos, ter 1 ou 2
//original do professor
/*
TArvore* remove_binario(TArvore* a, int info) {
    if (a == NULL) return NULL;

    if (info < a->info) {
        a->esq = remove_binario(a->esq, info);
    } else if (info > a->info) {
        a->dir = remove_binario(a->dir, info);
    } else {
        // Encontrou o nó a remover
        if (a->esq == NULL && a->dir == NULL) {
            free(a);
            return NULL;
        } else if (a->esq == NULL) {
            TArvore* temp = a->dir;
            free(a);
            return temp;
        } else if (a->dir == NULL) {
            TArvore* temp = a->esq;
            free(a);
            return temp;
        } else {
            // Dois filhos: encontrar o menor da subárvore direita
            TArvore* temp = a->dir;
            while (temp->esq != NULL)
                temp = temp->esq;
            a->info = temp->info;
            a->dir = remove_binario(a->dir, temp->info);
        }
    }
    return a;
}

*/
//nova
TArvore* remove_binario(TArvore* a, char nome_remover[]) {
    if (a == NULL) return NULL;

    if (strcmp(nome_remover, a->nome) < 0) {
        a->esq = remove_binario(a->esq, nome_remover);
    } else if (strcmp(nome_remover, a->nome) > 0) {
        a->dir = remove_binario(a->dir, nome_remover);
    } else {
        // Encontrou o nó a remover
        if (a->esq == NULL && a->dir == NULL) { //nó folha, 0 filhos
            free(a);
            return NULL;
        } else if (a->esq == NULL) { //1 filho, à direita
            TArvore* temp = a->dir;
            free(a);
            return temp;
        } else if (a->dir == NULL) {//1 filho, à esquerda
            TArvore* temp = a->esq;
            free(a);
            return temp;
        } else {
            // Dois filhos: encontrar o menor da subárvore direita
            TArvore* temp = a->dir;
            while (temp->esq != NULL)
                temp = temp->esq;

        //aqui ajustado por ser string    
	//a->nome = temp->info; 
	//strcpy(destino, origem)
	//se faz a copia separada para String e para o Inteiro

	strcpy(a->nome, temp->nome);
	a->matricula = temp->matricula;
		
	// Remove o nó substituto lá de baixo
        a->dir = remove_binario(a->dir, temp->nome);
        }
    }
    return a;
}