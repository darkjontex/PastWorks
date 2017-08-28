//Programa feito para organizar Agenda de Gatas.
//Jonathan Iury A Santos - CP09230-80

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>

typedef struct agenda{
    int chave;
    char nome[50];
    int idade;
    int rank;
} Gata;


int main(){    //Função principal que chamará as outras funções.
    printf("*--------Agenda Pessoal para ca%cadores--------*\n", 135);
    printf("*------Vers%co 0.4------Por: Jonathan Iury-----*\n\n", 198);

    lernome(Gata *p);



}


void lernome(int *p){
    //função que irá ler o nome da Gata.
    scanf("%s", &Gata.nome);

}

void consulta(){
    //consulta que servirá para pesquisar GATA.
}

void adicionanovo(){
    //função que irá adicionar uma Gata.
}

void exibidados(){
    //função que mostrará os dados das Gatas pesquisadas
}

void menu(){
    //menu que será utilizado após a exibição dos dados, onde irá apagar, alterar ou fazer outra consulta.
}

void alterar(){
    //função que irá alterar os dados.
}

void apagar(){
    //função que fará a retirada de uma Gata da agenda.
}


