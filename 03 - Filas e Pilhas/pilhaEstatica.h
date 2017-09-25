#include<stdio.h>
#include<stdlib.h>

Pilha* cria_pilha();

/* Inserção em pilhas é sempre realizado no início da pilha. Também existe o caso da pilha estar vazia e ser necessário realizar uma inserção. OBS.: Devemos verificar se a pilha está cheia antes de inserir elementos */

int insere_pilha(Pilha* pi, int dados);

/* Remoção em pilhas é sempre realizado no início da pilha. OBS.: Não se pode remover de uma pilha vazia! Devemos verificar antes se a pilha está vazia */

int remove_pilha(Pilha* pi, int dados);

/* Exercício 1 USP

1_ Se a posição ocupada pela pilha é de 0 a t, então a próxima posição vaga será t+1. Logo, a função insere_pilha será:

int empilha(Pilha* pi, DADO A SER INSERIDO){
	if(pi != NULL){
		if(pilha_cheia(pi)) return 0;
		pi->dados[pi->t++] = dados;
		pi->t = (pi->t  + 1) % M;
		pi->qtd++;
	}
}

2_

int empilha(Pilha* pi, int dados){
	if(pi != NULL){
		if(pilha_cheia(pi)) return 0;
		pi->dados[pi->t] = dados;
		pi->t = (pi->t  + 1) % M;
		pi->qtd++;
		return 1;
	}
}

int desempilha(Pilha* pi){
	if(pi != NULL){
		if(pilha_vazia(pi)) return 0;
		pi->t = (pi->t  + 1) % M;
		pi->qtd--;
		return 1;
	}
}

*/


/* Exercícios 2 USP



1_ 

*/
