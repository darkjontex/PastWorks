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


int main(){    //Fun��o principal que chamar� as outras fun��es.
    printf("*--------Agenda Pessoal para ca%cadores--------*\n", 135);
    printf("*------Vers%co 0.4------Por: Jonathan Iury-----*\n\n", 198);

    lernome(Gata *p);



}


void lernome(int *p){
    //fun��o que ir� ler o nome da Gata.
    scanf("%s", &Gata.nome);

}

void consulta(){
    //consulta que servir� para pesquisar GATA.
}

void adicionanovo(){
    //fun��o que ir� adicionar uma Gata.
}

void exibidados(){
    //fun��o que mostrar� os dados das Gatas pesquisadas
}

void menu(){
    //menu que ser� utilizado ap�s a exibi��o dos dados, onde ir� apagar, alterar ou fazer outra consulta.
}

void alterar(){
    //fun��o que ir� alterar os dados.
}

void apagar(){
    //fun��o que far� a retirada de uma Gata da agenda.
}


