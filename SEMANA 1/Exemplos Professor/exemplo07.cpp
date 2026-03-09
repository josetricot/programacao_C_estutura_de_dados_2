#include <stdio.h>
#include <string.h>

typedef struct Cpessoa
{
	char nome[20];
	int idade;
};

int main(void)
{
	char condicao = 's';
	Cpessoa aluno[200];
	FILE *bin;
	int  tamanho = 0; 
	
	if((bin = fopen("arquivo_binario.txt","rb")) == NULL)
    {
        printf("Erro ao abrir arquivo");
    }
 	else
	{
		//Lendo o Arquivo
		while (!feof(bin))
		{
			fread(&aluno[tamanho] ,sizeof(Cpessoa),1, bin);
			tamanho++;
		}	


		//Mostrando na tela
		for (int i = 0; i<tamanho-1 ; i++)
		{
			printf("%s \t %d \n", aluno[i].nome, aluno[i].idade);
		}
		getchar();
	}

}
