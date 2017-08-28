/*Programa que ler uma string e a invert*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
    /*Declaração de Variável*/
    int i,j,cont=0,cont1=0;
    char str[50], str1[50];
    printf ("Digite uma string <Caso queira terminar digite 0>: ");
    gets (str);
    while(str[0]!='0')
    {
       printf ("\n\n A string que voce digitou foi: %s",str);
       
    /*Verificando o tamanho da string*/
       for (i=0;str[i]!= '\0'; i++)
       {
                 cont+=1;
       }
       
        printf("\nO tamanho da string e : %d\n\n",cont);
        
    /*alocando a string invertida*/
        for (j=cont-1;j>=0;j--)
        {
         str1[cont1]=str[j];
         cont1+=1;
         }
         str1[cont1]='\0';
         printf ("\n\nA string invertida e: %s\n\n", str1);
    
         printf ("Digite uma string <Caso queira terminar digite 0>: ");
         gets(str);
         cont=0;
         cont1=0;
    }

}
