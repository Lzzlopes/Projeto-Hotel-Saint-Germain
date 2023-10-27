#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

/*#include "Listar_Hospedes.h"
#include "Cadastro_Hospede.h"*/

void cabecalho(){
    printf("\t\t\t       ___________________________________________  \n");
    printf("\t\t\t      |                                           |  \n");
    printf("\t\t\t      |           HOTEL SAINT GERMAIN             |  \n");
    printf("\t\t\t      |                                           |  \n");
    printf("\t\t\t      |                                           |  \n");
    printf("\t\t\t      |      _______     _______     _______      |  \n");
    printf("\t\t\t      |     |       |   |       |   |       |     |  \n");
    printf("\t\t\t      |     |       |   |       |   |       |     |  \n");
    printf("\t\t\t      |     |       |   |       |   |       |     |  \n");
    printf("\t\t\t      |     |_______|   |_______|   |_______|     |  \n");
    printf("\t\t\t      |                                           |  \n");
    printf("\t\t\t      |      _______     _______     _______      |  \n");
    printf("\t\t\t      |     |       |   |       |   |       |     |  \n");
    printf("\t\t\t      |     |       |   |       |   |       |     |  \n");
    printf("\t\t\t      |     |       |   |       |   |       |     |  \n");
    printf("\t\t\t      |     |_______|   |_______|   |_______|     |  \n");
    printf("\t\t\t      |      _______     _______     _______      |  \n");
    printf("\t\t\t      |     |       |   |       |   |       |     |  \n");
    printf("\t\t\t      |     |       |   |       |   |       |     |  \n");
    printf("\t\t\t      |     |       |   |       |   |       |     |  \n");
    printf("\t\t\t      |     |_______|   |_______|   |_______|     |  \n");
    printf("\t\t\t      |                                           |  \n");
    printf("\t\t\t      |           Recepção e Lobby                |  \n");
    printf("\t\t\t      |             ___________                   |  \n");
    printf("\t\t\t      |            |           |                  |  \n");
    printf("\t\t\t      |            |   _____   |                  |  \n");
    printf("\t\t\t      |            |  |     |  |                  |  \n");
    printf("\t\t\t      |            |  |     |  |                  |  \n");
    printf("\t\t\t      |            |  |º    |  |                  |  \n");
    printf("\t\t\t      |____________|__|_____|__|__________________|  \n");
    printf("\n\n\n\n");
}

int ID_Hospede = 1;

struct cadastro
{
    int opcao, numero_hospedes;
    char nome [50];
    int cpf;
    FILE *Hc;
};

struct cadastro cad;

void cadastro_hospedes(){

    int i;

    getchar();

    cad.Hc = fopen("Hospedes Cadastrados.txt", "a");

    //Mensagem de erro caso nÃ£o consiga abrir o arquivo

    if(cad.Hc == NULL)
    {
        perror("Erro ao abrir o arquivo");
        exit(1);
    }

    //Escrita no arquivo

    fprintf(cad.Hc, "ID: %i\n", ID_Hospede);

    printf("Digite seu nome: ");
    gets(cad.nome);
    cad.nome[strcspn(cad.nome, "\n")] = '\0';

    for (i = 0; i < strlen(cad.nome); i++)
    {
        fputc(cad.nome[i], cad.Hc);
    }
    fprintf(cad.Hc, "\n");

   fclose(cad.Hc);

    ID_Hospede +=1;
}


void Listar_hospedes(){

    int c;

    cad.Hc = fopen("Hospedes Cadastrados.txt", "r");

    //Mensagem de erro caso nÃ£o exista o arquivo Hospedes Cadastrados

    if(cad.Hc == NULL)
    {
        perror("Erro ao abrir o arquivo");
        exit(1);
    }

    //RepetiÃ§Ã£o de leitura atÃ© chegar ao fim do arquivo

    while (1){
        c = fgetc(cad.Hc);
        if (feof(cad.Hc))
        {
            break;
        }
        printf("%c", c);
    }

    //Fechar o arquivo

    fclose(cad.Hc);

}

int main(){

    //Declarações

    int opcao;
    setlocale(LC_ALL, "Portuguese");
    
    //Opções Iniciais

    cabecalho();

    while (opcao != 4)
    {
        printf("Escolha uma opção:\n");
        printf("\n1 - Criar uma conta\n");    
        printf("\n2 -  Listar hóspedes do hotel\n");
        printf("\n3 - Excluir hóspede do hotel\n");
        printf("\n4 - Sair\n");
        
        scanf("%i", &opcao);

        switch (opcao)
        {

            case 1:    /*Cadastro de novo hóspede*/
                cadastro_hospedes();
                break;

            case 2:    /*Listar Hóspedes cadastrados do hotel*/

                Listar_hospedes();
                break;
            case 3:    /*Excluir Hóspede do hotel*/
                printf("nao feito :)");
                break;
        }
    }
    
    return 0;
}