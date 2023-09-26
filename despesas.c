#include <stdio.h>
#include <stdlib.h>
#include "despesas.h"
#include "variaveis.h"
#include "funcoes.h"

// VARIÁVEIS

void modulo_despesa(void){
    do {
        system("clear||cls");
        wprintf(L"==================================\n");
        wprintf(L"======= Módulo de Despesas =======\n");
        wprintf(L"==================================\n");
        wprintf(L"1 - Cadastrar Despesa\n");
        wprintf(L"2 - Pesquisar Despesa\n");
        wprintf(L"3 - Editar Despesa\n");
        wprintf(L"4 - Excluir Despesa\n");
        wprintf(L"0 - Sair\n");
        wprintf(L"\nDigite o que deseja fazer: "); scanf("%s", &opc);
        fflush(stdin);
        switch (opc) {
            case '1':
                cadastrar_despesa();
                getchar();
                fflush(stdin);
                break;
            case '2':
                pesquisar_despesa();
                getchar();
                fflush(stdin);
                break;
            case '3':
                editar_despesa();
                getchar();
                fflush(stdin);
                break;
            case '4':
                excluir_despesa();
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

// FUNÇÕES DE DESPESAS
void cadastrar_despesa(void){
    system("clear||cls");
    wprintf(L"===============================\n");
    wprintf(L"====== Cadastrar Despesa ======\n");
    wprintf(L"===============================\n");
    wprintf(L"\n");
    wprintf(L"Digite o seu CPF:\n");
    wprintf(L"Digite o valor($) da despesa:\n");
    wprintf(L"Informe em que foi gasto o valor informado:\n");
}

void pesquisar_despesa(void){
    system("clear||cls");
    wprintf(L"===============================\n");
    wprintf(L"====== Pesquisar Despesa ======\n");
    wprintf(L"===============================\n");
    wprintf(L"\n");
    wprintf(L"Digite o seu CPF:\n");
    // LISTAR DESPESAS
}

void editar_despesa(void){
    system("clear||cls");
    wprintf(L"===============================\n");
    wprintf(L"======== Editar Despesa =======\n");
    wprintf(L"===============================\n");
    wprintf(L"\n");
    wprintf(L"Digite o seu CPF:\n");
    // LISTAR DESPESAS
}

void excluir_despesa(void){
    system("clear||cls");
    wprintf(L"===============================\n");
    wprintf(L"======= Excluir Despesa =======\n");
    wprintf(L"===============================\n");
    wprintf(L"\n");
    wprintf(L"Digite o seu CPF:\n");
    // LISTAR DESPESAS
}