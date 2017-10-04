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
