#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 200

// --- CONTADORES GLOBAIS SIMPLIFICADOS ---
int totalColisoes1 = 0;
int totalColisoes2 = 0;
int tabelaCheia1 = 0;
int tabelaCheia2 = 0;

struct aluno {
	int mat;
	char nome[81];
	int acessos;
};
typedef struct aluno Aluno;

typedef Aluno* Hash[N];

int hash(int mat) {
	return (mat % N); 
}

int hash2(int mat) {
	return N - 2 - (mat % (N - 2));
}

Aluno* insere1(Hash tab, int mat, char* nome) {
	int h = hash(mat);
	int tentativas = 0;
	
	while (tab[h] != NULL) {
		if (tab[h]->mat == mat) break; 
		
		totalColisoes1++; // Bateu em alguém! Conta 1 colisão.
		h = (h + 1) % N; 
		tentativas++;
		
		if (tentativas == N) {
		    tabelaCheia1++; // Deu a volta na tabela e não achou vaga.
		    return NULL;
		}
	}
	
	if (tab[h] == NULL) { 
		tab[h] = (Aluno*) malloc(sizeof(Aluno));
		tab[h]->mat = mat;
		tab[h]->acessos = tentativas + 1; 
	}
	
	strcpy(tab[h]->nome, nome);
	return tab[h];
}

Aluno* insere2(Hash tab, int mat, char* nome) {
	int h = hash(mat);
	int h2 = hash2(mat);
	int tentativas = 0;
	
	while (tab[h] != NULL) {
		if (tab[h]->mat == mat) break; 
		
		totalColisoes2++; // Bateu em alguém! Conta 1 colisão.
		h = (h + h2) % N; 
		tentativas++;
		
		if (tentativas == N) {
		    tabelaCheia2++; // Deu a volta na tabela e não achou vaga.
		    return NULL;
		}
	}
	
	if (tab[h] == NULL) { 
		tab[h] = (Aluno*) malloc(sizeof(Aluno));
		tab[h]->mat = mat;
		tab[h]->acessos = tentativas + 1;
	}
	
	strcpy(tab[h]->nome, nome);
	return tab[h];
}

int main() {
    Hash dados1; 
    Hash dados2; 

    for(int i = 0; i < N; i++) {
        dados1[i] = NULL;
        dados2[i] = NULL;
    }

    FILE *arquivo = fopen("dados_nomes.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo dados_nomes.txt!\n");
        return 1;
    }

    int mat = 0; 
    char nome[81];  
    
    while (fscanf(arquivo, "%d %[^\n\r]", &mat, nome) == 2) {
        insere1(dados1, mat, nome); 
        insere2(dados2, mat, nome); 
    }
    fclose(arquivo);

    printf("%-7s | %-12s | %-7s | %-10s | %-7s\n", "Posicao", "Hash Simples", "Acessos", "Hash Duplo", "Acessos");
    printf("-----------------------------------------------------------\n");

    for (int i = 0; i < N; i++) {
        printf("%-7d | ", i);
        
        if (dados1[i] != NULL) {
            printf("%-12d | %-7d | ", dados1[i]->mat, dados1[i]->acessos);
        } else {
            printf("%-12s | %-7s | ", "-", "-");
        }
        
        if (dados2[i] != NULL) {
            printf("%-10d | %-7d\n", dados2[i]->mat, dados2[i]->acessos);
        } else {
            printf("%-10s | %-7s\n", "-", "-");
        }
    }

    // --- RELATORIO FINAL SIMPLIFICADO ---
    printf("\n=== RESUMO DE DESEMPENHO ===\n");
    printf("Hash Simples -> Colisoes: %d | Fichas Cheias: %d\n", totalColisoes1, tabelaCheia1);
    printf("Hash Duplo   -> Colisoes: %d | Fichas Cheias: %d\n", totalColisoes2, tabelaCheia2);
    printf("============================\n");

    for (int i = 0; i < N; i++) {
        if (dados1[i] != NULL) free(dados1[i]);
        if (dados2[i] != NULL) free(dados2[i]);
    }

    return 0;
}
