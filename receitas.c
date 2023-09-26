#include <stdio.h>
#include <stdlib.h>
#include "receitas.h"
#include "variaveis.h"
#include "funcoes.h"

// VARIÁVEIS

void modulo_receita(void){
    do {
        system("clear||cls");
        wprintf(L"==================================\n");
        wprintf(L"======= Módulo de Receitas =======\n");
        wprintf(L"==================================\n");
        wprintf(L"1 - Cadastrar Receita\n");
        wprintf(L"2 - Pesquisar Receita\n");
        wprintf(L"3 - Editar Receita\n");
        wprintf(L"4 - Excluir Receita\n");
        wprintf(L"0 - Sair\n");
        wprintf(L"\nDigite o que deseja fazer: "); scanf("%s", &opc);
        getchar();
        fflush(stdin);
        switch (opc) {
            case '1':
                cadastrar_receita();
                getchar();
                fflush(stdin);
                break;
            case '2':
                pesquisar_receita();
                getchar();
                fflush(stdin);
                break;
            case '3':
                editar_receita();
                getchar();
                fflush(stdin);
                break;
            case '4':
                excluir_receita();
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

// FUNÇÕES DE RECEITAS
void cadastrar_receita(void){
    system("clear||cls");
    wprintf(L"===============================\n");
    wprintf(L"====== Cadastrar Receita ======\n");
    wprintf(L"===============================\n");
    wprintf(L"\n");
    wprintf(L"Digite o seu CPF:\n");
    wprintf(L"Digite o valor($) da receita:\n");
    wprintf(L"Informe de onde foi apurado esse valor:\n");
}

void pesquisar_receita(void){
    system("clear||cls");
    wprintf(L"===============================\n");
    wprintf(L"====== Pesquisar Receita ======\n");
    wprintf(L"===============================\n");
    wprintf(L"\n");
    wprintf(L"Digite o seu CPF:\n");
    // LISTAR DESPESAS
}

void editar_receita(void){
    system("clear||cls");
    wprintf(L"===============================\n");
    wprintf(L"======== Editar Receita =======\n");
    wprintf(L"===============================\n");
    wprintf(L"\n");
    wprintf(L"Digite o seu CPF:\n");
    // LISTAR DESPESAS
}

void excluir_receita(void){
    system("clear||cls");
    wprintf(L"===============================\n");
    wprintf(L"======= Excluir Receita =======\n");
    wprintf(L"===============================\n");
    wprintf(L"\n");
    wprintf(L"Digite o seu CPF:\n");
    // LISTAR DESPESAS
}