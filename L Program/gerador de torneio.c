#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SAIR 'n'

int participantes, i;
char opcao;

int main ()
{
    printf("*******GERADOR DE TORNEIOS JONNYGAMES VERSAO 1.8 BETA******\n\n");
    printf("&&&&&&TORNEIO ANIME-FIGHT STREET FIGHTER 4&&&&&&\n\n");

srand ( time(NULL) );

printf("Entre com o numero de participantes:\n");
scanf ("%d", &participantes);


do{
printf("\nParticipante %d desafia participante %d\n", rand()%participantes, rand()%participantes);
printf("\nRandomizar novamente? (S/N)\n");
opcao = getche();
} while (opcao!= SAIR);
getche();
}
