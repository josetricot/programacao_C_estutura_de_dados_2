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

void Caminhamento_Pre_Ordem(TArvore *a)
{
 if (!Vazia(a))
    {
     printf("%d - %s\n", a->matricula, a->nome); 			
     Caminhamento_Pre_Ordem(a->esq);     
     Caminhamento_Pre_Ordem(a->dir);     
    }
}

void Caminhamento_In_Fixado(TArvore *a)
{
 if (!Vazia(a))
    {
     Caminhamento_In_Fixado(a->esq);     
     printf("%d - %s\n", a->matricula, a->nome); 			
     Caminhamento_In_Fixado(a->dir);     
    }
}

void Caminhamento_Pos_Fixado(TArvore *a)
{
 if (!Vazia(a))
    {
     Caminhamento_Pos_Fixado(a->esq);      
     Caminhamento_Pos_Fixado(a->dir);      
     printf("%d - %s\n", a->matricula, a->nome); 			
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

TArvore *insere_binario(TArvore *a, int matricula, char nome[]) {
    if (a == NULL) {
        a = Cria(NULL, matricula, nome, NULL);
    } else if (matricula < a->matricula) {
        a->esq = insere_binario(a->esq, matricula, nome);
    } else if (matricula > a->matricula) {
        a->dir = insere_binario(a->dir, matricula, nome);
    }
    return a;
}

//busca por matrícula que conta a quantidade de acessos/comparações
void Busca_Matricula_Conta_Acessos(TArvore *a, int matricula, int *cont)
{
	// 1. Somar +1 no contador de acessos
    (*cont)++; 
    
    // 2. Condições de busca...
    //chamda recursiva
    //condição e parada
    if (a == NULL) {
        printf("\nMatrícula não encontrada!\n");
    // se não nulo restam 3 possibilidades, matricula menor que atual
	// maior
	// ou igual    
    } else if (matricula < a->matricula) { 
		Busca_Matricula_Conta_Acessos(a->esq, matricula, cont);
    } else if (matricula > a->matricula) { 
		Busca_Matricula_Conta_Acessos(a->dir, matricula, cont);
	} else {
		printf("\nMatrícula encontada! Matricula: %d, Nome: %s, Acessos: %d\n", a->matricula, a->nome, *cont); 
	}  
}


