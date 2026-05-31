#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void bfs(int grafo[MAX][MAX], int inicio, int numVertices) {
    int visitados[MAX] = {0};
    int fila[MAX], proximo = 0, anterior = 0;

    visitados[inicio] = 1;
    fila[anterior++] = inicio;

    while (proximo < anterior) {
        int vertice = fila[proximo++];
        printf("%d ", vertice);

        for (int i = 0; i < numVertices; i++) {
            if (grafo[vertice][i] == 1 && !visitados[i]) {
                fila[anterior++] = i;
                visitados[i] = 1;
            }
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

    printf("Algoritmo BFS\n");
    printf("Iniciando pelo Vertice...: %d\n", VertIni);
    printf("Visitando os Vertices....: ");
    
	bfs(grafo, VertIni, numVertices);

    return 0;
}
