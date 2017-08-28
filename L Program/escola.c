#include <stdlib.h>
#include <stdio.h>
#define MAX 20

char aluno1[MAX], aluno2[MAX], aluno3[MAX];
int nota1, nota2, nota3, media, decisao;

int main() {

    puts ("Programa de escola 1.0v");
    puts ("Digite o nome dos alunos: \n");

    scanf ("%s %s %s", &aluno1, &aluno2, &aluno3);
    printf ("\naluno 1: %s \naluno 2: %s \naluno 3: %s \n\n\n", aluno1, aluno2, aluno3);
    puts ("Esta correto os nomes? \n\n Se sim, pressione 1 \n Se nao, pressione 0\n\n");

      scanf ("%d", &decisao);

        if (decisao == 1){

            puts ("\n\nDigite as notas 1, 2 e 3: \n\n");

        scanf ("%d", &nota1);
        scanf ("%d", &nota2);
        scanf ("%d", &nota3);

      printf ("\nNota 1: %d \nNota 2: %d \nNota 3: %d \n\n", nota1, nota2, nota3);

        }

}

