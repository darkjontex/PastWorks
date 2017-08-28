/*---------------------------------------------------------------------------#
Programa Com MENU interativo 2.0v
POR: Jonathan Iury A. Santos 12/08/2010

*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define DEPURA
#define MAX 32
#define SAIR 's'
#define TAM sizeof(int)*8



char menu(){ //Menu que vai retornar um valor do getche() para a função Main

        puts("\n\n(C)aracteres");
        puts("(I)nteiros");
        puts("(S)air");
        puts("Escolha sua opcao:");
        return (getche());

}

void lerCaracteres(char *a){ /*Este "*a" envia o vertor de caracteres do gets(a) para o vetChar da main*/
        puts("\nDigite uma string:");
        gets(a); /*e digita na tela a string*/
}
void invertStr(char *ori, char *inv){ /*ori recebe o vetor de caracteres "vetChar" da main, que ja possui valor*/
        int i,j;                      /* e entao o usa*/
        j=strlen(ori);                /*j exibe o tamanho do vetor vetChar q foi passado pra ori */
        for (i=j-1; i>=0; i--)
        {
                inv[j-i-1] = ori[i]; /*vetor é invertido*/
        }
        inv[j-i-1] = '\0';
}
int lerInteiros(){
        int inteiro;
        puts("\nEntre com um inteiro:");
        scanf("%d",&inteiro);
        return inteiro;

}
void binario(int x, char* bin){ //A gambiarra do Binario é o Int x (que representa num) entrar num vetor CHAR de indice "i"
        int aux, i;
        int cont=0; //Conta os numeros 1 do binario
        puts("Seu valor em binario e: ");
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

         }

     for(i=0; i<=TAM; i++)
     printf("%c", bin[i]);
     printf ("\nA quantidade de 1 no binario e: %d",cont);
}



void calculaTudo(int n, int *A, int *B)
{

        int i, maior=0,menor=0,cont1=0,cont=0;
        float par=0;
        //Entra no laço de vetor

        for (i=0 ; i<n ; i++)
        {
            cont+=1;
            printf("Digite o valor para o vetor %d :",cont);
            scanf("%d", &A[i]);
            B[menor]=A[i];
        }
        printf("\n");

        for (i=0; i< n; i++)
        {
             if(A[i]%2==0)
             {
               cont1+=1;
               par = par+ A[i];
             }

             if(A[maior] < A[i])
             {
                 A[maior] = A[i];
             }
             else
             {
                 if(B[menor] > A[i])
                 {
                      B[menor] = A[i];
                      printf("\n\n %d\n\n",B[menor]);
                 }//fim do if
             }//fim do else

    }//fim do for
    printf("O maior numero e :%d\n\nO menor e: %d\n\nA media dos numeros pares e: %.2f\n\n", A[maior], B[menor],(par/cont1));

}
void mostraResultados(char * res){
        printf("\nSua string invertida e: %s \n\n", res);

}


int  main()
{
     char vetChar[MAX], aux[MAX],vetInt[TAM+1], opcao;

     int   num,vetMaior[MAX],vetMenor[MAX];

     printf("Bem vindo ao Programa de calculo 2.0v \n");
     printf("Escolha uma opcao do menu para comecar a usar\nou sair do programa: \n");

     do
     {
        opcao=menu(opcao);
        switch(opcao){
                case 'c':
                case 'C':
                        lerCaracteres(vetChar);
                        invertStr(vetChar, aux);
                        break;
                case 'i':
                case 'I':
                        num = lerInteiros();
                        binario(num , vetInt);
                        //contaBit1(cont);
                        printf("\nDigite o tamanho de um vetor: ");
                        scanf("%d",&num);
                        calculaTudo(num, vetMaior, vetMenor );
                        break;

                default:
                        printf("\n\nOpcao neutra ou sair. Deseja sair mesmo? (s/n)\n\n");
                        opcao = getche();
                        continue;
        }
        mostraResultados(aux);
     }while (opcao != SAIR);

}



