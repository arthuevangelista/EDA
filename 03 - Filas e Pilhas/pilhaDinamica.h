#include<stdio.h>
#include<stdlib.h>
#define M 6

struct pilha{
	int init, final, qtd;
	int dados[M];
};

typedef struct pilha Pilha;

Pilha* init_pilha(Pilha* pi){
/* Cria a pilha Dinâmica*/

  pi = NULL;
  return pi;

}

Pilha* cria_slot(){
/* Cria a pilha Dinâmica*/

	Pilha *pi  = (Pilha*)malloc(sizeof(struct pilha));
	if(pi != NULL){
    pi->val = 0;
		pi->prox = NULL; // pi->prox = pi->topo
    pi->ant = NULL; // quando desempilhar, anterior vira novo proximo
	}
	return pi;
}

void libera_pilha(Pilha* pi){
/* Destrói a pilha Estática*/
	free(pi);
}

int pilha_vazia(Pilha* pi){
/* Verifica se a pilha está vazia*/
	if(pi == NULL){
			return 1;
		}else{
			return 0;
		}
	}
}

/* Inserção em pilhas é sempre realizado no início da pilha. Também existe o caso da pilha estar vazia e ser necessário realizar uma inserção. OBS.: Devemos verificar se a pilha está cheia antes de inserir elementos */

void empilha(Pilha* pi, int dados, Pilha* fim){
  Pilha* novo;
  novo = cria_slot();
	if(novo != NULL){
		novo->val = dados;
		pi->prox = novo;
		novo->ant = pi;
    fim = novo;
	}
}

/* Remoção em pilhas é sempre realizado no início da pilha. OBS.: Não se pode remover de uma pilha vazia! Devemos verificar antes se a pilha está vazia */

void desempilha(Pilha* pi, Pilha* fim){
  if(pilha_vazia(pi)){
    fim->ant->prox = NULL; // O próximo do fim->ant
    fim = fim->ant;
    free(fim->prox);
  }
}
