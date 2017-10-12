/*
    Elabore um programa para receber uma expressão
    em notação polonesa e gerar o resultado
    da expressão.
    234+*
    A pilha de resolução deve ser implementada
    em lista encadeada
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct pilha{
    int val;
    struct pilha *prox;
    struct pilha *ant;
}Pilha;

Pilha* init_pilha(Pilha* pi);
Pilha* cria_slot(Pilha* l);
void libera_pilha(Pilha* fim);
int pilha_vazia(Pilha* pi);
void empilha(Pilha* l, int dados, Pilha* fim);
void desempilha(Pilha* l, Pilha* fim);
void ler_nome(char *s);
int resolve(char* posfixa, Pilha* l, Pilha* fim);

int main(){
	Pilha *l, *fim;
	char* s;
	int result;

	l = NULL;
	fim = NULL;

	ler_nome(s);
	
	result = resolve(s,l,fim);

	printf("Resultado: %d\n\n", result);



    return 0;
}

Pilha* init_pilha(Pilha* pi){
/* Cria a pilha Dinâmica*/
  pi = NULL;
  return pi;

}
Pilha* cria_slot(Pilha* l){
/* Cria um slot da Pilha */

	Pilha *pi  = (Pilha*)malloc(sizeof(struct pilha));
  if(!(pilha_vazia(l))){
  		pi->prox = NULL; // pi->prox = pi->topo
      pi->ant = NULL; // quando desempilhar, anterior vira novo proximo
  }else{
      l = pi;
  }
	return pi;
}



int pilha_vazia(Pilha* pi){
/* Verifica se a pilha está vazia*/
	if(pi == NULL){
			return 1;
		}else{
			return 0;
		}
}

void empilha(Pilha* l, int dados, Pilha* fim){
  Pilha* novo;
  novo = cria_slot(l);
	if(novo != NULL){
		novo->val = dados;
		if(!pilha_vazia(l)){
			l->prox = novo;
			novo->ant = l;
    		fim = novo;
		}else{
			l=novo;
			fim = novo;
		}
	}
}

void desempilha(Pilha* l, Pilha* fim){
  if(!pilha_vazia(l)){
    fim->ant->prox = NULL; // O próximo do fim->ant
    free(fim->prox);
    fim = fim->ant;
  }
}


int resolve(char* posfixa, Pilha* l, Pilha* fim){
	int resultado;
	char c;
	int i=0;
	
	for(i=0; i < strlen(posfixa); i++){
		c = posfixa[i++];
		switch (c){
			case '+':
				resultado = fim->val + fim->ant->val;
				desempilha(l,fim);
				desempilha(l,fim);
				empilha(l,resultado,fim);
				break;
			case '-':
				resultado = fim->ant->val - fim->val;
				desempilha(l,fim);
				desempilha(l,fim);
				empilha(l,resultado,fim);
				break;
			case '*':
				resultado = fim->val * fim->ant->val;
				desempilha(l,fim);
				desempilha(l,fim);
				empilha(l,resultado,fim);
				break;
			case '/':
				resultado = fim->ant->val / fim->val;
				desempilha(l,fim);
				desempilha(l,fim);
				empilha(l,resultado,fim);
				break;
			default:
				empilha(l,(c-'0'),fim);
		}
	}
	return resultado;
}
void ler_nome(char *s){
// Função ler o nome
    char c;
    //int i;
    c = getchar();
    while(c!='\n'){
        *s = c;
        c=getchar();
        s++;
     //   i++;
    }
}
