/*Considere o conjunto de cidades do Rio Grande do Sul representado pelos índices abaixo:

0 - Porto Alegre
1 - Canoas
2 - Novo Hamburgo
3 - Gramado
4 - Caxias do Sul
5 - Passo Fundo
6 - Erechim
7 - Santa Maria
8 - Pelotas
9 - Rio Grande

As conexões entre as cidades são dadas pelas seguintes arestas:

0 -> 1 : 18 km
0 -> 2 : 45 km
1 -> 4 : 115 km
2 -> 3 : 75 km
3 -> 4 : 70 km
4 -> 5 : 145 km
5 -> 6 : 80 km
4 -> 7 : 290 km
7 -> 8 : 260 km
8 -> 9 : 60 km

Desenvolva um programa utilizando grafos e matriz de adjacência para verificar se existe uma rota disponível entre duas cidades. Caso não exista ligação entre duas cidades, o valor da posição na matriz deve ser 0.

a) O programa deve apresentar ao usuário:

0 - Porto Alegre
1 - Canoas
2 - Novo Hamburgo
...
b) O usuário deverá informar:

cidade de origem;
cidade de destino.

(Utilize os índices das cidades para entrada dos dados).

c) Realizar a busca da rota, utilizando um algoritmo de percurso em grafos DFS (Busca em Profundidade), ou
BFS (Busca em Largura). O algoritmo deve percorrer o grafo verificando se existe caminho entre a origem e o destino.

d) Apresentar o resultado, se existe rota entre as cidades  ou se não existe caminho disponível.
Extra: calcular a distância.
*/

/*
matriz de adjacências
	0	1	2	3	4	5	6	7	8	9
0		18	45	

1					115

2				75

3					70

4						145		290

5							80

6

7									260

8										60

9 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX 10

//o parâmetro da segunda matriz foi removido, usado apenas "grafo" para tudo
int bfs(int grafo[MAX][MAX], int inicio, int numVertices, int destino, int *distTotal) {
    int visitados[MAX] = {0};
    int fila[MAX], proximo = 0, anterior = 0;
    int dist_acumulada[MAX] = {0};

    visitados[inicio] = 1;
    fila[anterior++] = inicio;

    while (proximo < anterior) {
        int vertice = fila[proximo++];
        
        if (vertice == destino) {
            *distTotal = dist_acumulada[vertice];
            return 1; 
        }
        
        printf("%d ", vertice);

        for (int i = 0; i < numVertices; i++) {
            // em vez de == 1, > 0
            if (grafo[vertice][i] > 0 && !visitados[i]) {
                fila[anterior++] = i;
                visitados[i] = 1;
                
                //calculado usando o próprio grafo da busca
                dist_acumulada[i] = dist_acumulada[vertice] + grafo[vertice][i]; 
            }
        }
    }      
    return 0; 
}

//parâmetro da segunda matriz também foi removido aqui...
int dfs(int grafo[MAX][MAX], int inicio, int visitados[], int numVertices, int destino, int *distTotal) {
    visitados[inicio] = 1;
    
    if (inicio == destino) {
        return 1; 
    }   
    
    printf("%d ", inicio);

    for (int i = 0; i < numVertices; i++) {
        //verificamos se o peso é > 0
        if (grafo[inicio][i] > 0 && !visitados[i]) {
            
            //soma usando o próprio grafo
            *distTotal = *distTotal + grafo[inicio][i];
            
            if (dfs(grafo, i, visitados, numVertices, destino, distTotal) == 1) {
                return 1; 
            }  
            
            //subtraí usando o próprio grafo (backtracking)
            *distTotal = *distTotal - grafo[inicio][i];
        }   
    }   
    return 0; 
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    //uma única matriz...
    int grafoDistancias[MAX][MAX] = {0}; 
    int VertIni, destino;
    int distanciaBFS = 0;
    int distanciaDFS = 0;
    
    grafoDistancias[0][1] = 18;
    grafoDistancias[0][2] = 45;
    grafoDistancias[1][4] = 115;
    grafoDistancias[2][3] = 75;
    grafoDistancias[3][4] = 70;
    grafoDistancias[4][5] = 145;
    grafoDistancias[5][6] = 80;
    grafoDistancias[4][7] = 290;
    grafoDistancias[7][8] = 260;
    grafoDistancias[8][9] = 60 ;

    printf("\nDigite o número correspondente à cidade de origem: ");
    printf("\n0 - Porto Alegre\n1 - Canoas\n2 - Novo Hamburgo\n3 - Gramado\n4 - Caxias do Sul");
    printf("\n5 - Passo Fundo\n6 - Erechim\n7 - Santa Maria\n8 - Pelotas\n9 - Rio Grande\n");
    scanf("%d", &VertIni);
    
    printf("\nDigite o número correspondente à cidade de destino: ");
    printf("\n0 - Porto Alegre\n1 - Canoas\n2 - Novo Hamburgo\n3 - Gramado\n4 - Caxias do Sul");
    printf("\n5 - Passo Fundo\n6 - Erechim\n7 - Santa Maria\n8 - Pelotas\n9 - Rio Grande\n");
    scanf("%d", &destino);
    
    int numVertices = 10;

    printf("\nAlgoritmo BFS\n");
    printf("Iniciando pelo Vértice...: %d\n", VertIni);
    printf("Visitando os Vértices....: ");
    
    //passada matriz de distâncias e os parâmetros diminuíram
    if (bfs(grafoDistancias, VertIni, numVertices, destino, &distanciaBFS) == 1) {
        printf("\nCaminho encontrado!");
        printf("\nDistância encontrada: %d km\n", distanciaBFS);
    } else {
        printf("\nCaminho não encontrado!\n");
    }
    
    int visitados[MAX] = {0};

    printf("\nAlgoritmo DFS\n");
    printf("Iniciando pelo Vértice...: %d\n", VertIni);
    printf("Visitando os Vértices....: ");
    
    if (dfs(grafoDistancias, VertIni, visitados, numVertices, destino, &distanciaDFS) == 1) {
        printf("\nCaminho encontrado!");
        printf("\nDistância encontrada: %d km\n", distanciaDFS);
    } else {
        printf("\nCaminho não encontrado!\n");
    }

    return 0;
}
