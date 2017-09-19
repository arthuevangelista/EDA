#include <stdio.h>
#include <stdlib.h>
#define numpod 3
#define MAX_NAME 30

/*===================================================*/
/*        Aluno: Arthur Evangelista dos Santos		 */
/*              Matrícula: 14/0016686                */
/*===================================================*/

struct reg {
	char nome[MAX_NAME];
	int codprod, qtdven;
	float preunit, pretotal;
};

void leitura(struct reg produto[numpod]){
	int i = 0;

	printf("\n---------------------------------------------\n\tInsira as informacoes do produto");
	printf("\n---------------------------------------------\n");
	while(i<numpod){
		printf("\nNome do Produto: ");
		scanf("%s", produto[i].nome);
		printf("Código: ");
		scanf("%d", &produto[i].codprod);
		printf("Quantidade: ");
		scanf("%d", &produto[i].qtdven);
		printf("Preço: ");
		scanf("%f", &produto[i].preunit);
		produto[i].pretotal = produto[i].qtdven * produto[i].preunit;
		i++;
	}
}

void bubblesort(struct reg vetor[]){
/*Método da bolha*/
	int i, end = numpod;
	struct reg aux;
	int continua; /*= 1 true, = 0 false*/
	
	do{
		continua = 0;
		for(i = 0; i < (end - 1); i++){
			if(vetor[i].nome[0] > vetor[i + 1].nome[0]){
				aux = vetor[i];
				vetor[i] = vetor[i+1];
				vetor[i+1] = aux;
				continua = 1;
			}
		}
	end--;
	}while(continua != 0);

}

int main(){
	int j = 0;
	float FAT = 0;
	struct reg produto[numpod];

	leitura(produto);
	bubblesort(produto);

	system("clear");
	printf("\n================================================================================\n");
	printf("Nome\t\tCódigo\t\tQTDE\t\tPreço\t\tSub-total\t\t");
	printf("\n================================================================================\n");

	while(j<numpod){
		printf("%s\t\t%d\t\t%d\t\t%.2f\t\t%.2f\t\t\n", produto[j].nome, produto[j].codprod, produto[j].qtdven, produto[j].preunit, produto[j].pretotal);
		FAT+= produto[j].pretotal;
		j++;
	}
	printf("\n================================================================================\n");
	printf("\n\tFATURAMENTO: R$%.2f\n", FAT);
	printf("\n================================================================================\n");
return 0;
}
