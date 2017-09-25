#include<stdio.h>
#include<stdlib.h>
#define M 100

Fila* cria_fila();

/* Inserção em filas é sempre realizado no final da fila. Também existe o caso da fila estar vazia e ser necessário realizar uma inserção. OBS.: Devemos verificar se a fila está cheia antes de inserir elementos */

int insere_fila(Fila* fi, int dados);

/* Remoção em filas é sempre realizado no início da fila. OBS.: Não se pode remover de uma lista vazia! Devemos verificar antes se a lista está vazia */

int remove_fila(Fila* fi, int dados);
