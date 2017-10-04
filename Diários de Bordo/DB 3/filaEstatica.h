#include<stdio.h>
#include<stdlib.h>
#define A 22 // Altere de acordo com o exercício
#define B 21 // Altere de acordo com o exercício

struct fila{
	int init, jnit, fim, jim, qtd;
	int dados[A][A];
};

typedef struct fila Fila;

Fila* cria_fila(){
/* Cria a fila Estática*/

	Fila *fi  = (Fila*)malloc(sizeof(struct fila));
	if(fi != NULL){
		fi->init = 1;
		fi->jnit = 1;
		fi->fim = 1;
		fi->jim = 1;
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
			return 1; // 1 para vazia
		}else{
			return 0;
		}
	}
}

/* Verifica a quantidade de itens na fila*/
int fila_qtd(Fila* fi){
int qtd;
	if(fi != NULL)
		qtd = fi->qtd;
	return qtd;
}

/* Verifica se a fila está cheia*/
int fila_cheia(Fila* fi){
	if(fi != NULL){
		if(fi->qtd == (B*B)){
			return 1; // 1 para cheia
		}else{
			return 0;
		}
	}
}

/* Inserção em filas é sempre realizado no fim da fila. Também existe o caso da fila estar vazia e ser necessário realizar uma inserção. OBS.: Devemos verificar se a fila está cheia antes de inserir elementos */

int insere_fila(Fila* fi, int dados){
	if(fi != NULL){
		if(!(fila_cheia(fi))){
			return 0;
		}
		fi->dados[fi->fim][fi->jim] = dados;
		fi->fim++;
		if(fi->fim == B){
			fi->fim = 1;
			fi->jim++;
		}
		fi->qtd++;
		return 1;
	}
}

/* Remoção em filas é sempre realizado no início da fila. OBS.: Não se pode remover de uma lista vazia! Devemos verificar antes se a lista está vazia */

int remove_fila(Fila* fi){
	if(fi != NULL){
		if(!(fila_vazia(fi))){
			return 0;
		}
		fi->fim--;
		if(fi->fim == 1){
			fi->fim = B;
			fi->jim--;
		}
		fi->qtd--;
		return 1;
	}
}
