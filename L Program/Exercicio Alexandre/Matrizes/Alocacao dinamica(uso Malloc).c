#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>
#define MAX 10


int main(){

int x, y, z; //Cada dimensão da matriz representados por X, Y, Z
int ***matrizXYZ; //Matriz que irá se alocar dinamicamente em 3 dimensões
int i, j, k; //Variaveis auxiliares

printf("=======Bem-vindo ao programa de aloca%cao de Matriz 3.0v=======\n\n", 135);
printf("Digite o tamanho das dimens%ces de sua Matriz de 3 dimens%ces\n", 228, 228);
printf("OBS: Sua matriz ser%c preenchida automaticamente para testar a fun%cao Malloc\n", 160, 135);
printf("Exemplo: 5x5x5 ou 10x10x10\n");


    fflush(stdin);
    scanf("%d", &x);
    fflush(stdin);
    scanf("%d", &y);
    fflush(stdin);
    scanf("%d", &z);
    fflush(stdin);

    printf("\n\n\n");

     matrizXYZ=(int ***)malloc(x*sizeof(int**));
        if (matrizXYZ==NULL){
        exit (1);
        }

        for (i=0; i<x; i++){
            matrizXYZ[i]= i;
        }

        for (i=0; i<x; i++){
        printf("%d", matrizXYZ[i]);
        }

        printf("\n");

            for (i=0; i<x; i++){
                matrizXYZ[i]=(int **)malloc(y*sizeof(int*));
                if (matrizXYZ[i]==NULL){
                exit (1);
                }
            }

            for (j=0; j<y; j++){
                *matrizXYZ[j]= j;
            }

            for (j=0; j<y; j++){
            printf("%d", *matrizXYZ[j]);
            }

            printf("\n");

        for (k=0; k<y; k++){
            *matrizXYZ[k]=(int *)malloc(z*sizeof(int));
            if (matrizXYZ[k]==NULL){
            exit (1);
            }
        }

        for (k=0; k<z; k++){
                **matrizXYZ[k]= k;
            }

            for (k=0; k<z; k++){
            printf("%d", **matrizXYZ[k]);
            }

            printf("\n");

            free(**matrizXYZ);
            free(*matrizXYZ);
            free(matrizXYZ);


/*
    Filosofia de Jonathan Iury sobre o programa:
    Alocação dinamica é dificil, se tratando de matrizes então, o assunto complica ainda mais! (risos)
    Porém, como qualquer assunto na vida, tudo deve ser levado com sua importância e atenção
    Desta forma, a persistência por mais que de imediato não dê resultado, sempre lhe mostrará caminhos que
    Mesmo você não imaginava conseguir.
    Levei 3 dias pensando e tirando duvidas com o professor para entender ponteiros e o uso
    Da função Malloc, tenho 2 meses de estudo sobre ponteiros e digo:
    "Ainda não sei", pois ponteiro por mais simples que possa parecer
    Seu uso contínuo requer atenção para compreender o que cada "*" aponta no programa
    Mas persisti para entender pois meu sonho é programar, e nada irá me impedir de concretiza-lo!
    Para todos os programadores e alunos que estiverem lendo isso, dou-lhes um aviso:
    "Nunca desistam, por mais complexas sejam as dificuldades, pois vocês seram o futuro
    para a solução dos problemas do mundo de hoje e do futuro, onde sem vocês, a humanidade não estaria no conforto
    e satisfação tecnologica e profissional que se tem hoje!".

*/


printf("\n\nEste eh o teste de confirmacao com sucesso do malloc na Matriz!\n");
printf("\n\nMatriz Preenchida com Sucesso!\n");

getch();

}
