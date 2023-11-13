#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>
#include <time.h>

struct cadastro{
    char nome[25], sobrenome[25], email[80], pais[30], estado[30], cidade[30], rua[30];
    char cpf[11];
    long long int telefone;
    int numero, idade;
    int status; //1 para ativado e 0 para desativado
    
};

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

//Validar CPF
bool validarCPF(char cpf[]) {
    // Verifica se o CPF possui 11 dígitos
    if (strlen(cpf) != 11) {
        return false;
    }
    else if((strcmp(cpf,"00000000000") == 0) || (strcmp(cpf,"11111111111") == 0) || (strcmp(cpf,"22222222222") == 0) ||
        (strcmp(cpf,"33333333333") == 0) || (strcmp(cpf,"44444444444") == 0) || (strcmp(cpf,"55555555555") == 0) ||
        (strcmp(cpf,"66666666666") == 0) || (strcmp(cpf,"77777777777") == 0) || (strcmp(cpf,"88888888888") == 0) ||
        (strcmp(cpf,"99999999999") == 0)){
        return false;           
    }

    // Calcula o primeiro dígito verificador
    int soma = 0;
    for (int i = 0; i < 9; i++) {
        soma += (cpf[i] - '0') * (10 - i);
    }
    int digito1 = (soma % 11 < 2) ? 0 : 11 - (soma % 11);

    // Verifica o primeiro dígito verificador
    if (digito1 != cpf[9] - '0') {
        return false;
    }

    // Calcula o segundo dígito verificador
    soma = 0;
    for (int i = 0; i < 10; i++) {
        soma += (cpf[i] - '0') * (11 - i);
    }
    int digito2 = (soma % 11 < 2) ? 0 : 11 - (soma % 11);

    // Verifica o segundo dígito verificador
    if (digito2 != cpf[10] - '0') {
        return false;
    }

    // CPF é válido
    return true;
}

//cadastro de novos hóspedes
void cadastro_hospedes(){

    bool validadeCPF;

    FILE *Hc = fopen("Hospedes Cadastrados.txt", "a+");
    
    //Mensagem de erro caso não exista o arquivo Hospedes Cadastrados
    if(Hc == NULL){
        printf("\nErro ao abrir o arquivo");
        exit(1);
    }

    struct cadastro hospede;

    do{
        printf("Digite seu CPF sem pontos e traços: ");
        fflush(stdin);
        scanf("%s", hospede.cpf);
        validadeCPF = validarCPF(hospede.cpf);
        if(validadeCPF == false){
            printf("\nCPF inválido!\n");
        }

    }while(validadeCPF == false);

    printf("\nDigite seu primeiro nome: ");
    fflush(stdin);
    gets(hospede.nome);

    printf("\nDigite seu último sobrenome: ");
    fflush(stdin);
    gets(hospede.sobrenome);
    
    printf("\nDigite seu e-mail: ");
    fflush(stdin);
    scanf("%s", hospede.email);

    printf("\nDigite seu telefone (com DDD e tudo junto): ");
    fflush(stdin);
    scanf("%lld", &hospede.telefone);

    printf("\nDigite sua idade: ");
    fflush(stdin);
    scanf("%d", &hospede.idade);

    if(hospede.idade < 18){
        printf("Idade mínima: 18 anos");
        exit(1);
    }

    printf("\nDigite o país que você mora: ");
    fflush(stdin);
    gets(hospede.pais);

    printf("\nDigite o estado que você mora: ");
    fflush(stdin);
    gets(hospede.estado);

    printf("\nDigite a cidade que você mora: ");
    fflush(stdin);
    gets(hospede.cidade);

    printf("\nDigite a rua que você mora: ");
    fflush(stdin);
    gets(hospede.rua);

    printf("\nDigite o número da casa que você mora: ");
    fflush(stdin);
    scanf("%d", &hospede.numero);

    hospede.status = 1;

    fprintf(Hc, "%s %s %s %lld %s %d %s %s %s %s %d %i\n", hospede.nome, hospede.sobrenome, hospede.email, hospede.telefone, hospede.cpf, hospede.idade, hospede.pais, hospede.estado, hospede.cidade, hospede.rua, hospede.numero, hospede.status);

    fclose(Hc);
}

//Fim Cadastro


//Desativar um hospede especifico
void Desativar_hospedes(){
    FILE *Hc = fopen("Hospedes Cadastrados.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

        if((Hc == NULL) || (temp == NULL)){
        printf("\nErro ao abrir o arquivo");
        exit(1);
    }

    char cpf[11];
    int encontrado = 0;

    printf("Digite o CPF do hospede que deseja desativar: ");
    fflush(stdin);
    scanf("%s", cpf);

    struct cadastro hospede;

    while(fscanf(Hc, "%s %s %s %lld %s %d %s %s %s %s %d %i", hospede.nome, hospede.sobrenome, hospede.email, hospede.telefone, hospede.cpf, hospede.idade, hospede.pais, hospede.estado, hospede.cidade, hospede.rua, hospede.numero, hospede.status) != EOF){

        if(strcmp(hospede.cpf, cpf) == 0);
            printf("Nome: %s %s", hospede.nome, hospede.sobrenome);
    }


}


//Listar todos os hóspedes - falta ordenação
void Listar_hospedes(){

    int c;

    FILE *Hc = fopen("Hospedes Cadastrados.txt", "r");

    //Mensagem de erro caso não exista o arquivo Hospedes Cadastrados

    if(Hc == NULL)
    {
        printf("\nErro ao abrir o arquivo");
        exit(1);
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
//Fim listar todos os hospedes

//Listar Informações de um hóspede específico - testar
void Listar_info_hospede(){
    char cpf[11];
    int flag = 1;
    struct cadastro search;
    char opcao;

    FILE *Hc = fopen("Hospedes Cadastrados.txt", "r");

    //Mensagem de erro caso não exista o arquivo Hospedes Cadastrados

    if(Hc == NULL)
    {
        printf("Erro ao abrir o arquivo");
        exit(1);
    }
    
    printf("Insira o CPF do hóspede que deseja ver os dados: ");
    scanf("%i", &cpf);

    while (fread(&search, sizeof(struct cadastro), 1, Hc) == 1) {
    
        if(strncmp(search.cpf, cpf, 11) == 0){
            flag = 0;
        printf("Informações do hóspede: ");
        printf("Nome: %s\n", search.nome);
        printf("Idade: %s\n", search.idade);
        printf("CPF: %i/n", search.cpf);
        printf("Email: %s\n", search.email);
        printf("País: %s\n", search.pais);
        printf("Estado: %s\n", search.estado);
        printf("Cidade: %s\n", search.cidade);
        printf("Rua: %s\n", search.rua);
        printf("Numero: %s\n", search.numero);
        printf("Telefone: %i\n", search.telefone);
        }
    }
    if(flag == 1){
    printf("Hóspede não encontrado!\n");
    }

    printf("Pressione uma tecla para continuar...");
    getchar();

    fclose(Hc);
    return;
}

//Fim listar info hóspede específico

//Excluir CLiente - testar
void Excluir_cliente(){
    char cpf[11];
    int flag = 1;
    struct cadastro search;
    char opcao;

    FILE *Hc = fopen("Hospedes Cadastrados.txt", "r");

    //Mensagem de erro caso não exista o arquivo Hospedes Cadastrados

    if(Hc == NULL)
    {
        printf("Erro ao abrir o arquivo");
        exit(1);
    }
    
    printf("Insira o CPF do hóspede que deseja ver os dados: ");
    scanf("%i", &cpf);

    while (fread(&search, sizeof(struct cadastro), 1, Hc) == 1) {
    
        if(strncmp(search.cpf, cpf, 11) == 0){
            flag = 0;
        printf("Informações do hóspede a ser excluído: ");
        printf("Nome: %s\n", search.nome);
        printf("Idade: %s\n", search.idade);
        printf("CPF: %i/n", search.cpf);
        printf("Email: %s\n", search.email);
        printf("País: %s\n", search.pais);
        printf("Estado: %s\n", search.estado);
        printf("Cidade: %s\n", search.cidade);
        printf("Rua: %s\n", search.rua);
        printf("Numero: %s\n", search.numero);
        printf("Telefone: %i\n", search.telefone);

        printf("Confirmar exclusão? s/n");
        opcao = getchar();
        if (opcao == 's' || opcao == 'S')
        {
            FILE *temp = fopen("temporario.txt", "w");
            fclose(temp);
            Hc = fopen("Hospedes Cadastrados.txt", "r");
            while (fread(&search, sizeof(struct cadastro), 1, Hc) == 1)
            {
                if (!strcmp(search.cpf, cpf) == 0)
                {
                    temp = fopen("temporario.txt", "a");
                    fwrite(&search, sizeof(struct cadastro), 1, temp);
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