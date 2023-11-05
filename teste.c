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

// Pausa
void pausa(){
    while (getchar() != '\n'); // Limpa o buffer do teclado
    getchar(); // Aguarda a entrada de qualquer tecla
}
//Fim Pausa

//cadastro de novos hóspedes
void cadastro_hospedes(FILE **Hc){

    int i;

    getchar();

    *Hc = fopen("Hospedes Cadastrados.txt", "ab");

    //Mensagem de erro caso não consiga abrir o arquivo

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


//Listar todos os hóspedes com critérios
void Listar_hospedes(FILE **Hc){

    system("cls");

    int c;

    *Hc = fopen("Hospedes Cadastrados.txt", "rb");

    //Mensagem de erro caso não exista o arquivo Hospedes Cadastrados

    if(*Hc == NULL)
    {
        printf("Erro ao abrir o arquivo");
        exit(1);
    }

    //Repetição de leitura até chegar ao fim do arquivo

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

//Listar Informações de um hóspede específico
void Listar_info_hospede(FILE **Hc){

    int cpf, flag = 0;
    char buffer[100];

    *Hc = fopen("Hospedes Cadastrados.txt", "r");

    //Mensagem de erro caso não exista o arquivo Hospedes Cadastrados

    if(*Hc == NULL)
    {
        printf("Erro ao abrir o arquivo");
        exit(1);
    }
    
    printf("Insira o CPF do hóspede que deseja ver os dados: ");
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
    printf("Hóspede não encontrado!");
    }

    printf("Pressione uma tecla para continuar...");
    getchar();

    fclose(*Hc);
    return;
}
//Fim listar info hóspede específico

int main(){

    //Declarações

    int opcao;
    FILE *Hc;
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
                cadastro_hospedes(&Hc);
                break;

            case 2:    /*Listar Hóspedes cadastrados do hotel*/
                Listar_hospedes(&Hc);
                break;
            case 3: /*Listar Hóspede*/
                Listar_info_hospede(&Hc);
                break;
            case 4:    /*Excluir Hóspede do hotel*/
                printf("nao feito :)");
                break;
        }
    }
    
    return 0;
}