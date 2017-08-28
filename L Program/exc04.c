#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define MAX 9


unsigned int Vetor[MAX];
int media, menor, maior, i;

int main() {
    printf("######Bem-Vindo ao programa de calculo v2.0#######\n\n");
    printf("Ele calcula os numeros pares em um Vetor e tira o MAIOR, MENOR e MEDIA\n");
    printf("Entre com os valores de 0 a 9 que deseja que o programa calcule:\n\n");

    for (i=0; i<=MAX; i++) {

    scanf("%d", &Vetor[i]);

    }
        for (i=0; i<=MAX; i++) {

        printf("\nVocê digitou: %d\n", Vetor[i]);

        }



}
