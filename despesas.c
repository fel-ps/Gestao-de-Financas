#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <wchar.h>
#include <stdbool.h>
#include <time.h>
#include "despesas.h"
#include "variaveis.h"
#include "funcoes.h"
#include "clientes.h"

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

    FILE* fp2;
    Cliente* cl;
    cl = (Cliente*) malloc(sizeof(Cliente));
    fp2 = fopen("clientes.dat", "r+b");
    if (fp2 == NULL) {
        wprintf(L"\nErro na criação");
        exit(1);
    }

    despesa = preenche_despesa();
    fwrite(despesa, sizeof(DESPESA), 1, fp);

    while(fread(cl, sizeof(Cliente), 1, fp2)) {
        if ((strcmp(cl->cpf, despesa->cpf) == 0) && (cl->status != 'x')) {
            cl->saldo -= despesa->despesasaldo;
        }
    }

    fseeko(fp2, -1*(off_t)sizeof(Cliente), SEEK_CUR);
    fwrite(cl, sizeof(Cliente), 1, fp2);

    fclose(fp2);
    free(cl);
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

    char chaveinfo[6];
    char ecpf[12];
    int opcc = -1;
    int contador = 0;

    FILE* fp;
    DESPESA* ds;
    ds = (DESPESA*) malloc(sizeof(DESPESA));
    fp = fopen("despesas.dat", "r+b");
    if (fp == NULL) {
        wprintf(L"\nErro na criação");
        exit(1);
    }

    system("clear||cls");
    wprintf(L"===============================\n");
    wprintf(L"======== Editar Despesa =======\n");
    wprintf(L"===============================\n");
    wprintf(L"\n");


    wprintf(L"\nDigite o CPF do cliente cuja a despesa pertence(Apenas números): "); scanf("%[^\n]%*c", ecpf);
    fflush(stdin);
    wprintf(L"Digite a chave dela: "); scanf("%[^\n]%*c", chaveinfo);
    fflush(stdin);

    if(verifica_existe_cliente(ecpf) == 0)
    {
        while(fread(ds,sizeof(DESPESA), 1, fp)) 
        {
            if ((strcmp(ds->cpf, ecpf) == 0) && (strcmp(ds->id, chaveinfo) == 0) && (ds->status != 'x')) 
            {
                contador++;
                do 
                {
                    system("clear||cls");
                    wprintf(L"CHAVE: %s\n", ds->id);
                    wprintf(L"\n");
                    wprintf(L"1 - CPF: %s\n", ds->cpf);
                    wprintf(L"2 - Origem: %s\n", ds->despesatext);
                    wprintf(L"3 - Valor da despesa($): %.2f\n", ds->despesasaldo);
                    wprintf(L"4 - Data: %s\n", ds->data);
                    wprintf(L"0 - Finalizar alterações.\n");
                    wprintf(L"\n Campo que deseja editar: "); scanf("%d",&opcc);
                    fflush(stdin);
                    switch (opcc) 
                    {
                    case 1:
                        wprintf(L"\n");
                        do 
                        {
                            ler_cpf(ds->cpf);
                        } while (verifica_existe_cliente(ds->cpf) != 0);
                        break;
                    case 2:
                        wprintf(L"\nDigite um pequeno texto sobre a origem da desta despesa(sem acentuação): "); scanf("%[^\n]%*c", ds->despesatext);
                        fflush(stdin);
                        break;
                    case 3:
                        wprintf(L"\n");

                        FILE* fp2;
                        Cliente* cl;
                        cl = (Cliente*) malloc(sizeof(Cliente));
                        fp2 = fopen("clientes.dat", "r+b");
                        if (fp2 == NULL) {
                            wprintf(L"\nErro na criação");
                            exit(1);
                        }

                        while(fread(cl, sizeof(Cliente), 1, fp2)) {
                            if ((strcmp(cl->cpf, ds->cpf) == 0) && (cl->status != 'x')) {
                                cl->saldo += ds->despesasaldo;
                            }
                        }

                        fseeko(fp2, -1*(off_t)sizeof(Cliente), SEEK_CUR);
                        fwrite(cl, sizeof(Cliente), 1, fp2);

                        fclose(fp2);
                        free(cl);

                        w_saldo(&ds->despesasaldo);
                        fflush(stdin);

                        FILE* fp3;
                        Cliente* clf;
                        clf = (Cliente*) malloc(sizeof(Cliente));
                        fp3 = fopen("clientes.dat", "r+b");
                        if (fp3 == NULL) {
                            wprintf(L"\nErro na criação");
                            exit(1);
                        }

                        while(fread(clf, sizeof(Cliente), 1, fp3)) {
                            if ((strcmp(clf->cpf, ds->cpf) == 0) && (clf->status != 'x')) {
                                clf->saldo -= ds->despesasaldo;
                            }
                        }

                        fseeko(fp3, -1*(off_t)sizeof(Cliente), SEEK_CUR);
                        fwrite(clf, sizeof(Cliente), 1, fp3);

                        fclose(fp3);
                        free(clf);

                        break;
                    case 4:
                        wprintf(L"\n");
                        lerData(ds->data);
                        fflush(stdin);
                        break;
                    case 0:
                        break;
                    default:
                        invalido();
                        break;
                    }
                    fseeko(fp, -1*(off_t)sizeof(DESPESA), SEEK_CUR);
                    fwrite(ds, sizeof(DESPESA), 1, fp);
                } while (opcc!=0);
                break;
            }
        }

        if (contador == 0)
        {
            wprintf(L"\n");
            wprintf(L"Não foi encontrada a despesa informada deste cliente!");
            wprintf(L"\nTecle <ENTER> para continuar...\n");
            getchar();
            fflush(stdin);
        }

    } else{
        wprintf(L"\nCliente não encontrado!");
        wprintf(L"\nTecle <ENTER> para continuar...\n");
        getchar();
        fflush(stdin);
    }
}

void excluir_despesa(void){

    char chaveinfo[6];
    char ecpf[12];
    wprintf(L"\nDigite o CPF do cliente cuja a despesa pertence(Apenas números): "); scanf("%[^\n]%*c", ecpf);
    fflush(stdin);
    wprintf(L"Digite a chave dela: "); scanf("%[^\n]%*c", chaveinfo);
    fflush(stdin);

    excluirDespesa(ecpf, chaveinfo);
}

// CADASTRA DESPESA
DESPESA* preenche_despesa(void) 
{
    DESPESA* ds;
    ds = (DESPESA*) malloc(sizeof(DESPESA));

    bool v = true, f = false;
    char c;

    while(v) {
        ler_cpf(ds->cpf);
        c = verifica_existe_cliente(ds->cpf);
        if (c != 1) {
            v = f;  
        } else {
            wprintf(L"\nEste cliente ainda não foi cadastrado em nosso sistema\n!");
        }
    }
    wprintf(L"Digite um pequeno texto sobre a origem da desta receita(sem acentuação): "); scanf("%[^\n]%*c", ds->despesatext);
    fflush(stdin);
    w_saldo(&ds->despesasaldo);
    obterDataAtual(ds->data);
    gerarCodigoAleatorio(ds->id);
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
        wprintf(L"\n------ %s ------\n", ds->data);
        wprintf(L"CHAVE: %s \n", ds->id);
        wprintf(L"Valor Perdido(R$): %.2f\n", ds->despesasaldo);
        wprintf(L"Origem: %s\n", ds->despesatext);
    }
    else {
        return;
    }
}

// EXCLUIR DESPESA
void excluirDespesa(char* cpf, char* chaveinfo) {

    FILE* fp;
    DESPESA* ds;
    ds = (DESPESA*) malloc(sizeof(DESPESA));
    fp = fopen("despesas.dat", "rb+");
    if (fp == NULL) {
        wprintf(L"\nErro na criação");
        exit(1);
    }

    FILE* fp2;
    Cliente* cl;
    cl = (Cliente*) malloc(sizeof(Cliente));
    fp2 = fopen("clientes.dat", "r+b");
    if (fp2 == NULL) {
        wprintf(L"\nErro na criação");
        exit(1);
    }

    while (fread(ds, sizeof(DESPESA), 1, fp)) {
        if ((strcmp(ds->cpf, cpf) == 0) && (strcmp(ds->id, chaveinfo) == 0))  {
            ds->status = 'x';
            fseeko(fp, -1*(off_t)sizeof(DESPESA), SEEK_CUR);
            fwrite(ds, sizeof(DESPESA), 1, fp);

            while(fread(cl, sizeof(Cliente), 1, fp2)) {
                if ((strcmp(cl->cpf, ds->cpf) == 0) && (cl->status != 'x')) {
                    cl->saldo += ds->despesasaldo;
                }
            }

            fseeko(fp2, -1*(off_t)sizeof(Cliente), SEEK_CUR);
            fwrite(cl, sizeof(Cliente), 1, fp2);

            wprintf(L"\nDespesa excluída.\n");
            wprintf(L"\nTecle <ENTER> para continuar...\n");
            getchar();
            fflush(stdin);

            fclose(fp2);
            free(cl);
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

