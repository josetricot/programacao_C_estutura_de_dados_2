/*
Atividade – Geração de Palavras Utilizando Grafos

Considere o seguinte Grafo, que representa as conexões entre letras:

Deseja-se verificar todas as combinações possíveis que podem formar palavras a partir de cada letra inicial.

Para isso, utilize um vetor auxiliar, em que cada índice corresponde a uma letra:

vetor[0] = A
vetor[1] = C
vetor[2] = M
vetor[3] = N
vetor[4] = O
vetor[5] = R
vetor[6] = S
vetor[7] = T
A saída do programa deverá apresentar o caminho percorrido utilizando os índices do vetor e sua respectiva conversão para caracteres.

Exemplo:

Se o percurso encontrado for:

7 -> 4 -> 5 -> 0 -> 2

A saída deverá ser exibida como:

7[T] -> 4[O] -> 5[R] -> 0[A] -> 2[M]

ou, de forma textual:

TORAM

O programa deve percorrer o grafo e imprimir todas as combinações válidas encontradas.
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void bfs(int grafo[MAX][MAX], int inicio, int numVertices, char vetor[]) {
    int visitados[MAX] = {0};
    int fila[MAX], proximo = 0, anterior = 0;

    visitados[inicio] = 1;
    fila[anterior++] = inicio;
    
    int primeiro = 1; //criado um marcador! 1 significa "verdadeiro"

    while (proximo < anterior) {
        int vertice = fila[proximo++];
        
        //se NÃO for o primeiro, imprimimos a seta antes de mostrar a letra
        if (!primeiro) {
            printf(" -> ");
        }
        
        printf("%d[%c]", vertice, vetor[vertice]);
        primeiro = 0; //logo após imprimir o primeiro, muda para 0 (falso) para o resto do loop

        for (int i = 0; i < numVertices; i++) {
            if (grafo[vertice][i] == 1 && !visitados[i]) {
                fila[anterior++] = i;
                visitados[i] = 1;
            }
        }
    }
}

void dfs(int grafo[MAX][MAX], int inicio, int visitados[], int numVertices, char vetor[]) {
    visitados[inicio] = 1;
    
    //imprime a letra atual SEM a seta no final
    printf("%d[%c]", inicio, vetor[inicio]); 
    
    for (int i = 0; i < numVertices; i++) {
        if (grafo[inicio][i] == 1 && !visitados[i]) {
            //imprime a seta apenas se tivermos certeza que vamos visitar um vizinho válido
            printf(" -> "); 
            dfs(grafo, i, visitados, numVertices, vetor);
        }
    }
    
    visitados[inicio] = 0; //desmarca a letra para formar outras combinações! (Backtracking)
}

int main() {
    
    char vetor[8] = {0};
    
    vetor[0] = 'A';
    vetor[1] = 'C';
    vetor[2] = 'M';
    vetor[3] = 'N';
    vetor[4] = 'O';
    vetor[5] = 'R';
    vetor[6] = 'S';
    vetor[7] = 'T';
    
    int grafo[MAX][MAX] = {0};
    
    grafo[0][2] = 1;
    grafo[1][0] = 1;
    grafo[2][3] = 1;
    grafo[2][4] = 1;
    grafo[3][4] = 1;
    grafo[4][2] = 1;
    grafo[4][5] = 1;
    grafo[5][0] = 1;
    grafo[6][0] = 1;
    grafo[6][4] = 1;
    grafo[7][4] = 1;

    /*int numVertices = 8;
    int VertIni = 1;

    printf("Algoritmo BFS\n");
    printf("Iniciando pelo Vertice...: %d\n", VertIni);
    printf("Visitando os Vertices....: ");
    
	bfs(grafo, VertIni, numVertices, vetor);

    int visitados[MAX] = {0};

    printf("\nAlgoritmo DFS\n");
	printf("Iniciando pelo Vertice...: %d\n", VertIni);
    printf("Visitando os Vertices....: ");
    
	dfs(grafo, VertIni, visitados, numVertices, vetor);
	*/
	
	int numVertices = 8;

    printf("--- Algoritmo BFS ---\n");
    for (int i = 0; i < numVertices; i++) {
        printf("\nIniciando pelo Vertice %d[%c]: \n", i, vetor[i]);
        bfs(grafo, i, numVertices, vetor);
        printf("\n");
    }

    printf("\n\n--- Algoritmo DFS ---\n");
    for (int i = 0; i < numVertices; i++) {
        
        // ZERAMOS o vetor de visitados a cada nova letra inicial da DFS
        int visitados[MAX] = {0}; 
        
        printf("\nIniciando pelo Vertice %d[%c]: \n", i, vetor[i]);
        dfs(grafo, i, visitados, numVertices, vetor);
        printf("\n");
    }

    return 0;
}
