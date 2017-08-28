/*---------------------------------------------------------------------------#
prog 006

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

char menu(){
        //clrscr();
        puts("(C)aracteres");
        puts("(I)nteiros");
        puts("Escolha sua opcao:");
        return (getche());
        
}

void lerCaracteres(char *a){ /*a recebe o vertor de caracteres vetChar de main*/
        puts("\nDigite uma string:"); 
        gets(a); /*e digita na tela a string*/
}
void invertStr(char *ori, char *inv){ /*ori recebe o vertor de caracter vetChar da main(que ja possi valor*/
        int i,j;                      /* e entao o usa*/
        j=strlen(ori);                /*j exibe o tamanho do vertor vetChar q foi passado pra ori */
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
void binario(int x, char* bin){
        int aux, i, cont=0;
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
           aux = aux >> 1; // parte do for
                 
         }
    
     for(i=0; i<=TAM; i++)
     printf("%c", bin[i]);
     printf ("\nA quantidade de 1 no binario e: %d",cont);
}



void calculaTudo(int n, int *A, int *B)
{
        
        int i, maior=0,menor=0,cont1=0,cont=0;
        float par=0;
        //puts("\nEntrou em 6");
        
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
        puts("Sua string invertida e: ");
        puts(res);
}


int  main()
{
     char vetChar[MAX], aux[MAX],vetInt[TAM+1], opcao;

     int   num,vetMaior[MAX],vetMenor[MAX];

     do 
     {
        opcao=menu(opcao);
        switch(opcao){
                case 'c':
                case 'C':
                        lerCaracteres(vetChar);
                        invertStr(vetChar, aux);
                        mostraResultados(aux);
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
                        printf("\nOpcao invalida. Deseja sair mesmo? (s/n)\n\n");
                        opcao = getche();
                        continue;
        }
        
     }while (opcao != SAIR);

}



