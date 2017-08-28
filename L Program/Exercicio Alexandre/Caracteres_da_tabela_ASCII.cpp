#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define TAM_CHAR sizeof(char)*8

int main()
{ int i, j, aux, cont;
  char c, resp;
  char vetor[TAM_CHAR+1];
  cont=0;
  /*Imprime 20 caracteres enquanto o usuário desejar*/
  while(cont<20)
  {
   for(i=0; i<256; ++i)
   { c=i;
     printf("\n\nO caracter: %c\n", c);
     printf("Em decimal seu valor eh: %d\n", i);
     printf("Em hexadecimal seu valor eh: %x\n", i);
    /*Acha o valor em binário do caracter i*/
     for(j=TAM_CHAR-1, aux=i; j>=0; j--)
     { vetor[TAM_CHAR]='\0';
       if(aux&1)
        vetor[j]='1';
       else
        vetor[j]='0';
        aux=aux>>1;
     }
     printf("Em binario seu valor eh: %s\n", vetor);
     ++cont; 
   /*Loop que a cada 20 caracter impresso, pergunta se o usuário ainda deseja mais*/
     if(cont==20)
     { puts("Deseja continuar? s/n");
       resp=getch();
       if(resp=='s')
         cont=0;
       else 
         break;
     }   
   }  
  }
  getch();
} 
