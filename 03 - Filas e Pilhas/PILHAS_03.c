#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"pilhaEstatica.h"
#include"filaEstatica.h"

#define MAX_BASES 300

struct fila{
	int init, fim, qtd;
	int rnaa[MAX_BASES];
};

typedef struct fila Fila;

Fila* cria_fila(){
/* Cria a fila Estática*/
	Fila *fi  = (Fila*)malloc(sizeof(struct fila));
	if(fi != NULL){
		fi->init = 1;
		fi->fim = 1;
		fi->qtd = 0;
	}
	return fi;
}

void pares(Fila* fi){
  switch(fi->fim){
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

}

//
int main(){
  Fila* fi;
  fi = cria_fila();

  free(fi);
  return 0;
}
