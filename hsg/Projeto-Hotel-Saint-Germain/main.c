/* Requisitos:

*Pedro* - Cadastrar um novo cliente com todas as particularidades que o ramo de atuação exigir;

*Luiz* - Listar todos cliente, de forma ordenada (numérica ou Alfabética) a ser escolhido pelo operador; OK

*Luiz* - Consultar um cliente a partir do CPF cadastrado, listando todas suas informação, sendo obrigatória a validação do CPF no momento do cadastro;

*Pedro*- Desativar um cliente;

*Luiz* - Excluir um cliente;

*Pedro*- Vender um serviço / realizar um pedido (A depender do tema abordado);

- Sair;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "struct_cadastro.h"

int ID_Hospede = 1;

// ilustração
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
};
//Fim ilustração


//cadastro de novos hóspedes
void cadastro_hospedes(){

    int i;

    getchar();

    cad.Hc = fopen("Hospedes Cadastrados.txt", "a");

    //Mensagem de erro caso não consiga abrir o arquivo

    if(cad.Hc == NULL)
    {
        printf("Erro ao abrir o arquivo");
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
//Fim Cadastro


//Listar todos os hóspedes
void Listar_hospedes(){

    int c;

    cad.Hc = fopen("Hospedes Cadastrados.txt", "r");

    //Mensagem de erro caso não exista o arquivo Hospedes Cadastrados

    if(cad.Hc == NULL)
    {
        printf("Erro ao abrir o arquivo");
        exit(1);
    }

    //Repetição de leitura até chegar ao fim do arquivo

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
//Fim listar todos os hospedes

//Listar Informações de um hóspede específico
void Listar_info_hospede(){

    int cpf, c;

    cad.Hc = fopen("Hospedes Cadastrados.txt", "r");

    //Mensagem de erro caso não exista o arquivo Hospedes Cadastrados

    if(cad.Hc == NULL)
    {
        printf("Erro ao abrir o arquivo");
        exit(1);
    }

    printf("Qual o CPF do hóspede?");
    scanf("%i", &cpf);

    while (fread(&cad, sizeof(cad), 1, cad.Hc))
    {
        if (strcmp(cpf, cad.cpf))
        {
            while (1)
            {
            c = fgetc(cad.Hc);
            printf("%c", c);    
            }
        }
    }
    
    
}
//Fim listar info hóspede específico

int main(){

    //Declarações

    int opcao;
    setlocale(LC_ALL, "Portuguese");
    
    //Opções Iniciais

    cabecalho();

    while (opcao != 5)
    {
        printf("Escolha uma opção:\n");
        printf("\n1 - Criar uma conta\n");    
        printf("\n2 -  Listar hóspedes do hotel\n");
        printf("\n3 - Mostar informações de hóspede\n");
        printf("\n4 - Excluir hóspede do hotel\n");
        printf("\n5 - Sair\n");
        
        scanf("%i", &opcao);

        switch (opcao)
        {

            case 1:    /*Cadastro de novo hóspede*/
                cadastro_hospedes();
                break;

            case 2:    /*Listar Hóspedes cadastrados do hotel*/

                Listar_hospedes();
                break;
            case 3: /*Listar Hóspede*/
                Listar_info_hospede();
                break;
            case 4:    /*Excluir Hóspede do hotel*/
                printf("nao feito :)");
                break;
        }
    }
    
    return 0;
}