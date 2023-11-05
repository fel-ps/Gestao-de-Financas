#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <wchar.h>
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
        wprintf(L"2 - Listar Despesas\n");
        wprintf(L"3 - Editar Despesa\n");
        wprintf(L"4 - Excluir Despesa\n");
        wprintf(L"0 - Sair\n");
        wprintf(L"\nDigite o que deseja fazer: "); scanf("%s", &opc);
        getchar();
        fflush(stdin);
        switch (opc) {
            case '1':
                cadastrar_despesa();
                break;
            case '2':
                listar_despesas();
                break;
            case '3':
                editar_despesa();
                getchar();
                fflush(stdin);
                break;
            case '4':
                excluir_despesa();
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

    FILE* fp;
    DESPESA* despesa;
    fp = fopen("despesas.dat","ab");
    if (fp == NULL) {
        wprintf(L"\nErro na criação");
        exit(1);
    }

    despesa = preenche_despesa();
    fwrite(despesa, sizeof(DESPESA), 1, fp);
    fclose(fp);
    free(despesa);

    wprintf(L"\nDespesa Cadastrada!");
    wprintf(L"\nTecle <ENTER> para continuar...\n");
    getchar();
    fflush(stdin);
}

void listar_despesas(void){

    FILE* fp;
    DESPESA* ds;
    ds = (DESPESA*) malloc(sizeof(DESPESA));
    fp = fopen("despesas.dat", "rb");
    if (fp == NULL) {
        wprintf(L"\nErro na criação");
        exit(1);
    }

    char icpf[12];
    wprintf(L"\nDigite o CPF do cliente(Apenas números): "); scanf("%[^\n]%*c", icpf);
    fflush(stdin);
    while(fread(ds, sizeof(DESPESA), 1, fp)){
        exibe_despesas(ds, icpf);
    }

    wprintf(L"\nTecle <ENTER> para continuar...\n");
    getchar();
    fflush(stdin);

    free(ds);
    fclose(fp);
}

void editar_despesa(void){

    char cpf[12];

    system("clear||cls");
    wprintf(L"===============================\n");
    wprintf(L"======== Editar Despesa =======\n");
    wprintf(L"===============================\n");
    wprintf(L"\n");
    ler_cpf(cpf);
    // LISTAR DESPESAS
}

void excluir_despesa(void){

    char datainfo[11];
    char ecpf[12];
    int number;
    wprintf(L"\nDigite o CPF do cliente cuja a despesa pertence(Apenas números): "); scanf("%[^\n]%*c", ecpf);
    fflush(stdin);
    wprintf(L"Digite a data da despesa que deseja excluir(xx/yy/zzzz): "); scanf("%[^\n]%*c", datainfo);
    fflush(stdin);
    wprintf(L"Digite a numeração dela: "); scanf("%d", &number);
    fflush(stdin);

    excluirDespesa(ecpf, datainfo, number);
}

// CADASTRA DESPESA
DESPESA* preenche_despesa(void) 
{
    DESPESA* ds;
    ds = (DESPESA*) malloc(sizeof(DESPESA));

    ler_cpf(ds->cpf);
    wprintf(L"Digite um pequeno texto sobre a origem da desta receita(sem acentuação): "); scanf("%[^\n]%*c", ds->despesatext);
    fflush(stdin);
    w_saldo(&ds->despesasaldo);
    wprintf(L"Digite a numeração da despesa do dia de hoje(1,2,3..): "); scanf("%d", &(ds->id));
    fflush(stdin);
    obterDataAtual(ds->data);
    ds->status = 'a';

    return ds;
}

// EXIBIR DESPESAS
void exibe_despesas(DESPESA* ds, char *icpf)
{
    //  (ds->data == datinhainfo) && 
    if (ds == NULL) {
        wprintf(L"\n= = = Despesas Inexistentes = = =\n");
    } else if((strcmp(ds->cpf, icpf) == 0) && (ds->status != 'x')) {
        wprintf(L"\n----- %s -----\n", ds->data);
        wprintf(L"= = = Despesa %d = = =\n", ds->id);
        wprintf(L"Valor Adiquirido(R$): %.2f\n", ds->despesasaldo);
        wprintf(L"Origem: %s\n", ds->despesatext);
    }
    else {
        return;
    }
}

// EXCLUIR DESPESA
void excluirDespesa(char* cpf, char* datainfo, int number) {

    FILE* fp;
    DESPESA* ds;
    ds = (DESPESA*) malloc(sizeof(DESPESA));
    fp = fopen("despesas.dat", "rb+");
    if (fp == NULL) {
        wprintf(L"\nErro na criação");
        exit(1);
    }

    while (fread(ds, sizeof(DESPESA), 1, fp)) {
        if ((strcmp(ds->cpf, cpf) == 0) && (strcmp(ds->data, datainfo) == 0) && (ds->id == number))  {
            ds->status = 'x';
            fseeko(fp, -1*(off_t)sizeof(DESPESA), SEEK_CUR);
            fwrite(ds, sizeof(DESPESA), 1, fp);
            wprintf(L"\nDespesa excluída.\n");
            wprintf(L"\nTecle <ENTER> para continuar...\n");
            getchar();
            fflush(stdin);

            free(ds);
            fclose(fp);
            return;
        }
    }

    free(ds);
    fclose(fp);
    wprintf(L"\nDespesa não encontrada.\n");

    wprintf(L"\nTecle <ENTER> para continuar...\n");
    getchar();
    fflush(stdin);
}
