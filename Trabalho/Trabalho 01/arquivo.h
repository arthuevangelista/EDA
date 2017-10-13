#include<stdio.h>
#include<stdlib.h>

// Protótipo de função
void salva_arquivo(Cab* l, Processo* lista);

// Protótipo de função
void carrega_arquivo(Cab* l, Processo* lista);

void salva_arquivo(Cab* l, Processo* lista){
/* Função para salvar o arquivo */

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
    Processo* aux;
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

void carrega_arquivo(Cab* l, Processo* lista){
/* Função para carregar o arquivo */

  FILE* f;
  int op;

  f = fopen("simulacao.txt","r"); // lê na mesma pasta que o prog principal

  if(f == NULL){
    /* Verifica se ocorreu falha ao ler o arquivo */
    printf("Erro ao ler arquivo!\n");
    getchar();
    getchar();
  }else{
    int i;

    /* Caso tenha dado certo ler o arquivo carrega:
    Na PRIMEIRA LINHA: Cab */
    fscanf(f, "%d", &l->mem_total); // lê até que seja dado o \n
    /* Na SEGUNDA e demais linhas: LABEL, tamanho e duração*/
    Processo* aux;
    aux = l->ini;

    /* Grava os itens da lista */
    while (i != EOF) {
      fscanf(f, "%s %d %d", aux->LABEL, &aux->tam, &aux->DURACAO);
      // funcao_inserir(Processo* lista, aux->LABEL, aux->tam, aux->DURACAO);

      /* Para este protótipo, será inserido um novo nó no Processo* lista com os
       itens LABEL, tamanho e DURACAO como se estivessem sendo adicionados por
       um usuário */
      i = fgetc(f); // recebe item i do arquivo
      i++; // anda no arquivo
    } /*fim do while*/
  }


/* ao final, fecha o arquivo */
  op = fclose(f);
  if(op){
    printf("Dados carregados com sucesso!\n");
    getchar();
    getchar();
  }

}/* fim do carrega_arquivo */
