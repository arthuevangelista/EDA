/* Considere o desenho da arvore
  apresentado e monte um programa com as
  opções a seguir:
  sair
  criar arvore(pre definida)
  destroi arvore
  consulta elemento
  imprimir arvore
*/

/* Casa
      Imprimir a arvore por nivel
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct arvore{
  char info;
  struct arvore* esq;
  struct arvore* dir;
}arv;

arv* criaVazia(){
  return NULL;
}
arv* criar(char c, arv* sae, arv* sad){
  arv* novo = (arv*)malloc(sizeof(arv));

  novo->info = c;
  novo->esq = sae;
  novo->dir = sad;
  return novo;
}

int arv_vazia(arv* a){
  return (a==NULL);
}

arv* destroi(arv* a){
  if(!arv_vazia(a)){
    destroi(a->esq);
    destroi(a->dir);
    free(a);
  }
  return NULL;
}

int consulta(arv* a, char c){
  if(arv_vazia(a))
    return 0;
  else
    return a->info == c || consulta(a->esq, c) || consulta(a->dir, c);
}

void imprimir(arv* a){
  if(!arv_vazia){
    printf("%c ",a->info);
    imprimir(a->esq);
    imprimir(a->dir);
  }
}

int main(){
  arv *a,*b,*c,*d,*e,*f;
  int opcao = 1;

  while(opcao){
    //menu
    switch(opcao){
      case 1:
        if(arv_vazia(a)){
          f = criar('f',NULL,NULL);
          e = criar('e',NULL,NULL);
          d = criar('d',NULL,NULL);
          b = criar('b',NULL,d);
          c = criar('c',e,f);
          a = criar('a',b,c);
        }
        break;
      case 2:
        a = destroi(a);
        break;
      case 3:
        if(consulta(a,'c'))
          printf("\nEncontrei\n");
        break;
      case 4:
        imprimir(a);
        break;
    }
  }

  return 0;
}
