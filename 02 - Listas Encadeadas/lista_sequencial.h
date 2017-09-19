/* ---------------------------------------------*/
/*		HEADEAR COM PROTÓTIPO DAS FUNÇÕES		*/
/* ---------------------------------------------*/
/* Autor: Arthur Evangelista dos Santos		    */
/* Matrícula: 140016686						    */
/* ---------------------------------------------*/

#define MAX_NOME 30

struct registro{
	int matricula;
	char nome[MAX_NOME];
};

typedef struct lista Lista;

Lista* cria_lista();

void libera_lista(Lista* li);

int lista_cheia(Lista* li);

int lista_vazia(Lista* li);

int IU(Lista* li, struct registro aluno);

int IM(Lista* li, struct registro aluno);

int IN(Lista* li, struct registro aluno);

int EX(Lista* li, struct registro aluno);

void imprimir_na_ordem(Lista* li);
