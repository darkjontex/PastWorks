/*---------------------------------------------------------------------------#
Programa Prova Ler inteiro - binario - calcula tudo - imprimir string binaria invertida 1.1v
Esta versão diferente da 1.0 é que agora ele apenas imprimi o numero digitado e o resultado
Foi retirado printf's do andamento do processo como a atividade de complemento avaliativo pede
POR: Jonathan Iury A. Santos 07/10/2010
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define MAX 120
#define TAM sizeof(int)*8

int vetInt[MAX], index, i;
int maior, vetMaior[MAX], vetMenor[MAX], menor, cont, total;
char bina[MAX], invert[MAX];


    int main (){

        puts ("Entre com a sequencia de inteiros terminando com 0 em seguida");


         lerInteiros(vetInt);
         printf("\n");
         for (i=0; i<index; i++){
          printf("%d", vetInt[i]);
         }

         calculaTudo(index, maior, menor);
         binario(maior, vetInt, total);
         binario(menor, vetInt, total);

         binario(total, bina);

         invertStr(bina, invert);
         printf("Sua String binaria invertida e: \n");
         for (i=index; i>=0; i--){
         printf("%c", invert[i]);
         }

    }



void lerInteiros(int *vetInt){
    int aux, i;
    for (i=0; i<MAX; i++){
        scanf("%d", &aux);
            if (aux == 0){
                vetInt = aux;
                index = i+1;
                break;
            } else {
                vetInt[i] = aux;
            }
        }
}

void binario(int x, char *bin){ //A gambiarra do Binario é o Int x (que representa num) entrar num vetor CHAR de indice "i"
        int aux, i;
        cont=0; //Conta os numeros 1 do binario
        aux = x;
        for(i=TAM; i>=0; i--)
        {

           if(aux&1)
           {
              bin[i]='1';
              cont = cont +1;
           }
           else{
              bin[i]='0';
              }
           aux = aux >> 1; // parte do for e desloca a direita os "1's" binarios, oque previne a não estourar o vetorInt, deslocando 1 para direita.

         } total += cont;

      }

void invertStr(char *bina, char *inv){ /*ori recebe o vetor de caracteres "vetChar" da main, que ja possui valor*/
        int i,j;                      /* e entao o usa*/
        j=strlen(bina);                /*j exibe o tamanho do vetor vetChar q foi passado pra ori */
        for (i=j-1; i>=0; i--)
        {
                inv[j-i-1] = bina[i]; /*vetor é invertido*/
        }
        inv[j-i-1] = '\0';
}

void calculaTudo(int index)
{

        int i,cont1=0,cont=0;
        menor = 0;
        maior = 0;

        //Entra no laço de vetor

        printf("\n");

        for (i=0; i< index; i++){

             if(vetInt[i]%2==0){
                 if (vetInt[i] < vetInt[i+1]){
                 menor = vetInt[i];
                 }
                 if (vetInt[i] > vetInt[i+1]){
                      maior = vetInt[i];
                }
             }



    }//fim do for
}
