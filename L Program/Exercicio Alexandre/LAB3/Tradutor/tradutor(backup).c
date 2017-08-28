#define clrscrn system("cls")/*--------------------------------------------*/
/* Compiled with DEVC++ ,Borland under windows                             */
/* Use cc to compil programme under unix/linux                             */
/*-------------------------------------------------------------------------*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

void meaning(int i, FILE *OUTFILE)
     {
     char *trad[17]={"principal", "inclua", "defina", "se", "senao", "enquanto",
                     "faca", "escreva", "leia", "obtenha", "ponha", "estrutura",
                     "para", "enumeracao", "inicio", "fim"};

     fputs(trad[i],OUTFILE);

 }
 int token(char *sent,int *loc)
     {
     char *ancien[17]={"main","include","define","if","else","while","do","printf",
                       "scanf","gets","puts","struct","for","enum", "{", "}"};
     int i,check=0;

     for(i=0;i<16;i++){
       if((strcmp(ancien[i],sent))==0)// Comparing the gotten sentence with reserved words
       {
          *loc=i;
          check++;
       }
       }
     if (check)
        return check;
     else
        return 0;
 }

/***********************************/

  int main(int argc,char **argv)
  {   /* variables and Files */
      int i,loc,decal;
      FILE *INFILE, *OUTFILE;
      char old[30],tyro[30];
      char chaine[25]={"Steve Ataky Tsham Mpinda"};
      char sent[20], wordc;

printf("TRADUTOR DE CODIGO-FONTE VERSAO 0.7\n");
printf("Desenvolvido por: Jonathan Iury A Santos\n\n");


  /* Opening of the source file as read */
  do
    {
     printf("Entre com o nome do codigo-fonte:\n");
     scanf("%s", old);
     INFILE = fopen(old, "r");
     if (!INFILE)
         printf("\aProblemas para abrir o arquivo ou corrumpido "
                "o arquivo: %s.\n", INFILE);
    }
  while (!INFILE);
   /* Opening the destination file as write */
  do
    {
     printf("Onde salvar a traducao? (apenas informe o nome)\n");
     scanf("%s", tyro);
     OUTFILE = fopen(tyro, "w");
     if (!OUTFILE)
         printf("\aERREOR: Couldnt open the file "
                "The File: %s.\n", OUTFILE);
    }
  while (!OUTFILE);


     i=0;
     do{
       wordc=getc(INFILE);
        if(((wordc>96) && (wordc<123))||((wordc==123)||(wordc==125))){
           while(((wordc>96) && (wordc<123))||((wordc==123)||(wordc==125))){
                sent[i]=wordc;
                wordc=getc(INFILE);
                i++;
           }
           sent[i]='\0';
           if(token(sent,&loc))
             meaning(loc,OUTFILE);
           else
              fputs(sent,OUTFILE);
           i=0;
        }

              putc(wordc,OUTFILE);
        }

     while(wordc!=EOF);
clrscrn;
                   system("color 1e");
printf("             *****  *    *  ******  ******  ******  ******  ******\n");
printf("             *      *    *  *       *       *       *       *    *\n");
printf("             *****  *    *  *       ******  ******  ******  *    *\n");
printf("                 *  *    *  *       *            *       *  *    *\n");
printf("             *****  ******  ******  ******  ******  ******  ******\n");


printf("\n\n\n\n");

printf("             ******************************************************\n");
printf("             * grateful for the advantage we took being by your   *\n");
printf("             * side in order to improve our programming background*\n");
printf("             ******************************************************\n");

while(kbhit()==0);
 }

