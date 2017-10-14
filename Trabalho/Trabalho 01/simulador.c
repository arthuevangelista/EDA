/*
Projeto 1 - Estruturas de Dados

Integrantes:
  Arthur Evangelista dos Santos -140016686
  Rafael Makaha Gomes Ferreira - 160142369
  Renan Schadt Welz - 160143403
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>


//####################### Structs ################################
typedef struct processo{
    int tam;
    int duracao;
    int h_origem;
    char tipo;
    char* label;
    struct processo* prox;
    struct processo* ant;
}Processo;

typedef struct cab{
    int mem_total;
    int mem_livre;
    int num_proc;
    Processo* ini;
    Processo* fim;
}Cab;

//###################### Declaração de funções #####################
Cab* iniciaCab(Cab* l, int mem_total);
int lerMemoriaTotal();
void lerNome(char* s);
int menu1(Cab* l);
void menu2(Cab* l);
int checaMemoriaLivre(Cab* l, int temp_tam);
int inserirProcesso(Cab* l, char* nome, int tamanho);
int numeroRandom();
int retornaTempo();
void checaTempo(Cab* l);
Processo* removerProcesso(Cab* l, Processo* p);
Processo* unirBuracos(Cab* l, Processo* p);
void imprimirProcessos(Cab* l);
void realocarMemoria(Cab* l);
void salva_arquivo(Cab* l);
Cab* carrega_arquivo(Cab* l);
void escreverProcesso(Cab* l,Processo* aux);

/*################### Função principal do código #################*/
int main(){ 
    Cab* l;
    int mem_total;
    int opcao;

    opcao = menu1(l);
    switch(opcao){
      case 1:
        l = carrega_arquivo(l);
        break;
      case 2:
        mem_total = lerMemoriaTotal();
        l = iniciaCab(l, mem_total);
        break;    
    }
    menu2(l);

    return 0;
}

//############# Implementação de funções ###################

/*Inicializa o cabeçalho e a lista
para simulação da memoria do computador*/
Cab* iniciaCab(Cab* l, int mem_total){
  Processo* novo = (Processo*)malloc(sizeof(Processo));

  l = (Cab*)malloc(sizeof(Cab));
  l->mem_total = mem_total;
  l->mem_livre = l->mem_total;
  l->num_proc = 0;
  l->ini = l->fim = novo;

  novo->tipo = 'H';
  novo->tam = l->mem_total;
  novo->prox = novo;
  novo->ant = novo;

  return l;
}

/* Salva o tamanho total da memória
para se inicializar a simulação*/
int lerMemoriaTotal(){
    int tam_total;
    printf("\nInsira o tamanho total(em KiloBytes) da memória do sistema.\nValor: ");
    scanf("%d", &tam_total);
    return tam_total;
}

/* Lê o nome(label) para o processo
a ser inserido*/
void lerNome(char *s){
    char c;
    c = getchar();
    while(c!='\n'){
        *s = c;
        c=getchar();
        s++;
    }
    *s = '\0';
}


/*Menu de interação com o usuário*/
void menu2(Cab* l){
  int opcao=1, x;
  int temp_tam;
  char opcao2 = 'g';
  char temp_nome[50];

  while(opcao){
    system("clear");
    printf("\n1.Inserir Processo.");
    printf("\n2.Printar Processos.");
    printf("\n0.Sair");
    printf("\n Opcao: ");
    setbuf(stdin, NULL);
    scanf("%d", &opcao);
    checaTempo(l);
    switch(opcao){
      case 1:
        printf("\nInsira um label para o processo: ");
        setbuf(stdin, NULL);
        memset(temp_nome,0,sizeof(temp_nome));
        lerNome(temp_nome);
        printf("Insira o tamanho (em Kilobytes) do processo: ");
        scanf("%d", &temp_tam);
        if(temp_tam<1){
          printf("Tamanho inválido\n");
          break;
        }
        if(checaMemoriaLivre(l, temp_tam)){
          checaTempo(l);
          if(inserirProcesso(l, temp_nome, temp_tam)){
            realocarMemoria(l);
            x = inserirProcesso(l, temp_nome, temp_tam);
          }
        }
        else{
          printf("\n Processo extrapola o tamanho da memória");
        }
        break;
      case 2:
        checaTempo(l);
        imprimirProcessos(l);
        getchar();
        getchar();
        break;
      case 3:
        salva_arquivo(l);
        break;
      default:
        break;
    }
  }
}

/*Faz verificação se o novo processo
pode ser inserido na lista de processos,
tomando como base seu tamanho e o 
tamanho da memória livre*/
int checaMemoriaLivre(Cab* l, int temp_tam){
  if(temp_tam <= l->mem_livre)
    return 1;
  return 0;
}

/*Insere um processo na lista de processos*/
int inserirProcesso(Cab* l, char* nome, int tamanho){
  int flag = 1;
  Processo* novo = (Processo*)malloc(sizeof(Processo));
  Processo* p = l->ini;

  novo->tipo = 'P';
  novo->tam = tamanho;
  novo->label = (char*)malloc(sizeof(char) * strlen(nome));
  strcpy(novo->label, nome);
  novo->duracao = numeroRandom();
  novo->h_origem = retornaTempo();

  if(l->ini == l->fim){
    l->ini = novo;
    l->ini->prox = l->fim;
    l->ini->ant = l->fim;
    l->fim->prox = novo;
    l->fim->ant = novo;
    l->fim->tam = l->fim->tam - novo->tam;
    l->mem_livre = l->fim->tam;
    flag = 0;
  }else{
    do{
      if(p->tipo == 'H'){
        if(p->tam > novo->tam){
          p->ant->prox = novo;
          novo->ant = p->ant;
          p->ant = novo;
          novo->prox = p;
          p->tam = p->tam - novo->tam;
          l->mem_livre = l->mem_livre - novo->tam;
          flag = 0;
          break;
        }
        else if(p->tam == novo->tam){
          p->tipo = 'P';
          p->label = novo->label;
          p->duracao = novo->duracao;
          p->h_origem = novo->h_origem;
          l->mem_livre = l->mem_livre - novo->tam;
          free(novo);
          flag = 0;
          break;
        }
      }
      p = p->prox;
    }while(p != l->ini);
  }
  if(flag == 0)
    l->num_proc++;
  if(flag == 1)
    free(novo);

  return flag;
}

//Se dois processos forem adicionados no
//mesmo segundo, eles sempre terão a mesma duração
int numeroRandom(){
  srand(time(NULL));
  return (rand() % 1000) + 2;
}

int retornaTempo(){
  return (int)time(NULL);
}

/*Faz a verificação do tempo de vida
de um processo*/
void checaTempo(Cab* l){
  int aux;
  int atual = (int)time(NULL);
  Processo* p = l->ini;

  do{
    if(p->tipo == 'P'){
      aux = atual - p->h_origem;
      if(aux >= p->duracao){
        p = removerProcesso(l,p);
      }
    }
    p = p->prox;
  }while(p != l->ini);

}

/* Transforma um processo ativo em inativo,
ou seja, torna-o uma lacuna*/
Processo* removerProcesso(Cab* l, Processo* p){
  p->tipo = 'H';
  l->mem_livre = l->mem_livre + p->tam;
  l->num_proc--;
  if(p->ant->tipo == 'H' || p->prox->tipo == 'H')
    p = unirBuracos(l, p);
  return p;
}

/* Une lacunas que estejam próximas umas das outras */
Processo* unirBuracos(Cab* l, Processo* p){
  Processo* q = p->ant;
  Processo* y = p->prox;

  if(l->num_proc == 0){
    p->prox->tam = l->mem_total;
    l->mem_livre = l->mem_total;
    y->prox = y;
    y->ant = y;
    l->ini = y;
    free(p);
    return y;
  }
  else if(p->ant->tipo == 'H' && p->prox->tipo == 'H'){
    p->ant->ant->prox = p;
    p->ant = p->ant->ant;
    p->prox->prox->ant = p;
    p->prox = p->prox->prox;
    p->tam = p->tam + q->tam + y->tam;

    if(l->ini == q){
      l->ini = p;
    }
    else if(l->fim == q){
      l->fim = p->ant;
    }
    else if(l->fim == p){
      l->ini = p->prox;
    }
    else if(l->fim == y){
      l->fim = p;
    }
    free (q);
    free (y);
  }
  else if(p->ant->tipo == 'H'){
    p->ant->prox = p->prox;
    p->prox->ant = p->ant;
    p->ant->tam = p->ant->tam + p->tam;
    if(l->ini == p){
      l->ini = y;
    }
    else if(l->fim == p){
      l->fim = q;
    }
    free(p);
    return q;
  }
  else if(p->prox->tipo == 'H'){
    p->prox->prox->ant = p;
    p->prox = p->prox->prox;
    p->tam = p->tam + y->tam;
    if(l->ini == y){
      l->ini = p->prox;
    }
    else if(l->fim == y){
      l->fim = p;
    }
    free(y);
  }
  return p;
}

/*Imprime os processos e lacunas atuais*/
void imprimirProcessos(Cab* l){
  Processo* p = l->ini;
  do{
    if(p->tipo == 'P'){
      printf("\nProcesso-> Label: %s ; tamanho: %d",p->label, p->tam);
    }
    if(p->tipo == 'H'){
      printf("\nLacuna-> tamanho: %d", p->tam);
    }
    p = p->prox;
  }while(p != l->ini);
  printf("\n\n Mem_Livre: %d ; Quant_proc: %d", l->mem_livre, l->num_proc);
}


/*Reorganiza os processos e as lacunas de memória
para fazer caber novos processos */
void realocarMemoria(Cab* l){
  int i=0, flag=0;
  Processo* p = l->ini;
  Processo* y = p->prox;
  Processo* novo = (Processo*)malloc(sizeof(Processo));

  if(l->fim->tipo == 'H'){
    do{
      if(p->tipo == 'H'){
        if(p == l->ini && flag==0){
          p = y;
          y = y->prox;
          flag++;
          continue;
        }
        p->ant->prox = p->prox;
        p->prox->ant = p->ant;
        l->mem_livre += p->tam;
        free(p);
        p = NULL;
      }
      p = y;
      y = y->prox;
    }while(p != l->ini);



  }else{
    novo->tipo = 'H';
    novo->tam = 0;
    l->fim->prox = novo;
    l->ini->ant = novo;
    novo->prox = l->ini;
    novo->ant = l->fim;
    l->fim = novo;
    do{
      if(p->tipo == 'H'){
        if(p == l->ini && flag==0){
          p = y;
          y = y->prox;
          flag++;
          continue;
        }
        p->ant->prox = p->prox;
        p->prox->ant = p->ant;
        l->mem_livre += p->tam;
        free(p);
        p = NULL;
      }
      p = y;
      y = y->prox;
    }while(p != l->fim);
  }
  if(flag){
    y = l->ini;
    l->fim->prox = y->prox;
    y->prox->ant = l->fim;
    l->ini = y->prox;
    l->mem_livre += y->tam;
    free(y);
  }
  l->fim->tam = l->mem_livre;
}

void salva_arquivo(Cab* l){
  /* Função para salvar o arquivo */
  
    FILE* f;
    int op;
    Processo* aux;
    aux = l->ini;
    int i;
  
    f = fopen("simulacao.txt","w+"); // salva na mesma pasta que o prog principal
  
    if(f == NULL){
      /* Verifica se ocorreu falha ao salvar o arquivo */
      printf("Erro ao salvar arquivo!\n");
      getchar();
      getchar();
    }else{
      
  
      /* Caso tenha dado certo criar o arquivo salva:
      Na PRIMEIRA LINHA: Cab */
      fprintf(f, "%d", l->mem_total);
      fputc('\n', f);
      /* Na SEGUNDA e demais linhas: label, tamanho e duração*/
      
  
      /* Grava os itens da lista */
      while(aux->prox != l->ini){
        fputc(aux->tipo, f);
        fputc(' ', f);
        if(aux->tipo == 'P'){
          fputs(aux->label,f);
          fputc(' ', f);
          fprintf(f, "%d", aux->tam);
          fputc(' ', f);
          fprintf(f, "%d", aux->duracao);
          fputc('\n', f);
        }else{
          fputs("h",f);
          fputc(' ', f);
          fprintf(f, "%d", aux->tam);
          fputc(' ', f);
          fprintf(f, "%d", 0);
          fputc('\n', f);
        }
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

Cab* carrega_arquivo(Cab* l){
    FILE* f;
    int op;
    int lixo;
    int i;
    char* c;
    int mem_total;
    Processo* aux = (Processo*)malloc(sizeof(Processo));            
    aux->label = (char*)malloc(sizeof(char)*50);
  
    f = fopen("simulacao.txt","r");
  
    if(f == NULL){
      printf("Erro ao ler arquivo!\n");
      getchar();
      getchar();
    }else{
      fscanf(f, "%d\n", &mem_total);
      l = iniciaCab(l,mem_total);
      l->mem_livre = mem_total;
        while (fscanf(f, "%c %s %d %d\n",&aux->tipo,aux->label, &aux->tam, &aux->duracao) != EOF) {
          escreverProcesso(l,aux);
      } /*fim do while*/
    }
  /* ao final, fecha o arquivo */
    op = fclose(f);
    if(op){
      printf("Dados carregados com sucesso!\n");
      getchar();
      getchar();
    }
    //free(aux->label);
    //free(aux);
return l;
}/* fim do carrega_arquivo */

int menu1(Cab* l){
  int opcao =0;
  while(opcao != 1 && opcao != 2){
    system("clear");
    printf("\nDeseja retomar a simulação anterior?");
    printf("\n1.Sim");
    printf("\n2.Não");
    printf("\nOpcao: ");
    scanf("%d", &opcao);
    switch(opcao){
      case 1:
        return 1;
        break;
      case 2:
        return 2;
        break;
    }
  }
}

void escreverProcesso(Cab* l, Processo* aux){
  Processo* novo = (Processo*)malloc(sizeof(Processo));
  
  novo->tipo = aux->tipo;
  novo->label = (char*)malloc(sizeof(char) * strlen(aux->label));
  strcpy(novo->label, aux->label);
  novo->tam = aux->tam;
  novo->duracao = aux->duracao;
  novo->h_origem = retornaTempo();
  if(l->num_proc == 0){
    l->ini = novo;
    l->fim->ant = novo;
    l->fim->prox = novo;
    novo->ant = l->fim;
    novo->prox = l->fim;
    l->mem_livre -= novo->tam;
    l->fim->tam = l->mem_livre;

  }else{
    l->fim->ant->prox = novo;
    novo->ant = l->fim->ant;
    novo->prox = l->fim;
    l->fim->ant = novo;
    l->mem_livre -= novo->tam;
    l->fim->tam = l->mem_livre;
  }
    if(novo->tipo == 'P')
      l->num_proc++;
  
}

