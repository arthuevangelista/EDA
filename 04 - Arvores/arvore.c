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
  return(a==NULL);
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

void imprimirPreOrdem(arv* a){
/* Imprime itens de uma árvore binária pré-definida em pré-ordem.*/
  if(!arv_vazia(a)){
    printf("%c ",a->info);
    imprimirPreOrdem(a->esq);
    imprimirPreOrdem(a->dir);
  }
}

void imprimirEmOrdem(arv* a){
  /* Imprime itens de uma árvore binária pré-definida em ordem.*/
  if(!arv_vazia(a)){
    imprimirEmOrdem(a->esq);
    printf("%c ",a->info);
    imprimirEmOrdem(a->dir);
  }
}

void imprimirPolonesa(arv* a){
  /* Imprime itens de uma árvore binária pré-definida em pós-ordem.
  Esta impresão também é conhecida como notação Polonesa*/
  if(!arv_vazia(a)){
    imprimirPolonesa(a->esq);
    imprimirPolonesa(a->dir);
    printf("%c ",a->info);
  }
}

void imprimirLargura(char* fila, arv* a){
  /* Imprime itens de uma árvore binária pré-definida em largura.
  Insere os nós da árvore em uma fila e vai imprimindo elas de acordo. */
  if(!arv_vazia(a)){
    printf("%c ",a->info);
    fila++;
    *fila = a->esq->info;
    fila++;
    *fila = a->dir->info;
    imprimirLargura(fila,a->esq);
    imprimirLargura(fila,a->dir);

  }
}

char* criaFila(int pedra){
  char* fila = (char*)malloc(sizeof(char) * pedra);
  return fila;
}

int main(){
  arv *a = NULL,*b,*c,*d,*e,*f;
  int opcao = 1; char op = 'z';
  char* pedreiro;
  int pedra = 0;

  while(opcao){

    system("clear");
    printf("\t\t>> MENU <<\n\n");
    printf("0 - SAIR\n");
    printf("1 - Inserir arvore(pre definida)\n");
    printf("2 - Destrói árvore\n");
    printf("3 - Busca\n");
    printf("4 - Impressão pré-ordem\n");
    printf("5 - Impressão em ordem\n");
    printf("6 - Impressão pós-ordem (polonesa)\n");
    printf("7 - Impressão em largura\n");
    printf("\t\t\t\tOPÇÃO: ");
    setbuf(stdin, NULL);
    scanf("%d", &opcao);

    switch(opcao){
      case 1:
        if(arv_vazia(a)){
          f = criar('f',NULL,NULL);
          pedra++;
          e = criar('e',NULL,NULL);
          pedra++;
          d = criar('d',NULL,NULL);
          pedra++;
          b = criar('b',NULL,d);
          pedra++;
          c = criar('c',e,f);
          pedra++;
          a = criar('a',b,c);
          pedra++;
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
        imprimirPreOrdem(a);
        break;
      case 5:
        imprimirEmOrdem(a);
        break;
      case 6:
        imprimirPolonesa(a);
        break;
      case 7:
        pedreiro = criaFila(pedra);
        *pedreiro = a->info;
        imprimirLargura(pedreiro,a);
        free(pedreiro);
        break;
    }
  }

  return 0;
}
