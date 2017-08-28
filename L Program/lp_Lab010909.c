#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define DEPURA
#define MAX 33

int  main()
{
int numInt, i, j;
char binario[MAX];
char resp;

do {
        printf("\nDigite um Int: ");
        scanf("%d",&numInt);
        for (i=0; i < 8*sizeof(int); i++)
        {
                if (numInt & 1)
                        binario[0] = '1';
                else binario[0] = '0';
        }

        printf("\n Leu %d! continua (s/n)?",  numInt);
        scanf("%c", &resp);
}while (resp == 's' || resp == 'S');


#ifdef NDEPURA
printf("\n Tam int: %d", sizeof(long double));
getchar();
#endif




}
