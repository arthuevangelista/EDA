#include<stdio.h>
#include<stdlib.h>
#define M 10 // Para exercício 1 N <= M = 6
#define N 6 // Para exercício 2 N > M = 6

/*===================================================*/
/*        Aluno: Arthur Evangelista dos Santos		 */
/*              Matrícula: 14/0016686                */
/*													 */
/*					FILA ESTÁTICA					 */
/*													 */
/*===================================================*/

struct fila{
	int init, final, qtd;
	int dados[M];
};

typedef struct fila Fila;

Fila* cria_fila(){
/* Cria a fila Estática*/

	Fila *fi  = (Fila*)malloc(sizeof(struct fila));
	if(fi != NULL){
		fi->init = 0;
		fi->final = 0;
		fi->qtd = 0;
	}
	return fi;
}

void libera_fila(Fila* fi){
/* Destrói a fila Estática*/
	free(fi);
}

/* Verifica se a fila está vazia*/
int fila_vazia(Fila* fi){
	if(fi != NULL){
		if(fi->qtd == 0){
			printf("Fila vazia!\n");
			getchar();
			getchar();
			return 1;
		}else{
			return 0;
		}
	}
}

/* Verifica a quantidade de itens na fila*/
void fila_qtd(Fila* fi){
	if(fi != NULL)
		printf("A quantidade de elementos da fila é %d\n", fi->qtd);
}

/* Verifica se a fila está cheia*/
int fila_cheia(Fila* fi){
	if(fi != NULL){
		if(fi->qtd == N){
			printf("Fila cheia!\n");
			getchar();
			getchar();
			return 1;
		}else{
			return 0;
		}
	}
}

int insere_fila(Fila* fi, int dados){
	if(fi != NULL){
		if(fila_cheia(fi)){
			return 0;
		}
		fi->dados[fi->final] = dados;
		fi->final = (fi->final  + 1) % M; // Se final+1 = M, então resultado do div mod é fi->init ( == 0)
		fi->qtd++;
		return 1;
	}
}

int remove_fila(Fila* fi){
	if(fi != NULL){
		if(fila_vazia(fi)){
			return 0;
		}
		fi->init = (fi->init  + 1) % M; // Apenas avança uma posição na fila. Quando fi->init+1 == M, então init circula pro inicio ( == 0). NÃO SE APAGA nenhum dado do vetor
		fi->qtd--;
		return 1;
	}
}

void imprimir_fila(Fila* fi){
	int i = fi->init;

	while(i != fi->final){
		printf("Posição = %d, Item = %d\n", i, fi->dados[i]);
		i = (i+1)%M;
	}
}

int main(){
	Fila* fi; // int fila[M]; -- sem uso de ponteiro
	int op = 1; int codigo;
	int dados;

/* Cria a lista */
	fi = cria_fila();

	while(codigo != 4){
		setbuf(stdin, NULL); /*Limpa o buffer do teclado*/

/*Menu principal*/
		system("clear");
		printf("\t\t>> Código <<\n");
		printf("0 - Insere dado na fila\n");
		printf("1 - Remove dado da fila\n");
		printf("2 - Imprima os dados da fila\n");
		printf("3 - Imprime quantidade de dados\n");
		printf("4 - Sair do programa\n");
		printf("\nInsira o código: ");
		scanf("%d", &codigo);

		switch(codigo){
			case 0:
				printf("\nInsira o valor do dado: ");
				scanf("%d", &dados);

			/* Insere itens na fila*/
				op  = insere_fila(fi, dados);
				break;
			case 1:
				printf("\nO primeiro valor foi removido!\n");
			/* Remove item da fila*/
				op  = remove_fila(fi);
				break;
			case 2:
			/* Imprime os itens na fila*/
				imprimir_fila(fi);
				getchar();
				getchar();
				break;
			case 3:
			/* Verifica a quantidade de itens na fila*/
				fila_qtd(fi);
				getchar();
				getchar();
				break;
			case 4:
			/* Destrói a fila */
				libera_fila(fi);
				return 0;
				break;
			default:
				printf("Operação inválida!\n");
		}
	}
}
