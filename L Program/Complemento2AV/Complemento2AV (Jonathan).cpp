#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define MAX1 10
#define MAX2 20

char ****aloca3(int o, int p, int q, int limite){
    char ****matriz; //Matriz que recebe os Calloc
    int i,j,k; //variáveis da matriz na função aloca3
//aloca os índices da matriz
     matriz=(char****)calloc(o,sizeof(char***));
    if (matriz==NULL){
        printf("Falta memória!");
        return(NULL);
    }
//aloca as linhas da matriz
    for (i=0;i<o;i++){
        matriz[i]=(char***)calloc(p,sizeof(char**));
        if(matriz[i]==NULL){
            printf("Falta memória!");
            getche();
            return(NULL);
        }
    }
//aloca as colunas da matriz
    for (i=0;i<o;i++){
        for (j=0;j<p;j++){
            matriz[i][j]=(char**)calloc(q,sizeof(char*));
            if(matriz[i][j]==NULL){
            printf("Falta memória!");
            getche();
            return(NULL);
        }
        }
    }
//Aloca a profundidade da matriz
for (i=0; i<o; i++){
  for (j=0; j<p; j++){
     for (k=0; k<q; k++){
    matriz[i][j][k]=(char*)calloc((21),sizeof(char));
    if(matriz[i][j][k]==NULL){
      printf("Falta memória!");
    getche();
  return(NULL);
    }
     }
   }
}

    return(matriz); //Retorna para a main a matriz alocada
}

int RemoveStr (char *string, int mat, int fim){
    int i, j; //i para inicio e j para fim da string
    int x; //Recebe tamanho da string
    x=strlen(string);
    if (fim==0)
     return(0);
        if (!( (mat+fim)>x) ){
         for (i=mat, j=mat+fim; i<=x; i++, j++){
            if (string[i]='\0'){
                break;
            }
            string[i]=string[j];

        }
    }
    else string[mat]='\0';
    //  Remove a string apartir do "j" da posição décima de k
    exit(-1);
}

//É obrigado a deixar a função Main embaixo das outras, pois a referência de algumas
//variáveis vem primeiro que a função Main por conta do Calloc que aloca memória para
//a matriz [i][j][k][nome] é responsavel por compor toda a matriz com as dimensões e a string
int main(){
    char string[MAX2+1];
    char ****matrizXYZ;
    int o, p, q; // Variáveis para alocar matriz
    int limite; //Limite para a string
    int x, y, z; // Variáveis da main para a matriz
    int nome; // variável para limitar impressão da string

    matrizXYZ=aloca3(MAX1, MAX1, MAX1, MAX2);

      printf("\nEntre com um nome (Maximo %d caracteres): ", MAX2);
      scanf("%s", string);
      string[MAX2]='/0';
  //  variável "string" recebe nome que usuário digita
  // Segue abaixo o laço para a matriz alocada receber a string
for (x=0; x<MAX1; x++){
    for (y=0; y<MAX1; y++){
        for (z=0; z<MAX1; z++){
            for (nome=0; nome<=MAX2; nome++){
                matrizXYZ[x][y][z][nome]=string[nome];
            }
        }
    }
}

        printf("\n");

    for (x=0; x<MAX1; x++){
    for (y=0; y<MAX1; y++){
    for (z=0; z<MAX1; z++){
    RemoveStr(matrizXYZ[x][y][z], z, y);
    }
    }
    }

for (x=0; x<MAX1; x++){
    for (y=0; y<MAX1; y++){
        for (z=0; z<MAX1; z++){
            printf("\n%d %d %d %s", x, y, z, matrizXYZ[x][y][z]);
        }
    }
}
}
