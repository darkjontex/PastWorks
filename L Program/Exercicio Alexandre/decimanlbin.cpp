#include<stdio.h>
#include<stdlib.h>



int main(){ 
unsigned int dec, bin, temp; 
printf("Digite um numero na base decimal: "); 
scanf("%u", &dec); 
bin=dec; 
printf("Numero na base binaria: "); 
for(temp=0; temp<12; temp++){ 
printf("\n%u", (bin>>temp)&1);

} 



system ("pause"); 
}
