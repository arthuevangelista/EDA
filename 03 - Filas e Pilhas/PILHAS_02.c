#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"pilhaEstatica.h"

#define MAX_STRING 100

char * infixaParaPosfixa ( char inf[]) {
	// Converte a função infixa em uma função posfixa
	char *posf;
	char *pi; int topo; // pilha
	int N, i, j;
	N = strlen(inf);
	posf = mallocc( N * sizeof (char));
	pi = mallocc( N * sizeof (char));
	topo = 0;
	pi[topo++] = inf[0]; // insere o primeiro parenteses na pilha
	for (j = 0, i = 1; /*PP*/ inf[i] != '\0'; ++i) {
			// a pilha está em pi[0..topo-1]
			switch (inf[i]) {
					char x;
					case '(': // se for parentese
						pi[topo++] = inf[i]; // empilha o parentese
						break;
					case ')': // se fechar parentese
						while (1) {
							x = pi[--topo]; // desempilha
							if (x == '(') break;
							posf[j++] = x;
						}// fim while

						break;
					case '+':
					case '-':
						while (1) {
							x = pi[topo-1];
							if (x == '(') break;
							--topo;
							// desempilha
							posf[j++] = x;
						}// fim while
						pi[topo++] = inf[i];
						// empilha
						break;
					case '*':
					case '/':
						while (1) {
							x = pi[topo-1];
							if (x == '(' || x == '+' || x == '-')
								break;
							--topo;
							posf[j++] = x;
						} // fim while
						pi[topo++] = inf[i];
						break;
						case ' ':
							break;
					default: posf[j++] = inf[i];
				} // fim switch
			} // fim for
			free( pi);
			posf[j] = '\0';
			return posf;
}// fim func infixaParaPosfixa

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



int main(){
	char s[MAX_STRING];
	char* posfixa;

	printf("Insira uma expressão matemática: \n");
	lerString(s);

	posfixa = infixaParaPosfixa(s);



	return 0;
}
