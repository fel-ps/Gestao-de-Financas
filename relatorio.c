#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <wchar.h>
#include <stdbool.h>
#include <time.h>
#include "clientes.h"
#include "despesas.h"
#include "receitas.h"
#include "relatorio.h"
#include "variaveis.h"
#include "funcoes.h"

// VARIÁVEIS

void modulo_relatorio(void){
    do {

        char cpffinal[12];

        system("clear||cls");
        wprintf(L"================================\n");
        wprintf(L"===== Módulo de Relatórios =====\n");
        wprintf(L"================================\n");
        wprintf(L"1 - Listar Despesas Por Mês\n");
        wprintf(L"2 - Listar Receitas Por Mês\n");
        wprintf(L"3 - Relatar Saldo do Mês atual\n");
        wprintf(L"0 - Sair\n");
        wprintf(L"\nDigite o que deseja fazer: "); scanf("%s", &opc);
        getchar();
        fflush(stdin);
        switch (opc) {
            case '1':
                list_dm();
                break;
            case '2':
                list_rm();
                break;
            case '3':
                wprintf(L"\n");
                ler_cpf(cpffinal);
                if(verifica_existe_cliente(cpffinal) == 0)
                {
                    saldofinal(cpffinal);
                } else {
                    wprintf(L"\nCliente não encontrado!");
                }
                break;
            case '0':
                break;
            default:
                invalido();
                break;
        }
    } while (opc!='0');
}

// DESPESA MENSAL

void list_dm(void) {

    int opx = -1;

    do 
    {

        system("clear||cls");
        wprintf(L"=========================================\n");
        wprintf(L"========= Listar Despesa Mensal =========\n");
        wprintf(L"=========================================\n");
        wprintf(L"\n");
        wprintf(L"1 - January  | 5 - May    | 10 - October\n");
        wprintf(L"2 - February | 6 - June   | 9 - September\n");
        wprintf(L"3 - March    | 7 - July   | 11 - November\n");
        wprintf(L"4 - April    | 8 - August | 12 - December\n");
        wprintf(L"\n");
        wprintf(L"Informe o mês desejado ('0' para sair): "); scanf("%d", &opx);
        getchar();
        fflush(stdin);
        switch (opx) {
            case 1:
                system("clear||cls");
                wprintf(L"\t\t\t\t\tDESPESAS DE JANEIRO");
                ;
                char mes[3] = "01";
                imprimirDespesasDoMes("despesas.dat", mes);
                break;
            case 2:
                system("clear||cls");
                wprintf(L"\t\t\t\t\tDESPESAS DE FEVEREIRO");
                ;
                char mes2[3] = "02";
                imprimirDespesasDoMes("despesas.dat", mes2);
                break;
            case 3:
                system("clear||cls");
                wprintf(L"\t\t\t\t\tDESPESAS DE MARÇO");
                ;
                char mes3[3] = "03";
                imprimirDespesasDoMes("despesas.dat", mes3);
                break;
            case 4:
                system("clear||cls");
                wprintf(L"\t\t\t\t\tDESPESAS DE ABRIL");
                ;
                char mes4[3] = "04";
                imprimirDespesasDoMes("despesas.dat", mes4);
                break;
            case 5:
                system("clear||cls");
                wprintf(L"\t\t\t\t\tDESPESAS DE MAIO");
                ;
                char mes5[3] = "05";
                imprimirDespesasDoMes("despesas.dat", mes5);
                break;
            case 6:
                system("clear||cls");
                wprintf(L"\t\t\t\t\tDESPESAS DE JUNHO");
                ;
                char mes6[3] = "06";
                imprimirDespesasDoMes("despesas.dat", mes6);
                break;
            case 7:
                system("clear||cls");
                wprintf(L"\t\t\t\t\tDESPESAS DE JULHO");
                ;
                char mes7[3] = "07";
                imprimirDespesasDoMes("despesas.dat", mes7);
                break;
            case 8:
                system("clear||cls");
                wprintf(L"\t\t\t\t\tDESPESAS DE AGOSTO");
                ;
                char mes8[3] = "08";
                imprimirDespesasDoMes("despesas.dat", mes8);
                break;
            case 9:
                system("clear||cls");
                wprintf(L"\t\t\t\t\tDESPESAS DE SETEMBRO");
                ;
                char mes9[3] = "09";
                imprimirDespesasDoMes("despesas.dat", mes9);
                break;
            case 10:
                system("clear||cls");
                wprintf(L"\t\t\t\t\tDESPESAS DE OUTUBRO");
                ;
                char mes10[3] = "10";
                imprimirDespesasDoMes("despesas.dat", mes10);
                break;
            case 11:
                system("clear||cls");
                wprintf(L"\t\t\t\t\tDESPESAS DE NOVEMBRO");
                ;
                char mes11[3] = "11";
                imprimirDespesasDoMes("despesas.dat", mes11);
                break;
            case 12:
                system("clear||cls");
                wprintf(L"\t\t\t\t\tDESPESAS DE DEZEMBRO");
                ;
                char mes12[3] = "12";
                imprimirDespesasDoMes("despesas.dat", mes12);
                break;
            case 0:
                break;
            default:
                invalido();
                break;
        }

    } while (opx!=0);
}

// RECEITA MENSAL

void list_rm(void) {

    int opx = -1;

    do 
    {

        system("clear||cls");
        wprintf(L"=========================================\n");
        wprintf(L"========= Listar Receita Mensal =========\n");
        wprintf(L"=========================================\n");
        wprintf(L"\n");
        wprintf(L"1 - January  | 5 - May    | 10 - October\n");
        wprintf(L"2 - February | 6 - June   | 9 - September\n");
        wprintf(L"3 - March    | 7 - July   | 11 - November\n");
        wprintf(L"4 - April    | 8 - August | 12 - December\n");
        wprintf(L"\n");
        wprintf(L"Informe o mês desejado ('0' para sair): "); scanf("%d", &opx);
        getchar();
        fflush(stdin);
        switch (opx) {
            case 1:
                system("clear||cls");
                wprintf(L"\t\t\t\t\tRECEITAS DE JANEIRO");
                ;
                char mes[3] = "01";
                imprimirReceitasDoMes("receitas.dat", mes);
                break;
            case 2:
                system("clear||cls");
                wprintf(L"\t\t\t\t\tRECEITAS DE FEVEREIRO");
                ;
                char mes2[3] = "02";
                imprimirReceitasDoMes("receitas.dat", mes2);
                break;
            case 3:
                system("clear||cls");
                wprintf(L"\t\t\t\t\tRECEITAS DE MARÇO");
                ;
                char mes3[3] = "03";
                imprimirReceitasDoMes("receitas.dat", mes3);
                break;
            case 4:
                system("clear||cls");
                wprintf(L"\t\t\t\t\tRECEITAS DE ABRIL");
                ;
                char mes4[3] = "04";
                imprimirReceitasDoMes("receitas.dat", mes4);
                break;
            case 5:
                system("clear||cls");
                wprintf(L"\t\t\t\t\tRECEITAS DE MAIO");
                ;
                char mes5[3] = "05";
                imprimirReceitasDoMes("receitas.dat", mes5);
                break;
            case 6:
                system("clear||cls");
                wprintf(L"\t\t\t\t\tRECEITAS DE JUNHO");
                ;
                char mes6[3] = "06";
                imprimirReceitasDoMes("receitas.dat", mes6);
                break;
            case 7:
                system("clear||cls");
                wprintf(L"\t\t\t\t\tRECEITAS DE JULHO");
                ;
                char mes7[3] = "07";
                imprimirReceitasDoMes("receitas.dat", mes7);
                break;
            case 8:
                system("clear||cls");
                wprintf(L"\t\t\t\t\tRECEITAS DE AGOSTO");
                ;
                char mes8[3] = "08";
                imprimirReceitasDoMes("receitas.dat", mes8);
                break;
            case 9:
                system("clear||cls");
                wprintf(L"\t\t\t\t\tRECEITAS DE SETEMBRO");
                ;
                char mes9[3] = "09";
                imprimirReceitasDoMes("receitas.dat", mes9);
                break;
            case 10:
                system("clear||cls");
                wprintf(L"\t\t\t\t\tRECEITAS DE OUTUBRO");
                ;
                char mes10[3] = "10";
                imprimirReceitasDoMes("receitas.dat", mes10);
                break;
            case 11:
                system("clear||cls");
                wprintf(L"\t\t\t\t\tRECEITAS DE NOVEMBRO");
                ;
                char mes11[3] = "11";
                imprimirReceitasDoMes("receitas.dat", mes11);
                break;
            case 12:
                system("clear||cls");
                wprintf(L"\t\t\t\t\tRECEITAS DE DEZEMBRO");
                ;
                char mes12[3] = "12";
                imprimirReceitasDoMes("receitas.dat", mes12);
                break;
            case 0:
                break;
            default:
                invalido();
                break;
        }

    } while (opx!=0);
}

// FUNÇÕES

// IMPRIMIR DESPESAS POR MÊS (CHAT GPT)

void imprimirDespesasDoMes(const char *nomeArquivo, const char *mes) {

    FILE* fp;
    DESPESA* ds;
    ds = (DESPESA*) malloc(sizeof(DESPESA));
    fp = fopen("despesas.dat", "rb");
    if (fp == NULL) {
        wprintf(L"\nErro na criação");
        exit(1);
    }

    wprintf(L"\n");
    wprintf(L"\n||     CPF     ||           DESCRIÇÃO           ||   SALDO   ||  ID   ||     Data   || Status\n");

    while(fread(ds,sizeof(DESPESA), 1, fp)) {
        // Extrai o mês da data (assumindo que o formato é "dd/mm/yyyy")
        char mesDespesa[3];
        strncpy(mesDespesa, ds->data + 3, 2);
        mesDespesa[2] = '\0';

        // Compara o mês
        if (strcmp(mesDespesa, mes) == 0) {
            // Imprime a despesa
            wprintf(L"||-------------||-------------------------------||-----------||-------||------------||-------\n");
            wprintf(L"|| %-12s|| %-30s|| %-10.2f|| %-5s || %-11s|| %c\n",
       ds->cpf, ds->despesatext, ds->despesasaldo,
       ds->id, ds->data, ds->status);

        }
    }

    wprintf(L"\nTecle <ENTER> para continuar...\n");
    getchar();
    fflush(stdin);

    fclose(fp);
}

// IMPRIMIR RECEITAS POR MÊS (CHAT GPT)

void imprimirReceitasDoMes(const char *nomeArquivo, const char *mes) {

    FILE* fp;
    RECEITA* rc;
    rc = (RECEITA*) malloc(sizeof(RECEITA));
    fp = fopen("receitas.dat", "rb");
    if (fp == NULL) {
        wprintf(L"\nErro na criação");
        exit(1);
    }

    wprintf(L"\n");
    wprintf(L"\n||     CPF     ||           DESCRIÇÃO           ||   SALDO   ||  ID   ||     Data   || Status\n");

    while(fread(rc,sizeof(RECEITA), 1, fp)) {
        // Extrai o mês da data (assumindo que o formato é "dd/mm/yyyy")
        char mesReceita[3];
        strncpy(mesReceita, rc->data + 3, 2);
        mesReceita[2] = '\0';

        // Compara o mês
        if (strcmp(mesReceita, mes) == 0) {
            // Imprime a despesa
            wprintf(L"||-------------||-------------------------------||-----------||-------||------------||-------\n");
            wprintf(L"|| %-12s|| %-30s|| %-10.2f|| %-5s || %-11s|| %c\n",
       rc->cpf, rc->receitatext, rc->receitasaldo,
       rc->id, rc->data, rc->status);

        }
    }

    wprintf(L"\nTecle <ENTER> para continuar...\n");
    getchar();
    fflush(stdin);

    fclose(fp);
}

// RELATAR SALDO FINAL

void saldofinal(char* cpf) {

    FILE* fp;
    FILE* fp2;
    FILE* fp3;

    Cliente* cl;
    cl = (Cliente*) malloc(sizeof(Cliente));
    fp = fopen("clientes.dat", "rb");
    if (fp == NULL) {
        wprintf(L"\nErro na criação");
        exit(1);
    }

    DESPESA* ds;
    ds = (DESPESA*) malloc(sizeof(DESPESA));
    fp2 = fopen("despesas.dat", "rb");
    if (fp2 == NULL) {
        wprintf(L"\nErro na criação");
        exit(1);
    }

    RECEITA* rc;
    rc = (RECEITA*) malloc(sizeof(RECEITA));
    fp3 = fopen("receitas.dat", "rb");
    if (fp3 == NULL) {
        wprintf(L"\nErro na criação");
        exit(1);
    }


    double SALDORC = 0;
    double SALDODS = 0;
    double SALDOFINISH = 0;

    while(fread(cl,sizeof(Cliente), 1, fp)) 
    {
        if (strcmp(cl->cpf, cpf) == 0)
        {   
            if (cl->status != 'x')
            {

                char mes[3];
                obterMesAtual(mes);
                mes[2] = '\0';
                
                system("clear||cls");
                wprintf(L"\t\t\t\t\tRECEITAS DESSE MÊS");
                wprintf(L"\n||     CPF     ||           DESCRIÇÃO           ||   SALDO   ||  ID   ||     Data   ||\n");

                while(fread(rc,sizeof(RECEITA), 1, fp3)) {
                    // Extrai o mês da data (assumindo que o formato é "dd/mm/yyyy")
                    char mesReceita[3];
                    strncpy(mesReceita, rc->data + 3, 2);
                    mesReceita[2] = '\0';


                    // Compara o mês
                    if ((strcmp(mesReceita, mes) == 0) && (rc->status != 'x')) {
                        // Imprime a despesa
                        wprintf(L"||-------------||-------------------------------||-----------||-------||------------||\n");
                        wprintf(L"|| %-12s|| %-30s|| %-10.2f|| %-5s || %-11s||\n",
                        rc->cpf, rc->receitatext, rc->receitasaldo,
                        rc->id, rc->data);

                        SALDORC += rc->receitasaldo;

                    }
                }

                wprintf(L"\n");
                wprintf(L"\t\t\t\t\tDESPESAS DESSE MÊS");
                wprintf(L"\n||     CPF     ||           DESCRIÇÃO           ||   SALDO   ||  ID   ||     Data   ||\n");

                while(fread(ds,sizeof(DESPESA), 1, fp2)) {
                    // Extrai o mês da data (assumindo que o formato é "dd/mm/yyyy")
                    char mesDespesa[3];
                    strncpy(mesDespesa, ds->data + 3, 2);
                    mesDespesa[2] = '\0';

                    // Compara o mês
                    if ((strcmp(mesDespesa, mes) == 0) && (ds->status != 'x')) {
                        // Imprime a despesa
                        wprintf(L"||-------------||-------------------------------||-----------||-------||------------||\n");
                        wprintf(L"|| %-12s|| %-30s|| %-10.2f|| %-5s || %-11s||\n",
                        ds->cpf, ds->despesatext, ds->despesasaldo,
                        ds->id, ds->data);

                        SALDODS += ds->despesasaldo;
                    }
                }

                SALDOFINISH = SALDORC - SALDODS;
                wprintf(L"\n");
                wprintf(L"CLIENTE: %s", cl->nome);
                wprintf(L"\n");
                if (SALDOFINISH > 0)
                {
                    wprintf(L"O SEU SALDO FINAL DESSE MÊS É DE: \033[0;32m%.2f\033[0m", SALDOFINISH);
                } else {
                    wprintf(L"O SEU SALDO FINAL DESSE MÊS É DE: \033[0;31m%.2f\033[0m", SALDOFINISH);
                }
                wprintf(L"\n");
                wprintf(L"\nTecle <ENTER> para continuar...\n");
                getchar();
                fflush(stdin);

            } else {

                wprintf(L"\nCLIENTE NÃO EXISTENTE NO BANCO DE DADOS!");
                wprintf(L"\nTecle <ENTER> para continuar...\n");
                getchar();
                fflush(stdin);
            }
            
        }
    }






    fclose(fp);
    fclose(fp2);
    fclose(fp3);

    free(rc);
    free(ds);
    free(cl);
}