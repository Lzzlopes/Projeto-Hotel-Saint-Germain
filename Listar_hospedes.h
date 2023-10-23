void Listar_hospedes(FILE *Hc){

    int c;

    Hc = fopen("Hospedes Cadastrados.txt", "r");

    //Mensagem de erro caso não exista o arquivo Hospedes Cadastrados

    if(Hc == NULL)
    {
        perror("Erro ao abrir o arquivo");
        return 1;
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

    return 0;
}