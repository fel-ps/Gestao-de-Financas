#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <wchar.h>
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
        wprintf(L"2 - Listar Receitas\n");
        wprintf(L"3 - Editar Receita\n");
        wprintf(L"4 - Excluir Receita\n");
        wprintf(L"0 - Sair\n");
        wprintf(L"\nDigite o que deseja fazer: "); scanf("%s", &opc);
        getchar();
        fflush(stdin);
        switch (opc) {
            case '1':
                cadastrar_receita();
                break;
            case '2':
                listar_receitas();
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

    FILE* fp;
    RECEITA* receita;
    fp = fopen("receitas.dat","ab");
    if (fp == NULL) {
        wprintf(L"\nErro na criação");
        exit(1);
    }

    receita = preenche_receita();
    fwrite(receita, sizeof(RECEITA), 1, fp);
    fclose(fp);
    free(receita);

    wprintf(L"\nReceita Cadastrada!");
    wprintf(L"\nTecle <ENTER> para continuar...\n");
    getchar();
    fflush(stdin);

}

void editar_receita(void){

    char cpf[12];

    system("clear||cls");
    wprintf(L"===============================\n");
    wprintf(L"======== Editar Receita =======\n");
    wprintf(L"===============================\n");
    wprintf(L"\n");
    ler_cpf(cpf);
    // LISTAR DESPESAS
}

void excluir_receita(void){

    char cpf[12];

    system("clear||cls");
    wprintf(L"===============================\n");
    wprintf(L"======= Excluir Receita =======\n");
    wprintf(L"===============================\n");
    wprintf(L"\n");
    ler_cpf(cpf);
    // LISTAR DESPESAS
}

void listar_receitas(void){

    FILE* fp;
    RECEITA* rc;
    rc = (RECEITA*) malloc(sizeof(RECEITA));
    fp = fopen("receitas.dat", "rb");
    if (fp == NULL) {
        wprintf(L"\nErro na criação");
        exit(1);
    }

    char icpf[12];
    wprintf(L"\nDigite o CPF do cliente: "); scanf("%[^\n]%*c", icpf);
    fflush(stdin);
    while(fread(rc, sizeof(RECEITA), 1, fp)){
        exibe_receitas(rc, icpf);
    }

    wprintf(L"\nTecle <ENTER> para continuar...\n");
    getchar();
    fflush(stdin);

    free(rc);
    fclose(fp);

}

// CADASTRA RECEITA
RECEITA* preenche_receita(void) 
{
    RECEITA* rc;
    rc = (RECEITA*) malloc(sizeof(RECEITA));

    ler_cpf(rc->cpf);
    wprintf(L"Digite um pequeno texto sobre a origem da desta receita(sem acentuação): "); scanf("%[^\n]%*c", rc->receitatext);
    fflush(stdin);
    w_saldo(&rc->receitasaldo);
    wprintf(L"Digite a numeração da receita desta data(1,2,3..): "); scanf("%d", &(rc->id));
    fflush(stdin);
    obterDataAtual(rc->data);
    rc->status = 'a';

    return rc;
}

// EXIBIR RECEITAS
void exibe_receitas(RECEITA* rc, char *icpf)
{
    //  (rc->data == datinhainfo) && 
    if (rc == NULL) {
        wprintf(L"\n= = = Receitas Inexistentes = = =\n");
    } else if((strcmp(rc->cpf, icpf) == 0) && (rc->status != 'x')) {
        wprintf(L"\n----- %s -----\n", rc->data);
        wprintf(L"= = = Receita %d = = =\n", rc->id);
        wprintf(L"Valor Adiquirido(R$): %.2f\n", rc->receitasaldo);
        wprintf(L"Origem: %s\n", rc->receitatext);
    }
    else {
        return;
    }
} 