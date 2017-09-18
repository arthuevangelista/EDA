#include<stdio.h>
#include<stdlib.h>
#define MAX_NOME 30
#define MAX_INTERACOES 2

/*===================================================*/
/*        Aluno: Arthur Evangelista dos Santos		 */
/*              Matrícula: 14/0016686                */
/*===================================================*/

struct reg{
	int matricula;
	char nome[MAX_NOME];
};

int main(){
	int interacoes = 0;
	char codigo[2];
/*	struct reg aluno[inout];*/
	struct reg tempBuffer; /*Registro temporário do nome e da matricula*/


	while(interacoes < MAX_INTERACOES){
		setbuf(stdin, NULL); /*Limpa o buffer do teclado*/

		system("clear");
		printf("\t\t>> Código <<\n");
		printf("IU - Inclui alunos. Apresenta por ordem de inserção\n");
		printf("IM - Inclui alunos. Apresenta por ordem de matrícula\n");
		printf("EX - Remove aluno\n");
		printf("IN - Inclui alunos. Apresenta por ordem alfabética\n");
		printf("\nInsira Código nome matrícula: ");
		scanf("%s %s %d", codigo, tempBuffer.nome, &tempBuffer.matricula);;

		if(codigo[0] == 'I'){
			switch(codigo[1]){
				case 'U':
					printf("Opção IU");
					interacoes++;
					getchar();
					getchar();
					break;
				case 'M':
					printf("Opção IM");
					interacoes++;
					getchar();
					getchar();
					break;
				case 'N':
					printf("Opção IN");
					interacoes++;
					getchar();
					getchar();
					break;
				default:
					break;
			}/*fim switch*/
		}else{
			if(codigo[0] == 'E'){
				printf("Opção EX");
				interacoes++;
				getchar();
				getchar();
			}else{
				printf("Opção inválida!\n");
				getchar();
				getchar();
			}/*fim if-else 'EX'*/
		}/*fim if-else 'IU IM IN'*/

		printf("%s %d\n", tempBuffer.nome, tempBuffer.matricula);

	}/*fim while*/
}/*fim da função main*/
