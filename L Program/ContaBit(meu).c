#include<stdio.h>
#include<conio.h>

int conta_bit (int num, int bit);

void main (void) {

  int num, b, quant;


  printf("Digite um numero:\n");
  scanf("%d", &num);
  printf("Digite o bit que deseja contar 0 ou 1 :\n");
  scanf("%d", &b);
  quant = conta_bit(num, b);
  printf("A quantidade de bits %d no numero %d eh %d\n", b,num,quant);
  getch();
}

int conta_bit (int num, int bit) {

  int i, flag = 1, valor, conta1, conta0;

  for(i=0; i<16; i++) {
    valor = num&flag; // Utiliza o & para manipular os
    if(valor)         // binario da variavel num
      conta1++;
    else
      conta0++;
    flag = flag << 1; // Movimenta um BIT de flag para direita
  }
  if(bit)
    return(conta1);
  return(conta0);
}
