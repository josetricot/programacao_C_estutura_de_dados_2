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

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <locale.h>

#define MAX 10

int bfs(int grafo[MAX][MAX], int inicio, int numVertices, int destino, int distancias[MAX][MAX], int *distTotal) {
    int visitados[MAX] = {0};
    int fila[MAX], proximo = 0, anterior = 0;

	//CRIADO O CADERNINHO
    int dist_acumulada[MAX] = {0}; //vetor para o BFS, para anotar a distância total até cada cidade, ao invés de uma varíável única

    visitados[inicio] = 1;
    fila[anterior++] = inicio;

    while (proximo < anterior) {
        int vertice = fila[proximo++];
        
        if (vertice==destino) {
			*distTotal = dist_acumulada[vertice];
			return 1; //retorna verdadeiro se achou o caminho
		}
        
        printf("%d ", vertice);

        for (int i = 0; i < numVertices; i++) {
            if (grafo[vertice][i] == 1 && !visitados[i]) {
                fila[anterior++] = i;
                visitados[i] = 1;
                
                dist_acumulada[i] =dist_acumulada[vertice] + distancias[vertice][i]; 
                
				/*dist_acumulada[vertice] tem a quilometragem total do início até onde estamos agora.
				distancias[vertice][i] tem o tamanho da estrada que liga onde estamos à nova cidade.*/             
            }
		}
    }	   
    return 0; //retorna que não econtrou o caminho
}

//void dfs(int grafo[MAX][MAX], int inicio, int visitados[], int numVertices) {
int dfs(int grafo[MAX][MAX], int inicio, int visitados[], int numVertices, int destino, int distancias[MAX][MAX], int *distTotal) {
    visitados[inicio] = 1;
    
    if (inicio==destino) {
		//printf("\nCaminho encontrado!"); lá no main...
		return 1; //retorna verdadeiro se achou o caminho
	}	
    
    printf("%d ", inicio);

	for (int i = 0; i < numVertices; i++) {
	        if (grafo[inicio][i] == 1 && !visitados[i]) {
	            
	            //SOMA a distância da estrada que vamos tentar agora
            	*distTotal = *distTotal + distancias[inicio][i];
	            
	            //se o explorador que mandamos retornar 1, repassamos o 1 para trás!
	            if (dfs(grafo, i, visitados, numVertices, destino, distancias, distTotal) == 1) {
	                return 1; 
	            }  
	            // o explorador voltou e não achou.
            	// SUBTRAI a distância que havíamos somado na linha ali de cima
            	*distTotal = *distTotal - distancias[inicio][i];
	     	}   
	}	
	return 0; //retorna que não econtrou o caminho
}

int main() {
	setlocale(LC_ALL, "Portuguese");
	
    int grafoAdjacencias[MAX][MAX];
    int grafoDistancias[MAX][MAX];
	int VertIni, destino;
	int i, j;
	int distanciaBFS = 0;
	int distanciaDFS = 0;
		
	//criando a matriz com zeros
    //percorre as linhas
    for(i = 0; i < MAX; i++) {
        //percorre as colunas de cada linha
        for(j = 0; j < MAX; j++) {
            grafoAdjacencias[i][j] = 0;
        }
    }
	//ou int grafoAdjacencias[MAX][MAX] = {0}; na declaração

	//criando a matriz com zeros
    //percorre as linhas
    for(i = 0; i < MAX; i++) {
        //percorre as colunas de cada linha
        for(j = 0; j < MAX; j++) {
            grafoDistancias[i][j] = 0;
        }
    }
	//ou int grafoDistancias[MAX][MAX] = {0}; na declaração
	
	//preenchendo
	grafoAdjacencias[0][1] = 1;
	grafoAdjacencias[0][2] = 1;
	grafoAdjacencias[1][4] = 1;
	grafoAdjacencias[2][3] = 1;
	grafoAdjacencias[3][4] = 1;
	grafoAdjacencias[4][5] = 1;
	grafoAdjacencias[5][6] = 1;
	grafoAdjacencias[4][7] = 1;
	grafoAdjacencias[7][8] = 1;
	grafoAdjacencias[8][9] = 1;
	
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
	printf("\n0 - Porto Alegre");
	printf("\n1 - Canoas");
	printf("\n2 - Novo Hamburgo");
	printf("\n3 - Gramado");
	printf("\n4 - Caxias do Sul");
	printf("\n5 - Passo Fundo");
	printf("\n6 - Erechim");
	printf("\n7 - Santa Maria");
	printf("\n8 - Pelotas");
	printf("\n9 - Rio Grande\n");
	scanf("%d", &VertIni);
	
	printf("\nDigite o número correspondente à cidade de destino: ");
	printf("\n0 - Porto Alegre");
	printf("\n1 - Canoas");
	printf("\n2 - Novo Hamburgo");
	printf("\n3 - Gramado");
	printf("\n4 - Caxias do Sul");
	printf("\n5 - Passo Fundo");
	printf("\n6 - Erechim");
	printf("\n7 - Santa Maria");
	printf("\n8 - Pelotas");
	printf("\n9 - Rio Grande\n");
	scanf("%d", &destino);
	
	int numVertices = 10;

    printf("\nAlgoritmo BFS\n");
    printf("Iniciando pelo Vertice...: %d\n", VertIni);
    printf("Visitando os Vertices....: ");
	
	if (bfs(grafoAdjacencias, VertIni, numVertices, destino, grafoDistancias, &distanciaBFS)==1) {
		printf("\nCaminho encontrado!");
		printf("\nDistância encontrada: %d", distanciaBFS);
	} else printf("\nCaminho não encontrado!");
	
    int visitados[MAX] = {0};

	printf("\n");
    printf("\nAlgoritmo DFS\n");
	printf("Iniciando pelo Vertice...: %d\n", VertIni);
    printf("Visitando os Vertices....: ");
	
	if ( dfs(grafoAdjacencias, VertIni, visitados, numVertices, destino, grafoDistancias, &distanciaDFS) == 1) {
		printf("\nCaminho encontrado!");
		printf("\nDistância encontrada: %d", distanciaDFS);
	} else printf("\nCaminho não encontrado!");

	//BFS procura a rota com menos paradas (cidades) e o DFS explora um caminho até o fim antes de tentar outro
	//a lógica para somar a distância é um pouco diferente em cada um (o DFS usa recursividade e o BFS usa uma fila)
	
	
	//no DFS, o explorador vai por um caminho até o fim.
	//por isso, podíamos usar apenas uma variável (distTotal) e ir somando e subtraindo.
	//já o BFS explora "em círculos". Ele olha todos os vizinhos ao mesmo tempo.
	//se tentarmos usar apenas uma variável distTotal para ele, as distâncias de todos os caminhos vão se misturar!
	
    return 0;
}

/*TESTE 0 - 9

A distância de 743 km
Porto Alegre (0) -> Canoas (1) -> Caxias do Sul (4) -> Santa Maria (7) -> Pelotas (8) -> Rio Grande (9)
18 + 115 + 290 + 260 + 60 = 743
No DFS ele foi no modo "mergulho". Fez a rota 0 -> 1 -> 4, e aí de Caxias ele foi para Passo Fundo (5) e Erechim (6)
Quando chegou em Erechim e viu que era um beco sem saída para o destino, ele usou o backtracking!
Ele voltou para Caxias (4) e tentou o outro caminho indo para Santa Maria (7), achando a rota certa

No BFS: Ele foi no modo "onda". Testou todos os vizinhos de Porto Alegre (1 e 2), depois os vizinhos deles (4 e 3),
 depois os próximos (5 e 7), se espalhando uniformemente pelo mapa até a onda finalmente bater em Rio Grande (9) */
