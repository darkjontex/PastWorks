/*---------------------------------------------------------------------------#
Programa Com MENU
POR: Jonathan Iury 2010

*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define DEPURA
#define MAX 10
#define SAIR 's'
#define TAM sizeof(int)*8

char vetChar[MAX], opcao, aux[MAX];
int  vetInt[MAX], Resultado;

char menu(){ //Aqui é onde o menu entra em processo para retornar a função "main" o valor para escolher uma opção
        //clrscr();
        puts("\n(C)aracteres");
        puts("(I)nteiros");
        puts("Escolha sua opcao:");
        return (getche());
}

void lerCaracteres(char *palavra){ /*palavra recebe o vertor de caracteres vetChar de main*/
        puts("\nDigite uma string:");
        gets(palavra);
}

void invertStr(char *str, char *inv){
        int i,j;
        char ch;

        for(i = 0, j = strlen(str) - 1;  i <=j;  ++i, --j) {
            ch = str[i];
            str[i] = str[j];
            str[j] = ch;
  }
        inv[j-i-1] = '\0';

}
void lerInteiros(int *nInteiro){
        puts("\nEntrou em 1");
        gets(nInteiro);
}
void binario(int *binario){
        puts("\nEntrou em 2");
        gets(binario);
}

int contaBit(int *a){
        puts("\nEntrou em 3");
        gets(a);
}
void calculaTudo(int *a){
        puts("\nEntrou em 4");
        gets(a);
}
void mostraResultados(char *res){
        puts(res);
}


int  main() {


do {
        opcao=menu(opcao);
        switch(opcao){
                case 'c':
                case 'C':
                        lerCaracteres(vetChar);
                        printf("\nVoce digitou %s\n\n", vetChar);
                        invertStr(vetChar, aux);
                        printf("Sua String invertida: %s\n", vetChar);
                        break;
                case 'i':
                case 'I':
                        lerInteiros(vetInt);
                        binario(vetInt);
                        contaBit(vetInt);
                        calculaTudo(vetInt);
                        break;
                default:
                        printf("\nDeseja sair mesmo? (s/n)\n");
                        opcao = getche();
                        continue;
        }
        mostraResultados(Resultado);
}while (opcao != SAIR);

}

