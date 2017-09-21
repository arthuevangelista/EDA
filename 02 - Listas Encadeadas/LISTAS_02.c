#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_NOME 30
#define MAX_INTERACOES 3

/*===================================================*/
/*        Aluno: Arthur Evangelista dos Santos		 */
/*              Matrícula: 14/0016686                */
/*===================================================*/

struct aluno{
	int matricula;
	char nome[MAX_NOME];
	struct aluno* proximo; //Aponta pro proximo item da lista
	/*Aluno* anterior; -- para duplamente encadeada*/
};

typedef struct aluno* Lista;

typedef struct cabecalho{
	int qtd;
	struct aluno* primeiro;
	struct aluno* ultimo;
}Cab;

/*LIBERA A LISTA*/
void libera_lista(Cab* l){
	if(l != NULL){
		struct aluno* no;
		while((l->primeiro) != NULL){/*Enquanto não estivermos no final da lista...*/
			no = l->primeiro;
			l->primeiro = l->primeiro->proximo;
			free(no);
		}/*fim do while*/

		free(l);

	}/*fim do if*/
}

/*INSERÇÃO DE ELEMENTOS NA LISTA ENCADEADA*/
/*				OPERAÇÃO IU				*/
void IU(Cab* l, struct aluno novo){
	struct aluno* no = (struct aluno*)malloc(sizeof(struct aluno*));

	no->matricula = novo.matricula;
	strcpy(no->nome, novo.nome);

/*Se a lista estiver vazia, o cabecalho aponta pro novo elemento*/
	if(l->primeiro == NULL){
		no->proximo = l->ultimo;
		l->primeiro = l->ultimo = no;
		l->qtd++;
	}else{
		l->ultimo->proximo = no; /*O ultimo elemento do cabecalho deve ter como proximo o nó que estou adicionando*/
		l->ultimo = no; /*O novo ultimo é o nó que estou adicionando*/
		no->proximo = NULL;
		l->qtd++;
	}
	
}

/*				OPERAÇÃO IM				*/
void IM(Cab* l, struct aluno novo){
	struct aluno* no = (struct aluno*)malloc(sizeof(struct aluno*));

	struct aluno* anterior;
	struct aluno* atual = l->primeiro;

	no->matricula = novo.matricula;
	strcpy(no->nome, novo.nome);

/*Se a lista estiver vazia, o cabecalho aponta pro novo elemento*/
	if(l->primeiro == NULL){
		no->proximo = l->ultimo;
		l->primeiro = l->ultimo = no;
		l->qtd++;
	}else{
			printf("\nentrei ifelse");
		while(atual->matricula < novo.matricula){
			printf("entrei while");
			anterior = atual;
			atual = atual->proximo;
		}
		if(atual == NULL){
			printf("entrei if");
			no->proximo = l->ultimo->proximo;
			anterior->proximo = l->ultimo = no;
			l->qtd++;
		}else{
			printf("entrei else");
			no->proximo = anterior->proximo;
			anterior->proximo = no;
			l->qtd++;
		}
	}
	
}

void imprimir_na_ordem(struct aluno* l){
/*Apenas imprime os alunos na ordem em que foram mantidos no momento da inserção (seja por IU, IM ou IN)*/

/*Impressão recursiva*/
	struct aluno* aux = (struct aluno*)malloc(sizeof(struct aluno*));
	aux = l;
	if(aux != NULL){
		printf("%s, %d; ", aux->nome, aux->matricula);
		aux = aux->proximo;
		imprimir_na_ordem(aux);
	}
}

/*PROGRAMA PRINCIPAL*/
int main(){
	
	Cab* l;
	l = (Cab*) malloc(sizeof(Cab));
	l->primeiro = NULL;
	l->ultimo = NULL;
	l->qtd = 0;

	int interacoes = 0;
	char codigo[2];
	int operador; /*Operador recebe o retorno das funções. Dependendo de seu valor, as mensagens ENTRADA INVÁLIDA ou BASE VAZIA serão exibidas*/
	struct aluno tempBuffer; /*Registro temporário do nome e da matricula*/

	while(interacoes < MAX_INTERACOES){
		setbuf(stdin, NULL); /*Limpa o buffer do teclado*/

/*Menu principal*/
		system("clear");
		printf("\t\t>> Código <<\n");
		printf("IU - Inclui alunos. Apresenta por ordem de inserção\n");
		printf("IM - Inclui alunos. Apresenta por ordem de matrícula\n");
		printf("EX - Remove aluno\n");
		printf("IN - Inclui alunos. Apresenta por ordem alfabética\n");
		printf("\nInsira Código nome matrícula: ");
		scanf("%s %s %d", codigo, tempBuffer.nome, &tempBuffer.matricula);

/*Para verificar qual código foi inserido e agir conforme*/
		if(codigo[0] == 'I'){
			switch(codigo[1]){
				case 'U':
					/* OPERAÇÃO IU */
					IU(l, tempBuffer);
					printf("\n");
					imprimir_na_ordem(l->primeiro);
					getchar();
					getchar();
					interacoes++;
					break;
				case 'M':
					IM(l, tempBuffer);
					printf("\n");
					imprimir_na_ordem(l->primeiro);
					getchar();
					getchar();
					interacoes++;
					break;
				case 'N':
					/*IN(l, tempBuffer);*/
					printf("\n");
					imprimir_na_ordem(l->primeiro);
					getchar();
					getchar();
					interacoes++;
					break;
				default:
					break;
			}/*fim switch*/
		}/*else{
			if(codigo[0] == 'E'){
				operador = EX(li_encadeada, l, tempBuffer);
				if(operador == 0){
					printf("\nENTRADA INVÁLIDA.\nPressione qualquer tecla para continuar: ");
					getchar();
					getchar();
					continue;
				}
				if(l->primeiro == NULL){
					printf("\nBASE VAZIA.\nPressione qualquer tecla para continuar: ");
					getchar();
					getchar();
					continue;
				}
				imprimir_na_ordem(l->primeiro);
				interacoes++;
				}else{
					printf("Opção inválida!\n");
					getchar();
					getchar();
			}/*fim if-else 'EX'
		}/*fim if-else 'IU IM IN'*/



	}/*fim while*/

libera_lista(l);
	return 0;
}
