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
#include "funcoes.h"

int main(){

    //Declarações

    int opcao;
    setlocale(LC_ALL, "Portuguese");
    
    //Opções Iniciais

    cabecalho();

    while (opcao != 5)
    {
        cabecalho(); 
        printf("Escolha uma opção:\n");
        printf("\n1 - Criar uma conta\n");    
        printf("\n2 -  Listar hóspedes do hotel\n");
        printf("\n3 - Mostar informações de hóspede\n");
        printf("\n4 - Excluir hóspede do hotel\n");
        printf("\n5 - Sair\n\n");
        
        printf("Digite o numero da opção que deseja escolher: ");
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