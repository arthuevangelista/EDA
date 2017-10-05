#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_BASES 300

/*  switch(fi->fim){
    case 'B':
      // par será S
      break;
    case 'C':
      // par será F
      break;
    case 'S':
      // par será B
      break;
    case 'F':
      // par será C
      break;
    default:
      // caso inválido
  }
*/

// conta o número de bases
// divide no meio
// realiza o pareamento

// se não for par,

void dobra(char* pilha){
  int M; int i;
  M = strlen(pilha);
  int topp, t;

  topp = 0; t = M;
  char* aux = malloc( (M/2) * sizeof(char));

  for(i = M; i != (M/2); i--){
    aux[topp++] = pilha[i]; // Empilha os valores de cima da pilha para aux
    pilha[--t]; // desempilha i
  }

}

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
  char s[MAX_BASES];
  int i, topo;
  int N;

  printf("Insira as bases do RNAA: \n");
  ler_nome(s);

  N = strlen(s);
  char* pilha = malloc(N*sizeof(char)); // Cria uma pilha do tamanho do vetor S
  t = 0;

  for(i = 0; i < N; i++){
    pilha[t++] = s[i]; // Insere o vetor S na pilha
  }

  if(N%2 != 0){
    pilha[--t]; // Verifica se é ímpar. Se for, retira o último item da pilha
  }

printf("%d", N);


  return 0;
}
