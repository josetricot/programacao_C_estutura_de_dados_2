/*
Revisão para Recuperação – Atividade de Grafos 01

Desenvolva um programa em C++ que:

Percorra todos os caminhos possíveis do grafo utilizando Busca em Profundidade (DFS);
Armazene cada sequência de letras gerada;
Compare cada sequência com um conjunto de palavras válidas;
Exiba apenas as palavras encontradas no dicionário.
Dicionário
Utilize o seguinte conjunto de palavras para validação:

AMOR
CASA
ROMA
MORA
TORA
ROSA
SOMA
 
Exemplo de Caminhos
Palavra	Caminho
AMOR	A -> M -> O -> R
CASA	C -> A -> S -> A
ROMA	R -> O -> M -> A
MORA	M -> O -> R -> A
TORA	T -> O -> R -> A
ROSA	R -> O -> S -> A
SOMA	S -> O -> M -> A
Saída Esperada
O programa deverá exibir apenas as palavras encontradas no dicionário.

Exemplo:

AMOR encontrada
CASA encontrada
ROMA encontrada
MORA encontrada
TORA encontrada
ROSA encontrada
SOMA encontrada
*/

#include <stdio.h>
#include <string.h>

#define MAX 100

char letras[] = {'N', 'O', 'R', 'M', 'A', 'S', 'T'};

char dicionario[][5] = {"AMOR", "CASA", "ROMA", "MORA", "TORA", "ROSA", "SOMA"};
int numPalavrasNoDicionario = 7;

/*
void dfs(int grafo[MAX][MAX], int inicio, int visitados[], int numVertices) {
    visitados[inicio] = 1;
    printf("%d ", inicio);

    for (int i = 0; i < numVertices; i++) {
        if (grafo[inicio][i] == 1 && !visitados[i]) {
            dfs(grafo, i, visitados, numVertices);
        }
    }
}
*/

//adicionado palavraAtual para guardar o caminho e nivel para saber quantas letras já pegamos
void dfs(int grafo[MAX][MAX], int inicio, int visitados[], int numVertices, char palavraAtual[], int nivel) {
    visitados[inicio] = 1;
    
    //guarda a letra atual na nossa string e coloca o terminador nulo '\0' no final
    palavraAtual[nivel] = letras[inicio]; //letras[inicio] pega o número do vértice atual,inicio , e traduz para a letra do vetor
    palavraAtual[nivel + 1] = '\0'; //ex vetor: ['R', '\0', lixo, lixo, lixo] sempre empurrando o /0

    //se chega na 4a letra (nivel 3, começa no 0) para de buscar e compara
    if (nivel == 3) {
        for (int i = 0; i < numPalavrasNoDicionario; i++) {
            //strcmp retorna 0 se as duas strings forem exatamente iguais
            if (strcmp(palavraAtual, dicionario[i]) == 0) {
                printf("%s encontrada\n", palavraAtual);
            }
        }
    } else {
        //se ainda nao tem 4 letras continua a busca nos vizinhos
        for (int i = 0; i < numVertices; i++) {
            if (grafo[inicio][i] == 1 && !visitados[i]) {
                dfs(grafo, i, visitados, numVertices, palavraAtual, nivel + 1);
            }
        }
    }

    //backtracking, desmarca a letra para formar outras combinacoes
    visitados[inicio] = 0; 
}

int main() {

    int grafo[MAX][MAX] = {
        {0, 1, 0, 0, 0, 0, 0}, 
        {0, 0, 1, 1, 0, 1, 0}, 
        {0, 1, 0, 0, 1, 0, 0}, 
        {0, 1, 0, 0, 1, 0, 0}, 
        {0, 0, 0, 1, 0, 1, 0}, 
        {0, 1, 0, 0, 1, 0, 0}, 
        {0, 0, 0, 0, 1, 0, 0}
    };
    
    /*
	0=N
	1=O
	2=R
	3=M
	4=A
	5=S
	6=T
	*/
    int numVertices = 7;
    int visitados[MAX] = {0};
    char palavraAtual[5]; //string para guardar as 4 letras + \0
    
    printf("Procurando palavras no grafo...\n\n");
    
    //inicia o DFS a partir de cada um dos vértices possíveis
    for(int VertIni = 0; VertIni < numVertices; VertIni++){
        //nível inicial é 0
        dfs(grafo, VertIni, visitados, numVertices, palavraAtual, 0);
    }

    return 0;
}
