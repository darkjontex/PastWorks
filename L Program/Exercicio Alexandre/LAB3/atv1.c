#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define SAIR 's' || 'S'

int main() {
    int i;
    int x;

    FILE *fonte1;
    char escreve[256];
    char texto = "db.txt";
    char *Ma = "main";
    char Ma2[9] = "principal";
    char *Inclu = "include";
    char *Inclu2 = "incluir";
    char *defi = "define";
    char *defi2 = "definir";

    printf("------(--------Bem vindo ao tradutor de fontes 0.1v-------)------\n");
    printf("*Caso ja tenha colocado seu fonte na pasta do programa, favor modificar*\n");
    printf("*O nome para db.txt, caso contrario o programa nao executa a traducao*\n\n");

    printf("Pressione qualquer tecla para continuar...");
    getchar();
    fflush(stdin);

    fonte1 = fopen("db","a+t");

    if ( fonte1 == NULL ) {
	printf("O arquivo esta corrumpido e/ou nao compativel.\n");
	exit(1);
    } else {

        while (fgets(escreve, sizeof(escreve), fonte1)){

        if ((strcmp(escreve,Ma) == 0)){
            printf("Localizado main\n");
            fputc(Ma2, fonte1);
        }

        if (strcmp(escreve,Inclu) == 0){

            fputs(Inclu2, fonte1);
        }

        if (strcmp(escreve,defi) == 0){

            fputs(defi2, fonte1);
        }

    }

}


    printf("Traducao efetivada com sucesso!");

    fclose(fonte1);

}
