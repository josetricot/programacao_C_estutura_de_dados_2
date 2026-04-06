/*
Você foi contratado por uma pequena loja online que deseja organizar o seu estoque de produtos digitalmente. Atualmente, os dados estão apenas em papel, e a loja quer começar a armazenar as informações em um arquivo que possa ser lido e atualizado pelo sistema futuramente.

Problema:
Cada produto da loja possui três informações essenciais:

id (inteiro) – identificador único do produto

nome (string) – nome do produto

preco (float) – preço do produto

Sua tarefa é criar um programa que permita gerenciar o estoque de produtos com um menu interativo, oferecendo pelo menos as seguintes opções:

Cadastrar produto – o usuário deve informar os dados do produto e o programa deve armazená-los em um arquivo binário (estoque.dat).

Listar produtos – ler todos os produtos cadastrados no arquivo binário e exibir na tela.

Sair – encerrar o programa.

Utilize fwrite() e fread() para manipulação de arquivos binários em C e um loop para exibir o menu até o usuário escolher sair.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// estrutura do produto
typedef struct {
    int id;
    char nome[50];
    float preco;
} Produto;

// função para limpar o buffer do teclado
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// função para cadastrar um novo produto
void cadastrarProduto() {
    Produto prod;
    FILE *arquivo;
    
    // abre o arquivo no modo append (adicionar ao final) + binário
    arquivo = fopen("estoque.dat", "ab");
    
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    
    // entrada dos dados
    printf("\n*** CADASTRO DE PRODUTO ***\n");
    
    printf("Digite o ID do produto: ");
    scanf("%d", &prod.id);
    limparBuffer();
    
    printf("Digite o nome do produto: ");
    fgets(prod.nome, 50, stdin);
    // remove o '\n' do final da string
    prod.nome[strcspn(prod.nome, "\n")] = '\0';
    
    printf("Digite o preco do produto: R$ ");
    scanf("%f", &prod.preco);
    limparBuffer();
    
    // escreve a estrutura no arquivo binário
    size_t escritos = fwrite(&prod, sizeof(Produto), 1, arquivo);
    
    if (escritos == 1) {
        printf("\nProduto cadastrado com sucesso!\n");
        printf("ID: %d | Nome: %s | Preco: R$ %.2f\n", prod.id, prod.nome, prod.preco);
    } else {
        printf("Erro ao cadastrar o produto!\n");
    }
    
    fclose(arquivo);
}

// função para listar todos os produtos cadastrados
void listarProdutos() {
    Produto prod;
    FILE *arquivo;
    int contador = 0;
    float totalEstoque = 0;
    
    // abre o arquivo no modo leitura + binário
    arquivo = fopen("estoque.dat", "rb");
    
    if (arquivo == NULL) {
        printf("\nNenhum produto cadastrado ainda!\n");
        printf("Arquivo estoque.dat nao encontrado.\n");
        return;
    }
    
    printf("\n*** LISTA DE PRODUTOS CADASTRADOS ***\n");
    printf("************************************************\n");
    printf("%-5s %-30s %-10s\n", "ID", "NOME", "PRECO");
    printf("************************************************\n");
    
    // lê cada produto do arquivo até o final
    while (fread(&prod, sizeof(Produto), 1, arquivo) == 1) {
        printf("%-5d %-30s R$ %-10.2f\n", prod.id, prod.nome, prod.preco);
        contador++;
        totalEstoque += prod.preco;
    }
    
    printf("************************************************\n");
    printf("Total de produtos: %d\n", contador);
    printf("Valor total do estoque: R$ %.2f\n", totalEstoque);
    printf("************************************************\n");
    
    if (contador == 0) {
        printf("Nenhum produto encontrado no estoque.\n");
    }
    
    fclose(arquivo);
}

// função principal
int main() {
    int opcao;
    
    do {
        printf("\n*** SISTEMA DE GERENCIAMENTO DE ESTOQUE ***\n");
        printf("1 - Cadastrar produto\n");
        printf("2 - Listar produtos\n");
        printf("3 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        limparBuffer();
        
        switch(opcao) {
            case 1:
                cadastrarProduto();
                break;
            case 2:
                listarProdutos();
                break;
            case 3:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while(opcao != 3);
    
    return 0;
}
