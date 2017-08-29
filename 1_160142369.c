#include<stdio.h>

typedef struct{
  int ai;
  int di;
  int li;
  float dano;
}treinador;

float calculo(int bonus,int atk, int def,int lvl){
  float dano;
  if(lvl%2 != 0){
    bonus = 0;
  }
  dano = (atk+def)/2  +bonus;
  return dano;
}

int main(){
  int bonus;
  treinador player[2];

  scanf("%d", &bonus);

  scanf("%d %d %d", &player[0].ai, &player[0].di, &player[0].li);

  scanf("%d %d %d", &player[1].ai, &player[1].di, &player[1].li);

  player[0].dano = calculo(bonus, player[0].ai, player[0].di, player[0].li);
  player[1].dano = calculo(bonus, player[1].ai, player[1].di, player[1].li);

  if(player[0].dano == player[1].dano){
    printf("Empate\n");
  }
  if(player[0].dano > player[1].dano){
    printf("May: Se você tivesse beleza o que tem de derrota!\n");
  }
  if(player[0].dano < player[1].dano){
    printf("James: Eliminar a esperança é a nossa arte!\n");
  }

  return 0;
}
