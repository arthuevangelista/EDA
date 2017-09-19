#include <stdio.h>

/*Exercícios

1_ Elabore um programa para calcular o n-ésimo termo da série de fibonacci.

2_ Elabore um programa para imprimir os primeiros m termos da série de fibonacci.

3_ Criar uma lista simplesmente encadeada com n termos (imprima usando recursividade na ordem inversa e na ordem normal) .*/

/*Fazer os 6 exercícios da lista usando duplamente encadeada*/

int fibonacci(int posicaoAtual){
	int resultado = 0;
	int temp;
	
	temp = posicaoAtual;
	if(posicaoAtual > -1)
		switch (posicaoAtual){
			case 0:
				resultado = 0; /*Regra 1*/
				break;
			case 1:
				resultado = 1; /*Regra 2*/
				break;
			default:		   /*CASO GERAL*/
				resultado = fibonacci((temp-1)) + fibonacci((temp-2));
				break;
		}
	return resultado;
}

int main(){
	int nesimo, posicaoAtual = 0;

	printf("Insira o n-ésimo termo da série de Fibonacci: ");
	scanf("%d", &nesimo);
	
	while(posicaoAtual < nesimo){
		printf("%d\n", fibonacci(posicaoAtual));
		posicaoAtual++;
	}
	return 0;
}
