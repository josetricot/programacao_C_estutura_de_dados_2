/*Crie um programa que apresente um menu com as seguintes opções:

1. Carregar arquivo na memória
2. Ordenar dados
3. Procurar registro por código
4. Sair
a) Utilize realocação dinâmica de memória (função realloc) para carregar os dados do arquivo, garantindo o correto uso de ponteiros.

b) Implemente um algoritmo de ordenação dos dados.

c) Implemente uma função eficiente para localizar registros.

d) Obedeça à seguinte estrutura do arquivo binário a ser lido:

    typedef struct {
        int icodigo;
        char sproduto[100];
        char scategoria[30];
        float fpreco;
        int iestoque;
    } DADOS;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// definição da estrutura
typedef struct {
    int icodigo;
    char sproduto[100];
    char scategoria[30];
    float fpreco;
    int iestoque;
} DADOS;

// ====================================================================
// ALGORITMO DE ORDENAÇÃO: INSERTION SORT (Adaptado do InsertSort.cpp)
// ====================================================================
void insertSort(DADOS *v, int n) {
    int i, j;
    DADOS chave;
    
    // o laço começa de 1 porque assumimos que o elemento 0 já está "ordenado"
    for(j = 1; j < n; j++) {
        chave = v[j]; // guarda a estrutura inteira (o registro atual)
        i = j - 1;
        
        // compara pelo campo 'icodigo'
		// move os elementos maiores para a direita
        while(i >= 0 && v[i].icodigo > chave.icodigo) {
            v[i+1] = v[i];
            i--;
        }
        // insere a estrutura na posição correta
        v[i+1] = chave;
    }
}

// ====================================================================
// FUNÇÃO PARA LOCALIZAR REGISTROS: BUSCA BINÁRIA
// ====================================================================
int buscaBinaria(DADOS *arr, int esq, int dir, int codigoBusca) {
    while (esq <= dir) {
        int meio = esq + (dir - esq) / 2;
        
        if (arr[meio].icodigo == codigoBusca) return meio; // encontrou
        
        if (arr[meio].icodigo < codigoBusca) 
            esq = meio + 1; // ignora a metade esquerda
        else 
            dir = meio - 1; // ignora a metade direita
    }
    return -1; // não encontrou
}

int main() {
    DADOS *registros = NULL; // ponteiro inicial vazio
    int totalRegistros = 0;
    int opcao = 0;
    int ordenado = 0; // flag para saber se os dados já foram ordenados

    do {
        printf("\n========================================\n");
        printf("                MENU\n");
        printf("========================================\n");
        printf("1. Carregar arquivo na memoria\n");
        printf("2. Ordenar dados\n");
        printf("3. Procurar registro por codigo\n");
        printf("4. Sair\n");
        printf("========================================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                FILE *arquivo = fopen("dados.bin", "rb");
                if (arquivo == NULL) {
                    printf("Erro ao abrir o arquivo 'dados.bin'. Certifique-se de que ele esta na mesma pasta do programa.\n");
                    break;
                }

                // se já havia dados na memória (usuário escolheu a opção 1 mais de uma vez), limpamos primeiro
                if (registros != NULL) {
                    free(registros);
                    registros = NULL;
                }
                totalRegistros = 0;
                ordenado = 0; // se recarregou, perdeu a ordenação

                DADOS temp;
                // fread retorna 1 se leu com sucesso um bloco do tamanho de DADOS
                while (fread(&temp, sizeof(DADOS), 1, arquivo) == 1) {
                    totalRegistros++;
                    
                    // ====================================================================================
                    // O QUE O REALLOC FAZ?
                    // 1. ele tenta AUMENTAR A MEMÓRIA no mesmo local onde o ponteiro atual está
                    // 2. se não houver espaço contíguo livre, ele MUDA A MEMÓRIA:
                    //    - Aloca um novo bloco de memória maior em outro endereço
                    //    - Copia todos os dados antigos para esse novo endereço
                    //    - Libera (dá free) no endereço antigo automaticamente
                    // 3. POR QUE USAR 'novoPonteiro'?
                    //    se faltar memória RAM, o realloc retorna NULL. Se você fizesse:
                    //    registros = realloc(registros, ...);
                    //    perderia-se o endereço antigo (que tinha os dados) e causaria vazamento de memória
                    //    usando 'novoPonteiro', protegemos os dados que já existem caso dê erro!
                    // ====================================================================================
                    
                    DADOS *novoPonteiro = (DADOS*) realloc(registros, totalRegistros * sizeof(DADOS));
                    
                    if (novoPonteiro == NULL) {
                        printf("ERRO FATAL: Falta de memoria! O programa sera encerrado.\n");
                        free(registros); // libera o que já tinha lido para não vazar memória
                        fclose(arquivo);
                        return 1;
                    }
                    
                    // a realocação deu certo! Atualizamos o ponteiro principal com o novo endereço
                    registros = novoPonteiro; 
                    
                    // salva a estrutura recém-lida na última posição alocada do vetor
                    registros[totalRegistros - 1] = temp;
                }
                
                fclose(arquivo);
                printf("\nArquivo carregado com sucesso! Total de registros lidos: %d\n", totalRegistros);
                break;
            }
            case 2: {
                if (totalRegistros == 0) {
                    printf("\nNenhum dado na memoria. Carregue o arquivo primeiro (Opcao 1).\n");
                } else {
                    // chama o InsertSort passando o vetor e a quantidade de elementos
                    insertSort(registros, totalRegistros);
                    ordenado = 1;
                    printf("\nDados ordenados com sucesso usando InsertSort!\n");
                }
                break;
            }
            case 3: {
                if (totalRegistros == 0) {
                    printf("\nNenhum dado na memoria. Carregue o arquivo primeiro (Opcao 1).\n");
                    break;
                }
                if (!ordenado) {
                    printf("\nATENCAO: Os dados precisam estar ordenados para usar a Busca Binaria. Use a opcao 2 primeiro.\n");
                    break;
                }

                int codigoBusca;
                printf("\nDigite o codigo do produto que deseja procurar: ");
                scanf("%d", &codigoBusca);

                // chama a busca binária
                int indice = buscaBinaria(registros, 0, totalRegistros - 1, codigoBusca);

                if (indice != -1) {
                    printf("\n--- Registro Encontrado ---\n");
                    printf("Codigo: %d\n", registros[indice].icodigo);
                    printf("Produto: %s\n", registros[indice].sproduto);
                    printf("Categoria: %s\n", registros[indice].scategoria);
                    printf("Preco: %.2f\n", registros[indice].fpreco);
                    printf("Estoque: %d\n", registros[indice].iestoque);
                    printf("---------------------------\n");
                } else {
                    printf("\nRegistro com codigo %d nao encontrado.\n", codigoBusca);
                }
                break;
            }
            case 4:
                printf("\nEncerrando o programa...\n");
                break;
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }
    } while (opcao != 4);

    // boa prática: Libera a memória alocada dinamicamente antes de encerrar o programa
    if (registros != NULL) {
        free(registros);
    }

    return 0;
}
