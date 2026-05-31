#include <stdio.h>

#define MAX 100

void dfs(int grafo[MAX][MAX], int inicio, int visitados[], int numVertices) {
    visitados[inicio] = 1;
    printf("%d ", inicio);

    for (int i = 0; i < numVertices; i++) {
        if (grafo[inicio][i] == 1 && !visitados[i]) {
            dfs(grafo, i, visitados, numVertices);
        }
    }
}

int main() {
    int grafo[MAX][MAX] = {
    	{1, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 1}
    };
    int numVertices = 6;
    int VertIni = 0;
    int visitados[MAX] = {0};

    printf("Algoritmo DFS\n");
	printf("Iniciando pelo Vertice...: %d\n", VertIni);
    printf("Visitando os Vertices....: ");
    
	dfs(grafo, VertIni, visitados, numVertices);

    return 0;
}
