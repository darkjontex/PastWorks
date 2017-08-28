//Programa feito para organizar Agenda de Gatas.
//Jonathan Iury A Santos - CP09230-80

//PROGRAMA FUNCIONANDO 100%
//Comentário de esforço:
//-----------------------
//Levei dias e horas para estudar muito para as diversas cadeiras do período
//Ser Universitário no curso que sempre sonhei fazer para trabalhar no ramo de Games
//Não é nada facil, porém não sabia que as dificuldades seriam tantas
//Mas nunca desisti, sempre fui atrás, e as vezes, por mais que o tempo seja decisivo
//Eu nunca cansei de ir atrás, pois acredito que o esforço de um aluno, por mais desorientado
//Que seja, pode valer perante ao avaliador que percebe esta atitude.
//Afinal, um bom profissional, não é o que simplismente entende do assunto, mas sim aquele que tem
//Disposição para resolver os problemas da empresa, serviço ou comunidade.
//Conhecimento é fundamental, mas o esforço é a gasolina que mantem o aluno com vontade
//De seguir em frente, não importando as circuntâncias.

//Agradeço a Deus por ter me dado paciência durante os momentos de tensão
//E a UFMA por me dar a oportunidade de ser alguem na vida, mas por mais
//Que eu falhe, eu levantarei para lutar....morrerei tentando, mas minha vida não
//Será apagada por desistencia minha, e sim do esforço que tive para tentar ficar de pé!

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#define MAX 200

typedef struct contato{
    int chave;
    char nome[50];
    int idade;
    int ano;
    int rank;
} Agenda;


void leitura(Agenda *g, int *tam){
    //Função usada para Salvar as Gatas digitadas
    int i, h=0; //Auxiliar
    FILE *DATABASE;

    if ((DATABASE = fopen("AGENDA", "rb")) == NULL){
        printf("BANCO DA AGENDA N%cO EXISTE OU ESTA CORRUMPIDA\n", 198);
     } else

    printf("Lendo informacoes na agenda...");

             //while (!feof(DATABASE)){
            fread(&h, sizeof(int), 1,DATABASE);
            tam=h;
            printf("\n\n%d\n\n", tam);
            for (i=0; i<=tam; i++){
                //while (!feof(DATABASE)){
                fread(&g[i].chave, sizeof(int), 1,DATABASE);
                fread(&g[i].nome, sizeof(char[50]), 1,DATABASE);
                fread(&g[i].idade, sizeof(int), 1,DATABASE);
                fread(&g[i].ano, sizeof(int), 1,DATABASE);
                fread(&g[i].rank, sizeof(char), 1,DATABASE);
                //}
            }

    fclose(DATABASE);
}


void salvar(Agenda *g, int *tam){
    //Função usada para Salvar as Gatas digitadas
    int i; //Auxiliar
    FILE *DATABASE;

    if ((DATABASE = fopen("AGENDA", "r+b")) == NULL){
        printf("BANCO DA AGENDA N%cO EXISTE OU ESTA CORRUMPIDA\n", 198);
        exit(1);
     }

    printf("Salvando...\n");
    printf("SALVO COM SUCESSO!!!\n\n");

        fwrite(&tam, sizeof(int), 1,DATABASE);
        for(i=0; i<MAX; i++){
            fwrite(&g[i].chave, sizeof(int), 1,DATABASE);
            fwrite(&g[i].nome, sizeof(char[50]), 1,DATABASE);
            fwrite(&g[i].idade, sizeof(int), 1,DATABASE);
            fwrite(&g[i].ano, sizeof(int), 1,DATABASE);
            fwrite(&g[i].rank, sizeof(int), 1,DATABASE);
        }

        fclose(DATABASE);

}


void consulta(Agenda *g){
    //consulta que servirá para pesquisar GATA.
    char categoria;
    char opcao;
    char cnome[50];
    int cchave;
    int crank;
    int cont=0;
    int i; //Auxiliar

    printf ("\nPara fazer uma busca\nSelecione uma categoria para buscar\n");
    printf("Caso deseje sair selecione <S>\n\n");
    puts("(N)ome\n");
    puts("(C)onsulta numero\n");
    puts("(R)ank\n");
    fflush(stdin);
    categoria = tolower(getchar());
    fflush(stdin);

        switch (categoria){
            case 'n':
                puts("Digite o nome para busca:");
                gets(cnome);
                 printf("loading...\n");
                     for (i=0; i<MAX; i++){
                        if ((strcmp(cnome,g[i].nome)) != 0){
                        }
                            else {
                            cont = cont+1;
                            printf("%d %s %danos conheceu em %d rank: %d\n", g[i].chave, g[i].nome, g[i].idade, g[i].ano, g[i].rank);
                        }
                     }
                    if (cont == 0){
                    printf("Gata nao existe.\n");
                } else {
                    printf("Foi localizado %d gata(s)", cont);
                }

            break;
            case 'c':
                puts("Digite o numero da GATA:");
                scanf("%d", &cchave);
                fflush(stdin);
                    for (i=0; i<MAX; i++){
                        if (cchave == g[i].chave){
                            printf("%d %s %danos conheceu em %d rank: %d\n", g[i].chave, g[i].nome, g[i].idade, g[i].ano, g[i].rank);
                        }
                    }

            break;
            case 'r':
                puts("Digite a nota de rank:");
                scanf("%d", &crank);
                    for (i=0; i<MAX; i++){
                        if (crank == g[i].rank){
                            printf("%d %s %danos conheceu em %d rank: %d\n", g[i].chave, g[i].nome, g[i].idade, g[i].ano, g[i].rank);
                        }
                    }

            break;
            case 's':
                puts("Deseja para de consultar? (S/N)\n");
                opcao = tolower(getchar());
                if (opcao == 's'){
                    return 0;
                } else {
                    return (consulta(g));
                  }

            default:
                puts("Opcao invalida, deseja sair do programa? (S/N)\n");
                opcao = tolower(getchar());
                if (opcao == 's'){
                    exit(1);
                } else {
                    return (consulta(g));
                    printf("\n");
                }
        }
}


void adicionagata(Agenda *g, int *tam){
    //função que irá adicionar uma Gata.
    int i; //Auxiliar
    int cont;

    printf ("\nQuantas Gatas deseja cadastrar?\n");
     scanf ("%d", &cont);
     cont=cont+(*tam);

      printf("\n");
        for (i=(*tam); i<cont; i++){

            printf("Entre com o numero da gata:\n");
            scanf("%d", &g[i].chave);
            printf ("Numero da Gata: %d\n", g[i].chave);
            fflush(stdin);
            puts("Digite o nome da Gata:");
            gets (g[i].nome);
            fflush(stdin);
            puts("Digite sua idade:");
            scanf ("%d", &g[i].idade);
            fflush(stdin);
            puts("Quando a conheceu (ano):");
            scanf ("%d", &g[i].ano);
            fflush(stdin);
            puts("Digite uma nota para ela (de 0 a 5):");
            scanf ("%d", &g[i].rank);
            fflush(stdin);
            (*tam)+=1;
        printf("%d %s %danos conheceu em %d rank: %d\n", g[i].chave, g[i].nome, g[i].idade, g[i].ano, g[i].rank);
        printf("\n");
        }

}

void exibidados(Agenda *g, int *aviso){
    //função que mostrará os dados das Gatas pesquisadas
    int i; //Auxiliar

    if (aviso == 1){
        printf("Reinicie o programa!");
        exit(1);
    } else

    printf("\n\n");
    for (i=0; i<MAX; i++){
        if ((g[i].ano) != 0){
         printf("%d %d %s %danos conheceu em %d rank: %d\n", i, g[i].chave, g[i].nome, g[i].idade, g[i].ano, g[i].rank);
        }
    }
}

void alterar(Agenda *g){
    //função que irá alterar os dados.
    char opcao1;
    char opcao2;
    int opcaoint;
    int achave;
    int i;

    printf("\n\n");
    fflush(stdin);

        for (i=0; i<MAX; i++){
            if ((g[i].ano) != 0) {
                printf("%d %d %s %danos conheceu em %d rank: %d\n", i,g[i].chave , g[i].nome, g[i].idade, g[i].ano, g[i].rank);
            }
        }

        printf("\nDigite o numero do index da gata que deseja alterar:\n");
        scanf("%d", &achave);
        fflush(stdin);
        printf("\nO que deseja alterar? digite o numero da opcao.\n\n");
        printf(" 1 - Nome\n 2 - Idade\n 3 - Ano que a conheceu\n 4 - Rank\n 5 - Numero\n 6 - Sair\n\n");
        scanf("%d", &opcaoint);
        fflush(stdin);

        switch (opcaoint){

        case 1:
            printf("nome do registro: %s", g[achave].nome);
            printf("\nDigite o novo nome:\n");
            fflush(stdin);
            gets(g[achave].nome);
            printf("%d %s %danos conheceu em %d rank: %d\n", g[achave].chave, g[achave].nome, g[achave].idade, g[achave].ano, g[achave].rank);
            fflush(stdin);
            break;
        case 2:
            printf("idade atual da gata: %d", g[achave].idade);
            printf("\nDigite a nova idade:\n");
            fflush(stdin);
            scanf("%d", &g[achave].idade);
            printf("\n%d %s %danos conheceu em %d rank: %d\n", g[achave].chave, g[achave].nome, g[achave].idade, g[achave].ano, g[achave].rank);
            fflush(stdin);
            break;
        case 3:
            printf("ano do registro: %d", g[achave].ano);
            printf("\nDigite o novo ano:\n");
            fflush(stdin);
            scanf("%d", &g[achave].ano);
            printf("%d %s %danos conheceu em %d rank: %d\n", g[achave].chave, g[achave].nome, g[achave].idade, g[achave].ano, g[achave].rank);
            fflush(stdin);
            break;
        case 4:
            printf("rank do registro: %d", g[achave].rank);
            printf("\nDigite o novo rank:\n");
            fflush(stdin);
            scanf("%d", &g[achave].rank);
            printf("%d %s %danos conheceu em %d rank: %d\n", g[achave].chave, g[achave].nome, g[achave].idade, g[achave].ano, g[achave].rank);
            fflush(stdin);
            break;
        case 5:
            printf("Numero atual: %d", g[achave].chave);
            printf("\nDigite o novo numero:\n");
            fflush(stdin);
            scanf("%d", &g[achave].chave);
            break;

        default:
            printf("Deseja sair? (s/n)");
            opcao2 = tolower(getchar());
                if (opcao2 == 's'){
                    printf("\n\n");
                    return 0;
                } else {
                    return (alterar(g));
                }
        }
}



void apagar(Agenda *g){
    //função que fará a retirada de uma Gata da agenda.
    int apchave;
    int i;
    char aopcao;
    char repete;

    for (i=0; i<MAX; i++){
        if ((g[i].ano) != 0){
           printf("%d %d %s %danos conheceu em %d rank: %d\n", i, g[i].chave, g[i].nome, g[i].idade, g[i].ano, g[i].rank);
        }
    }

        puts ("Digite o numero do index da gata que deseja apagar:");
        scanf ("%d", &apchave);
        fflush(stdin);
        printf("\n\n");
        printf("%d %s %danos conheceu em %d rank: %d\n", g[apchave].chave, g[apchave].nome, g[apchave].idade, g[apchave].ano, g[apchave].rank);
        puts("Tem certeza que deseja apagar este registro? (S/N)");
        aopcao = tolower(getchar());
        fflush(stdin);
        printf("\n\n");

            if (aopcao == 's'){
                g[apchave].chave = 0;
                g[apchave].nome[0] = '\0';
                g[apchave].idade = 0;
                g[apchave].ano = 0;
                g[apchave].rank = 0;

                printf("Deseja apagar mais algum registro? (S/N)\n");
                repete = tolower(getchar());
                    if (repete == 's'){
                        apagar(g);
                    } else {
                        return 0;
                    }

            } else {

                for (i=0; i<MAX; i++){
                    if ((g[i].ano) != 0){
                    printf("%d %s %danos conheceu em %d rank: %d\n", g[i].chave, g[i].nome, g[i].idade, g[i].ano, g[i].rank);
                    }
                }
                printf("\n\n");
            }

}



void menu(Agenda *g, int*tam){
    //menu que será utilizado após a exibição dos dados, onde irá apagar, alterar ou fazer outra consulta.
    int mopcao, x;
    char mcopcao;
    char invalido;


    printf("O que deseja fazer?\n");
    printf("Escolha uma op%cao!\n\n", 135);
    printf("1- Consultar\n");
    printf("2- Cadastrar\n");
    printf("3- Alterar dados\n");
    printf("4- Excluir\n");
    printf("5- Salvar\n");
    printf("6- Sair\n");
    printf("\n");

    scanf("%d", &mopcao);
    fflush(stdin);

    switch (mopcao){

    case 1:
        system("cls");
        consulta(g);
        return menu(g, tam);
        break;

    case 2:
        system("cls");
        adicionagata(g, tam);
        //x=*tam;
        return menu(g, tam);
        //*tam=x;
        break;

    case 3:
        system("cls");
        alterar(g);
        return menu(g, tam);
        break;

    case 4:
        system("cls");
        apagar(g);
        return menu(g, tam);
        break;

    case 5:
        system("cls");
        salvar(g, *tam);
        return menu(g, tam);
        break;

    case 6:
        system("cls");
        printf("Deseja realmente sair? (S/N)\n");
        mcopcao = tolower(getchar());
            if (mcopcao == 's'){
                exit(1);
            } else {
                return menu(g, tam);
            }
    default:
            printf("Opcao invalida, deseja sair? (s/n)");
            invalido = tolower(getchar());
                if (invalido == 's'){
                    return 0;
                } else {
                    return (menu(g, tam));
                }
            }

}


//Função principal que chamará as outras funções.
int main(){
    Agenda *Gata;
    FILE *DATABASE;
    int aviso;
    int i, tamanho;
    /*Este código realiza a alocação dinâmica
    da estrutura de dados para a agenda Gata*/
    Gata = (Agenda*) calloc (MAX, sizeof(Agenda));
    if (Gata==NULL){
        //Realiza uma Realocação caso dê erro ao alocar memória
        Gata = (Agenda*) realloc (MAX, tamanho * sizeof(Agenda));
        Gata++;
    }

    //Testa se o arquivo agenda existe
    if ((DATABASE = fopen("AGENDA", "rb")) == NULL){
        printf("BANCO DA AGENDA N%cO EXISTE OU ESTA CORRUMPIDA\n", 198);
        aviso = 1;
     }
    fclose(DATABASE);
    //Chamada das funções do programa

    printf("*--------Agenda Pessoal para ca%cadores--------*\n", 135);
    printf("*------Vers%co 1.8------Por: Jonathan Iury-----*\n\n", 198);


    //CASO O BANCO AGENDA NÃO EXISTA, CRIA-SE UM
    if (aviso == 1){
    printf("Agenda vazia, tecle ENTER para criar o BANCO DA AGENDA\n");
    printf("Tornando possivel o cadastro e consulta de GATAS\n");
        getchar();
        if ((DATABASE = fopen("AGENDA", "wb")) == NULL){
            printf("Erro ao criar arquivo\n");
        } else {
            printf("BANCO CRIADO COM SUCESSO!!!\n");
            fclose(DATABASE);
          }
    }

    leitura(Gata, &tamanho);
    printf("\n%d\n\n", tamanho);
    exibidados(Gata, aviso);
    printf("\n");
    consulta(Gata);
    printf("\n");
    menu(Gata, &tamanho);
    printf("\n\n");

}




