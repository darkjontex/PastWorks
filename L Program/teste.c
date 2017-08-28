#include <stdio.h>
#include <stdlib.h>
#define MAX 500

int main() {


        int inteiro[MAX], i;
        puts("\nEntre com um inteiro:");
        do {
            for (i=0; i<=MAX; i++){
             inteiro[i] = gets();
            }
        }while (inteiro != '0');

        printf ("%d", inteiro);

}






