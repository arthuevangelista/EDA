#include<stdio.h>
#include<stdlib.h>
#define M 6

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

int pilha_vazia(Pilha* pi){
/* Verifica se a pilha está vazia*/
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

void pilha_qtd(Pilha* pi){
/* Verifica a quantidade de itens na pilha*/
	if(pi != NULL)
		printf("A quantidade de elementos da pilha é %d\n", pi->qtd);
}

int pilha_cheia(Pilha* pi){
/* Verifica se a pilha está cheia*/
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

/* Inserção em pilhas é sempre realizado no início da pilha. Também existe o caso da pilha estar vazia e ser necessário realizar uma inserção. OBS.: Devemos verificar se a pilha está cheia antes de inserir elementos */

int empilha(Pilha* pi, int dados){
	if(pi != NULL){
		if(pilha_cheia(pi)){
			return 0;
		}
		pi->dados[pi->t] = dados;
		pi->t = (pi->t  + 1) % M;
		pi->qtd++;
		return 1;
	}
}

/* Remoção em pilhas é sempre realizado no início da pilha. OBS.: Não se pode remover de uma pilha vazia! Devemos verificar antes se a pilha está vazia */

int desempilha(Pilha* pi){
	if(pi != NULL){
		if(pilha_vazia(pi)){
			return 0;
		}
		pi->t = (pi->t  + 1) % M;
		pi->qtd--;
		return 1;
	}
}

void imprimir_pilha(Pilha* pi){
/* Função imprimir pilha */
	int i = pi->t;

	while(i != pi->init){
		printf("Posição = %d, Item = %d\n", i, pi->dados[i]);
		i = (i-1)%M;
	}
}
