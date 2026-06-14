/*Descobrindo Rotas Entre Cidades
Considere o seguinte grafo, que representa conexões rodoviárias entre cidades do Rio Grande do Sul:

Índice	Cidade
1	Porto Alegre
2	Canoas
3	Novo Hamburgo
4	Gramado
5	Caxias do Sul
6	Passo Fundo
7	Erechim
8	Santa Maria
 
Desenvolva um programa em C++ que:
1. Solicite ao usuário uma cidade de origem;
2. 3Solicite uma cidade de destino;
3. Utilize Busca em Profundidade (DFS) para encontrar todos os caminhos possíveis entre as duas cidades;
4.  Exiba cada caminho encontrado utilizando:
-os índices dos vértices;
-os nomes das cidades.
Exemplo
Entrada:

Cidade de origem: Porto Alegre
Cidade de destino: Erechim
 
Saída:

0 -> 2 -> 4 -> 5 -> 6

Porto Alegre -> Novo Hamburgo -> Caxias do Sul -> Passo Fundo -> Erechim
 
Outro caminho possível:

0 -> 7 -> 5 -> 6

Porto Alegre -> Santa Maria -> Passo Fundo -> Erechim
 
Caso não exista rota entre as cidades, o programa deve informar:
Nenhum caminho encontrado.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <locale.h>

#define MAX 10

void dfs(int grafo[MAX][MAX], int inicio, int visitados[], int numVertices, int destino, int caminho[], int tamanhoCaminho, char vetCidades[][20], int *encontrou) {
    //marca a cidade como visitada e adiciona na rota
    visitados[inicio] = 1;
    caminho[tamanhoCaminho] = inicio;
    tamanhoCaminho++;
    
    if (inicio == destino) {
        *encontrou = 1; //avisa o main que achou um caminho      
        
        //imprime os indices
        for (int i = 0; i < tamanhoCaminho; i++) {
            printf("%d", caminho[i]);
            if (i < tamanhoCaminho - 1) printf(" -> ");
        }
        printf("\n");
        
        //imprime os nomes das cidades
        for (int i = 0; i < tamanhoCaminho; i++) {
            printf("%s", vetCidades[caminho[i]]);
            if (i < tamanhoCaminho - 1) printf(" -> ");
        }
        printf("\n\n");
    } else {
        //se nao chegou continua explorando os vizinhos
        //laço começa do 1 e vai até o 8, <= numVertices
        for (int i = 1; i <= numVertices; i++) {
            if (grafo[inicio][i] == 1 && !visitados[i]) {
                
                dfs(grafo, i, visitados, numVertices, destino, caminho, tamanhoCaminho, vetCidades, encontrou);
            }
        }
    }
    
    //backtracking, desmarca o vertice atual antes de voltar
    visitados[inicio] = 0;
}

int main() {
    setlocale(LC_ALL, "Portuguese");    
    
    int grafoAdjacencias[MAX][MAX] = {0};
    
    char vetCidades[][20] = {
        "NULL", "Porto Alegre", "Canoas", "Novo Hamburgo", "Gramado", "Caxias do Sul", "Passo Fundo", "Erechim", "Santa Maria"
    };
    int VertIni, destino;
        
    //preenchendo exatamente com os indices de 1 a 8 da imagem
    grafoAdjacencias[1][2] = 1; grafoAdjacencias[2][1] = 1;
    grafoAdjacencias[1][8] = 1; grafoAdjacencias[8][1] = 1;
    grafoAdjacencias[2][3] = 1; grafoAdjacencias[3][2] = 1;
    grafoAdjacencias[3][4] = 1; grafoAdjacencias[4][3] = 1;
    grafoAdjacencias[3][5] = 1; grafoAdjacencias[5][3] = 1;
    grafoAdjacencias[4][5] = 1; grafoAdjacencias[5][4] = 1;
    grafoAdjacencias[5][6] = 1; grafoAdjacencias[6][5] = 1;
    grafoAdjacencias[6][7] = 1; grafoAdjacencias[7][6] = 1;
    grafoAdjacencias[6][8] = 1; grafoAdjacencias[8][6] = 1;

    printf("\nDigite o número correspondente à cidade de origem: ");
    printf("\n1 - Porto Alegre");
    printf("\n2 - Canoas");
    printf("\n3 - Novo Hamburgo");
    printf("\n4 - Gramado");
    printf("\n5 - Caxias do Sul");
    printf("\n6 - Passo Fundo");
    printf("\n7 - Erechim");
    printf("\n8 - Santa Maria\n-> ");
    scanf("%d", &VertIni);
    
    printf("\nDigite o número correspondente à cidade de destino: ");
    printf("\n1 - Porto Alegre");
    printf("\n2 - Canoas");
    printf("\n3 - Novo Hamburgo");
    printf("\n4 - Gramado");
    printf("\n5 - Caxias do Sul");
    printf("\n6 - Passo Fundo");
    printf("\n7 - Erechim");
    printf("\n8 - Santa Maria\n-> ");
    scanf("%d", &destino);
    
    int numVertices = 8;
    int visitados[MAX] = {0};
    int caminho[MAX] = {0}; //vetor novo para armazenar a rota
    int encontrou = 0;      //variável de controle 0 = nao 1 = sim

    printf("\nResultados:\n\n");
    
    //chama a DFS passando 0 como o tamanho inicial do caminho
    dfs(grafoAdjacencias, VertIni, visitados, numVertices, destino, caminho, 0, vetCidades, &encontrou);

    if (encontrou == 0) {
        printf("Nenhum caminho encontrado.\n");
    }

    return 0;
}

