#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <wchar.h>
#include <stdbool.h>
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

    char datainfo[11];
    char ecpf[12];
    int number;
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
    wprintf(L"Digite a data da receita que deseja editar(xx/yy/zzzz): "); scanf("%[^\n]%*c", datainfo);
    fflush(stdin);
    wprintf(L"Digite a numeração dela: "); scanf("%d", &number);
    fflush(stdin);

    if(verifica_existe_cliente(ecpf) == 0)
    {
        while(fread(rc,sizeof(RECEITA), 1, fp)) 
        {
            if ((strcmp(rc->cpf, ecpf) == 0) && (strcmp(rc->data, datainfo) == 0) && (rc->id == number) && (rc->status != 'x')) 
            {
                contador++;
                do 
                {
                    system("clear||cls");
                    wprintf(L"\n");
                    wprintf(L"1 - CPF: %s\n", rc->cpf);
                    wprintf(L"2 - Origem: %s\n", rc->receitatext);
                    wprintf(L"3 - Saldo($): %.2f\n", rc->receitasaldo);
                    wprintf(L"4 - Data: %s\n", rc->data);
                    wprintf(L"5 - Numeração do dia: %d\n", rc->id);
                    wprintf(L"0 - Finalizar alterações.\n");
                    wprintf(L"\n Campo que deseja editar: "); scanf("%d",&opcc);
                    fflush(stdin);
                    switch (opcc) 
                    {
                    case 1:
                        wprintf(L"\n");
                        ler_cpf(rc->cpf);
                        break;
                    case 2:
                        wprintf(L"\nDigite um pequeno texto sobre a origem da desta receita(sem acentuação): "); scanf("%[^\n]%*c", rc->receitatext);
                        fflush(stdin);
                        break;
                    case 3:
                        wprintf(L"\n");
                        w_saldo(&rc->receitasaldo);
                        break;
                    case 4:
                        wprintf(L"\nDigite a data de quando foi cadastrada esta receita(xx/yy/zzzz): "); scanf("%[^\n]%*c", rc->data);
                        fflush(stdin);
                        break;
                    case 5:
                        wprintf(L"\nDigite qual foi a numeração do dia desta receita(1,2,3..): "); scanf("%d", &(rc->id));
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
            wprintf(L"Não foi encontrado a receita informada deste cliente!");
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

    char datainfo[11];
    char ecpf[12];
    int number;
    wprintf(L"\nDigite o CPF do cliente cuja a receita pertence(Apenas números): "); scanf("%[^\n]%*c", ecpf);
    fflush(stdin);
    wprintf(L"Digite a data da receita que deseja excluir(xx/yy/zzzz): "); scanf("%[^\n]%*c", datainfo);
    fflush(stdin);
    wprintf(L"Digite a numeração dela: "); scanf("%d", &number);
    fflush(stdin);

    excluirReceita(ecpf, datainfo, number);
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
RECEITA* preenche_receita(void) 
{
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

// EXCLUIR RECEITA
void excluirReceita(char* cpf, char* datainfo, int number) {

    FILE* fp;
    RECEITA* rc;
    rc = (RECEITA*) malloc(sizeof(RECEITA));
    fp = fopen("receitas.dat", "rb+");
    if (fp == NULL) {
        wprintf(L"\nErro na criação");
        exit(1);
    }

    while (fread(rc, sizeof(RECEITA), 1, fp)) {
        if ((strcmp(rc->cpf, cpf) == 0) && (strcmp(rc->data, datainfo) == 0) && (rc->id == number))  {
            rc->status = 'x';
            fseeko(fp, -1*(off_t)sizeof(RECEITA), SEEK_CUR);
            fwrite(rc, sizeof(RECEITA), 1, fp);
            wprintf(L"\nReceita excluída.\n");
            wprintf(L"\nTecle <ENTER> para continuar...\n");
            getchar();
            fflush(stdin);

            free(rc);
            fclose(fp);
            return;
        }
    }

    free(rc);
    fclose(fp);
    wprintf(L"\nReceita não encontrado.\n");

    wprintf(L"\nTecle <ENTER> para continuar...\n");
    getchar();
    fflush(stdin);
}