/*---------------------------------------------------------------------------#
prog 001

*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define DEPURA
#define MAX 10

int  main()
{
char vetChar[MAX], varChar, *pChar;
int  vetInt[MAX], varInt, *pInt, i;

printf("\nDigite um inteiro e um char (int,char): ");
scanf ("\n%d,%c", &varInt, &varChar);
printf("\nO valor armazenado em varInt e varChar sao %d e %c",varInt,varChar);
printf("\nOs respectivos enderecos sao: %x e %x", &varInt, &varChar);
printf("\nA diferenca entre os enderecos eh %d", varChar-varInt+1);
pInt = &varInt;
pChar= &varChar;
printf("\nOs ponteiros apontam para %x e %x que contem %d e %c",pInt,pChar,*pInt,*pChar);
vetChar[0]=*pChar;
vetInt[0]=*pInt;
printf("\n A posicao que os vetores possuem agora %d,%c", vetInt[0],vetChar[0]);
pChar = vetChar;
pInt = &vetInt[0];
printf("\nOs vetores estao nos enderecos %x e %x",pInt,pChar);
i=0;
do{
        printf("\nDigite um inteiro e um char (int,char): ");
        scanf ("\n%d,%c", pInt,pChar);

} while (i++<MAX && *pChar++ != '0' && *pInt++ != 0);

for (;i>=0;i--,pChar--)
{
        putchar(*pChar);
}

getche();



}
