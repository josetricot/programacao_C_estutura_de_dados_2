/*

Considerando o arquivo de dados "dados.bin", com a estrutura apresentada abaixo, desenvolva um programa em linguagem C que realize a leitura do conteúdo do arquivo para um bloco com capacidade de até 5.000 registros.

Após o carregamento dos dados, escolha um método de ordenação e ordene os registros com base no campo icodigo.

Na sequência, implemente o algoritmo de busca binária para possibilitar a localização de registros a partir do código informado.

Além disso, o programa deverá gerar um novo arquivo binário ordenado, contendo os dados já classificados.

O sistema deve disponibilizar um menu de opções, permitindo ao usuário executar as funcionalidades implementadas.

Para verificação da integridade do arquivo, você poderá utilizar o programa lendo.exe.

Estrutura do Arquivo Binário: 

    typedef struct {
        int icodigo;
        char sproduto[100];
        char scategoria[30];
        float fpreco;
        int iestoque;
    } DADOS;

*/

/* 

ANTES DE CRIRAR O MENU

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int icodigo;
    char sproduto[100];
    char scategoria[30];
    float fpreco;
    int iestoque;
} DADOS;

int buscaBinaria(DADOS *vet, int esq, int dir, int codigoBusca) {
    while (esq <= dir) {
        int meio = esq + (dir - esq) / 2;
        
        if (vet[meio].icodigo == codigoBusca) return meio; // encontrou
        
        if (vet[meio].icodigo < codigoBusca) 
            esq = meio + 1; // ignora a metade esquerda
        else 
            dir = meio - 1; // ignora a metade direita
    }
    return -1; // não encontrou
}

void insertSort(DADOS *vet, int n) {
    int i, j;
    DADOS chave;
    
    // o laço começa de 1 porque assumimos que o elemento 0 já está "ordenado"
	for(j = 1; j < n; j++) {
		chave = vet[j]; // guarda a estrutura inteira (o registro atual)
	    i = j - 1;
	        
	        // compara pelo campo 'icodigo'
			// move os elementos maiores para a direita
       	while(i >= 0 && vet[i].icodigo > chave.icodigo) {
	    	vet[i+1] = vet[i];
	        i--;
	    }
	        // insere a estrutura na posição correta
	    vet[i+1] = chave;
	}
}

main(){


	DADOS vet[5000];

	int totalRegistros = 0;
	
	FILE *arquivo;
	arquivo =fopen("dados.bin", "rb");
	
	
	if(arquivo == NULL){
		printf("arquivo não encontrado.\n");
	}
	
	
	while (fread(&vet[totalRegistros], sizeof(DADOS), 1, arquivo) == 1) {
	                    totalRegistros++;
	};
	fclose(arquivo);
	
	arquivo =fopen("dados_ordenados.bin", "wb");
	
	if(arquivo == NULL){
	
	printf("arquivo não encontrado.\n");
	
	}
	
	insertSort(vet, totalRegistros);
	fwrite(vet, sizeof(DADOS), totalRegistros, arquivo);
	fclose(arquivo);
}

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int icodigo;
    char sproduto[100];
    char scategoria[30];
    float fpreco;
    int iestoque;
} DADOS;

int buscaBinaria(DADOS *vet, int esq, int dir, int codigoBusca) {
    while (esq <= dir) {
        int meio = esq + (dir - esq) / 2;
        
        if (vet[meio].icodigo == codigoBusca) return meio; // encontrou
        
        if (vet[meio].icodigo < codigoBusca) 
            esq = meio + 1; // ignora a metade esquerda
        else 
            dir = meio - 1; // ignora a metade direita
    }
    return -1; // não encontrou
}

void insertSort(DADOS *vet, int n) {
    int i, j;
    DADOS chave;
    
    // o laço começa de 1 porque assumimos que o elemento 0 já está "ordenado"
	for(j = 1; j < n; j++) {
		chave = vet[j]; // guarda a estrutura inteira (o registro atual)
	    i = j - 1;
	        
	        // compara pelo campo 'icodigo'
			// move os elementos maiores para a direita
       	while(i >= 0 && vet[i].icodigo > chave.icodigo) {
	    	vet[i+1] = vet[i];
	        i--;
	    }
	        // insere a estrutura na posição correta
	    vet[i+1] = chave;
	}
}

int main(){
	
	DADOS vet[5000];
    int totalRegistros = 0;
    FILE *arquivo;
    int opcao;
    int codigoBusca;
    int indice;
    int estaOrdenado = 0; //falso para usuário só conseguir  buscar se ordenado
    
	do {
		printf("\nDigite 1 para ler os dados\n");
		printf("\nDigite 2 para ordenar\n");
		printf("\nDigite 3 para procura\n");
		printf("\nDigite 4 salvar dados ordenados em novo arquivo\n");
		printf("\nDigite 5 sair\n");
	
		scanf("%d", &opcao);

		switch(opcao) {
			case 1:
				arquivo =fopen("dados.bin", "rb");
				estaOrdenado=0;
				if(arquivo == NULL){
				printf("arquivo não encontrado.\n");
				} else {
					totalRegistros = 0; // Reset para novas leituras
					while (fread(&vet[totalRegistros], sizeof(DADOS), 1, arquivo) == 1) {
				    	totalRegistros++;
					};
					fclose(arquivo);
					printf("Sucesso! %d registros lidos.\n", totalRegistros);
				}
				break;
			
			case 2:
				if (totalRegistros ==0){
					printf("Siga o fluxo 1, 2 e 3 e depois 4.");
				} else {
					insertSort(vet, totalRegistros);
					printf("Dados ordenados na memoria.\n");
					estaOrdenado=1;	
				}	
				break;

			case 3:
	        	if (totalRegistros ==0){
					printf("Siga o fluxo 1, 2 e 3 e depois 4.");
				} else if (estaOrdenado==0) {
					printf("Primeiro se deve ordenar os dados!\n");
				} else {
					printf("\nDigite o codigo do produto que deseja procurar: ");
	            	scanf("%d", &codigoBusca);
	            	// chama a busca binária
	            	indice = buscaBinaria(vet, 0, totalRegistros - 1, codigoBusca);
			    		if (indice == -1) {
							printf("\nRegistro com codigo %d nao encontrado.\n", codigoBusca);
						} else {
	    					printf("\n--- Registro Encontrado ---\n");
	                    	printf("Codigo: %d\n", vet[indice].icodigo);
	                    	printf("Produto: %s\n", vet[indice].sproduto);
	                    	printf("Categoria: %s\n", vet[indice].scategoria);
	                    	printf("Preco: %.2f\n", vet[indice].fpreco);
	                    	printf("Estoque: %d\n", vet[indice].iestoque);
	                    	printf("---------------------------\n");
						}
				}
				break;
				
			case 4:
    			if (totalRegistros == 0) {
        			printf("\nErro: Nao ha dados carregados. Siga o fluxo (1 -> 2 -> 4).\n");
    			} else if (estaOrdenado == 0) {
        			printf("\nErro: O arquivo so pode ser gerado apos a ordenacao (Opcao 2).\n");
    			} else {
        			arquivo = fopen("dados_ordenados.bin", "wb");
        			if (arquivo == NULL) {
            			printf("\nErro ao criar o arquivo.\n");
        			} else {
            			fwrite(vet, sizeof(DADOS), totalRegistros, arquivo);
            			fclose(arquivo);
            			printf("\nArquivo 'dados_ordenados.bin' gerado com sucesso!\n");
        			}
    			}
    			break;
		
			case 5:
			printf("Saindo...\n");
			break;
		
			default:
			printf("Digite apenas 1,2,3,4 ou 5 para sair.\n");
			break;	
		}
	} while(opcao != 5);
    
	return 0;
}	
	
