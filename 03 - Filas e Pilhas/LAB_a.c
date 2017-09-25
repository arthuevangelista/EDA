#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
#include"filaEstatica.h"
#define MAXIMO 100

typedef int titem;

#define N 22
#define LIVRE 0
#define PAREDE 32767

void cria(int L[N][N]){
// Cria labirinto
	int i, j;
	for(i = 0; i < N; i++){
		L[i][0] = PAREDE;
		L[i][N - 1] = PAREDE;
	}
	for(j = 0; j < N; j++){
		L[0][j] = PAREDE;
		L[N - 1][j] = PAREDE;
	}

int num_randomico;

	for(i = 1; i < N - 1; i++){
		for(j = 1; j < N - 1; j++){
			num_randomico = rand();
			if((rand()%3 == 0) && (L[i][j] != PAREDE)) L[i][j] = PAREDE;
			else L[i][j] = LIVRE;
		}
	}

	L[1][1] = LIVRE;
	L[N - 2][N - 2] = LIVRE;
}

void exibe(int L[N][N]){
	int i, j;
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++)
			switch(L[i][j]){
				case LIVRE: putchar(' '); break;
				case PAREDE: putchar('#'); break;
				default: putchar(126);
			}
	printf("\n");
	}
}

void anota(int L[N][N]){
	L[1][1] = 1;
	Fila* fi; int op;
	fi = cria_fila();

	while(!(fila_vazia(fi))){
		
	}

libera_fila(fi);
}

// extrai()

int main(void){
	int L[N][N];
	char r;
	srand(time(NULL));
	do{
		system("clear");
		cria(L);
		anota(L);
		// extrai(L);
		exibe(L);
		// _gotoxy(1, N + 3);
		printf("Continua... (s/n) ");
		scanf("%c%*c", &r);
	}while(toupper(r) != 'N' );

	return 0;
}
