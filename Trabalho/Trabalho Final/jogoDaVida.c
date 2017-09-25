#include <stdio.h>
#include <stdlib.h> /*Pra fazer o clear*/
#define FINAL 40 /*Para mostrar eficientemente a GGG é necessário uma matriz 40x40*/

/*===================================================================================*/
/*							OO - Exercício de Programação 1						     */
/*===================================================================================*/
/* Engenheiro: Arthur Evangelista												     */
/* Data: 07/09/2017													                 */
/* Mais informações: <https://gitlab.com/oofga/eps_2017_2/ep1/wikis/home>            */
/*																			         */
/*																			         */
/*								CÓPIA NÃO COMÉDIA                                    */
/*																			         */
/*===================================================================================*/


/*'o' = bloco      ' ' = espaço vazio*/

void block(int posicaox, int posicaoy, char mundo[FINAL][FINAL]){
	mundo[posicaoy][posicaox] = 'o';
	mundo[posicaoy][posicaox + 1] = 'o';
	mundo[posicaoy + 1][posicaox] = 'o';
	mundo[posicaoy + 1][posicaox + 1] = 'o';
}

void blinker(int posicaox, int posicaoy, char mundo[FINAL][FINAL]){
	mundo[posicaoy][posicaox] = 'o';
	mundo[posicaoy][posicaox + 1] = 'o';
	mundo[posicaoy][posicaox + 2] = 'o';
}

void glider(int posicaox, int posicaoy, char mundo[FINAL][FINAL]){
	mundo[posicaoy][posicaox] = 'o';
	mundo[posicaoy + 1][posicaox + 1] = 'o';
	mundo[posicaoy + 1][posicaox + 2] = 'o';
	mundo[posicaoy][posicaox + 2] = 'o';
	mundo[posicaoy - 1][posicaox + 2] = 'o';
}

void gosperGliderGun(int posicaox, int posicaoy, char mundo[FINAL][FINAL]){
	posicaox--; posicaoy--;
	/*36 direita p esquerda
	9 cima pra baixo*/

	mundo[posicaoy+5][posicaox+11] = 'o';
	mundo[posicaoy+6][posicaox+11] = 'o';
	mundo[posicaoy+7][posicaox+11] = 'o';
	mundo[posicaoy+4][posicaox+12] = 'o';
	mundo[posicaoy+8][posicaox+12] = 'o';
	mundo[posicaoy+3][posicaox+13] = 'o';
	mundo[posicaoy+9][posicaox+13] = 'o';
	mundo[posicaoy+3][posicaox+14] = 'o';
	mundo[posicaoy+9][posicaox+14] = 'o';
	mundo[posicaoy+6][posicaox+15] = 'o';
	mundo[posicaoy+5][posicaox+17] = 'o';
	mundo[posicaoy+6][posicaox+17] = 'o';
	mundo[posicaoy+7][posicaox+17] = 'o';
	mundo[posicaoy+4][posicaox+16] = 'o';
	mundo[posicaoy+8][posicaox+16] = 'o';
	mundo[posicaoy+6][posicaox+18] = 'o';

	mundo[posicaoy+3][posicaox+21] = 'o';
	mundo[posicaoy+4][posicaox+21] = 'o';
	mundo[posicaoy+5][posicaox+21] = 'o';
	mundo[posicaoy+3][posicaox+22] = 'o';
	mundo[posicaoy+4][posicaox+22] = 'o';
	mundo[posicaoy+5][posicaox+22] = 'o';
	mundo[posicaoy+2][posicaox+23] = 'o';
	mundo[posicaoy+6][posicaox+23] = 'o';
	mundo[posicaoy+1][posicaox+25] = 'o';
	mundo[posicaoy+2][posicaox+25] = 'o';
	mundo[posicaoy+6][posicaox+25] = 'o';
	mundo[posicaoy+7][posicaox+25] = 'o';

	block(posicaox, (posicaoy + 5), mundo);
	block((posicaox + 35), (posicaoy + 3), mundo);

}

void aplicaRegra (int posicaox, int posicaoy, char mundo[FINAL][FINAL], char futuro[FINAL][FINAL]){
	int contador = 0;
	int i = 0, j = 0;
	int vida;
	
/*pra debugging 	printf("y = %d, x = %d\n", posicaoy, posicaox);*/
	
	if(mundo[posicaoy][posicaox] == 'o'){
		vida = 1;
	}else{
		vida = 0;
	}
	
	for(j = posicaox - 1; j < posicaox + 2; j++){
		for(i = posicaoy - 1; i < posicaoy + 2; i++){
			if(mundo[i][j] == 'o'){
				if((i == posicaoy) && (j == posicaox)){
				}else{
					contador++;}
			}
/*pra debugging printf("i = %d, j = %d, contagem = %d\n", i, j, contador);*/
		}
	}

	switch (contador){
		case 0:
		case 1:
			futuro[posicaoy][posicaox] = ' ';
			break;
		case 2:
			if(vida == 1)
				futuro[posicaoy][posicaox] = 'o'; /*Senão, mantém morto*/
			break;
		case 3:
			futuro[posicaoy][posicaox] = 'o';
			break;
		default:
			futuro[posicaoy][posicaox] = ' ';
}

}

void telaInicial(){
/*Pura estética*/

	system("clear");
	printf("======================================================================\n\n");
	printf("\t\t\tO JOGO DA VIDA");
	printf("\n\n======================================================================\n");
	printf("\n\nPressione qualquer tecla para continuar ");
	getchar();
}

struct dados{
/*Estrutura com os dados do usuário sobre a figura*/
	int num_figuras, x, y;
	int tipo_figura[FINAL];
};

void userInput(struct dados Figura, char mundo[FINAL][FINAL]){
/*Recebe os dados do usuário*/
	int i = 0;

	telaInicial();
	system("clear");
	printf("Insira a quantidade de figuras que deseja inserir: ");
	scanf("%d", &Figura.num_figuras);
	while(i < Figura.num_figuras){
		system("clear");
		printf("Escolha as figuras que deseja adicionar:\n");
		printf("1 - Block\n");
		printf("2 - Blinker\n");
		printf("3 - Glider\n");
		printf("4 - Gosper Glider Gun\n");
		scanf("%d", &Figura.tipo_figura[i]);
		system("clear");
		printf("Escolha a posição desta figura (em x, y):\n");
		scanf("%d %d", &Figura.x, &Figura.y);
		switch (Figura.tipo_figura[i]){
			case 1:
				block(Figura.x, Figura.y, mundo);
				i++;
				break;
			case 2:
				blinker(Figura.x, Figura.y, mundo);
				i++;
				break;
			case 3:
				glider(Figura.x, Figura.y, mundo);
				i++;
				break;
			case 4:
				gosperGliderGun(Figura.x, Figura.y, mundo);
				i++;
				break;
			default:
				printf("Entrada inválida");
		}
	}
}

int main(){
/*Função principal - responsável por mundo receber futuro e atualiza a matriz*/
	int posicaox = 0, posicaoy = 0;
	int num_figuras, i = 0;
	int x = 0, y = 0;
	char mundo[FINAL][FINAL], futuro[FINAL][FINAL];
	struct dados Figura;
	
	for(posicaoy = 0; posicaoy < FINAL; posicaoy++){
		for(posicaox = 0; posicaox < FINAL; posicaox++){
			mundo[posicaoy][posicaox] = ' ';
		}
	}

	userInput(Figura, mundo); /*Chamada da função para receber os dados do usuário*/

	for(posicaoy = 0; posicaoy < FINAL; posicaoy++){
		for(posicaox = 0; posicaox < FINAL; posicaox++){
			futuro[posicaoy][posicaox] = mundo[posicaoy][posicaox];
		}
	}

	for(posicaoy = 0; posicaoy < FINAL; posicaoy++){
		for(posicaox = 0; posicaox < FINAL; posicaox++){
			printf("%c", mundo[posicaoy][posicaox]);
		}
		printf("\n");
	}

	getchar();
	getchar();
	
	while(1 == 1){
		system("clear");
		for(posicaoy = 1; posicaoy < FINAL - 1; posicaoy++){
			for(posicaox = 1; posicaox < FINAL - 1; posicaox++){
				aplicaRegra(posicaox, posicaoy, mundo, futuro);
			}
		}
		
		for(posicaoy = 0; posicaoy < FINAL; posicaoy++){
			for(posicaox = 0; posicaox < FINAL; posicaox++){
				mundo[posicaoy][posicaox] = futuro[posicaoy][posicaox];
			}
		}
		
		for(posicaoy = 0; posicaoy < FINAL; posicaoy++){
			for(posicaox = 0; posicaox < FINAL; posicaox++){
				printf("%c", mundo[posicaoy][posicaox]);
			}
			printf("\n");
		}

	getchar();
	getchar();

	}
	
	return 0;
}
