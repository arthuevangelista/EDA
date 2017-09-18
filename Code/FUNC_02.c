#include<stdio.h>

int soma(int A[4][4]){
	int i = 0, j = 0;
	int resultado = 0;

	for(i = 0; i < 4; i++){
		for(j = 0; j < 4; j++){
			if((i == 1 && j == 0) || (i == 2 && j == 1) || (i == 3 && j == 2))
				resultado += A[i][j];
		}
	}

	return (resultado);
}

int main(){
	int i = 0, j = 0, A[4][4];
	printf("Insira os valores da Matriz A:\n");
	for(i = 0; i < 4; i++){
		for(j = 0; j < 4; j++){
			scanf("%d", &A[i][j]);
		}
	}
	
	printf("O resultado sera: %d\n\n", soma(A));
	return 0;
}
