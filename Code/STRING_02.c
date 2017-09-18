#include <stdio.h>

int main(){
	long nc = 0; int c;
	c = getchar();
	while (c != EOF){
	nc++; /*Conta o número de caracteres inseridos antes de ser dado um CTRL+D*/
	c = getchar();
	}
	
	printf("%ld\n", (nc-1));
	/*É printado nc-1 pq o ENTER dado para analisar o dado é contabilizado. Portanto, ao colocarmos nc-1, estamos ignorando o ENTER*/
	return 0;
}
