/*Considere o arquivo dados.txt apresentado na Semana 12. Faça dois programas:

1. um programa que carregue os dados na memória e implemente a pesquisa binária em uma estrutura linear;
2. outro programa que implemente a pesquisa em uma estrutura hierárquica.
Os programas devem:

iniciar automaticamente;
carregar os dados;
ordená-los, se necessário;
pesquisar o nome "Valentina Moura";
encerrar automaticamente.
Todos os processos devem ser executados sem interação com o usuário.

Ao final, cada programa deve apresentar:

o tempo total necessário para executar todos os processos;
o número de acessos realizados durante a pesquisa.*/
/*
1 Definir a estrutura de dados (struct).

2 Ler o arquivo e armazenar as linhas em um vetor.

3 Ordenar o vetor.

4 Aplicar a busca binária para encontrar "Valentina Moura".*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h> //biblioteca para idiomas e caracteres especiais
#include <time.h> //para calcular o tempo total de execução

typedef struct {
    int matricula;
    char nome[128];
} Estudante;

//funcao original esetava para trocar numeros inteiros soltos
//agora precisamos trocar o estudante inteiro (matricula+nome),precisa ser com o tipo estudante
//void swap(int* a, int* b) { 
void swap(Estudante* a, Estudante* b) { //com ponteiro pois usamos &, temos que passar as variiáveis por referência -- swap(&vec[i], &vec[j])
  //int tmp; ajustada para Estudante inteiro e não int
  Estudante tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;}
 
//ajustado para nome
//int partition(int vec[], int left, int right) {
int partition(Estudante vec[], int left, int right) {

  int i, j;
  i = left;
  for (j = left + 1; j <= right; ++j) {
//alteração para poder comparar com nome
//    if (vec[j] < vec[left]) { // funcao original
// 	  if (strcmp(nome, a->nome) < 0) { // nome vem ANTES alfabeticamente, assim era no exercício anterior
//agora não temos nome a=>nome, vamos usar j para acessar estudante na posição j
	if (strcmp(vec[j].nome, vec[left].nome) < 0) {
      ++i;
      swap(&vec[i], &vec[j]);
    }
  }
  swap(&vec[left], &vec[i]);
   return i;}
 
//void quickSort(int vec[], int left, int right) { ajuste para receceber Estudante vec[]
void quickSort(Estudante vec[], int left, int right) {
  int r;
   if (right > left) {
    r = partition(vec, left, right);
    quickSort(vec, left, r - 1);
    quickSort(vec, r + 1, right);  }
}

// busca binária
//precisou de ajuses pois a iriginal buscava número solto int x dentro de um vetor de inteiros int vertor[]
//int BuscaBinaria(int vetor[], int tamanho, int x, int &acessos) {
int BuscaBinaria(Estudante vetor[], int tamanho, char nomeBuscado[], int &acessos) {
    int esquerda = 0;
    int direita = tamanho - 1;
    int meio;
    acessos = 0;

    while (esquerda <= direita) {
        acessos++; 
        meio = (esquerda + direita) / 2;
        
        //if (vetor[meio] == x) {
        if (strcmp(vetor[meio].nome, nomeBuscado) == 0) {
            return meio; //quando acha nome exatamente igual
        } 
        //else if (vetor[meio] < x) {
		else if (strcmp(vetor[meio].nome, nomeBuscado) < 0) {
            esquerda = meio + 1; 
        } 
        else {
            direita = meio - 1;  
        }
    }
    return -1; //executa quando percorreu tudo e não encontrou, por convenção é -1 pois os vetores começam em 0
}

/* colocado no inicio pois swap, parition e quickSort usam Estudante
struct Estudante {
		         int matricula;
		         char nome[128];
		        } ;
*/

int main(void) {
	
	clock_t inicio = clock();
	setlocale(LC_ALL, "Portuguese"); //configura o programa para usar o idioma português
	//ouve conflito de codificação então usei um comendo direto
	//system("chcp 65001"); //força o terminal do Windows a exibir UTF-8
	
	Estudante listaDeEstudantes[1000];

	FILE *arquivo;
	arquivo = fopen("dados.txt", "r");
	
	if (arquivo == NULL) { printf("Erro!"); }

	// lemos enquanto o fscanf conseguir capturar os 2 itens (matrícula e nome)
	// fscanf(arquivo, "%d %[^\n]", &matricula, nome); //lê do arquivo
	int contador = 0; // índice para controlar a posição no vetor
	while(fscanf(arquivo, "%d %[^\n]", &listaDeEstudantes[contador].matricula, listaDeEstudantes[contador].nome) == 2) {
    	contador++; // Avança para a próxima posição do vetor
	}	
	
	fclose(arquivo); //sempre fechamos o arquivo após o uso
	
	//chamamos funcão de ordenação, para 1000 estudantes
	quickSort(listaDeEstudantes, 0, 999);
	
	//teste, laço de impressão do vetor ordenado
	/*for (int q=0; q<1000; q++)
	{
        printf(" %d %s \n",listaDeEstudantes[q].matricula, listaDeEstudantes[q].nome);
    }
	*/
	
	//até aqui mostra vetor ondenado, agora vamos para o busca binária
    
	printf("\n---------------- RESULTADO DA BUSCA BINÁRIA ----------------\n");

	int total_acessos = 0;
	//chamamos a busca UMA vez e guardamos o índice que ela retornar
	int posicao = BuscaBinaria(listaDeEstudantes, 1000, "Valentina Moura", total_acessos);

	if (posicao != -1) { //se for diferente de -1 significa que achou, ou seja, devolveu um índice válido, retornou meio, estudante encontrado
    printf("Encontrado: Matrícula %d | Nome: %s\n", listaDeEstudantes[posicao].matricula, listaDeEstudantes[posicao].nome);
    printf("Total de acessos: %d\n", total_acessos);
	} else {
    printf("Estudante não encontrado.\n");

}
	clock_t fim = clock();
	//calcula o tempo em segundos (como é um número quebrado, usamos double e %f)
    double tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC; //para converter para segundos
    printf("Tempo total de execução: %f segundos\n", tempo_gasto);
}
	


		        

