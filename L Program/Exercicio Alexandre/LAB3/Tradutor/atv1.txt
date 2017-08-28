#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i,cont=0,cont1=0, A[50],B[50],maior=0,menor=0,num;
    float par=0;
    printf("Digite o tamanho do vetor: ");
    scanf("%d",&num);
    
    for (i=0 ; i<num ; i++)
    {
        cont+=1;
        printf("Digite o valor para o vetor %d :",cont);
        scanf("%d",&A[i]);
        //B[menor]=A[i];
     }
    
    printf("\n");
    
    for (i=0; i< num; i++)
    {   
        if(A[i]%2==0){
             cont1+=1;
             par = par+ A[i];
        }     
        if(A[maior] < A[i]){
           A[maior] = A[i];
        }else{
           if(A[menor] > A[i]){
               A[menor] = A[i];
           }//fim do if
         }//fim do else
         
    }//fim do for
    
    printf("O maior numero e :%d\n\nO menor e: %d\n\nA media dos numeros pares e: %.2f\n\n", A[maior], A[menor],(par/cont1));
    
    system("pause");
}
