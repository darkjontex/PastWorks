#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

void traduzir(int i, FILE *SAIDA)
     {
     char *traduz[17]={"principal", "inclua", "defina", "se", "senao", "enquanto",
                       "faca", "escreva", "leia", "obtenha", "ponha", "estrutura",
                       "para", "enumeracao", "inicio", "fim"};

     fputs(traduz[i],SAIDA);

 }
 int token(char *posi, int *loca){

     char *db[17]= {"main","include","define","if","else","while","do","printf",
                    "scanf","gets","puts","struct","for","enum", "{", "}"};
     int i,checa=0;

     for(i=0;i<16;i++){
       if((strcmp(db[i],posi))==0)// Comparing the gotten sentence with reserved words
       {
          *loca=i;
          checa++;
       }
     }

     if (checa){
        return checa;
     }
     else{
        return 0;
     }
 }

//Inicio da função Main

int main(int argc,char **argv){
// Chama a função de tradução e os arquivos fonte

      int i;
      int loca;
      FILE *FONTE, *SAIDA;
      char fonte1[30],fonte2[30];
      char posi[20], carac;

printf("TRADUTOR DE CODIGO-FONTE VERSAO 0.7\n");
printf("Desenvolvido por: Jonathan Iury A Santos\n\n");


//Abre o arquivo FONTE para leitura e teste
  do{
     printf("Entre com o nome do codigo-fonte:\n");
     scanf("%s", fonte1);
     FONTE = fopen(fonte1, "r");
     if (!FONTE){
         printf("\aProblemas para abrir o arquivo ou corrumpido "
                "o arquivo: %s.\n", FONTE);
     }
    }
  while (!FONTE);

//Testa SAIDA
  do{
     printf("Onde salvar a traducao? (apenas informe o nome)\n");
     scanf("%s", fonte2);
     SAIDA = fopen(fonte2, "w");
     if (!SAIDA){
         printf("\aProblemas com o arquivo ou "
                "O arquivo: %s. esta corrumpido\n", SAIDA);
     }
    }
  while (!SAIDA);

// Localiza a palavra e substitui na posição da palavra
     i=0;
     do{
       carac=getc(FONTE);
        if(((carac>96) && (carac<123))||((carac==123)||(carac==125))){
           while(((carac>96) && (carac<123))||((carac==123)||(carac==125))){
                posi[i]=carac;
                carac=getc(FONTE);
                i++;
           }
           posi[i]='\0';

//Realiza a tradução se a palavra estiver em vetor "trad"
           if(token(posi,&loca)){
             traduzir(loca,SAIDA);
           }
           else{
              fputs(posi,SAIDA);
           i=0;
           }
        }
              putc(carac,SAIDA);
        }

     while(carac != EOF);

 printf("\n\nVerifique seu arquivo de destino\nTraducao efetuada com sucesso!!\n");

  }
