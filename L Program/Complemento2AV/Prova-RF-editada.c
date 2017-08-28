#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define TAM 10
#define MAX 20

char ****associar3(int x, int y, int z, int w){
    char ****p; //Matriz que recebe os Calloc
    int i,j,k; //variáveis da matriz
//aloca as linhas da matriz
     p=(char****)calloc(x,sizeof(char***));
    if (p==NULL){
        printf("MEMÓRIA INSUFICIENTE!!!");
        return(NULL);
    }

//aloca colunas da matriz
    for (i=0;i<x;i++){
        p[i]=(char***)calloc(y,sizeof(char**));
        if(p[i]==NULL){
            printf("MEMÓRIA INSUFICIENTE!!!");
            getche();
            return(0);
        }
    }

//aloca a profundidade da matriz
    for (i=0;i<x;i++){
        for (j=0;j<y;j++){
            p[i][j]=(char**)calloc(z,sizeof(char*));
            if(p[i][j]==NULL){
                printf("MEMÓRIA INSUFICIENTE!!!");
                getche();
                return(0);
        }
        }
    }
        for (i=0;i<x;i++){
            for (j=0;j<y;j++){
                for (k=0;k<z;k++){
                   p[i][j][k]=(char*)calloc((21),sizeof(char));
                      if(p[i][j][k]==NULL){
                                  printf("MEMÓRIA INSUFICIENTE!!!");
                                  getche();
                                  return(0);
                                  }
            }
        }
    }
    return(p);
}

int removestr (char*s, int p, int y){
    int x, i, j;
    x=strlen(s);
    if (y==0) return(0);
    if (!(p+y>x)){
        for (i=p, j=p+y ; i<=x; i++, j++){
            if (s[i]='\0')
                break;
            s[i]=s[j];

        }
    }
    else s[p]='\0';
    //  Remove a string apartir do "j" da posição décima de k
    return(0);
}


void lernome(char*s){
      printf("\ndigite uma palavra ( %d caracteres):\n", MAX);
      scanf("%s", s);
      s[MAX]='/0'; //assegura que termina aqui
}

void copiar (char****mat, char*m, int x, int y, int z, int w){
    int i, j, k, l;
    for (i=0;i<x;i++){
        for (j=0;j<y;j++){
            for (k=0;k<z;k++){
                for (l=0;l<w;l++){
                   mat[i][j][k][l]=m[l];
                }
             }
         }
    }
}

//É obrigado a deixar a função Main embaixo das outras, pois a referência de algumas
//variáveis vem primeiro que a função Main por conta do Calloc que aloca memória para
//a matriz [i][j][k][l]
int main(){
    char s[MAX+1];
    char****nomes;
    int x, y, z, w, i, j, k, l;

    nomes=associar3(TAM, TAM, TAM, MAX);
    lernome (s);
  //  variável "s" recebe nome que usuário digita
  // Segue abaixo o laço para a matriz alocada receber a string
     for (i=0;i<TAM;i++){

        for (j=0;j<TAM;j++){

            for (k=0;k<TAM;k++){

                for (l=0;l<=MAX;l++){
                   nomes[i][j][k][l]=s[l];
                }
             }
         }
    }


        printf("\nlala12");
    for (i=0;i<TAM;i++){
        for (j=0;j<TAM;j++){
            for (k=0;k<TAM;k++){
                   removestr(nomes[i][j][k], k, j);
             }
         }
    }

    for (i=0;i<TAM;i++){
        for (j=0;j<TAM;j++){
            for (k=0;k<TAM;k++){
                printf("\n %d %d %d %s", i, j, k, nomes[i][j][k]);
             }
         }
    }

}
