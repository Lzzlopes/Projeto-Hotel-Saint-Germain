/* Requisitos:

*Pedro* - Cadastrar um novo cliente com todas as particularidades que o ramo de atuação exigir;

*Luiz* - Listar todos cliente, de forma ordenada (numérica ou Alfabética) a ser escolhido pelo operador; OK

*Luiz* - Consultar um cliente a partir do CPF cadastrado, listando todas suas informação, sendo obrigatória a validação do CPF no momento do cadastro; TESTAR

*Pedro*- Desativar um cliente;

*Luiz* - Excluir um cliente; OK

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

    
}
//Fim Cadastro

//Ordenação
void selectionSort(struct cadastro *hospedes, int num_hospedes) {
    int i, j, min_idx;
    struct cadastro temp;

    for (i = 0; i < num_hospedes - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < num_hospedes; j++) {
            if (strcmp(hospedes[j].cpf, hospedes[min_idx].cpf) < 0) {
                min_idx = j;
            }
        }
        // Troca os hóspedes na posição i e min_idx
        temp = hospedes[i];
        hospedes[i] = hospedes[min_idx];
        hospedes[min_idx] = temp;
    }
}
//Fim Ordenação

//Listar todos os hóspedes - OK
void Listar_hospedes(){

    int i, num_hospedes;
    

    FILE *Hc = fopen("Hospedes Cadastrados.txt", "r");

    //Mensagem de erro caso não exista o arquivo Hospedes Cadastrados

    if(Hc == NULL)
    {
        printf("Erro ao abrir o arquivo");
        exit(1);
    }

    //contar o numero de hospedes

    fseek(Hc, 0, SEEK_END);
    num_hospedes = ftell(Hc) / sizeof(CADASTRO);
    rewind(Hc);

    //Alocar memória

    struct cadastro *hospedes = (struct cadastro *) malloc(num_hospedes * sizeof(struct cadastro));

    if(hospedes == NULL)
    {
        printf("Erro na alocação de memória");
        fclose(Hc);
        exit(1);
    }
    
    fread(hospedes, sizeof(struct cadastro), num_hospedes, Hc);

    fclose(Hc);

    selectionSort(hospedes, num_hospedes);

    printf("\n");
    for (i = 0; i < num_hospedes; i++)
    {
        printf("CPF: %s", hospedes[i].cpf);
        printf("Nome: %s", hospedes[i].nome);
        printf("Email: %s", hospedes[i].email);
        printf("Estado: %s", hospedes[i].estado);
        printf("Cidade: %s", hospedes[i].cidade);
        printf("Telefone: %i", hospedes[i].telefone);
    }

    free(hospedes);
    
}
//Fim listar todos os hospedes

//Listar Informações de um hóspede específico - testar
void Listar_info_hospede(){

    int flag = 1;
    char cpf[12];
    struct cadastro search;

    FILE *Hc = fopen("Hospedes Cadastrados.txt", "r");

    //Mensagem de erro caso não exista o arquivo Hospedes Cadastrados

    if(Hc == NULL)
    {
        printf("Erro ao abrir o arquivo");
        exit(1);
    }
    
    printf("Insira o CPF do hóspede que deseja ver os dados: ");
    fgets(cpf, sizeof(cpf), stdin);

    while (fread(&search, sizeof(CADASTRO), 1, Hc) == 1) {
    
        if(strcmp(search.cpf, cpf) == 0){
            flag = 0;
        printf("Informações do hóspede a ser excluído: ");
        printf("Nome: %s\n", search.nome);
        printf("CPF: %s", search.cpf);
        printf("Email: %s", search.email);
        printf("Estado: %s", search.estado);
        printf("Cidade: %s", search.cidade);
        printf("Telefone: %i", search.telefone);
        }
    }
    if(flag == 1){
    printf("Hóspede não encontrado!");
    }

    printf("Pressione uma tecla para continuar...");
    getchar();

    fclose(Hc);
    return;
}
//Fim listar info hóspede específico

//Excluir CLiente - OK
void Excluir_cliente(){
    int flag = 1;
    struct cadastro search;
    char opcao, cpf[12];

    FILE *Hc = fopen("Hospedes Cadastrados.txt", "r");

    //Mensagem de erro caso não exista o arquivo Hospedes Cadastrados

    if(Hc == NULL)
    {
        printf("Erro ao abrir o arquivo");
        exit(1);
    }
    
    printf("Insira o CPF do hóspede que deseja ver os dados: ");
    fgets(cpf, sizeof(cpf), stdin);

    while (fread(&search, sizeof(CADASTRO), 1, Hc) == 1) {
    
        if(strncmp(search.cpf, cpf, 11) == 0){
            flag = 0;
        printf("Informações do hóspede a ser excluído: ");
        printf("Nome: %s\n", search.nome);
        printf("CPF: %s", search.cpf);
        printf("Email: %s", search.email);
        printf("Estado: %s", search.estado);
        printf("Cidade: %s", search.cidade);
        printf("Telefone: %i", search.telefone);

        printf("Confirmar exclusão? s/n");
        opcao = getchar();
        if (opcao == 's' || opcao == 'S')
        {
            FILE *temp = fopen("temporario.txt", "w");
            fclose(temp);
            Hc = fopen("Hospedes Cadastrados.txt", "r");
            while (fread(&search, sizeof(CADASTRO), 1, Hc) == 1)
            {
                if (!strcmp(search.cpf, cpf) == 0)
                {
                    temp = fopen("temporario.txt", "a");
                    fwrite(&search, sizeof(CADASTRO), 1, temp);
                    fclose(temp);
                }
            }

            fclose(Hc);
            remove("Hospedes Cadastrados.txt");
            rename("temporario.txt", "Hospedes Cadastrados.txt");
            
            printf("Exclusão bem sucedida");

        } 
        else if((opcao == 'n') || (opcao == 'N')){
            fclose(Hc);
            printf("Exclusão de hóspede cancelada pelo usuário");
        }
        

        }
    }    
    if(flag == 1){
    printf("Hóspede não encontrado!");
    }

    printf("Pressione uma tecla para continuar...");
    getchar();

    fclose(Hc);
    return;
}
//Fim excluir cliente

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
                Excluir_cliente();
                break;
        }
    }
    
    return 0;
}