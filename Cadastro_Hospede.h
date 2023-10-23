void cadastro_hospede(char *nome, int *CPF, int *numero_hospedes, int *numero_reserva){

    *numero_reserva +=1;

    printf("Nome:");
    scanf(" %s", nome);
    printf("Cpf: ");
    scanf("%i", CPF);
    printf("Numero de hospedes: ");
    scanf("%i", numero_hospedes);


}
