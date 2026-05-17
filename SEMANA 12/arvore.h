typedef struct Nodo {
		         struct Nodo *esq;
		         int info;
		         struct Nodo *dir;
		        } TNodo;

typedef TNodo TArvore;

TArvore *Cria(TArvore *esq, int info, TArvore* dir)
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
      p->info = info;
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
     printf("%d ", a->info); 			
     Caminhamento_Pre_Ordem(a->esq);     
     Caminhamento_Pre_Ordem(a->dir);     
    }
}

void Caminhamento_In_Fixado(TArvore *a)
{
 if (!Vazia(a))
    {
     Caminhamento_In_Fixado(a->esq);     
     printf("%d ", a->info); 			
     Caminhamento_In_Fixado(a->dir);     
    }
}

void Caminhamento_Pos_Fixado(TArvore *a)
{
 if (!Vazia(a))
    {
     Caminhamento_Pos_Fixado(a->esq);      
     Caminhamento_Pos_Fixado(a->dir);      
     printf("%d ", a->info); 			
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

TArvore *insere_binario(TArvore *a, int info) {
    if (a == NULL) {
        a = Cria(NULL, info, NULL);
    } else if (info < a->info) {
        a->esq = insere_binario(a->esq, info);
    } else if (info > a->info) {
        a->dir = insere_binario(a->dir, info);
    }
    return a;
}

