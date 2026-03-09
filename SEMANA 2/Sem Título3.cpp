#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Cpessoa
{ char nome[20];
int idade;} ;

int main(void)
{
Cpessoa *paluno;
paluno = (struct Cpessoa *) malloc(4*sizeof(struct Cpessoa));

strcpy((*paluno).nome, "Homer");
(*paluno).idade = 22;

strcpy((*(paluno+1)).nome, "Marge");
(*(paluno+1)).idade = 22;

strcpy((*(paluno+2)).nome, "Lisa");
(*(paluno+2)).idade = 23;

strcpy((*(paluno+3)).nome, "Bart");
(*(paluno+3)).idade = 24;

for (int i = 0; i<4 ; i++)
{
printf("%s - %d \n", (*(paluno+i)).nome, (*(paluno+i)).idade);
}
getchar();
return 1;
}
