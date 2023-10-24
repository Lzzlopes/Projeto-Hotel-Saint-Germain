#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include 

/*#include "Listar_Hospedes.h"
#include "Cadastro_Hospede.h"*/

int ID_Hospede = 0;

void cadastro_hospedes(FILE *Hc){

    Hc = fopen("Hospedes Cadastrados.txt", "a");


    //Mensagem de erro caso não consiga abrir o arquivo

    if(Hc == NULL)
    {
        perror("Erro ao abrir o arquivo");
    }

    //Escrita no arquivo

    fprinf("ID: %i", ID_Hospede);
   

}


void Listar_hospedes(FILE *Hc){

    int c;

    Hc = fopen("Hospedes Cadastrados.txt", "r");

    //Mensagem de erro caso não exista o arquivo Hospedes Cadastrados

    if(Hc == NULL)
    {
        perror("Erro ao abrir o arquivo");
    }

    //Repetição de leitura até chegar ao fim do arquivo

    while (1){
        c = fgetc(Hc);
        if (feof(Hc))
        {
            break;
        }
        printf("%c", c);
    }

    //Fechar o arquivo

    fclose(Hc);

}


int main(){

    //Declarações

    int opcao, numero_hospedes;
    char *nome = (char *) malloc(50*sizeof(char));
    int cpf;
    FILE *Hc;

    //Fim declarações



    //Opções Iniciais

    printf("Escolha uma opção\n");
    printf("\n1 - Criar uma conta\n");    
    printf("\n2 -  Listar hóspedes do hotel\n");
    printf("\n3 - Excluir hóspede do hotel\n");
    printf("\n4 - Sair");
    
    scanf("%i", &opcao);

    switch (opcao)
    {

    case 1 /*Cadastro de novo hóspede*/:

        cadastro_hospedes(Hc);

    case 2 /*Listar Hóspedes cadastrados do hotel*/:

        Listar_hospedes(Hc);



    case 3 /*Excluir Hóspede do hotel*/:

    
    case 4:
        return 0;
    }

}