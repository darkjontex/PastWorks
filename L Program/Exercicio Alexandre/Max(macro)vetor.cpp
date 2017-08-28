#include<stdio.h>
#include<stdlib.h>

/*funçao q compara se o numero na proxima posiçao do vetor é maior q a anterior*/
int selecao (int *vetor, int n) /*n e o tamanho do vetor*/
{
    int i,j, pos, aux; /*aux é um idexador de vetor*/
    
    for (i=0; i<n-1;i++) /*o i esta na primeica casa do vetor e vai incrementado*/
    {
        pos = i;
            for (j=i+1;j<n;j++) /*O j esta na segunda casa, compara com a primeira, se for menor assume a primeia posiçao e vai incrementando*/
            {
                if (vetor[j] < vetor[pos])
                pos = j;
            }
            
         aux = vetor[i];
         vetor[i]=vetor[pos];
         vetor[pos]=aux;           
    }         

}


int main()
{
 int vet[100], tam, i,cont=0,soma=0, media;
 printf("Digite o tamanho do vetor: ");
 scanf("%d",&tam);
 
 for (i=0 ; i<tam ; i++)
 {
     cont+=1;
     printf("Digite o valor para o vetor %d :",cont);
     scanf("%d",&vet[i]);
 }
 /* for para imprimir o vetor digitado*/
 printf ("O vetor que voce digitou foi:  ");
 for (i=0 ; i<tam; i++) printf("%d  ", vet[i]);
 
 /*Chamda da função*/
 
 selecao(vet,tam);
 
 /*imprimendo o vetor ordenado*/
 printf("\nO vetor em ordem crescente e: ");
 for(i=0 ; i<tam ; i++)
       printf("%d  ",vet[i]);
 
       printf("\n\n");
/*Imprimindo o menor e o maior numero do vetor*/
 printf("O menor numero e: %d\n", vet[0]);
 printf("O maior numero e : %d\n", vet[tam-1]);

/*Media dos numeros pares*/
 for(i=0;i<tam;i++)
 {
    if (vet[i]%2==0) soma=soma+vet[i];
     
  }
/*imprimindo a media */
  
  printf("A media dos numeros pares e: %d\n", media=soma/2);  


 
 system("pause"); 
}       
