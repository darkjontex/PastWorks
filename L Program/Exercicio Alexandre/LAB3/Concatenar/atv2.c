#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int main(int argc, int **argv) {
    printf("Programa de Concatenacao de arquivos 1.7v\n");
    printf("***********Por Jonathan Iury*************\n\n");

    FILE *arq1, *arq2;

   char string[256];
   char *nome1;
   char *nome2;

   printf("digite o nome dos arquivos de entrada e saida\n");
   puts("Entrada:");
   gets(nome1);


  if ((arq1 = fopen(nome1, "r")) == NULL){

      printf("Problemas para abrir %s\n", nome1);
   }
   else

   puts("Saida:");
   gets(nome2);
        if ((arq2 = fopen(nome2, "a+")) == NULL) {

       printf("Problemas para abrir %s\n", nome2);

       fclose(arq1);
    }

   else{

        rewind(arq2);
       while (fgets(string, sizeof(string), arq1))

         fputs(string, arq2);

       fclose(arq1);

       fclose(arq2);

    }

    printf("Concatenacao com sucesso!!");

}
