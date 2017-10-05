#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_BASES 300

void dobra(char* pilha, int* t, int* contagem); // Protótipo de função
void verifica(char* pilha, char* aux, int* topp, int* t, int* cont);  // Protótipo de função

void ler_nome(char *s){
// Função ler o nome
    char c;
    c = getchar();
    while(c!='\n'){
        *s = c;
        c=getchar();
        s++;
    }
}

int main(){
  char s[MAX_BASES];
  int i, t, contagem;
  int N;

  printf("Insira as bases do RNAA: \n");
  ler_nome(s);

  N = strlen(s);
  char* pilha = malloc(N*sizeof(char)); // Cria uma pilha do tamanho do vetor S
  t = 0;

  for(i = 0; i < N; i++){
    pilha[t++] = s[i]; // Insere o vetor S na pilha
  }

  dobra(pilha, &t, &contagem); // dobra t em um auxiliar e retorna o novo valor do topo da pilha

  printf("O número de pares são: %d", contagem);

  free(pilha);
  return 0;
}

/*----------------------------------------------------*/
/*                FUNÇÃO VERIFICA                     */
/*----------------------------------------------------*/
/* Recebe duas pilhas e verifica o pareamento do      */
/* topo delas até que encontre um não pareamento      */
/* Quando ocorrido o não pareamento, envia cada pilha */
/* para a função dobra                                */
/*----------------------------------------------------*/

void verifica(char* pilha, char* aux, int* topp, int* t, int* cont){

  while(*t != 1){
    switch(pilha[*t]){
      case 'B':
        if(aux[*topp] == 'S'){
          *cont++; // soma contagem
          --*t; // desempilha pilha
          --*topp; // desempilha auxiliar
          break;
        }
      case 'C':
        if(aux[*topp] == 'F'){
          *cont++;
          --*t;
          --*topp;
          break;
        }
      case 'S':
        if(aux[*topp] == 'B'){
          *cont++;
          --*t;
          --*topp;
          break;
        }
      case 'F':
        if(aux[*topp] == 'C'){
          *cont++;
          --*t;
          --*topp;
          break;
        }
      default:
        dobra(pilha, t, cont);
        dobra(aux, topp, cont);
    }
  }
}

/*----------------------------------------------*/
/*                FUNÇÃO DOBRA                  */
/*----------------------------------------------*/
/* Recebe uma string, dobra esta string e manda */
/* realizar o pareamento dessa pilha !          */
/*----------------------------------------------*/

void dobra(char* pilha, int* t, int* contagem){
  int M; int i;
  M = strlen(pilha);
  int topp;

  if(M%2 != 0){
    --*t; // Verifica se é ímpar. Se for, retira o último item da pilha
  }

  topp = 0;
  char* aux = malloc( (M/2) * sizeof(char));

  for(i = M; i != (M/2); i--){
    aux[topp++] = pilha[i]; // Empilha os valores de cima da pilha para aux
    pilha[--*t]; // desempilha i
  }

  verifica(pilha, aux, &topp, t, contagem);

  free(aux);
}
