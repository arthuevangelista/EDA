#include<stdio.h>
#define NUM_PLAYER 2

struct player{
int ataque, defesa, level;
int bonus;
float dano;

};

int main(){

	struct player Jogadores[NUM_PLAYER];
	int Bonus;

	scanf("%d", &Bonus);
	scanf("%d %d %d", &Jogadores[0].ataque, &Jogadores[0].defesa, &Jogadores[0].level);
	scanf("%d %d %d", &Jogadores[1].ataque, &Jogadores[1].defesa, &Jogadores[1].level);

	if((Jogadores[0].level % 2) == 0)
		Jogadores[0].bonus = Bonus;
	if((Jogadores[1].level % 2) == 0)
		Jogadores[1].bonus = Bonus;

Jogadores[0].dano = ((Jogadores[0].ataque + Jogadores[0].defesa)/2) + Jogadores[0].bonus;
Jogadores[1].dano = ((Jogadores[1].ataque + Jogadores[1].defesa)/2) + Jogadores[1].bonus;

if(Jogadores[0].dano == Jogadores[1].dano){
	printf("Empate\n");
}else{
if(Jogadores[0].dano < Jogadores[1].dano)
	printf("May: Se você tivesse beleza o que tem de derrota!\n");
else{
if(Jogadores[0].dano > Jogadores[1].dano)
	printf("James: Eliminar a esperança é a nossa arte!\n");
}
}
	return 0;
}
