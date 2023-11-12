#ifndef struct_cadastro
#define struct_cadastro

typedef struct cadastro CADASTRO;
struct cadastro
{
    char nome [50], email [30], estado[3], cidade[30], cpf[12];
    int telefone;
};

#endif