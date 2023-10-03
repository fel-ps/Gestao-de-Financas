#include <stdio.h>
#include <stdlib.h>
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

    char cpf[12];
    char name[51];
    char telefone[16];

    system("clear||cls");
    wprintf(L"===============================\n");
    wprintf(L"====== Cadastrar Cliente ======\n");
    wprintf(L"===============================\n");
    wprintf(L"\n");
    ler_nome(name);
    ler_cpf(cpf);
    ler_telefone(telefone);
    wprintf(L"Endereço:\n");
}

void pesquisar_cliente(void){
    system("clear||cls");
    wprintf(L"===============================\n");
    wprintf(L"====== Pesquisar Cliente ======\n");
    wprintf(L"===============================\n");
    wprintf(L"\n");
    wprintf(L"Digite o CPF:\n");
}

void editar_cliente(void){
    system("clear||cls");
    wprintf(L"===============================\n");
    wprintf(L"======== Editar Cliente =======\n");
    wprintf(L"===============================\n");
    wprintf(L"\n");
    wprintf(L"Digite o CPF:\n");
}

void excluir_cliente(void){
    system("clear||cls");
    wprintf(L"===============================\n");
    wprintf(L"======= Excluir Cliente =======\n");
    wprintf(L"===============================\n");
    wprintf(L"\n");
    wprintf(L"Digite o CPF:\n");
}