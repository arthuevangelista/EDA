#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"pilhaEstatica.h"

#define MAX_BASES 300

void pares(Fila* fi){


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
  topo = 0;

  for(i = 0; i < N; i++){
    pilha[topo++] = s[i]; // Insere o vetor S na pilha
  }

  if(N%2 != 0){
    pilha[--topo]; // Verifica se é ímpar. Se for, retira o último item da pilha
  }

  for(i = 0){
    char* pilha = malloc( (N/2) * sizeof(char));
  }

  return 0;
}
