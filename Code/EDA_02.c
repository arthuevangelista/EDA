#include <stdio.h>
#include <stdlib.h>
#define MAXIMO 3

/*===================================================*/
/*        Aluno: Arthur Evangelista dos Santos		 */
/*              Matrícula: 14/0016686                */
/*===================================================*/

struct reg {
	int matricula;
	char nome[30];
};

void bubblesort(struct reg vetor[]){
/*Método da bolha*/
	int i, end = MAXIMO;
	struct reg aux;
	int continua; /*= 1 true, = 0 false*/
	
	do{
		continua = 0;
		for(i = 0; i < (end - 1); i++){
			if(vetor[i].matricula > vetor[i + 1].matricula){
				aux = vetor[i];
				vetor[i] = vetor[i+1];
				vetor[i+1] = aux;
				continua = 1;
			}
		}
	end--;
	}while(continua != 0);

}

int registro(struct reg aluno[MAXIMO], int lsub){
/*Registro do aluno na turma*/
	system("clear");

	if(lsub < MAXIMO){
		printf("Insira a matrícula e o nome do aluno:\n");
		scanf("%d", &aluno[lsub].matricula);
		scanf("%s", aluno[lsub].nome);
		lsub++;
	}else{
		printf("\nTurma lotada!");
	}
	return lsub;
}

void leitura(struct reg aluno[MAXIMO], int lsub){
/*Leitura dos registros da turma*/
	system("clear");
	int i = 0;

	printf("====================================================\n");
	while(i < lsub){
		printf("%d - %s\n", aluno[i].matricula, aluno[i].nome);
		i++;
	}
	printf("====================================================\n");

	printf("\n\nPressione qualquer tecla para continuar...");
	getchar();
	getchar();
}

void remocao(struct reg aluno[], int lsub){
/*Remoção de aluno*/
system("clear");
int chaveK, u;
int resultado_pesquisa = -1, init = 0, meio, fim = (MAXIMO - 1);

/*Recebe chave K*/
	printf("Insira a matricula do aluno que deseja remover: ");
	scanf("%d", &chaveK); /*Pode ter a opção de pesquisar por nome ou por matr*/
/*Pesquisa Binária p/ saber se existe este aluno na turma*/

	do{
		meio=(init+fim)/2;
		if(chaveK < aluno[meio].matricula)
			fim = meio - 1;
		else
			init = meio + 1;
	}while((init <= fim)&&(chaveK != aluno[meio].matricula));

	if(chaveK = aluno[meio].matricula)
		resultado_pesquisa = meio;
/*Remoção do individuo da pilha*/
/*Chamada da função Bubble sort para reorganização*/
/*Foi parar no switch-case*/
}

int main(){
	char c = 'z';
	int lsub = 0;
	struct reg aluno[MAXIMO];


	while(c != '0'){
		setbuf(stdin, NULL); /*Limpa o buffer do teclado*/

		system("clear");
		printf("\t\t>> MENU <<\n");
		printf("1 - Incluir aluno na turma\n");
		printf("2 - Imprimir alunos da turma\n");
		printf("3 - Remover aluno\n");
		printf("0 - SAIR\n");
		printf("\t\tOPÇÃO: ");
		c = getchar();

		switch(c){
			case '0' :
				break;
			case '1' :
				lsub = registro(aluno, lsub);
				bubblesort(aluno);
				break;
			case '2' :
				leitura(aluno, lsub);
				break;
			case '3' :
				remocao(aluno, lsub);
				bubblesort(aluno);
				break;
			default :
				printf("Opção inválida!\n");
		}
	}
}
