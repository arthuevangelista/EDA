#include<stdio.h>
#include<stdlib.h>
#define TAM_VET 7

void case_1(int vetor[]){
/*Case 1 - Alimentar vetor (7 valores distintos)*/
	int i = 0;	
	system("clear");
	printf("Insira o vetor de números a ser analisado: \n");
	setbuf(stdin, NULL);
	while(i<TAM_VET){
		scanf("%d", &vetor[i]);
		i++;
	}
	return;
}

void case_2(int vetor[]){
/*Case 2 - Ordenar vetor (método da bolha)*/
	int i, aux, end = TAM_VET;
	int continua; /*= 1 true, = 0 false*/
	
	do{
		continua = 0;
		for(i = 0; i < (end - 1); i++){
			if(vetor[i] > vetor[i + 1]){
				aux = vetor[i];
				vetor[i] = vetor[i+1];
				vetor[i+1] = aux;
				continua = 1;
			}
		}
	end--;
	}while(continua != 0);

}

void case_3(){
/*Case 3 - Consultar vetor (pesquisa sequencial)*/
system("clear");
}

int case_4(int *v, int K){
/*Case 4 - Consultar vetor (pesquisa binária)*/
int res, init, fim, meio;

res = -1;
init = 0; fim = 6;

do{
	meio=(init+fim)/2;
	if(K<v[meio])
		fim = meio - 1;
	else
		init = meio + 1;
}while((init <= fim)&&(K != v[meio]));

if(K = v[meio])
	res = meio;

return (res);
}

void case_5(int v[]){
/*Case 5 - Imprimir vetor*/
	system("clear");
	int i = 0;

	printf("Seu vetor é:\n");
	while(i < TAM_VET){
		printf("v[%d] = %d\n", i, v[i]);
		i++;
	}
	printf("\n\nPressione qualquer tecla para voltar...");
	getchar();
	getchar();
}

int main(){
	char c = 'z';
	int K;
	int result = 0, zero, vetor[TAM_VET];

while(c != '0'){
	setbuf(stdin, NULL); /*Limpa o buffer do teclado*/

	system("clear");
	printf("\t\t>> MENU <<\n");
	printf("1 - Alimentar vetor (7 valores distintos)\n");
	printf("2 - Ordenar vetor (método da bolha)\n");
	printf("3 - Consultar vetor (pesquisa sequencial)\n");
	printf("4 - Consultar vetor (pesquisa binária)\n");
	printf("5 - Imprimir vetor\n");
	printf("0 - SAIR\n");
	printf("\t\tOPÇÃO: ");
	c = getchar();

	switch(c){
		case '0' :
			break;
		case '1' :
			case_1(vetor);
			break;
		case '2' :
			case_2(vetor);
			break;
		case '3' :
			case_3();
			break;
		case '4' :
			system("clear");

			printf("Insira um número para pesquisar: ");
			scanf("%d", &K);
			result = case_4(vetor, K);
			printf("\n===============================\n");
			printf("\nSeu número encontra-se em v[%d]\n", result);
			printf("\n===============================\n");
			printf("\n\nPressione qualquer tecla para voltar...");
			getchar();
			getchar();
			break;
		case '5' :
			case_5(vetor);
			break;
		default :
			printf("Opção inválida!\n");
	}
}

}
