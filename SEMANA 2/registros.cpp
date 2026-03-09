#include <stdio.h>
#include <string.h>

typedef struct Cpessoa
{
	char nome[20];
	int idade;
};

int main(void)
{
	Cpessoa aluno[4];
	
	strcpy(aluno[0].nome, "Celso de Melo");
	aluno[0].idade = 22;
	
	strcpy(aluno[1].nome, "Augusto Nunes");
	aluno[1].idade = 22;
	
	strcpy(aluno[2].nome, "Julia Cleria");
	aluno[2].idade = 23;
	
	strcpy(aluno[3].nome, "Lucas Barroso");
	aluno[3].idade = 24;

	for (int i = 0; i<4 ; i++)
	{
		printf("%s \t %d \n", aluno[i].nome, aluno[i].idade);
	}
	getchar();
}

