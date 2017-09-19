#include<stdio.h>
#include<stdlib.h>
#include "lista_sequencial.h" /*Adiciona o header da lista*/
#define MAX_NOME 30
#define MAX_ALUNOS 10
#define MAX_INTERACOES 13 /*Trocar pra 20 mais tarde*/

/*===================================================*/
/*        Aluno: Arthur Evangelista dos Santos		 */
/*              Matrícula: 14/0016686                */
/*===================================================*/

struct lista{
	int qtd; /*Quantidade de elementos da lista*/
	struct registro turma[MAX_ALUNOS];
/*Vetor de alunos (turma) estático (com número máximo de alunos)*/
};

/*CRIA A LISTA*/
Lista* cria_lista(){
	Lista *li; /*variável local li*/
	li = (Lista*)malloc(sizeof(struct lista)); /*Aloca o espaço pra lista*/
	if(li != NULL) /*Se deu certo, então faça qtd = 0*/
		li->qtd = 0; /*Altera valor de qtd no ponteiro para li*/
	return li; /*retorna a variável local li*/
}

/*DELETA A LISTA*/
void libera_lista(Lista* li_sequencial){
	free(li_sequencial); /*Recebe por referência li e libera li_sequencial*/
}

/*VERIFICA SE A LISTA ESTÁ CHEIA*/
int lista_cheia(Lista* li_sequencial){
/* Para utilizar esta função faça:

int x = lista_cheia(li_sequencial);

ou dentro de uma estrutura de comparação

if(lista_cheia(li_sequencial)		*/

	if(li_sequencial == NULL)
		return -1; /*Significa que a lista não foi inicializada*/
	return (li_sequencial->qtd == MAX_ALUNOS); /*retorna 0 se a lista NÃO estiver cheia e 1 se ela estiver cheia*/
}

/*VERIFICA SE A LISTA ESTÁ VAZIA*/
int lista_vazia(Lista* li_sequencial){
/* Para utilizar esta função faça:

int x = lista_vazia(li_sequencial);

ou dentro de uma estrutura de comparação

if(lista_vazia(li_sequencial)		*/

	if(li_sequencial == NULL)
		return -1; /*Significa que a lista não foi inicializada*/
	return (li_sequencial->qtd == 0); /*retorna 0 se a lista NÃO estiver vazia e 1 se ela estiver vazia*/
}

/*INSERÇÃO DE ELEMENTOS NA LISTA ESTÁTICA*/
/*				OPERAÇÃO IU				*/
int IU(Lista* li, struct registro aluno){
	if(li == NULL)
		return 0; /*A lista não foi criada ainda*/
	if(lista_cheia(li))
		return 0; /*A lista está cheia e não é possível inserir alunos*/
	li->turma[li->qtd] = aluno; /*Insere o aluno al na lista turma na posição qtd (posição atual)*/
/*Lembrando que esta função adiciona alunos no final da lista para que seja possível exibir em ordem de inserção*/
	li->qtd++; /*Incrementa a posição da lista*/
	return 1; /*A inserção foi um sucesso e o programa pode prosseguir*/
}

/*				OPERAÇÃO IM				*/
int IM(Lista* li, struct registro aluno){
/*Por ordem de matrícula*/
	int k, i = 0;
	if(li == NULL)
		return 0;
	if(lista_cheia(li))
		return 0;
	while((i < li->qtd) && (li->turma[i].matricula < aluno.matricula))
		i++;
/*Este while procura na lista em que posição está a matrícula maior ou igual à matricula a ser inserida*/
	for(k = li->qtd-1; k >= i; k--)
		li->turma[k+1] = li->turma[k]; /*move todos os dados posteriores em uma posição para inserir o aluno na posição i*/
	li->turma[i] = aluno;
	li->qtd++; /*Incrementa a posição da lista*/
	return 1; /*A inserção foi um sucesso e o programa pode prosseguir*/
}

/*				OPERAÇÃO IN				*/
int IN(Lista* li, struct registro aluno){
/*Por ordem alfabética*/
/*Mesma ideia que a op IM porém usando ordenação alfabética*/

	int k, i = 0;
	if(li == NULL)
		return 0;
	if(lista_cheia(li))
		return 0;
	while((i < li->qtd) && (li->turma[i].nome[0] < aluno.nome[0]))
		i++;
	if(li->turma[i].nome[0] == aluno.nome[0])
		i++;
	for(k = li->qtd-1; k >= i; k--)
		li->turma[k+1] = li->turma[k];
	li->turma[i] = aluno;
	li->qtd++; /*Incrementa a posição da lista*/
	return 1; /*A inserção foi um sucesso e o programa pode prosseguir*/
}

/*REMOÇÃO DE ELEMENTOS NA LISTA ESTÁTICA*/
/*				OPERAÇÃO EX				*/
int EX(Lista* li, struct registro aluno){
	int k, i = 0;
	while((i < li->qtd) && (li->turma[i].matricula != aluno.matricula))
		i++;
	if(i == li->qtd) /*Entrada inválida*/
		return 0;

	if(i == li->qtd-1){/*Se o valor estiver no FINAL da lista, ele apenas decrementa li->qtd e retorna 1*/
		li->qtd--;
		return 1;
	}else{
/*Desloca os dados da turma se a lista não estiver vazia*/
	for(k = i; k < li->qtd-1; k++)
		li->turma[k] = li->turma[k+1];
	li->qtd--;
	return 1;
	}/*fim do if-else*/

}

/*	IMPRESSÃO	*/
void imprimir_na_ordem(Lista* li){
/*Apenas imprime os alunos na ordem em que foram mantidos no momento da inserção (seja por IU, IM ou IN)*/
	int i;
	printf("\n");
	for(i = 0; i < li->qtd; i++)
		printf("%s, %d; ", li->turma[i].nome, li->turma[i].matricula);
	getchar();
	getchar();
}

/*PROGRAMA PRINCIPAL*/
int main(){
	int interacoes = 0;
	char codigo[2];
	int operador; /*Operador recebe o retorno das funções IU, IM, IN e EX. Dependendo de seu valor, as mensagens ENTRADA INVÁLIDA ou BASE VAZIA serão exibidas*/
	Lista* li_sequencial; /*Declarada a lista sequencial*/
	struct registro tempBuffer; /*Registro temporário do nome e da matricula*/

	/*Chama função que cria a lista*/
	li_sequencial = cria_lista(); /*recebe a lista alocada dinamicamente na função*/

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
					operador = IU(li_sequencial, tempBuffer);
					if(operador == 0){
						printf("\nLista cheia ou inexistente. Por gentileza, tente novamente. Pressione qualquer tecla para continuar: ");
						getchar();
						getchar();
					}
					imprimir_na_ordem(li_sequencial);
					interacoes++;
					break;
				case 'M':
					operador = IM(li_sequencial, tempBuffer);
					if(operador == 0){
						printf("\nLista cheia ou inexistente. Por gentileza, tente novamente. Pressione qualquer tecla para continuar: ");
						getchar();
						getchar();
					}
					imprimir_na_ordem(li_sequencial);
					interacoes++;
					break;
				case 'N':
					operador = IN(li_sequencial, tempBuffer);
					if(operador == 0){
						printf("\nLista cheia ou inexistente. Por gentileza, tente novamente. Pressione qualquer tecla para continuar: ");
						getchar();
						getchar();
					}
					imprimir_na_ordem(li_sequencial);
					interacoes++;
					break;
				default:
					break;
			}/*fim switch*/
		}else{
			if(codigo[0] == 'E'){
				operador = EX(li_sequencial, tempBuffer);
				if(operador == 0){
					printf("\nENTRADA INVÁLIDA.\nPressione qualquer tecla para continuar: ");
					getchar();
					getchar();
					continue;
				}
				operador = lista_vazia(li_sequencial);
				if(operador == 1){
					printf("\nBASE VAZIA.\nPressione qualquer tecla para continuar: ");
					getchar();
					getchar();
					continue;
				}
				imprimir_na_ordem(li_sequencial);
				interacoes++;
				}else{
					printf("Opção inválida!\n");
					getchar();
					getchar();
			}/*fim if-else 'EX'*/
		}/*fim if-else 'IU IM IN'*/



	}/*fim while*/

libera_lista(li_sequencial); /*Limpa a memória alocada anteriormente*/
return 0;
}/*fim da função main*/
