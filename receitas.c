#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <wchar.h>
#include <stdbool.h>
#include <time.h>
#include "receitas.h"
#include "variaveis.h"
#include "funcoes.h"
#include "clientes.h"

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
                break;
            case '4':
                excluir_receita();
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

    FILE* fp2;
    Cliente* cl;
    cl = (Cliente*) malloc(sizeof(Cliente));
    fp2 = fopen("clientes.dat", "r+b");
    if (fp2 == NULL) {
        wprintf(L"\nErro na criação");
        exit(1);
    }

    receita = preenche_receita();
    fwrite(receita, sizeof(RECEITA), 1, fp);

    while(fread(cl, sizeof(Cliente), 1, fp2)) {
        if ((strcmp(cl->cpf, receita->cpf) == 0) && (cl->status != 'x')) {
            cl->saldo += receita->receitasaldo;
        }
    }

    fseeko(fp2, -1*(off_t)sizeof(Cliente), SEEK_CUR);
    fwrite(cl, sizeof(Cliente), 1, fp2);

    fclose(fp2);
    free(cl);
    fclose(fp);
    free(receita);

    wprintf(L"\nReceita Cadastrada!");
    wprintf(L"\nTecle <ENTER> para continuar...\n");
    getchar();
    fflush(stdin);

}

void editar_receita(void){

    char chaveinfo[6];
    char ecpf[12];
    int opcc = -1;
    int contador = 0;

    FILE* fp;
    RECEITA* rc;
    rc = (RECEITA*) malloc(sizeof(RECEITA));
    fp = fopen("receitas.dat", "r+b");
    if (fp == NULL) {
        wprintf(L"\nErro na criação");
        exit(1);
    }

    system("clear||cls");
    wprintf(L"===============================\n");
    wprintf(L"======== Editar Receita =======\n");
    wprintf(L"===============================\n");
    wprintf(L"\n");


    wprintf(L"\nDigite o CPF do cliente cuja a receita pertence(Apenas números): "); scanf("%[^\n]%*c", ecpf);
    fflush(stdin);
    wprintf(L"Digite a chave dela: "); scanf("%[^\n]%*c", chaveinfo);
    fflush(stdin);

    if(verifica_existe_cliente(ecpf) == 0)
    {
        while(fread(rc,sizeof(RECEITA), 1, fp)) 
        {
            if ((strcmp(rc->cpf, ecpf) == 0) && (strcmp(rc->id, chaveinfo) == 0) && (rc->status != 'x')) 
            {
                contador++;
                do 
                {
                    system("clear||cls");
                    wprintf(L"CHAVE: %s\n", rc->id);
                    wprintf(L"\n");
                    wprintf(L"1 - CPF: %s\n", rc->cpf);
                    wprintf(L"2 - Origem: %s\n", rc->receitatext);
                    wprintf(L"3 - Valor da receita($): %.2f\n", rc->receitasaldo);
                    wprintf(L"4 - Data: %s\n", rc->data);
                    wprintf(L"0 - Finalizar alterações.\n");
                    wprintf(L"\n Campo que deseja editar: "); scanf("%d",&opcc);
                    fflush(stdin);
                    switch (opcc) 
                    {
                    case 1:
                        wprintf(L"\n");
                        do 
                        {
                            ler_cpf(rc->cpf);
                        } while (verifica_existe_cliente(rc->cpf) != 0);
                        break;
                    case 2:
                        wprintf(L"\nDigite um pequeno texto sobre a origem da desta receita(sem acentuação): "); scanf("%[^\n]%*c", rc->receitatext);
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
                            if ((strcmp(cl->cpf, rc->cpf) == 0) && (cl->status != 'x')) {
                                cl->saldo -= rc->receitasaldo;
                            }
                        }

                        fseeko(fp2, -1*(off_t)sizeof(Cliente), SEEK_CUR);
                        fwrite(cl, sizeof(Cliente), 1, fp2);

                        fclose(fp2);
                        free(cl);

                        w_saldo(&rc->receitasaldo);
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
                            if ((strcmp(clf->cpf, rc->cpf) == 0) && (clf->status != 'x')) {
                                clf->saldo += rc->receitasaldo;
                            }
                        }

                        fseeko(fp3, -1*(off_t)sizeof(Cliente), SEEK_CUR);
                        fwrite(clf, sizeof(Cliente), 1, fp3);

                        fclose(fp3);
                        free(clf);

                        break;
                    case 4:
                        wprintf(L"\n");
                        lerData(rc->data);
                        fflush(stdin);
                        break;
                    case 0:
                        break;
                    default:
                        invalido();
                        break;
                    }
                    fseeko(fp, -1*(off_t)sizeof(RECEITA), SEEK_CUR);
                    fwrite(rc, sizeof(RECEITA), 1, fp);
                } while (opcc!=0);
                break;
            }
        }

        if (contador == 0)
        {
            wprintf(L"\n");
            wprintf(L"Não foi encontrada a receita informada deste cliente!");
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

void excluir_receita(void){

    char chaveinfo[6];
    char ecpf[12];
    wprintf(L"\nDigite o CPF do cliente cuja a receita pertence(Apenas números): "); scanf("%[^\n]%*c", ecpf);
    fflush(stdin);
    wprintf(L"Digite a chave dela: "); scanf("%[^\n]%*c", chaveinfo);
    fflush(stdin);

    excluirReceita(ecpf, chaveinfo);
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
    wprintf(L"\nDigite o CPF do cliente(Apenas números): "); scanf("%[^\n]%*c", icpf);
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
RECEITA* preenche_receita(void) {
    RECEITA* rc;
    rc = (RECEITA*) malloc(sizeof(RECEITA));

    bool v = true, f = false;
    char c;

    while(v) {
        ler_cpf(rc->cpf);
        c = verifica_existe_cliente(rc->cpf);
        if (c != 1) {
            v = f;  
        } else {
            wprintf(L"\nEste cliente ainda não foi cadastrado em nosso sistema\n!");
        }
    }
    wprintf(L"Digite um pequeno texto sobre a origem da desta receita(sem acentuação): "); scanf("%[^\n]%*c", rc->receitatext);
    fflush(stdin);
    w_saldo(&rc->receitasaldo);
    obterDataAtual(rc->data);
    gerarCodigoAleatorio(rc->id);
    rc->status = 'a';

    return rc;
}

// EXIBIR RECEITAS
void exibe_receitas(RECEITA* rc, char *icpf){
    //  (rc->data == datinhainfo) && 
    if (rc == NULL) {
        wprintf(L"\n= = = Receitas Inexistentes = = =\n");
    } else if((strcmp(rc->cpf, icpf) == 0) && (rc->status != 'x')) {
        wprintf(L"\n------ %s ------\n", rc->data);
        wprintf(L"CHAVE: %s \n", rc->id);
        wprintf(L"Valor Adiquirido(R$): %.2f\n", rc->receitasaldo);
        wprintf(L"Origem: %s\n", rc->receitatext);
    }
    else {
        return;
    }
} 

// EXCLUIR RECEITA
void excluirReceita(char* cpf, char* chaveinfo) {

    FILE* fp;
    RECEITA* rc;
    rc = (RECEITA*) malloc(sizeof(RECEITA));
    fp = fopen("receitas.dat", "rb+");
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

    while (fread(rc, sizeof(RECEITA), 1, fp)) {
        if ((strcmp(rc->cpf, cpf) == 0) && (strcmp(rc->id, chaveinfo) == 0))  {
            rc->status = 'x';
            fseeko(fp, -1*(off_t)sizeof(RECEITA), SEEK_CUR);
            fwrite(rc, sizeof(RECEITA), 1, fp);

            while(fread(cl, sizeof(Cliente), 1, fp2)) {
                if ((strcmp(cl->cpf, rc->cpf) == 0) && (cl->status != 'x')) {
                    cl->saldo -= rc->receitasaldo;
                }
            }

            fseeko(fp2, -1*(off_t)sizeof(Cliente), SEEK_CUR);
            fwrite(cl, sizeof(Cliente), 1, fp2);

            wprintf(L"\nReceita excluída.\n");
            wprintf(L"\nTecle <ENTER> para continuar...\n");
            getchar();
            fflush(stdin);

            fclose(fp2);
            free(cl);
            free(rc);
            fclose(fp);
            return;
        }
    }

    free(rc);
    fclose(fp);
    wprintf(L"\nReceita não encontrada.\n");

    wprintf(L"\nTecle <ENTER> para continuar...\n");
    getchar();
    fflush(stdin);
}
