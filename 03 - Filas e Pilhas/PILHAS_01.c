#include<stdio.h>
#include<stdlib.h>
#define M 10
#define N 6

/*===================================================*/
/*        Aluno: Arthur Evangelista dos Santos		 */
/*              Matrícula: 14/0016686                */
/*													 */
/*					PILHA ESTÁTICA					 */
/*													 */
/*===================================================*/

struct pilha{
	int init, final, qtd;
	int dados[M];
};

typedef struct pilha Pilha;

Pilha* cria_pilha(){
/* Cria a pilha Estática*/

	Pilha *pi  = (Pilha*)malloc(sizeof(struct pilha));
	if(pi != NULL){
		pi->t = 0; // pi->t = pi->topo
		pi->init = 0;
		pi->qtd = 0;
	}
	return pi;
}

void libera_pilha(Pilha* pi){
/* Destrói a pilha Estática*/
	free(pi);
}

/* Verifica se a pilha está vazia*/
int pilha_vazia(Pilha* pi){
	if(pi != NULL){
		if(pi->qtd == 0){
			printf("Pilha vazia!\n");
			getchar();
			getchar();
			return 1;
		}else{
			return 0;
		}
	}
}

/* Verifica a quantidade de itens na pilha*/
void pilha_qtd(Pilha* pi){
	if(pi != NULL)
		printf("A quantidade de elementos da pilha é %d\n", pi->qtd);
}

/* Verifica se a pilha está cheia*/
int pilha_cheia(Pilha* pi){
	if(pi != NULL){
		if(pi->qtd == N){
			printf("Pilha cheia!\n");
			getchar();
			getchar();
			return 1;
		}else{
			return 0;
		}
	}
}

int empilha(Pilha* pi, int dados){
	if(pi != NULL){
		if(pilha_cheia(pi)){
			return 0;
		}
		pi->dados[pi->t] = dados;
		pi->t = (pi->t  + 1) % M; // Se t + 1 = M, então resultado do div mod é pi->init ( == 0)
		pi->qtd++;
		return 1;
	}
}

int desempilha(Pilha* pi){
	if(pi != NULL){
		if(pilha_vazia(pi)){
			return 0;
		}
		pi->t = (pi->t  + 1) % M; // Apenas avança uma posição na pilha. Quando pi->init+1 == M, então init circula pro inicio ( == 0). NÃO SE APAGA nenhum dado do vetor
		pi->qtd--;
		return 1;
	}
}

void imprimir_pilha(Pilha* pi){
	int i = pi->t;

	while(i != pi->init){
		printf("Posição = %d, Item = %d\n", i, pi->dados[i]);
		i = (i-1)%M;
	}
}

int main(){
	Pilha* pi; // int pilha[M]; -- sem uso de ponteiro
	int op = 1; int codigo;
	int dados;

/* Cria a lista */
	pi = cria_pilha();

	while(codigo != 4){
		setbuf(stdin, NULL); /*Limpa o buffer do teclado*/

/*Menu principal*/
		system("clear");
		printf("\t\t>> Código <<\n");
		printf("0 - Insere dado na pilha\n");
		printf("1 - Remove dado da pilha\n");
		printf("2 - Imprima os dados da pilha\n");
		printf("3 - Imprime quantidade de dados\n");
		printf("4 - Sair do programa\n");
		printf("\nInsira o código: ");
		scanf("%d", &codigo);

		switch(codigo){
			case 0:
				printf("\nInsira o valor do dado: ");
				scanf("%d", &dados);

			/* Insere itens na pilha*/
				op  = empilha(pi, dados);
				break;
			case 1:
				printf("\nO primeiro valor foi removido!\n");
			/* Remove item da pilha*/
				op  = desempilha(pi);
				break;
			case 2:
			/* Imprime os itens na pilha*/
				imprimir_pilha(pi);
				getchar();
				getchar();
				break;
			case 3:
			/* Verifica a quantidade de itens na pilha*/
				pilha_qtd(pi);
				getchar();
				getchar();
				break;
			case 4:
			/* Destrói a pilha */
				libera_pilha(pi);
				return 0;
				break;
			default:
				printf("Operação inválida!\n");
		}
	}
}
