#include <stdio.h>
#define TAM_MAX 50 /*Use #DEFINE para definir var globais. Não precisa de ponto e virgula*/
#define TOTALUNOS 4

void leia_nome(char s[]){
	int tam = 0, c;
	printf("Nome: ");
	while(c != '.'){
		c = getchar();
		s[tam] = c;
		tam++;
	}
	s[tam+1] = '\0';
}

int leia_nota(int aluno){
	int nota = 0;
	printf("Nota: ");
	scanf("%d", &nota);
	return (nota);
}

int main(){
	char naluno[TOTALUNOS][TAM_MAX];
	int notaluno[TOTALUNOS];
	int i=0,ind=-1,maior_nota;

	while(i<TOTALUNOS){
		printf("----------------------------------");
		printf("\nSobre o aluno %d\n", (i+1));
		leia_nome(naluno[i]);
		notaluno[i] = leia_nota(i);
		i++;
	}

	maior_nota = -1; i = 0;
	while(i<TOTALUNOS){
		if(notaluno[i]>maior_nota){
			maior_nota = notaluno[i];
			ind = i;
		}
	i++;
	}

	printf("\n---------------------------------------\n");
	printf("LAUREADO : %s COM NOTA %d", naluno[ind], notaluno[ind]);
	printf("\n---------------------------------------\n");
return 0;
}
