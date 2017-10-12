#include<stdio.h>
#include<stdlib.h>

// Protótipo de função
void salva_arquivo();

// Protótipo de função
FILE* carrega_arquivo();

void salva_arquivo(Cab* l, Processo* lista){
/* Função para salvar o arquivo */
/* O retorno da função é um arquivo com os parametros de entrada de cada nó
(LABEL, tamanho e DURACAO). No momento de abertura do arquivo, estes parametros
serão carregados para a lista encadeada utilizando a função carrega_arquivo */

  FILE* f;
  int op;

  f = fopen("simulacao.txt","w"); // salva na mesma pasta que o prog principal

  if(f == NULL){
    /* Verifica se ocorreu falha ao salvar o arquivo */
    printf("Erro ao salvar arquivo!\n");
    getchar();
    getchar();
  }else{
    int i;

    /* Caso tenha dado certo criar o arquivo salva:
    Na PRIMEIRA LINHA: Cab */
    fprintf(f, "%d", l->mem_total);
    fputc('\n', f);
    /* Na SEGUNDA e demais linhas: LABEL, tamanho e duração*/
    Lista* aux;
    aux = l->ini;

    /* Grava o primeiro item da lista */
    for(i = 0; i <= strlen(lista->LABEL); i++){
      fputc(aux->LABEL[i], f);
    }
    fputc(' ', f);
    fprintf(f, "%d", aux->tam);
    fputc(' ', f);
    fprintf(f, "%d", aux->DURACAO);
    fputc('\n', f);

    /* Grava os demais itens da lista */
    while(aux->prox != l->ini){
      for(i = 0; i <= strlen(lista->LABEL); i++){
        fputc(aux->LABEL[i], f);
      }
      fputc(' ', f);
      fprintf(f, "%d", aux->tam);
      fputc(' ', f);
      fprintf(f, "%d", aux->DURACAO);
      fputc('\n', f);

      aux = aux->prox; /* Anda na lista */
    } /*fim do while*/
  }


/* ao final, fecha o arquivo */
  op = fclose(f);
  if(op){
    printf("Dados salvos com sucesso!\n");
    getchar();
    getchar();
  }

}/* fim do salva_arquivo */
