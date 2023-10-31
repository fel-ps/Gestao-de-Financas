#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include "clientes.h"
#include "variaveis.h"
#include "funcoes.h"

// VARIÁVEIS

void modulo_cliente(void){
    do {
        system("clear||cls");
        wprintf(L"==================================\n");
        wprintf(L"======= Módulo de Clientes =======\n");
        wprintf(L"==================================\n");
        wprintf(L"1 - Cadastrar Cliente\n");
        wprintf(L"2 - Pesquisar Cliente\n");
        wprintf(L"3 - Editar Cliente\n");
        wprintf(L"4 - Excluir Cliente\n");
        wprintf(L"0 - Sair\n");
        wprintf(L"\nDigite o que deseja fazer: "); scanf("%s", &opc);
        getchar();
        fflush(stdin);
        switch (opc) {
            case '1':
                cadastrar_cliente();
                getchar();
                fflush(stdin);
                break;
            case '2':
                pesquisar_cliente();
                getchar();
                fflush(stdin);
                break;
            case '3':
                editar_cliente();
                getchar();
                fflush(stdin);
                break;
            case '4':
                excluir_cliente();
                getchar();
                fflush(stdin);
                break;
            case '0':
                break;
            default:
                invalido();
                break;
        }
    } while (opc!='0');
}

// FUNÇÕES DE CLIENTES
void cadastrar_cliente(void){

    FILE* fp;
    Cliente* cliente;
    printf("Exemplo com Arquivo Binário\n");
    fp = fopen("clientes.dat","ab");
    if (fp == NULL) {
        fp = fopen("clientes.dat", "wb");
        if (fp == NULL) {
            wprintf(L"\nErro na criação");
            exit(1);
        }
    }

    system("clear||cls");
    wprintf(L"===============================\n");
    wprintf(L"====== Cadastrar Cliente ======\n");
    wprintf(L"===============================\n");
    wprintf(L"\n");
    cliente = preenche_Cliente();
    fwrite(cliente, sizeof(Cliente), 1, fp);
    fclose(fp);
    free(cliente);

}

void pesquisar_cliente(void){

    char cpf[12];

    system("clear||cls");
    wprintf(L"===============================\n");
    wprintf(L"====== Pesquisar Cliente ======\n");
    wprintf(L"===============================\n");
    wprintf(L"\n");
    ler_cpf(cpf);
}

void editar_cliente(void){

    char cpf[12];

    system("clear||cls");
    wprintf(L"===============================\n");
    wprintf(L"======== Editar Cliente =======\n");
    wprintf(L"===============================\n");
    wprintf(L"\n");
    ler_cpf(cpf);
}

void excluir_cliente(void){

    char cpf[12];

    system("clear||cls");
    wprintf(L"===============================\n");
    wprintf(L"======= Excluir Cliente =======\n");
    wprintf(L"===============================\n");
    wprintf(L"\n");
    ler_cpf(cpf);
}

Cliente* preenche_Cliente(void) {
    Cliente* cl;
    cl = (Cliente*) malloc(sizeof(Cliente));

    ler_nome(cl->nome);
    ler_cpf(cl->cpf);
    ler_telefone(cl->telefone);
    w_saldo(&cl->saldo);

    //cl->status = 'o';
    return cl;
}