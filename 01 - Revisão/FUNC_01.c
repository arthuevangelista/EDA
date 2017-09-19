#include<stdio.h>

float media(int vetor[]){

/*Nao e necessario especificar o tamanho do vetor aqui ja que esta variavel local estara apenas recebendo a referencia de A na memoria*/
	int i = 0;
	float resultado = 0;
	while(i < 10){
	resultado += vetor[i];
	i += 1;
	}
	resultado = resultado/10;
	return (resultado);
}

int main(){
	int i = 0, A[10];

	printf("Insira os 10 valores do vetor A:\n");
	while(i<10){
		scanf("%d", &A[i]);
		i += 1;
	}
	
	printf("A media dos valores do vetor A e: %.2f\n", media(A));
	return 0;
}
