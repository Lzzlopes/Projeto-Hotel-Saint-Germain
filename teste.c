/* Requisitos:

*Pedro* - Cadastrar um novo cliente com todas as particularidades que o ramo de atua��o exigir;

*Luiz* - Listar todos cliente, de forma ordenada (num�rica ou Alfab�tica) a ser escolhido pelo operador; OK

*Luiz* - Consultar um cliente a partir do CPF cadastrado, listando todas suas informa��o, sendo obrigat�ria a valida��o do CPF no momento do cadastro;

*Pedro*- Desativar um cliente;

*Luiz* - Excluir um cliente;

*Pedro*- Vender um servi�o / realizar um pedido (A depender do tema abordado);

- Sair;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "struct_cadastro.h"

int ID_Hospede = 1;

// ilustra��o
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
    printf("\t\t\t      |           Recep��o e Lobby                |  \n");
    printf("\t\t\t      |             ___________                   |  \n");
    printf("\t\t\t      |            |           |                  |  \n");
    printf("\t\t\t      |            |   _____   |                  |  \n");
    printf("\t\t\t      |            |  |     |  |                  |  \n");
    printf("\t\t\t      |            |  |     |  |                  |  \n");
    printf("\t\t\t      |            |  |�    |  |                  |  \n");
    printf("\t\t\t      |____________|__|_____|__|__________________|  \n");
    printf("\n\n\n\n");
};
//Fim ilustra��o

// Pausa
void pausa(){
    while (getchar() != '\n'); // Limpa o buffer do teclado
    getchar(); // Aguarda a entrada de qualquer tecla
}
//Fim Pausa

//cadastro de novos h�spedes
void cadastro_hospedes(FILE **Hc){

    int i;

    getchar();

    *Hc = fopen("Hospedes Cadastrados.txt", "ab");

    //Mensagem de erro caso n�o consiga abrir o arquivo

    if(*Hc == NULL)
    {
        printf("Erro ao abrir o arquivo");
        exit(1);
    }

    //Escrita no arquivo

    fprintf(*Hc, "ID: %i\n", ID_Hospede);

    printf("Digite seu nome: ");
    gets(cad.nome);
    cad.nome[strcspn(cad.nome, "\n")] = '\0';

    for (i = 0; i < strlen(cad.nome); i++)
    {
        fputc(cad.nome[i], *Hc);
    }
    fprintf(*Hc, "\n");

    fprintf(*Hc, "CPF: %i\n", cad.cpf);

   fclose(*Hc);

    ID_Hospede +=1;
    cad.cpf += 1;
}
//Fim Cadastro


//Listar todos os h�spedes com crit�rios
void Listar_hospedes(FILE **Hc){

    system("cls");

    int c;

    *Hc = fopen("Hospedes Cadastrados.txt", "rb");

    //Mensagem de erro caso n�o exista o arquivo Hospedes Cadastrados

    if(*Hc == NULL)
    {
        printf("Erro ao abrir o arquivo");
        exit(1);
    }

    //Repeti��o de leitura at� chegar ao fim do arquivo

    while (1){
        c = fgetc(*Hc);
        if (feof(*Hc))
        {
            break;
        }
        printf("%c", c);
    }

    printf("Pressione uma tecla para continuar...");

    pausa();

    //Fechar o arquivo

    fclose(*Hc);

    
}
//Fim listar todos os hospedes

//Listar Informa��es de um h�spede espec�fico
void Listar_info_hospede(FILE **Hc){

    int cpf, flag = 0;
    char buffer[100];

    *Hc = fopen("Hospedes Cadastrados.txt", "r");

    //Mensagem de erro caso n�o exista o arquivo Hospedes Cadastrados

    if(*Hc == NULL)
    {
        printf("Erro ao abrir o arquivo");
        exit(1);
    }
    
    printf("Insira o CPF do h�spede que deseja ver os dados: ");
    scanf("%i", &cpf);

    while (fgets(buffer, sizeof(buffer), *Hc)) {
        int aux_cpf;
        if (sscanf(buffer, "CPF: %i", &aux_cpf)) 
        {

            if (aux_cpf == cpf) 
            {
                printf("CPF: %i\n", aux_cpf);
                while (fgets(buffer, sizeof(buffer), *Hc))
                {
                    if (sscanf(buffer, "Nome: %s", cad.nome) == 1) {
                        printf("Nome: %s\n", cad.nome);
                    } else if (sscanf(buffer, "Email: %s", cad.email) == 1) {
                        printf("Email: %s\n", cad.email);
                    } else if (sscanf(buffer, "Estado: %s", cad.estado) == 1) {
                        printf("Estado: %s\n", cad.estado);
                    } else if (sscanf(buffer, "Cidade: %s", cad.cidade) == 1) {
                        printf("Cidade: %s\n", cad.cidade);
                    } else if (sscanf(buffer, "Telefone: %d", &cad.telefone) == 1) {
                        printf("Telefone: %d\n", cad.telefone);
                        break;
                    }
                }   
                flag = 1;
                break;
            }
        }
    }
    
    if(!flag){
    printf("H�spede n�o encontrado!");
    }

    printf("Pressione uma tecla para continuar...");
    getchar();

    fclose(*Hc);
    return;
}
//Fim listar info h�spede espec�fico

int main(){

    //Declara��es

    int opcao;
    FILE *Hc;
    setlocale(LC_ALL, "Portuguese");
    
    //Op��es Iniciais

    cabecalho();

    while (opcao != 5)
    {
        printf("Escolha uma op��o:\n");
        printf("\n1 - Criar uma conta\n");    
        printf("\n2 -  Listar h�spedes do hotel\n");
        printf("\n3 - Mostar informa��es de h�spede\n");
        printf("\n4 - Excluir h�spede do hotel\n");
        printf("\n5 - Sair\n");
        
        scanf("%i", &opcao);

        switch (opcao)
        {

            case 1:    /*Cadastro de novo h�spede*/
                cadastro_hospedes(&Hc);
                break;

            case 2:    /*Listar H�spedes cadastrados do hotel*/
                Listar_hospedes(&Hc);
                break;
            case 3: /*Listar H�spede*/
                Listar_info_hospede(&Hc);
                break;
            case 4:    /*Excluir H�spede do hotel*/
                printf("nao feito :)");
                break;
        }
    }
    
    return 0;
}