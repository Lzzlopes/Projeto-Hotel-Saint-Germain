#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cadastro.h"
#include "listar.h"

int numero_reserva = 0;

int main(){

    //Declarações

    int opcao, numero_hospedes;
    char *nome;
    int cpf[11];

    nome = (char *) malloc(50*sizeof(char));

    FILE *fp;

    //Fim declarações



    //Opções Iniciais

    printf("Escolha uma opção\n");
    printf("\n1 - Criar uma conta\n");    
    printf("\n2 -  Listar hóspedes do hotel\n");
    printf("\n3 - Excluir hóspede do hotel\n");
    
    scanf("%i", &opcao);

    switch (opcao)
    {

    case 1 /*Cadastro de novo hóspede*/:

        cadastro_hospedes(&nome, &cpf, &numero_hospedes, &numero_reserva);

        printf("Numero da reserva: %i", numero_reserva);
        printf("Nome do hóspede: %s", nome);
        printf("CPF: %i", cpf);        
        printf("Numero de hóspedes: %i", numero_hospedes);

        break;

    case 2 /*Listar Hóspedes cadastrados do hotel*/:

        Listar_Clientes();

        break;

    case 3 /*Excluir Hóspede do hotel*/:


        break;
    
    default:
        break;
    }


    return 0;
}